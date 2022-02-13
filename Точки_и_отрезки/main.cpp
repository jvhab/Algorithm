#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void my_quick_sort(vector<int>& v, int left, int right)
{
	int first = left;
	int last = right;
	int mid = (int)(left + right) / 2;
	while (first <= last)
	{
		while (v[first] < v[mid])
			first++;
		while (v[last] > v[mid])
			last--;
		if (first <= last)
		{
			swap(v[first], v[last]);
			first++;
			last--;
		}
	}
	if (left < last)
		my_quick_sort(v, left, last);
	if (right > first)
		my_quick_sort(v, first, right);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> start;
	vector<int> end;
	vector<int> point(m);
	while (n--)
	{
		int a;
		int b;
		cin >> a >> b;
		start.push_back(a);
		end.push_back(b);
	}
	for (auto& i : point)
		cin >> i;

	my_quick_sort(start, 0, start.size() - 1);
	my_quick_sort(end, 0, end.size() - 1);

	for (auto k : point)
	{
		auto n = upper_bound(start.begin(), start.end(), k);
		auto m = lower_bound(end.begin(), end.end(), k);

		cout << n - m << " ";
	}

	return 0;
}