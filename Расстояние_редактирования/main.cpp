#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s1;
	string s2;
	cin >> s1 >> s2;
	int size_1 = s1.size();
	int size_2 = s2.size();
	vector<vector<int>> a;
	for (size_t i = 0; i <= size_1; ++i)
		a.push_back(vector<int>(size_2 + 1));
	for (size_t i = 0; i <= size_1; ++i)
		a[i][0] = i;
	for (size_t i = 0; i <= size_2; ++i)
		a[0][i] = i;
	for (size_t i = 1; i <= size_1; ++i) {
		for (size_t j = 1; j <= size_2; ++j) {
			int c{};
			if (s1[i - 1] == s2[j - 1])
				c = 0;
			else
				c = 1;
			int mins = min({ a[i][j - 1] + 1, a[i - 1][j] + 1, a[i - 1][j - 1] + c });
			a[i][j] = mins;
		}
	}
	cout << a[size_1][size_2] << "\n";
	return 0;
}