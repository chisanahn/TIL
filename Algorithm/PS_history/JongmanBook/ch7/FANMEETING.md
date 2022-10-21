# 팬미팅

- ch7. 분할 정복
- 난이도 : 상

https://algospot.com/judge/problem/read/FANMEETING#

<br>

## 실패

30분 동안 고민해봤는데 1도 감이 안 온다.

<br>

## FFT를 이용한 풀이

카라츠바 알고리즘은 좀 느려서 JAVA의 경우, 시간초과가 난다는 얘기를 듣고 FFT를 공부한 뒤 FFT로 풀어봤다.

<details><summary>c++ 소스코드</summary>

```c++
#include <bits/stdc++.h>

using namespace std;

typedef complex<double> cpx;

void FFT(vector<cpx> &f, cpx w) {
    int n = (int) f.size();
    if(n == 1) return;
    
    vector<cpx> even(n/2), odd(n/2);
    for(int i=0; i<n; i++) {
        (i%2 ? odd : even)[i/2] = f[i];
    }
    
    FFT(even, w*w);
    FFT(odd, w*w);
    
    cpx wp(1, 0);
    for(int i=0; i<n/2; i++) {
        f[i] = even[i] + wp * odd[i];
        f[i + n/2] = even[i] - wp * odd[i];
        wp *= w;
    }
}

vector<int> multiply(vector<cpx> a, vector<cpx> b) {
    int n = 1;
    while(n < a.size() + 1 || n < b.size() + 1) n *= 2;
    n *= 2;
    
    a.resize(n);
    b.resize(n);
    
    cpx w(cos(2*M_PI/n), sin(2*M_PI/n));
    
    FFT(a, w);
    FFT(b, w);
    
    vector<cpx> c(n);
    for(int i=0; i<n; i++)
        c[i] = a[i] * b[i];
    FFT(c, cpx(1,0)/w);
    
    vector<int> ret(n);
    for(int i=0; i<n; i++) {
        c[i] /= cpx(n, 0);
        ret[i] = round(c[i].real());
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        string members, fans;
        cin >> members >> fans;
        
        vector<cpx> A(members.size());
        for(int i=0; i<A.size(); i++)
            A[i] = cpx(members[i] == 'M', 0);
        
        vector<cpx> B(fans.size());
        for(int i=0; i<B.size(); i++)
            B[B.size() - 1 - i] = cpx(fans[i] == 'M', 0);
        
        vector<int> ret = multiply(A, B);
        int allHugs = fans.size() - members.size() + 1;
        for(int i=0; i<fans.size()-members.size()+1; i++) {
            if(ret[members.size() - 1 + i]) allHugs--;
        }
        
        cout << allHugs << "\n";
    }
}

```

</details>

java로도 풀어봤지만 시간초과를 받았다.

<details><summary>java 소스코드</summary>

