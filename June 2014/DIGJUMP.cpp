#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	string s;
	cin >> s;
	vector < int > bucket[10];
	for (int i = 0; i < s.size(); ++i)
		bucket[s[i] - '0'].push_back(i);

	queue <int> q;
	vector <int> d(s.size(), 1000 * 1000 * 1000);
	vector <char> used(10, false);
	vector <char> used_long(s.size(), false);

	used_long[0] = true;
	d[0] = 0;
	q.push(0);

	int end = s.size() - 1;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		if (curr + 1 < s.size() && !used_long[curr + 1])
		{
			d[curr + 1] = d[curr] + 1;
			used_long[curr + 1] = true;
			q.push(curr + 1);
			if (curr + 1 == end)
			{
				cout << d[end] << endl;
				return 0;
			}
		}

		if (curr - 1 >= 0 && !used_long[curr - 1])
		{
			d[curr - 1] = d[curr] + 1;
			used_long[curr - 1] = true;
			q.push(curr - 1);
		}

		int number = s[curr] - '0';

		if (!used[number])
		{
			for (int i = 0; i < bucket[number].size(); ++i)
			{
				int node = bucket[number][i];
				if (!used_long[node])
				{
					d[node] = d[curr] + 1;
					used_long[node] = true;
					q.push(node);
				}
				if (node == end)
				{
					cout << d[end] << endl;
					return 0;
				}
			}
			used[number] = true;
		}
	}
}