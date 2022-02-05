# Read file input
with open("input.txt", "r") as f:
    grid = [[int(j) for j in i.rstrip('\n')] for i in f]

height = len(grid)
width = len(grid[0])

def dfs(r,c):
    res = 1
    current_height = grid[r][c]
    grid[r][c] = 9
    if r > 0 and current_height <= grid[r-1][c] < 9:
        res += dfs(r-1,c)
    if r < height-1 and current_height <= grid[r+1][c] < 9:
        res += dfs(r+1,c)
    if c > 0 and current_height <= grid[r][c-1] < 9:
        res += dfs(r,c-1)
    if c < width-1 and current_height <= grid[r][c+1] < 9:
        res += dfs(r,c+1)
    return res

# Locate all low points, and raise basins to height level 9
basin_heights = []
for r in range(height):
    for c in range(width):
        # Above
        if r > 0 and grid[r-1][c] <= grid[r][c]:
            continue
        # Below
        if r < height-1 and grid[r+1][c] <= grid[r][c]:
            continue
        # Left
        if c > 0 and grid[r][c-1] <= grid[r][c]:
            continue
        # Right
        if c < width-1 and grid[r][c+1] <= grid[r][c]:
            continue
        basin_heights.append(dfs(r,c))

basin_heights.sort()
basin_heights.reverse()

ans = 1
for i in basin_heights[:3]:
    ans *= i

print(f"Result: {ans}")
