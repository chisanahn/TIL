#include <iostream>
#include <math.h>

using namespace std;

struct cor
{
    double x;
    double y;
    double z;
};

double dist(cor A, cor B)
{
    double x_dist = A.x - B.x;
    double y_dist = A.y - B.y;
    double z_dist = A.z - B.z;
    double ret = sqrt(x_dist * x_dist + y_dist * y_dist + z_dist * z_dist);
    return ret;
}

double func(cor A, cor B, cor C)  {
    if(A.x > B.x) return func(B, A, C);

    double g_y = (A.y - B.y) / (A.x - B.x);
    double g_z = (A.z - B.z) / (A.x - B.x);

    double x_min = A.x, x_max = B.x;
    double x_a, x_b; 
    cor a, b;
    while(x_max - x_min > 0.0000001) {
        a = b = A;
        x_a = x_min + (x_max - x_min) / 3;
        a.x = x_a;
        a.y += (x_a - A.x)*g_y;
        a.z += (x_a - A.x)*g_z;
        x_b = x_a + (x_max - x_min) / 3;
        b.x = x_b;
        b.y += (x_b - A.x)*g_y;
        b.z += (x_b - A.x)*g_z;

        if(dist(a, C) < dist(b, C)) x_max = x_b;
        else x_min = x_a;
    }
    return dist(a, C);
}

int main()
{
    cor A, B, C;
    cin >> A.x >> A.y >> A.z >> B.x >> B.y >> B.z >> C.x >> C.y >> C.z;
    
    cout << fixed;
    cout.precision(6);
    cout << func(A, B, C) << '\n';
}