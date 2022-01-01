#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int num_instructions = 0;
	string binary_string;
	cin >> binary_string;
	int num_bits = binary_string.length();
	vector<int> frequencies(num_bits);
	int data_length = 0;
	// Calculate frequency of '1' bits at each position
	while (cin) {
		for (int i = 0; i < binary_string.length(); i++) {
			if (binary_string[i] == '1') {
				frequencies[i]++;
			}
		}
		cin >> binary_string;
		data_length++;
	}
	// Calculate gamma rate based on frequencies
	int gamma_rate = 0;
	for (int frequency : frequencies) {
		gamma_rate <<= 1;
		if (frequency > data_length/2) {
			gamma_rate++;
		}
	}
	// Calculate epsilon rate based on gamma rate (binary inverse)
	int epsilon_rate = (1 << num_bits) - 1 - gamma_rate;

	int power_consumption = gamma_rate * epsilon_rate;
	cout << "Result: " << power_consumption << '\n';
}
