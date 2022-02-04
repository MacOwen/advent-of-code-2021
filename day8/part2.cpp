#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int pattern_to_int(string pattern) {
	int result = 0; for (char c : pattern)
		result += 1<<(c-'a');
	return result;
}

int main() {
	freopen("input.txt","r",stdin);

	// Process each line, count number of segments in each output number
	string s;
	vector<vector<int>> signal_data;
	vector<vector<int>> output_data;
	while (cin >> s) {
		// Process signal patterns
		vector<int> signals;
		for (int i=0;i<10;i++) {
			signals.push_back(pattern_to_int(s));
			cin >> s;
		}
		// Process output patterns
		vector<int> outputs;
		for (int i=0;i<4;i++) {
			cin >> s;
			outputs.push_back(pattern_to_int(s));
		}
		signal_data.push_back(signals);
		output_data.push_back(outputs);
	}
	
	int ans = 0;
	// Find output num for each signal output
	for (int display=0;display<signal_data.size();display++) {
		int patterns[10] = {}; // 7-segment representation for each number
		unordered_map<int,int> values; // Maps signal to real value
		unordered_set<int> found;
		// Find 1,4,7,8 (unique segment counts)
		for (int i : signal_data[display]) {
			if (__builtin_popcount(i) == 2) {
				values[i] = 1;
				patterns[1] = i;
				found.insert(i);
			} else if (__builtin_popcount(i) == 4) {
				values[i] = 4;
				patterns[4] = i;
				found.insert(i);
			} else if (__builtin_popcount(i) == 3) {
				values[i] = 7;
				patterns[7] = i;
				found.insert(i);
			} else if (__builtin_popcount(i) == 7) {
				values[i] = 8;
				patterns[8] = i;
				found.insert(i);
			}
		}
		int cf = patterns[1];
		int bd = patterns[4] & ~cf;
		// Find 3
		for (int i : signal_data[display]) {
			if (found.find(i) != found.end()) continue;
			if (__builtin_popcount(i & ~cf) == 3) {
				values[i] = 3;
				patterns[3] = i;
				found.insert(i);
			}
		}
		// Find 9
		for (int i : signal_data[display]) {
			if (found.find(i) != found.end()) continue;
			if (__builtin_popcount(i & patterns[3]) == 5) {
				values[i] = 9;
				patterns[9] = i;
				found.insert(i);
			}
		}
		int adg = patterns[3] & ~cf;
		// Find 0
		for (int i : signal_data[display]) {
			if (found.find(i) != found.end()) continue;
			if (__builtin_popcount(i & adg) == 2) {
				values[i] = 0;
				patterns[0] = i;
				found.insert(i);
			}
		}
		// Find 6
		for (int i : signal_data[display]) {
			if (found.find(i) != found.end()) continue;
			if (__builtin_popcount(i & ~adg) == 3) {
				values[i] = 6;
				patterns[6] = i;
				found.insert(i);
			}
		}
		// Find 5 and 2
		for (int i : signal_data[display]) {
			if (found.find(i) != found.end()) continue;
			if (__builtin_popcount(i & bd) == 2) {
				values[i] = 5;
				patterns[5] = i;
				found.insert(i);
			} else {
				values[i] = 2;
				patterns[2] = i;
				found.insert(i);
			}
		}
		// Calculate number from output pattern
		int num = 0;
		for (int i : output_data[display])
			num = num*10 + values[i];
		ans += num;
	}

	cout << "Result: " << ans << '\n';
}
