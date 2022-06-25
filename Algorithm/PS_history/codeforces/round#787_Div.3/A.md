# A. Food for Animals

엄청 쉬운 문제

## 성공. 9분 정도 소요

```java
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    int numOfDogFood, numOfCatFood, numOfUnivFood, numOfDog, numOfCat;

    void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numberOfTest = Integer.parseInt(br.readLine());

        for (int test = 0; test < numberOfTest; test++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            numOfDogFood = Integer.parseInt(st.nextToken());
            numOfCatFood = Integer.parseInt(st.nextToken());
            numOfUnivFood = Integer.parseInt(st.nextToken());
            numOfDog = Integer.parseInt(st.nextToken());
            numOfCat = Integer.parseInt(st.nextToken());

            numOfDogFood -= numOfDog;
            numOfCatFood -= numOfCat;
            if(numOfDogFood < 0) numOfUnivFood += numOfDogFood;
            if(numOfCatFood < 0) numOfUnivFood += numOfCatFood;

            if(numOfUnivFood < 0) System.out.println("NO");
            else System.out.println("YES");
        }
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}import java.io.*;
import java.util.StringTokenizer;

public class Main {

    int numOfDogFood, numOfCatFood, numOfUnivFood, numOfDog, numOfCat;

    void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numberOfTest = Integer.parseInt(br.readLine());

        for (int test = 0; test < numberOfTest; test++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            numOfDogFood = Integer.parseInt(st.nextToken());
            numOfCatFood = Integer.parseInt(st.nextToken());
            numOfUnivFood = Integer.parseInt(st.nextToken());
            numOfDog = Integer.parseInt(st.nextToken());
            numOfCat = Integer.parseInt(st.nextToken());

            numOfDogFood -= numOfDog;
            numOfCatFood -= numOfCat;
            if(numOfDogFood < 0) numOfUnivFood += numOfDogFood;
            if(numOfCatFood < 0) numOfUnivFood += numOfCatFood;

            if(numOfUnivFood < 0) System.out.println("NO");
            else System.out.println("YES");
        }
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
```

