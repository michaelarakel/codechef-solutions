#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void solve()
{
	int n, s, k;
	cin >> n >> k >> s;
	vector <pair<int, int> > v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i].first;
		v[i].second = i + 1;
	}

	sort(v.begin(), v.end(), greater<pair<int, int> >());

	sort(v.begin(), v.begin() + k);

	for (int i = 0; i < v.size(); ++i)
		cout << v[i].second << ' ';
	cout << endl;

}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
}