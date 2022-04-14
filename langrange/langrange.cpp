#include <bits/stdc++.h>

using namespace std;

class langrange {
private:
	int n;
	vector<int> x;
	vector<int> y;
public:
	langrange(int _n) : n(_n) {
		x.resize(n);
		y.resize(n);
	}
	void input()
	{
		for (int i = 0; i < n; ++i)
			cin >> x[i];
		for (int i = 0; i < n; ++i)
			cin >> y[i];
	}
	void calc()
	{
		double sum = 0;
		double tmp;
		cin >> tmp;
		for (int i = 0; i < n; ++i)
		{
			double p = 1;
			for (int j = 0; j < n; ++j)
			{
				if (i != j)
					p *= (tmp - x[j]) / (x[i] - x[j]);
			}
			sum += p * y[i];
		}
		cout << "Interpolated value at " << tmp << " is " << sum << '\n';
	}
};
int32_t main()
{
	cin.tie(0)->sync_with_stdio(false);
	cout << setprecision(10) << fixed;

	int n;
	cin >> n;
	langrange obj(n);
	obj.input();
	obj.calc();
	return 0;
}