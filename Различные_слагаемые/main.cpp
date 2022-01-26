#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<int> v1;
	cin >> n;
	int j = 0;
	int sums = 0;
	int nn = 0;
	if (n == 1)
	{
		std::cout << 1 << endl << 1;
	}
	else if (n == 2)
	{
		std::cout << 1 << endl << 2;
	}
	else
	{
		for (int i = 1; i < n; ++i)
		{
			sums += i;
			if (sums <= n)
			{
				v1.push_back(i);
			}
			else if (sums > n)
			{
				sums = sums - i;
				while (sums != n)
				{
					sums -= j;
					j++;
					sums += j;
				}
				v1[v1.size() - 1] = v1[v1.size() - 1] + j;
				break;
			}
		}
		cout << v1.size() << "\n";
		for (auto line : v1)
		{
			cout << line << " ";
		}
	}
	
	return 0;
}