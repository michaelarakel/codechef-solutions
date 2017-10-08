#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <numeric>

using namespace std;

typedef unsigned long long ull;

ull binpow_bymod(ull a, ull n)
{
	ull res = 1;
	while (n > 0)
	{
		if (n & 1)
			res = (res * a);
		a = (a * a);
		n >>= 1;
	}
	return res;
}

ull rev(ull n)
{
	ull reverse_modulo = binpow_bymod(n, 0ULL - 1);
	return reverse_modulo;
}

vector <ull > power;
vector <ull > rev_power;

inline void init_pow(int n)
{
	power.push_back(1);
	rev_power.push_back(1);
	for (int i = 1; i <= n; ++i)
	{
		power.push_back((power[i - 1] * 193));
		rev_power.push_back(rev(power[i]));
	}
}

inline void hasher(const string& s, vector <ull >& hash)
{
	hash.push_back(s[0] - 'a' + 1);
	for (int i = 1; i < s.size(); ++i)
		hash.push_back((hash[i - 1] + (s[i] - 'a' + 1) * power[i]));
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	init_pow(s1.size());
	vector <ull > hash_s1, hash_s2;
	hasher(s1, hash_s1);
	hasher(s2, hash_s2);
	int start = 1,
		end = s2.size();
	int pos_start, pos_end, len = 0;
	while (start <= end)
	{
		int middle = start + (end - start) / 2;
		unordered_set <ull > s;
		for (int i = 0; i < s1.size() - middle + 1; ++i)
		{
			if (i == 0)
				s.insert(hash_s1[middle - 1]);
			else
			{
				long long temp = hash_s1[i + middle - 1] - hash_s1[i - 1];
				s.insert(temp  * rev_power[i]);
			}
		}
		ull  check_hash = 0;
		bool found = false;
		for (int i = 0; i < s2.size() - middle + 1; ++i)
		{
			if (i == 0)
				check_hash = hash_s2[middle - 1];
			else
			{
				ull  temp = hash_s2[i + middle - 1] - hash_s2[i - 1];
				check_hash = temp * rev_power[i];
			}
			if (s.find(check_hash) != s.end())
			{
				len = middle;
				pos_start = i;
				pos_end = i + middle - 1;
				found = true;
				break;
			}
		}
		if (!found)
			end = middle - 1;
		else
			start = middle + 1;
	}
	if (len)
	{
		for (int i = pos_start; i <= pos_end; ++i)
			cout << s2[i];
		cout << endl;
	}
	cout << len << endl;
}