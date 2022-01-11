#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>
#include <cmath>
using namespace std;

// Converts comma separated string into ints
vector<int> csv_to_ints(string s) {
	vector<int> nums;
	int current_num = 0;
	for (char c : s) {
		if (c == ',') {
			nums.push_back(current_num);
			current_num = 0;
			continue;
		}
		current_num *= 10;
		current_num += c-'0';
	}
	nums.push_back(current_num);
	return nums;
}

// Find a target number in a given board
pair<int,int> find_num(vector<vector<int>> board, int target) {
	for (int r=0;r<5;r++) {
		for (int c=0;c<5;c++) {
			if (board[r][c] == target)
				return make_pair(r,c);
		}
	}
	return make_pair(-1,-1);
}

// Prints contents of bingo board (used for debugging)
void print_board(vector<vector<int>> board) {
	for (vector<int> v : board) {
		for (int i : v) {
			cout << " " << i;
		}
		cout << '\n';
	}
}

int calculate_score(vector<vector<int>> board, unordered_set<int> chosen_nums, int winning_num) {
	int score = 0;
	for (int r=0;r<5;r++) {
		for (int c=0;c<5;c++) {
			int num = board[r][c];
			if (chosen_nums.find(num) == chosen_nums.end())
				score += num;
		}
	}
	return score*winning_num;
}

int main() {
	freopen("input.txt", "r", stdin);
	string bingo_nums_string;
	cin >> bingo_nums_string;
	vector<int> bingo_nums = csv_to_ints(bingo_nums_string);
	unordered_set<int> chosen_nums;

	vector<vector<vector<int>>> boards;
	vector<vector<int>> board_rows;
	vector<vector<int>> board_cols;
	
	int board_num = 0;
	while (cin) {
		vector<vector<int>> board(5);
		for (int r=0;r<5;r++) {
			vector<int> row(5);
			for (int c=0;c<5;c++) {
				int num;
				cin >> num;
				row[c] = num;
			}
			board[r] = row;
		}
		boards.push_back(board);
		vector<int> rows(5);
		vector<int> cols(5);
		board_rows.push_back(rows);
		board_cols.push_back(cols);
		board_num++;
	}
	boards.pop_back();
	board_rows.pop_back();
	board_cols.pop_back();
	int num_boards = board_num-1;
	
	int max_score = 0;
	for (int bingo_num : bingo_nums) {
		chosen_nums.insert(bingo_num);
		for (board_num=0;board_num<num_boards;board_num++) {
			pair<int,int> coords = find_num(boards[board_num], bingo_num);
			if (coords.first == -1) continue;
			int r = coords.first;
			int c = coords.second;
			board_rows[board_num][r]++;
			board_cols[board_num][c]++;
			if (board_rows[board_num][r] == 5 || board_cols[board_num][c] == 5)
				max_score = max(max_score, calculate_score(boards[board_num], chosen_nums, bingo_num));
		}
		if (max_score > 0)
			break;
	}

	cout << "Result: " << max_score << '\n';
}
