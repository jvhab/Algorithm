#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> ladder;
	vector<int> res(n + 1);
	ladder.push_back(0);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		ladder.push_back(a);
	}
	res[1] = ladder[1];
	for (size_t i = 2; i <= n; ++i) {
		res[i] = max({res[i - 1] + ladder[i], res[i - 2] + ladder[i]});

	}	
	cout << res[n] << "\n";

	return 0;
}