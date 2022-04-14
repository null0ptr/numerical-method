#include <bits/stdc++.h>

using namespace std;

class secant {
private:
	double f(double x) const {
		return -12 - 21 * x + 18 * x * x - 2.4 * x * x * x;
	}
	double fbar(double x) const {
		return -21 + 36 * x - 2.4 * 3 * x * x;
	}
public:
	secant() {}
	double calc()
	{
		double x0 = 1.3;
		double prv = 1;
		for (int i = 0; i < 1000000; ++i)
		{
			x0 = x0 - (f(x0) * (prv - x0)) / (f(prv) - f(x0));
		}
		return x0;
	}
};
int32_t main()
{
	cin.tie(0)->sync_with_stdio(false);
	cout << setprecision(10) << fixed;

	secant s;
	cout << s.calc() << '\n';
	return 0;
}