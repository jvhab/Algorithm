#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <tuple>
#include <map>
using namespace std;

class Node
{
public:
	int freq;
	string code;

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
	static void decode()
	{
		pair<int, int> p1;
		map<string, char> mp1;
		cin >> p1.first >> p1.second;
		cin.get();
		for (int i = 0; i < p1.first; ++i)
		{
			string s1;
			getline(cin, s1);
			char first_symb = s1[0];
			string s2 = "";
			for (size_t j = 3; j < s1.size(); ++j)
			{
				s2 += s1[j];
			}
			mp1[s2] = first_symb;
		}
		string s3;
		cin >> s3;
		string fin = "";
		string result = "";
		for (size_t i = 0; i < s3.size(); ++i)
		{
			fin += s3[i];
			if (mp1.find(fin) != mp1.end())
			{
				result = result + string(1, mp1[fin]);
				fin = "";
			}
		}
		cout << result;
		
	}
};

int main()
{
	string result;
	Node::decode();
	return 0;
}