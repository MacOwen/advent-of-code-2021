#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> grid;
int height, width;

void dfs(int r, int c) {
	// U
	if (r > 0 && grid[r-1][c] < 10) {
		grid[r-1][c]++;
		if (grid[r-1][c] == 10) {
			grid[r-1][c]++;
			dfs(r-1,c);
		}
	}
	// D
	if (r < height-1 && grid[r+1][c] < 10) {
		grid[r+1][c]++;
		if (grid[r+1][c] == 10) {
			grid[r+1][c]++;
			dfs(r+1,c);
		}
	}
	// L
	if (c > 0 && grid[r][c-1] < 10) {
		grid[r][c-1]++;
		if (grid[r][c-1] == 10) {
			grid[r][c-1]++;
			dfs(r,c-1);
		}
	}
	// R
	if (c < width-1 && grid[r][c+1] < 10) {
		grid[r][c+1]++;
		if (grid[r][c+1] == 10) {
			grid[r][c+1]++;
			dfs(r,c+1);
		}
	}
	// UL
	if (r > 0 && c > 0 && grid[r-1][c-1] < 10) {
		grid[r-1][c-1]++;
		if (grid[r-1][c-1] == 10) {
			grid[r-1][c-1]++;
			dfs(r-1,c-1);
		}
	}
	// UR
	if (r > 0 && c < width-1 && grid[r-1][c+1] < 10) {
		grid[r-1][c+1]++;
		if (grid[r-1][c+1] == 10) {
			grid[r-1][c+1]++;
			dfs(r-1,c+1);
		}
	}
	// BL
	if (r < height-1 && c > 0 && grid[r+1][c-1] < 10) {
		grid[r+1][c-1]++;
		if (grid[r+1][c-1] == 10) {
			grid[r+1][c-1]++;
			dfs(r+1,c-1);
		}
	}
	// BR
	if (r < height-1 && c < width-1 && grid[r+1][c+1] < 10) {
		grid[r+1][c+1]++;
		if (grid[r+1][c+1] == 10) {
			grid[r+1][c+1]++;
			dfs(r+1,c+1);
		}
	}
}

int main() {
	freopen("input.txt","r",stdin);

	// Read file input
	string s;
	while (cin >> s) {
		vector<int> line;
		for (char c : s)
			line.push_back(c-'0');
		grid.push_back(line);
	}
	height = grid.size();
	width = grid[0].size();

	// Complete 100 steps
	int num_flashes = 0;
	for (int i=0;i<100;i++) {
		// Increment energy levels
		for (int r=0;r<height;r++) {
			for (int c=0;c<width;c++) {
				grid[r][c]++;
			}
		}
		// Update energy values based on neighbors
		for (int r=0;r<height;r++) {
			for (int c=0;c<width;c++) {
				if (grid[r][c] == 10)
					dfs(r,c);
			}
		}
		// Reset energy levels
		for (int r=0;r<height;r++) {
			for (int c=0;c<width;c++) {
				if (grid[r][c] > 9) {
					grid[r][c] = 0;
					num_flashes++;
				}
			}
		}
	}

	cout << "Result: " << num_flashes << '\n';
}
