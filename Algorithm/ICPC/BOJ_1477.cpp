#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, L;
    priority_queue<int, vector<int>, greater<int>> station;
    for (int i=0; i<M; i++) {
        int item;
        cin>> item;
        station.push(item);
    }

    
}