#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int base = 1000 * 1000 * 1000 + 9;

int n, q;
int m;

const int maxn = 100000;
const int maxm = 100;

int dp[maxm + 1][maxm + 1];
int v[maxn];

inline int subset_num()
{
	for (int i = 0; i < m; ++i)
		dp[i][0] = 0;
	for (int i = 0; i < n; ++i)
	{
		int curr = v[i] % m;
		if (curr < 0)
			curr += m;
		++dp[curr][0];
	}

	for (int j = 1; j < m; ++j)
	{
		for (int i = 0; i < m; ++i)
		{
			long long temp = 0;
			for (int k = 0; k <= m / 2; ++k)
			{
				for (int l = 0; l < j; ++l)
				{
					temp += dp[k][j - l] * 1ll * dp[(m + i - k) % m][l];
					if (temp >= base)
						temp -= base;
				}
			}
			dp[i][j] = temp;
		}
	}

	long long ans = 0;
	for (int i = 0; i < m; ++i)
	{
		ans += dp[0][i];
		ans %= base;
	}
	return ans;
}

inline void solve()
{
	cin >> n >> q;
	for (int i = 0; i < n; ++i)
		scanf("%d", &v[i]);
	vector <int> answers(100, -1);
	for (int i = 0; i < q; ++i)
	{
		scanf("%d", &m);
		if (answers[m - 1] == -1)
		{
			answers[m - 1] = subset_num();
			if (answers[m - 1] >= base)
				answers[m - 1] -= base;
		}
		printf("%d\n", answers[m - 1]);
	}
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
}