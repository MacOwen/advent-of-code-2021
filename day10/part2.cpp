#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define ll int64_t

int main() {
	freopen("input.txt","r",stdin);

	// Read file input
	vector<string> data;
	string s;
	while (cin >> s)
		data.push_back(s);

	unordered_map<char,int> points = {
		{')', 1},
		{']', 2},
		{'}', 3},
		{'>', 4}
	};
	unordered_map<char,char> closing = {
		{'(', ')'},
		{'[', ']'},
		{'{', '}'},
		{'<', '>'}
	};

	// Calculate score for each line
	vector<ll> completion_scores;
	for (string line : data) {
		stack<int> current;
		for (char c : line) {
			if (closing.find(c) != closing.end()) {
				current.push(closing[c]);
			} else {
				if (!current.empty() && current.top() == c) {
					current.pop();
				} else {
					current = {};
					break;
				}
			}
		}
		// Calculate completion score (0 for complete lines)
		ll score = 0;
		while (!current.empty()) {
			score *= 5;
			score += points[current.top()];
			current.pop();
		}
		if (score)
			completion_scores.push_back(score);
	}
	// Take median score
	sort(completion_scores.begin(), completion_scores.end());
	ll middle_score = completion_scores[completion_scores.size()/2];

	cout << "Result: " << middle_score << '\n';
}
