#include <iostream>
using namespace std;

int main() {
	int previous_depth;
	int current_depth;

	// Input first depth reading
	cin >> previous_depth;

	// Read all depths, incrementing when depth is greater than previous depth
	int num_decreases = 0;
	while (cin >> current_depth) {
		if (current_depth > previous_depth)
			num_decreases++;
		previous_depth = current_depth;
	}

	// Output final number of depth increases
	cout << num_decreases << '\n';
}
