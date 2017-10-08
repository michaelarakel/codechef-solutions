#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	int t;
	cin >> t;
	for (int test = 0; test < t; ++test)
	{
		int n, m;
		cin >> n >> m;

		int even[2], odd[2];

		even[0] = n / 2;
		odd[0] = n - even[0];

		even[1] = m / 2;
		odd[1] = m - even[1];

		long long frac[2];
		frac[0] = even[0] * 1ll * odd[1] + even[1] * 1ll * odd[0];
		frac[1] = n * 1ll * m;
		long long g = gcd(frac[0], frac[1]);

		cout << frac[0] / g << '/' << frac[1] / g << endl;
	}
}