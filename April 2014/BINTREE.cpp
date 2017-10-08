#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

inline deque <int> get_ancestors(int n)
{
	deque <int> ans;
	ans.push_back(n);

	while (n != 1)
	{
		n /= 2;
		ans.push_front(n);
	}

	return ans;
}

inline void solve()
{
	int a[2];
	cin >> a[0] >> a[1];

	if (a[0] > a[1])
		swap(a[0], a[1]);

	deque <int> ancestors[2];
	for (int i = 0; i < 2; ++i)
		ancestors[i] = get_ancestors(a[i]);

	int lca;

	for (int i = ancestors[0].size() - 1; i >= 0; --i)
	if (binary_search(ancestors[1].begin(), ancestors[1].end(), ancestors[0][i]))
	{
		lca = ancestors[0][i];
		break;
	}

	int path_len[2] = { 0, 0 };

	for (int j = 0; j < 2; ++j)
	{
		for (int i = ancestors[j].size() - 1; i >= 0; --i)
		{
			if (ancestors[j][i] == lca)
				break;
			++path_len[j];
		}
	}

	cout << path_len[0] + path_len[1] << endl;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		solve();
}