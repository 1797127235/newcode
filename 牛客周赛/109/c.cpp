#include<iostream>
#define int long long
using namespace std;

int get(int x1, int y1, int x2, int y2)
{
	int x = abs(x1 - x2);
	int y = abs(y1 - y2);
	return x * x + y * y;
}

signed main()
{
	int x1, y1, x2, y2;

	cin >> x1 >> y1 >> x2 >> y2;

    int x = -2 * (y2 - y1) + x1;
    int y = 2 * (x2 - x1) + y1;

    cout << x << " " << y << endl;

                               

    

}