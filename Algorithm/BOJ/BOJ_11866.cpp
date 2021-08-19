#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> visited(n, 0);

    vector<int> ret;
    int num = 0;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        while (1)
        {
            if (visited[index] == 0)
                count++;
            if (count == k)
                break;
            index++;
            index %= n;
        }
        visited[index] = 1;
        ret.push_back(index + 1);
        index++;
        index %= n;
    }

    cout << "<";
    for (int i = 0; i < ret.size() - 1; i++)
    {
        cout << ret[i] << ", ";
    }
    cout << ret.back() << ">\n";
}