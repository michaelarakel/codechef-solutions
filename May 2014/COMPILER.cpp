#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main()
{
	bitset<32> b(-(1 << 15));
	cout << b;
	int t;
	cin >> t;
	for (int m = 0; m < t; ++m)
	{
		string s;
		cin >> s;
		int ans = 0;
		int depth = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '>')
				--depth;
			else
				++depth;
			if (depth < 0)
				break;
			if (depth == 0)
				ans = i + 1;
		}
		cout << ans << endl;
	}
}