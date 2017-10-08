#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	char c;
	vector <int> v[10];

	for (int i = 0; i < n; ++i)
	{
		cin >> c;
		int num = c - '0';
		for (int j = 0; j < 10; ++j)
		{
			int temp = abs(j - num);
			if (i > 0)
				temp += v[j][i - 1];
			v[j].push_back(temp);
		}
	}

	for (int i = 0; i < m; ++i)
	{
		int x; 
		cin >> x;
		int a;
		if (x == 1)
			a = v[0][0];
		else
			a = v[0][x - 1] - v[0][x - 2];
		cout << v[a][x - 1] << endl;
	}
}