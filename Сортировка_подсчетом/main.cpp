#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> my_sort(vector<int>& v1)
{
	vector<int> result(11);
	vector<int> fin;
	for (auto k : v1)
		result[k]++;

	for (size_t i = 0; i < result.size(); i++)
	{
		while (result[i] != 0)
		{
			fin.push_back(i);
			result[i]--;
		}
	}
	
	return fin;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v1(n);
	for (auto& k : v1)
		cin >> k;
	vector<int> res = my_sort(v1);

	for (auto k : res)
		cout << k << " ";
	return 0;
}