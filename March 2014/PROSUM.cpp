#include <iostream>
#include <vector>

using namespace std;

inline void solve()
{
	int n;
	cin >> n;
	
	int size = 0;
	int two_count = 0;
	int num;
	long long ans = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &num);
		if (num == 0 || num == 1)
			continue;
		ans += size;
		++size;
		if (num == 2)
		{
			ans -= two_count;
			++two_count;
		}
	}
	cout << ans << endl;
}

int main()
{
	int test_cases;
	cin >> test_cases;
	for (int i = 0; i < test_cases; ++i)
		solve();
}