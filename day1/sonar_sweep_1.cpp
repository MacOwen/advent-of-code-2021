#include <iostream>
using namespace std;

int main() {
	int previous_depth;
	int depth;

	// Input first depth reading
	cin >> previous_depth;

	// Read all depths, incrementing when depth is greater than previous depth
	int num_increases = 0;
	while (cin >> depth) {
		if (depth > previous_depth)
			num_increases++;
		previous_depth = depth;
	}

	// Output final number of depth increases
	cout << num_increases<< '\n';
}
