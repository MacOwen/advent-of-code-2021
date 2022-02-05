#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	freopen("input.txt","r",stdin);

	// Read file input
	vector<vector<int>> grid;
	string s;
	while (cin >> s) {
		vector<int> row;
		for (char c : s) {
			row.push_back(c-'0');
		}
		grid.push_back(row);
	}
	int height = grid.size();
	int width = grid[0].size();
	// Calculate all low points, and sum their risk levels
	int low_sum = 0;
	for (int r=0;r<height;r++) {
		for (int c=0;c<width;c++) {
			// Above
			if (r > 0 && grid[r-1][c] <= grid[r][c]) continue;
			// Below
			if (r < height-1 && grid[r+1][c] <= grid[r][c]) continue;
			// Left
			if (c > 0 && grid[r][c-1] <= grid[r][c]) continue;
			// Right
			if (c < width-1 && grid[r][c+1] <= grid[r][c]) continue;

			low_sum += grid[r][c]+1;
		}
	}
	cout << "Result: " << low_sum << '\n';
}
