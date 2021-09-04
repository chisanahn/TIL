#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 0;
    for(int i=1; i<=n; i++) {
        if(i<100) count++;
        else {
            vector<int> S;
            int div = i;
            while(div>0) {
                S.push_back(div%10);
                div/=10;
            }
            reverse(S.begin(), S.end());
            if(S[0]-S[1] == S[1]-S[2]) count++;
        }
    }
    
    cout << count << '\n';
}