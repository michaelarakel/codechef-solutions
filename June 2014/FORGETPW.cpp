#include <iostream>
#include <deque>
#include <string>
#include <map>

using namespace std;

void solve()
{
	int rule_num;
	cin >> rule_num;
	map <char, char> change;
	for (int i = 0; i < rule_num; ++i)
	{
		char c, p;
		cin >> c >> p;
		change[c] = p;
	}
	deque <char> decimal, integer;
	string s;
	cin >> s;
	bool change_deque = false;
	for (int i = 0; i < s.size(); ++i)
	{
		auto it = change.find(s[i]);
		if (it != change.end())
			s[i] = it->second;
		if (s[i] == '.')
		{
			change_deque = true;
			continue;
		}
		if (change_deque)
			decimal.push_back(s[i]);
		else
			integer.push_back(s[i]);
	}
	while (!integer.empty() && integer.front() == '0')
		integer.pop_front();
	while (!decimal.empty() && decimal.back() == '0')
		decimal.pop_back();

	if (integer.empty() && decimal.empty())
		cout << '0';
	else
	{
		for (int i = 0; i < integer.size(); ++i)
			cout << integer[i];
		if (!decimal.empty())
		{
			cout << '.';
			for (int i = 0; i < decimal.size(); ++i)
				cout << decimal[i];
		}
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
}