#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> window;
	int depth;
	int window_depth = 0;
	// Add first 3 depths to window
	for (int i = 0; i < 3; i++) {
		cin >> depth;
		window.push(depth);
		window_depth += depth;
	}

	// Slide window one depth reading at a time, incrementing whenever window size increases
	int num_increases = 0;
	int prev_window_depth = window_depth;
	while (cin >> depth) {
		window_depth -= window.front();
		window_depth += depth;
		if (window_depth > prev_window_depth) {
			num_increases++;
		}
		window.pop();
		window.push(depth);
		prev_window_depth = window_depth;
	}

	// Output final number of window depth increases
	cout << "Result: " << num_increases << '\n';
}
