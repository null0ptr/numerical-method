#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream& operator<<(ostream& os, const T_container& v)
{
	os << '{';
	string sep;
	for (const T& x : v)
		os << sep << x, sep = ", ";
	return os << '}';
}

void dbg_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
	cerr << ' ' << H;
	dbg_out(T...);
}
#ifdef Local
#define debug(...) cerr<<"["<<__LINE__<<"]-->" << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

class bisection {
private:
	const double eps = 1e-8;
	double f(double x) const
	{
		return x * x * x + x * x - 1;
	}
public:
	bisection() {}
	double calc(double a, double b)
	{
		double mid = b;
		for (int i = 0; i < 1000000; ++i)
		{
			mid = (b + a) / 2.0;
			if (f(a) * f(mid) < 0)
				b = mid;
			else
				a = mid;
		}
		return mid;
	}
};
int32_t main()
{
	cin.tie(0)->sync_with_stdio(false);
	cout << setprecision(10) << fixed;

	bisection b;
	cout << b.calc(-10, 10) << '\n';

	return 0;
}