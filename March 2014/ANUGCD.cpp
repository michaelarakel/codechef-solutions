#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 100000;

struct node
{
	node(int val = -1, int count = -1) : val(val), count(count) {}
	int count;
	int val;
};

node best(const node& a, const node& b)
{
	if (a.val < b.val)
		return b;
	if (a.val > b.val)
		return a;
	return node(a.val, a.count + b.count);
}

node max(const node& a, const node& b)
{
	if (a.val < b.val)
		return b;
	return a;
}

typedef vector <node> segment_tree;

void build(segment_tree& tree, const vector <int>& a, const int size, int v, int left, int right)
{
	if (left == right)
		tree[v] = node(a[left], 1);
	else
	{
		int middle = left + (right - left) / 2;
		build(tree, a, size, 2 * v, left, middle);
		build(tree, a, size, 2 * v + 1, middle + 1, right);
		tree[v] = best(tree[2 * v], tree[2 * v + 1]);
	}
}

void create(segment_tree& tree, const vector <int>& a, const int size, int v, int left, int right)
{
	tree.resize(4 * size + 1);
	build(tree, a, size, v, left, right);
}

node get_max(segment_tree& tree, int v, int l, int r, int tl, int tr)
{
	if (l > r)
		return node();
	if (l == tl && r == tr)
		return tree[v];
	int tm = tl + (tr - tl) / 2;
	return best(get_max(tree, 2 * v, l, min(r, tm), tl, tm),
		get_max(tree, 2 * v + 1, max(l, tm + 1), r, tm + 1, tr));
}

segment_tree trees[maxn + 1];
vector <vector <int> > pos(maxn);
vector <int> a(maxn);
int n, m;
vector<int> primes;
int lp[maxn + 1] = { 0, }; // lowest prime divisor

inline void init()
{
	lp[1] = 1;

	/*
	generation of all primes from [2, maxn] in O(maxn) and getting their factorisation
	*/
	for (int i = 2; i <= maxn; ++i)
	{
		if (lp[i] == 0)
		{
			lp[i] = i;
			primes.push_back(i);
		}
		for (int j = 0; j < primes.size() && primes[j] <= lp[i] && i * primes[j] <= maxn; ++j)
			lp[i * primes[j]] = primes[j];
	}
	vector <vector <int> > source(maxn);
	for (int i = 0; i < n; ++i)
	{
		int temp = a[i];
		while (temp > 1)
		{
			source[lp[temp]].push_back(a[i]);
			pos[lp[temp]].push_back(i);
			int temp2 = lp[temp];
			while (temp2 == lp[temp])
				temp /= lp[temp];
		}
	}
	for (auto it : primes)
	if (!source[it].empty())
		create(trees[it], source[it], source[it].size(), 1, 0, source[it].size() - 1);
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	init();
	for (int i = 0; i < m; ++i)
	{
		int g, x, y;
		scanf("%d %d %d", &g, &x, &y);
		node ans(-1, -1);
		while (g > 1)
		{
			if (!pos[lp[g]].empty())
			{
				int start_pos = lower_bound(pos[lp[g]].begin(), pos[lp[g]].end(), (x - 1)) - pos[lp[g]].begin(),
					end_pos = upper_bound(pos[lp[g]].begin(), pos[lp[g]].end(), (y - 1)) - pos[lp[g]].begin() - 1;
				if (start_pos <= end_pos)
					ans = max(ans, get_max(trees[lp[g]], 1, start_pos, end_pos, 0, pos[lp[g]].size() - 1));
			}
			int temp = lp[g];
			while (lp[g] == temp)
				g /= lp[g];
		}
		if (ans.val == -1)
			printf("%d %d\n", -1, -1);
		else
			printf("%d %d\n", ans.val, ans.count);
	}
}