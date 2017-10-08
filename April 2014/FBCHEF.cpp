#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int log(int n)
{
	int res = 1;
	while ((1 << res) < n)
		++res;
	return res;
}

const int maxn = 100000;
const int log_maxn = 17;
int n;

int wealth[maxn + 1];
int height[maxn + 1];

vector <int> graph[maxn];

int sparse_table[maxn][log_maxn];

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> wealth[i];

	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}


}