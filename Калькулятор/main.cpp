#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> step(n + 1, INT_MAX);
	step[n] = 0;
	vector<int> prev(n + 1, -1);
	for (size_t i = n; i > 1; --i) {
		int temp = step[i] + 1;
		if (step[i / 3] > temp && i % 3 == 0) {
			step[i / 3] = temp;
			prev[i / 3] = i;
		}
		if (step[i / 2] > temp && i % 2 == 0) {
			step[i / 2] = temp;
			prev[i / 2] = i;
		}
		if (step[i - 1] > temp) {
			step[i - 1] = temp;
			prev[i - 1] = i;
		}
	}
	cout << step[1] << "\n";
	for (size_t i = 1; i != -1; i = prev[i])
		cout << i << " ";
	return 0;
}