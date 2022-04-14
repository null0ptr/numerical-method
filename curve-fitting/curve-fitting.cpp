#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
	cin.tie(0)->sync_with_stdio(false);
	cout << setprecision(10) << fixed;

	int n;
	cin >> n;
	vector<double> x(n), y(n);
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> y[i];
	double sx = 0, sy = 0, sxx = 0, sxy = 0;
	for (int i = 0; i < n; ++i)
	{
		sx += log(x[i]);
		sy += log(y[i]);
		sxx += log(x[i]) * log(x[i]);
		sxy += log(x[i]) * log(y[i]);
	}
	double b = (n * sxy - sx * sy) / (n * sxx - sx * sx);
	double a = (sy - b * sx) / n;
	cout << exp(a) << ' ' << b << '\n';
	return 0;
}