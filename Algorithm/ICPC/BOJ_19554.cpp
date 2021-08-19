#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int min = 1, max = n;
    int mid;
    while (1)
    {
        mid = min + (max - min) / 2;
        cout << "? " << mid << endl;
        int res;
        cin >> res;
        if (res == 0)
        {
            cout << "= " << mid << endl;
            break;
        }
        else if (res == -1)
        {
            min = mid + 1;
        }
        else if (res == 1)
        {
            max = mid - 1;
        }
    }
}