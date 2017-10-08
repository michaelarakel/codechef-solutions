#include <iostream>
#include <vector>

using namespace std;

bool is_inside(pair <int, int> a, pair <int, int> b, int n)
{
	if (b.first <= b.second)
	{
		if (a.first <= a.second)
		{
			return (b.first <= a.first) &&
				(a.second <= b.second);
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (a.first > a.second)
		{
			return (b.first <= a.first) &&
				(a.second <= b.second);
		}
		else
		{
			return (a.first >= b.first && a.second <= n) ||
				(a.first >= 1 && a.second <= b.second);
		}
	}
}

void solve()
{
	int n, k, p;
	cin >> n >> k >> p;
	vector <pair <int, int> > my(k);
	vector <pair <int, int> > his(p);
	for (int i = 0; i < k; ++i)
		cin >> my[i].first >> my[i].second;
	for (int i = 0; i < p; ++i)
		cin >> his[i].first >> his[i].second;

	for (int i = 0; i < k; ++i)
	{
		pair <int, int> curr = my[i];
		bool found = 0;
		for (int j = 0; j < p; ++j)
		{
			if (is_inside(curr, his[j], n))
			{
				found = 1;
				break;
			}
		}
		if (!found)
		{
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
		solve();
}