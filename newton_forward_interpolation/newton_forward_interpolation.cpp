#include <bits/stdc++.h>

using namespace std;

class newton_forward_interpolation {
private:
	int n;
	vector<int> a;
	vector<int> f;
	vector<vector<double>> dif;
	void factorial()
	{
		f[0] = 1;
		for (int i = 1; i <= n; ++i)
			f[i] = (f[i - 1] * i);
	}
	void calc_difference()
	{
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < n - i; ++j)
				dif[j][i] = dif[j + 1][i - 1] - dif[i][j - 1];
		}
	}
	double work(double u, int r)
	{
		double x = u;
		for (int i = 1; i < r; ++i)
			x *= (u - i);
		return x;
	}
public:
	newton_forward_interpolation(int _n) : n(_n) {
		a.resize(n);
		dif.resize(n, vector<double>(n));
		f.resize(n + 1);
		factorial();
	}
	void input()
	{
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		for (int i = 0; i < n; ++i)
			cin >> dif[i][0];
	}
	double calc()
	{
		int val;
		cin >> val;
		double sum = dif[0][0];
		double x = (val - a[0]) / (a[1] - a[0]);
		for (int i = 1; i < n; ++i)
			sum += work(x, i) * dif[0][i] / f[i];
		return sum;
	}
};
int32_t main()
{
	cin.tie(0)->sync_with_stdio(false);
	cout << setprecision(10) << fixed;

	int n;
	cout << "Enter number of items\n";
	cin >> n;
	newton_forward_interpolation obj(n);
	obj.input();
	cout << obj.calc() << '\n';
	return 0;
}