#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector <long long>& v)
{
	for (auto it : v)
		cout << it << ' ';
	return;
}

void sim(vector <long long>& v)
{
	long long num = *max_element(v.begin(), v.end());
	for (auto& it : v)
		it = num - it;
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector <long long> v(n);
	bool has_negative = false;
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	if (k == 0)
		print(v);
	else
	{
		sim(v);
		--k;
		if (k & 1)
		{
			sim(v);
			print(v);
		}
		else
			print(v);
	}
}