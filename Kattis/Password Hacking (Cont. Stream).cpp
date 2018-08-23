#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	int n;
	string s;
	double a[500];
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)cin >> s >> a[i];
		sort(a, a + n);
		double r = 0;
		for (int i = 0; i < n; i++)r += a[i] * (n - i);
		printf("%.4f\n", r);
	}
	return 0;
}
