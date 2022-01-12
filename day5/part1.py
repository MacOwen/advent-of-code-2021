# Read file input
with open("input.txt", "r") as f:
	data = [i.rstrip('\n') for i in f]

data = [i.split(" -> ") for i in data]

# Process line data
lines = []
for start_coord, end_coord in data:
    x_start, y_start = [int(i) for i in start_coord.split(',')]
    x_end, y_end = [int(i) for i in end_coord.split(',')]
    line = (x_start,y_start,x_end,y_end)
    lines.append(line)

# Find x and y dimensions
x_dim = lines[0][0]
y_dim = lines[0][1]
for x_start,y_start,x_end,y_end in lines:
    x_dim = max(x_dim,x_start,x_end)
    y_dim = max(y_dim,y_start,y_end)
x_dim += 1
y_dim += 1

# Build grid with correct dimensions
grid = []
for _ in range(x_dim):
    grid.append([0]*y_dim)

# Fill grid
for x_start,y_start,x_end,y_end in lines:
    # Calculate line dimensions and x/y increment
    x_length = abs(x_end-x_start)
    y_length = abs(y_end-y_start)
    line_length = max(x_length,y_length)
    if x_start == x_end:
        x_inc = 0
    else:
        x_inc = (x_end-x_start)//x_length
    if y_start == y_end:
        y_inc = 0
    else:
        y_inc = (y_end-y_start)//y_length

    # Skip if line is diagonal
    if x_inc != 0 and y_inc != 0:
        continue

    # Mark vents along line
    x_pos = x_start
    y_pos = y_start
    grid[x_start][y_start] += 1 # Fill initial tile
    for _ in range(line_length):
        x_pos += x_inc
        y_pos += y_inc
        grid[x_pos][y_pos] += 1

# Count number of overlap tiles
overlap_tiles = 0
for grid_line in grid:
    for tile in grid_line:
        if tile > 1:
            overlap_tiles += 1

print(f"Result: {overlap_tiles}")
