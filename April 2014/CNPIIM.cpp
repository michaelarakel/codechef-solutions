#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 2000000;
int dp[maxn + 1];

int lp[maxn + 1];
vector <int> pr;

void init_prime()
{
	for (int i = 2; i <= maxn; ++i)
	{
		if (lp[i] == 0)
		{
			pr.push_back(i);
			lp[i] = i;
		}
		for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * 1ll * pr[j] <= maxn; ++j)
			lp[i * pr[j]] = pr[j];
	}
}

int divisors_count(int n)
{
	if (n == 1)
		return 1;
	int ans = 1;
	while (n > 1)
	{
		int counter = 0;
		int temp = lp[n];
		while (temp == lp[n])
		{
			++counter;
			n /= lp[n];
		}
		ans *= (counter + 1);
	}
	return ans;
}

void init_dp()
{
	init_prime();
	dp[0] = dp[1] = 0;
	for (int i = 2; i <= maxn; ++i)
		dp[i] = dp[i - 1] + divisors_count(i - 1);
}

int main()
{
	init_dp();

	int t;
	cin >> t;

	for (int cases = 0; cases < t; ++cases)
	{
		int n;
		cin >> n;
		long long ans = 0;
		for (int i = 1; i <= n - 1; ++i)
		{
			int temp = i * (n - i);
			ans += dp[temp];
		}
		cout << ans << endl;
	}
}