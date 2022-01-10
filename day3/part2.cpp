#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

int binary_to_decimal(string s) {
	int num = 0;
	for (char c : s) {
		num <<= 1;
		if (c == '1') {
			num += 1;
		}
	}
	return num;
}

int main() {
	freopen("input.txt", "r", stdin);
	vector<string> binary_strings;
	while (cin) {
		string s;
		cin >> s;
		binary_strings.push_back(s);
	}
	int num_bits = binary_strings[0].length();

	// Calculate oxygen generator rating
	unordered_set<string> possible_numbers;
	for (string s : binary_strings) {
		possible_numbers.insert(s);
	}
	vector<int> current_indices;
	for (int i = 0; i < binary_strings.size(); i++) {
		current_indices.push_back(i);
	}
	for (int i = 0; i < num_bits; i++) {
		// Calculate most frequent bit
		int frequency = 0;
		for (int idx : current_indices) {
			if (binary_strings[idx][i] == '1') {
				frequency++;
			}
		}
		char bit;
		if (frequency*2 >= current_indices.size()) {
			bit = '1';
		} else {
			bit = '0';
		}
		// Remove non-matching binary strings
		vector<int> next_indices;
		for (int idx : current_indices) {
			if (binary_strings[idx][i] == bit) {
				next_indices.push_back(idx);
			} else {
				possible_numbers.erase(binary_strings[idx]);
				if (possible_numbers.size() == 1) {
					next_indices = {};
					break;
				}
			}
		}
		current_indices = next_indices;
	}
	int oxygen_rating = binary_to_decimal(*(possible_numbers.begin()));

	// Calculate CO2 scrubber rating
	possible_numbers = {};
	for (string s : binary_strings) {
		possible_numbers.insert(s);
	}
	current_indices = {};
	for (int i = 0; i < binary_strings.size(); i++) {
		current_indices.push_back(i);
	}
	for (int i = 0; i < num_bits; i++) {
		// Calculate most frequent bit
		int frequency = 0;
		for (int idx : current_indices) {
			if (binary_strings[idx][i] == '1') {
				frequency++;
			}
		}
		char bit;
		if (frequency*2 >= current_indices.size()) {
			bit = '0';
		} else {
			bit = '1';
		}
		// Remove non-matching binary strings
		vector<int> next_indices;
		for (int idx : current_indices) {
			if (binary_strings[idx][i] == bit) {
				next_indices.push_back(idx);
			} else {
				possible_numbers.erase(binary_strings[idx]);
				if (possible_numbers.size() == 1) {
					next_indices = {};
					break;
				}
			}
		}
		current_indices = next_indices;
	}
	int scrubber_rating = binary_to_decimal(*(possible_numbers.begin()));

	int life_support_rating = oxygen_rating * scrubber_rating;
	cout << "Result: " << life_support_rating << '\n';
}
