#include <bits/stdc++.h>

using namespace std;

class simpson {
private:
	double upper, lower;
	int subinterval;
	double f(double x)
	{
		return 1 / (1 + pow(x, 2));
	}
public:
	simpson() {}
	void input()
	{
		cin >> upper >> lower >> subinterval;
	}
	void calc()
	{
		double ans = f(upper) + f(lower);
		double step = (upper - lower) / subinterval;
		for (int i = 1; i < subinterval; ++i)
		{
			double x = lower + i * step;
			if (i % 2)
				ans += 4 * f(x);
			else
				ans += 2 * f(x);
		}
		ans *= (step / 3);
		cout << fabs(ans) << '\n';
	}
};
int32_t main()
{
	cin.tie(0)->sync_with_stdio(false);
	cout << setprecision(10) << fixed;

	simpson obj;
	obj.input();
	obj.calc();
	return 0;
}