#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <tuple>
using namespace std;

class Node
{
public:
	int freq;
	string code;

	// Для сортировки в priority_queue
	bool operator < (const Node& other) const
	{
		return tie(freq, code) > tie(other.freq, other.code);
	}
	static unordered_map<char, string> encode(const string& text)
	{
		unordered_map<char, int> freq_sym;
		for (auto s : text)
			freq_sym[s]++;
		vector<Node> v1;
		for (auto symb : freq_sym)
		{
			v1.push_back({ symb.second, string(1, symb.first) });
		}
		priority_queue<Node> que{ v1.begin(), v1.end() };
		unordered_map<char, string> result;
		if (v1.size() == 1)
		{
			result[v1[0].code[0]] = "0";
			return result;
		}
		while (que.size() >= 2)
		{
			auto first = que.top();
			que.pop();
			auto second = que.top();
			que.pop();
			for (auto s : first.code)
				result[s] = "0" + result[s];
			for (auto s : second.code)
				result[s] = "1" + result[s];
			que.push({ first.freq + second.freq, first.code + second.code });
		}
		return result;
	}
};

int main()
{
	string text;
	string result;
	cin >> text;
	auto res = Node::encode(text);
	for (auto s : text)
	{
		result += res[s];
	}
	cout << res.size() << " " << result.size() << endl;
	for (auto s : res)
	{
		cout << s.first << ": " << s.second << endl;
	}
	cout << result << endl;
	return 0;
}