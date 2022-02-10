#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<long> Merge(vector<long> a, vector<long> b, long& res)
{
	vector<long> result;
	auto ptr_a = a.begin();
	auto ptr_b = b.begin();
	while (true)
	{
		if (*ptr_a <= *ptr_b)
		{
			result.push_back(*ptr_a);
			ptr_a++;
			if (ptr_a == a.end())
			{
				result.insert(result.end(), ptr_b, b.end());
				break;
			}
		}
		else
		{
			long c = a.end() - ptr_a;
			result.push_back(*ptr_b);
			res += c;
			ptr_b++;
			if (ptr_b == b.end())
			{
				result.insert(result.end(), ptr_a, a.end());
				break;
			}
		}
	}
	return result;
}

vector<long> MergeSort(vector<long>& v, int left, int right, long& res)
{
	if (left == right)
	{
		vector<long> vec;
		vec.push_back(v[left]);
		return vec;
	}
	int mid = (left + right) / 2;
	return Merge(MergeSort(v, left, mid, res), MergeSort(v, mid + 1, right, res), res);
}

int main()
{
	int n;
	cin >> n;
	vector<long> v1(n);
	vector<long> result;
	long res = 0;
	for (auto& i : v1)
		cin >> i;
	result = MergeSort(v1, 0, v1.size() - 1, res);
	cout << res << endl;
	//for (auto s : result)
	//	cout << s << " ";
	return 0;
}