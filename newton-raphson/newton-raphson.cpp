#include <bits/stdc++.h>

using namespace std;

class newton_raphson {
private:
	double f(double x) const {
		return 8 * exp(-x) * sin(x) - 1;
	}
	double fbar(double x) const {
		return 8 * exp(-x) * (cos(x) - sin(x));
	}
public:
	newton_raphson() {}
	double calc()
	{
		double x0 = 0.3;
		for (int i = 0; i < 1000000; ++i)
		{
			x0 = x0 - (f(x0) / fbar(x0));
		}
		return x0;
	}
};
int32_t main()
{
	cin.tie(0)->sync_with_stdio(false);
	cout << setprecision(10) << fixed;

	newton_raphson ns;
	cout << ns.calc() << '\n';
	return 0;
}