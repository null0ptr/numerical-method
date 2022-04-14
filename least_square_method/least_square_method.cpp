#include <bits/stdc++.h>

using namespace std;

class least_square_method {
	int n;
	vector<double> a, b;
public:
	least_square_method(int _n) : n(_n) {
		a.resize(n);
		b.resize(n);
	}
	void calc()
	{
		for (int i = 0; i < n; ++i)
			cin >> a[i] >> b[i];
		double s1 = 0, s2 = 0, m1 = 0, m2 = 0;
		for (int i = 0; i < n; ++i)
		{
			s1 += a[i];
			s2 += b[i];
			m1 += a[i] * b[i];
			m2 += a[i] * a[i];
		}
		double ax = (s1 * m1 - s2 * m2) / (s1 * s1 - n * m2);
		double bx = (s2 * s1 - n * m1) / (s1 * s1 - n * m2);
		cout << "a = " << ax << ", b = " << bx << '\n';
	}
};
int32_t main()
{
	cin.tie(0)->sync_with_stdio(false);
	cout << setprecision(10) << fixed;

	auto v = freopen("./input_least_square_method.txt", "r", stdin);
	int n;
	cin >> n;
	least_square_method l(n);
	l.calc();
	return 0;
}