#include <iostream>
#include <vector>

using namespace std;

enum turn
{
	first,
	second
};

inline turn rev(const turn& t)
{
	if (t == first)
		return second;
	return first;
}

const int maxn = 1000000;
int bucket[maxn];

void solve()
{
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	long long val = d;
	int max_val = -1;
	for (int i = 0; i < n; ++i)
	{
		if (i == 0)
		{
			++bucket[val];
			continue;
		}
		val = (a * val * val + b * val + c) % maxn;
		if (max_val < val)
			max_val = val;
		++bucket[val];
	}
	turn t = first;
	long long ans = 0;
	for (int i = max_val; i >= 0; --i)
	{
		if (!(bucket[i] & 1))
		{
			bucket[i] = 0;
			continue;
		}
		if (t == first)
			ans += i;
		else
			ans -= i;
		t = rev(t);
		bucket[i] = 0;
	}
	cout <<  abs(ans) << endl;
}

int main()
{
	int test_cases;
	cin >> test_cases;
	for (int i = 0; i < test_cases; ++i)
		solve();
}