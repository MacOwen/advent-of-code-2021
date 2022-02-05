#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> grid;
int height, width;

int dfs(int r, int c) {
	if (grid[r][c] == 9) return 0;
	int res = 1;
	int current_height = grid[r][c];
	grid[r][c] = 9;
	if (r > 0 && current_height <= grid[r-1][c])
		res += dfs(r-1,c);
	if (r < height-1 && current_height <= grid[r+1][c])
		res += dfs(r+1,c);
	if (c > 0 && current_height <= grid[r][c-1])
		res += dfs(r,c-1);
	if (c < width-1 && current_height <= grid[r][c+1])
		res += dfs(r,c+1);
	return res;
}

int main() {
	freopen("input.txt","r",stdin);

	// Read file input
	string s;
	while (cin >> s) {
		vector<int> row;
		for (char c : s) {
			row.push_back(c-'0');
		}
		grid.push_back(row);
	}
	height = grid.size();
	width = grid[0].size();
	// Calculate all low points, and sum their risk levels
	vector<int> basin_heights;
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

			basin_heights.push_back(dfs(r,c));
		}
	}
	sort(basin_heights.rbegin(),basin_heights.rend());

	int ans = 1;
	for (int i=0;i<3;i++)
		ans *= basin_heights[i];
	
	cout << "Result: " << ans << '\n';
}
