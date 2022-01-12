#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	freopen("input.txt","r",stdin);

	// Process line data
	vector<vector<int>> lines;
	while (cin) {
		int x_start, y_start, x_end, y_end;
		cin >> x_start;
		getchar(); // Skip "," between x and y values
		cin >> y_start;
		// Skip " -> " between coordinate pairs
		for (int i=0;i<4;i++) {
			getchar();
		}
		cin >> x_end;
		getchar(); // Skip "," between x and y values
		cin >> y_end;

		lines.push_back({x_start,y_start,x_end,y_end});
	}
	lines.pop_back();

	// Find x and y dimensions
	int x_dim = lines[0][0];
	int y_dim = lines[0][1];
	for (vector<int> line : lines) {
		int x_start = line[0];
		int y_start = line[1];
		int x_end = line[2];
		int y_end = line[3];
		x_dim = max(x_dim,x_start);
		x_dim = max(x_dim,x_end);
		y_dim = max(y_dim,y_start);
		y_dim = max(y_dim,y_end);
	}
	x_dim++;
	y_dim++;
	
	// Build grid with correct dimensions
	int grid[x_dim][y_dim] = {};

	// Fill grid
	for (vector<int> line : lines) {
		int x_start = line[0];
		int y_start = line[1];
		int x_end = line[2];
		int y_end = line[3];
		// Calculate line dimensions and x/y increment
		int x_length = abs(x_end-x_start);
		int y_length = abs(y_end-y_start);
		int line_length = max(x_length,y_length);
		int x_inc,y_inc;
		if (x_start == x_end)
			x_inc = 0;
		else
			x_inc = (x_end-x_start)/x_length;
		if (y_start == y_end)
			y_inc = 0;
		else
			y_inc = (y_end-y_start)/y_length;

		// Mark vents along line
		int x_pos = x_start;
		int y_pos = y_start;
		grid[x_start][y_start]++;
		for (int i=0;i<line_length;i++) {
			x_pos += x_inc;
			y_pos += y_inc;
			grid[x_pos][y_pos]++;
		}
	}

	// Count number of overlap tiles
	int overlap_tiles = 0;
	for (int x=0;x<x_dim;x++) {
		for (int y=0;y<y_dim;y++) {
			if (grid[x][y] > 1)
				overlap_tiles++;
		}
	}

	cout << "Result: " << overlap_tiles << '\n';
}
