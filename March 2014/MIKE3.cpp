#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

inline bool next_combination(vector <int>& v, int n)
{
	int k = v.size();
	for (int i = k - 1; i >= 0; --i)
	{
		if (v[i] < n - k + i + 1)
		{
			++v[i];
			for (int j = i + 1; j < k; ++j)
				v[j] = v[j - 1] + 1;
			return true;
		}
	}
	return false;
}

inline bool is_clique(const vector <unordered_set <int> >& g, const vector <int>& combination)
{
	for (int i = 1; i < combination.size(); ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (g[combination[i] - 1].find(combination[j] - 1) == g[combination[i] - 1].end())
				return false;
		}
	}
	return true;
}

inline void find_biggest_clique(const vector <unordered_set <int> >& graph)
{
	int ans = 1;
	for (int i = 2; i <= graph.size(); ++i)
	{
		vector <int> combination(i);
		for (int j = 0; j < i; ++j)
			combination[j] = j + 1;
		bool got_clique = false;
		do
		{
			if (is_clique(graph, combination))
			{
				got_clique = true;
				break;
			}
		} while (next_combination(combination, graph.size()));

		if (!got_clique)
			break;
		else
			ans = i;
	}
	cout << ans;
}

int main()
{
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	vector <unordered_set <int> > v(m);
	for (int i = 0; i < m; ++i)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j)
		{
			int num;
			scanf("%d", &num);
			v[i].insert(num);
		}
	}
	vector <unordered_set <int> > g(m);
	for (int i = 1; i < m; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			bool intersect = false;
			for (auto it = v[j].begin(); !intersect && it != v[j].end(); ++it)
			{
				if (v[i].find(*it) != v[i].end())
				{
					intersect = true;
					break;
				}
			}
			if (!intersect)
			{
				g[i].insert(j);
				g[j].insert(i);
			}
		}
	}
	find_biggest_clique(g);
}