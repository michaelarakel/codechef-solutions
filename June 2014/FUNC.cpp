//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int base = 1000 * 1000 * 1000 + 7;

long double eps = 1e-16;

const int maxn = 10001;
int v[maxn];

void solve()
{
	int n, queries;
	scanf("%d%d", &n, &queries);
	long long total_sum = 0;

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &v[i]);
		if (v[i] < 0)
			v[i] = -v[i];
		total_sum += v[i];
		if (total_sum >= base)
			total_sum -= base;
	}

	long double temp = 1;
	for (int query_num = 0; query_num < queries; ++query_num)
	{
		long long x;
		scanf("%lld", &x);

		long long query = total_sum;
		for (int i = 0; i < min(n, 100); ++i)
		{
			long long a = (long long) exp(log(x) / (i + 1));
			if (a == 1)
				break;
			--a;
			if (a >= base)
				a %= base;
			query += (a * v[i]) % base;
			if (query >= base)
				query %= base;
		}

		printf("%d\n", query);
	}
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
}