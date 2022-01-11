# Read file input
with open("input.txt", "r") as f:
	data = [i.rstrip('\n') for i in f]

bingo_nums = [int(i) for i in data[0].split(',')]
chosen_nums = set()
winners = set()

boards = []
board_rows = []
board_cols = []

num_boards = (len(data)-1)//6
scores = [0]*num_boards

# Build board data
for board_num in range(num_boards):
    board = {}
    board_pos = 2+board_num*6
    for row in range(5):
        row_vals = [int(i) for i in data[board_pos+row].split()]
        for col in range(5):
            board[row_vals[col]] = (row,col)
    boards.append(board)
    board_rows.append([0]*5)
    board_cols.append([0]*5)

# Calculates score of a winning board
def calculate_score(board_num, winning_num):
    score = 0
    board = boards[board_num]
    for num in board.keys():
        if num not in chosen_nums:
            score += num
    return score * winning_num

# Choose numbers until player(s) win (if multiple players win in one turn, pick the higher score)
newest_score = 0
for bingo_num in bingo_nums:
    chosen_nums.add(bingo_num)
    for board_num in range(num_boards):
        if board_num in winners:
            continue
        board = boards[board_num]
        if bingo_num in board:
            r,c = board[bingo_num]
            board_rows[board_num][r] += 1
            board_cols[board_num][c] += 1
            if board_rows[board_num][r] == 5 or board_cols[board_num][c] == 5:
                newest_score = calculate_score(board_num, int(bingo_num))
                winners.add(board_num)

print(f"Result: {newest_score}")
