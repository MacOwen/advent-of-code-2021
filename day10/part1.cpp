#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

int main() {
	freopen("input.txt","r",stdin);

	// Read file input
	vector<string> data;
	string s;
	while (cin >> s)
		data.push_back(s);

	unordered_map<char,int> points = {
		{')', 3},
		{']', 57},
		{'}', 1197},
		{'>', 25137}
	};
	unordered_map<char,char> closing = {
		{'(', ')'},
		{'[', ']'},
		{'{', '}'},
		{'<', '>'}
	};

	// Calculate score for each line
	int total_score = 0;
	for (string line : data) {
		stack<int> current;
		for (char c : line) {
			if (closing.find(c) != closing.end()) {
				current.push(closing[c]);
			} else {
				if (!current.empty() && current.top() == c) {
					current.pop();
				} else {
					total_score += points[c];
					break;
				}
			}
		}
	}

	cout << "Result: " << total_score << '\n';
}
