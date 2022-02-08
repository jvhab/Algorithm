#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct max_heap
{
	vector<int> v1;
	vector<int> result;

	void ShiftDown()
	{
		int i = 0;
		while (2 * i + 1 < v1.size())
		{
			int left = 2 * i + 1;
			int right = 2 * i + 2;
			int j = left;
			if (right < v1.size() && v1[right] > v1[left])
				j = right;
			if (v1[i] >= v1[j])
				break;
			swap(v1[i], v1[j]);
			i = j;
		}
	}

	void ShiftUp()
	{
		int i = v1.size() - 1;
		while (v1[i] > v1[(i - 1) / 2])
		{
			swap(v1[i], v1[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}

	void Insert(int number)
	{
		v1.push_back(number);
		ShiftUp();
	}

	void ExtractMax()
	{
		result.push_back(v1[0]);
		v1[0] = v1[v1.size() - 1];
		v1.erase(v1.end() - 1);
		ShiftDown();
	}

	void print()
	{
		for (auto i : result)
			cout << i << endl;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	max_heap temp;
	while (n--)
	{
		string comand;
		cin >> comand;
		if (comand == "Insert")
		{
			int n;
			cin >> n;
			temp.Insert(n);
		}
		else if (comand == "ExtractMax")
		{
			temp.ExtractMax();
		}
	}
	temp.print();
	return 0;
}