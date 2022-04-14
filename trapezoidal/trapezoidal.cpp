#include <bits/stdc++.h>

using namespace std;

class trapezoidal {
private:
	double subinterval, upper, lower;
	double f(double x)
	{
		return 1 / (1 + pow(x, 2));
	}
public:
	trapezoidal() {}
	void input()
	{
		cin >> upper >> lower >> subinterval;
	}
	void calc()
	{
		double step = (upper - lower) / subinterval;
		double ans = f(lower) + f(upper);
		for (int i = 1; i < subinterval; ++i)
			ans += (2 * f(lower + i * step));
		ans = ans * step / 2;
		cout << fabs(ans) << '\n';
	}
};
int32_t main()
{
	cin.tie(0)->sync_with_stdio(false);
	cout << setprecision(10) << fixed;

	trapezoidal obj;
	obj.input();
	obj.calc();
	return 0;
}