#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int counter = 0;
	int max_ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		if (num == 0)
			counter = 0;
		else
			++counter;
		max_ans = max(max_ans, counter);
	}

	cout << max_ans << endl;
}