```java
import java.io.*;
import java.util.*;

class Complex {
    private final double r, i;

    public Complex(double real, double imaginary) {
        this.r = real;
        this.i = imaginary;
    }

    public double getReal() {
        return r;
    }

    public double getImaginary() {
        return i;
    }

    public Complex add(Complex other) {
        return add(this, other);
    }

    public Complex subtract(Complex other) {
        return subtract(this, other);
    }

    public Complex multiply(Complex other) {
        return multiply(this, other);
    }

    public Complex divide(Complex other) {
        return divide(this, other);
    }

    public static Complex add(Complex a, Complex b) {
        return new Complex(a.r + b.r, a.i + b.i);
    }

    public static Complex subtract(Complex a, Complex b) {
        return new Complex(a.r - b.r, a.i - b.i);
    }

    public static Complex multiply(Complex a, Complex b) {
        return new Complex(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r);
    }

    public static Complex divide(Complex c1, Complex c2) {
        double r = (c1.r * c2.r + c1.i * c2.i) / (c2.r * c2.r + c2.i * c2.i);
        double c = (c1.i * c2.r - c1.r * c2.i) / (c2.r * c2.r + c2.i * c2.i);
        return new Complex(r, c);
    }
}

class Main {

    void FFT(List<Complex> f, Complex w) {
        int n = f.size();
        if (n == 1) return;

        List<Complex> even = new ArrayList<>(), odd = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) even.add(f.get(i));
            else odd.add(f.get(i));
        }
        FFT(even, w.multiply(w));
        FFT(odd, w.multiply(w));

        Complex wp = new Complex(1, 0);
        for (int i = 0; i < n / 2; i++) {
            Complex curEven = even.get(i), curOdd = odd.get(i);
            f.set(i, curEven.add(wp.multiply(curOdd)));
            f.set(i + n / 2, curEven.subtract(wp.multiply(curOdd)));
            wp = wp.multiply(w);
        }
    }

    List<Integer> multiply(List<Complex> A, List<Complex> B) {
        int n = 1;
        while (n < A.size() + 1 || n < B.size() + 1) n *= 2;
        n *= 2;
        while (n > A.size()) A.add(new Complex(0, 0));
        while (n > B.size()) B.add(new Complex(0, 0));

        Complex w = new Complex(Math.cos(2 * Math.PI / n), Math.sin(2 * Math.PI / n));
        FFT(A, w);
        FFT(B, w);
        List<Complex> C = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            Complex a = A.get(i), b = B.get(i);
            C.add(a.multiply(b));
        }

        FFT(C, new Complex(1, 0).divide(w));
        for (int i = 0; i < n; i++) {
            Complex c = C.get(i);
            C.set(i, c.divide(new Complex(n, 0)));
        }
        List<Integer> ret = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            ret.add((int) Math.round(C.get(i).getReal()));
        }
        return ret;
    }

    void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            String members = br.readLine();
            List<Complex> A = new ArrayList<>();
            for (int i = 0; i < members.length(); i++) {
                if(members.charAt(i) == 'F') A.add(new Complex(0, 0));
                else A.add(new Complex(1, 0));
            }
            String fans = br.readLine();
            List<Complex> B = new ArrayList<>();
            for (int i = fans.length() - 1; i >= 0; i--) {
                if(fans.charAt(i) == 'F') B.add(new Complex(0, 0));
                else B.add(new Complex(1, 0));
            }

            List<Integer> ret = multiply(A, B);
            int allHugs = fans.length() - members.length() + 1;
            for (int i = 0; i < fans.length() - members.length() + 1; i++) {
                if (ret.get(members.length() - 1 + i) > 0) allHugs--;
            }
            sb.append(allHugs).append("\n");
        }
        System.out.print(sb.toString());
        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
```

</details>

<br>

## 비트마스킹을 이용한 풀이

길이가 최대 30만이기 때문에 일반적인 비트마스킹으로 불가능하다.

보통 배열을 이용해서 비트를 쪼개서 구현하는 식인것 같은데 코드를 봐도 잘 이해가 안 된다.

> 사실상 BitSet을 직접 구현하는 방법

https://algospot.com/judge/submission/detail/139936

`BitSet`이라는 클래스를 이용해서 비트마스킹을 엄청 간단하게 구현한 풀이도 있었다.

> 구현 코드를 좀 살펴보니깐 long[] 배열로 비트를 저장해서 사용한다.

https://algospot.com/judge/submission/detail/690409

위 풀이들을 참고해서 깔끔한 풀이를 하나 작성해봤다.

<details><summary>소스코드</summary>

```java
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int C = Integer.parseInt(br.readLine());
        for (int c = 0; c < C; c++) {

            String member = br.readLine();
            String fan = br.readLine();

            int memberMaleCnt = member.chars()
                    .reduce(0, (a, b) -> {
                        if (b == 'M') return a + 1;
                        else return a;
                    });

            int fanMaleCnt = fan.chars()
                    .reduce(0, (a, b) -> {
                        if (b == 'M') return a + 1;
                        else return a;
                    });

            if (memberMaleCnt == 0 || fanMaleCnt == 0) {
                sb.append(fan.length() - member.length() + 1).append("\n");
                continue;
            } else if (member.length() == memberMaleCnt && fan.length() == memberMaleCnt) {
                sb.append("0").append("\n");
                continue;
            }

            BitSet members = new BitSet(member.length());
            for (int i = member.length() - 1; i >= 0; i--) {
                if (member.charAt(i) == 'M') {
                    members.set(i);
                }
            }

            BitSet fans = new BitSet(fan.length());
            for (int i = fan.length() - 1; i >= 0; i--) {
                if (fan.charAt(i) == 'M') {
                    fans.set(i);
                }
            }

            int hugs = 0;
            for (int i = 0; i < fan.length() - member.length() + 1; i++) {
                if (!members.intersects(fans.get(i, fan.length()))) hugs++;
            }
            sb.append(hugs).append("\n");
        }
        System.out.print(sb.toString());
    }
}
```

</details>