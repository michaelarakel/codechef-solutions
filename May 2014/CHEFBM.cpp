#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m, p;
	cin >> n >> m >> p;
	vector < vector <int> > queries(n);
	for (int i = 0; i < p; ++i)
	{
		int a, b;
		cin >> a >> b;
		queries[a - 1].push_back(b - 1);
	}
	vector <int> v(m);
	for (int i = 0; i < m; ++i)
		v[i] = i + 1;

	for (int i = 0; i < n; ++i)
	{
		if (queries[i].empty())
		{
			cout << m - 1 << endl;
			continue;
		}

	}
}