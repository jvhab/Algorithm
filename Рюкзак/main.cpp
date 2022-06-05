#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int W;
	cin >> W;
	int n;
	cin >> n;
	vector<int> v1(n);
	for (auto& i : v1)
		cin >> i;
	vector<vector<int>> all_things;
	for (size_t i = 0; i <= n; ++i) {
		all_things.push_back(vector<int>(W + 1));
	}
	for (size_t i = 0; i <= n; ++i) {
		for (size_t j = 0; j <= W; ++j) {
			if (i == 0 || j == 0)
				all_things[i][j] = 0;
			else {
				if (v1[i - 1] > j)
					all_things[i][j] = all_things[i - 1][j];
				else {
					int prev = all_things[i - 1][j];
					int temp = v1[i - 1] + all_things[i - 1][j - v1[i - 1]];
					all_things[i][j] = max({ prev, temp });
				}
			}
		}
	}
	/*for (size_t i = 0; i <= n; ++i) {
		for (size_t j = 0; j <= W; ++j) {
			cout << all_things[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << all_things[n][W];
	return 0;
}