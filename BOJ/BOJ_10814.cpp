#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    map<pair<int, int>, string> members;
    for(int i=0; i<N; i++) {
        int age;
        string name;
        cin >> age >> name;
        members[{age, i}] = name;
    }

    for(auto& m : members) cout << m.first.first << " " << m.second << '\n';
}