# Read file input
with open("input.txt", "r") as f:
    grid = [[int(j) for j in i.rstrip('\n')] for i in f]

height = len(grid)
width = len(grid[0])

num_flashes = 0

def dfs(r,c):
    # U
    if r > 0 and grid[r-1][c] < 10:
        grid[r-1][c] += 1
        if grid[r-1][c] == 10:
            grid[r-1][c] += 1
            dfs(r-1,c)
    # D
    if r < height-1 and grid[r+1][c] < 10:
        grid[r+1][c] += 1
        if grid[r+1][c] == 10:
            grid[r+1][c] += 1
            dfs(r+1,c)
    # L
    if c > 0 and grid[r][c-1] < 10:
        grid[r][c-1] += 1
        if grid[r][c-1] == 10:
            grid[r][c-1] += 1
            dfs(r,c-1)
    # R
    if c < width-1 and grid[r][c+1] < 10:
        grid[r][c+1] += 1
        if grid[r][c+1] == 10:
            grid[r][c+1] += 1
            dfs(r,c+1)
    # UL
    if r > 0 and c > 0 and grid[r-1][c-1] < 10:
        grid[r-1][c-1] += 1
        if grid[r-1][c-1] == 10:
            grid[r-1][c-1] += 1
            dfs(r-1,c-1)
    # UR
    if r > 0 and c < width-1 and grid[r-1][c+1] < 10:
        grid[r-1][c+1] += 1
        if grid[r-1][c+1] == 10:
            grid[r-1][c+1] += 1
            dfs(r-1,c+1)
    # BL
    if r < height-1 and c > 0 and grid[r+1][c-1] < 10:
        grid[r+1][c-1] += 1
        if grid[r+1][c-1] == 10:
            grid[r+1][c-1] += 1
            dfs(r+1,c-1)
    # BR
    if r < height-1 and c < width-1 and grid[r+1][c+1] < 10:
        grid[r+1][c+1] += 1
        if grid[r+1][c+1] == 10:
            grid[r+1][c+1] += 1
            dfs(r+1,c+1)

# Complete 100 steps
for _ in range(100):
    """
    # Print grid (debug)
    for line in grid:
        print(line)
    print()
    """
    # Increment energy levels
    for r in range(height):
        for c in range(width):
            grid[r][c] += 1
    # Update energy values based on neighbors
    for r in range(height):
        for c in range(width):
            if grid[r][c] == 10:
                dfs(r,c)
    # Reset energy levels
    for r in range(height):
        for c in range(width):
            if grid[r][c] > 9:
                grid[r][c] = 0
                num_flashes += 1

print(f"Result: {num_flashes}")
