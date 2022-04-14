#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
	cin.tie(0)->sync_with_stdio(false);
	cout << setprecision(10) << fixed;

	int n;
	cin >> n;
	vector<vector<double>> a(n, vector<double>(n + 1));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= n; ++j)
			cin >> a[i][j];

	return 0;
}