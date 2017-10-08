#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline bool test(const vector <int>& v, long long testing)
{
	for (int i = 0; i < v.size(); ++i)
	{
		if (testing < v[i])
			return false;
		--testing;
	}
	return true;
}

inline void solve()
{
	int n;
	scanf("%d", &n);
	vector <int> v(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &v[i]);
	long long start = 0,
		end = 1000 * 1000 * 1000 * 1ll * 100;
	while (start < end)
	{
		if (start == end - 1)
		{
			if (test(v, start))
				printf("%d\n", start);
			else
				printf("%d\n", end);
			return;
		}
		long long middle =  start + (end - start) / 2;
		if (test(v, middle))
			end = middle;
		else
			start = middle + 1;
	}
	printf("%d\n", start + (end - start) / 2);
}

int main()
{
	int test_cases;
	cin >> test_cases;
	for (int i = 0; i < test_cases; ++i)
		solve();
}