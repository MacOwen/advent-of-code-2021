#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	freopen("input.txt","r",stdin);

	// Process fish data
	vector<int> data;
	while (cin) {
		int fish;
		cin >> fish;
		data.push_back(fish);
		// Ignore next character (comma)
		getchar();
	}
	data.pop_back();

	// Fill dp array for number of lanternfish spawned from a 0-day fish after i days for i=0..80
	int dp[data.size()+1] = {};
	dp[0] = 1;
	vector<int> lanternfish = {0};
	for (int day=1;day<=80;day++) {
		for (int i=lanternfish.size()-1;i>=0;i--) {
			if (lanternfish[i] == 0) {
				lanternfish[i] = 6;
				lanternfish.push_back(8);
			} else {
				lanternfish[i]--;
			}
		}
		dp[day] = lanternfish.size();
	}

	// Calculate total number of fish based on dp array
	int num_fish = 0;
	for (int days : data) {
		num_fish += dp[80-days];
	}

	cout << "Result: " << num_fish << '\n';
}
