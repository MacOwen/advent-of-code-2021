# Read file input
with open("input.txt", "r") as f:
    grid = [[int(j) for j in i.rstrip('\n')] for i in f]

height = len(grid)
width = len(grid[0])

low_sum = 0 # Sum of risk levels of low points
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
        low_sum += grid[r][c]+1

print(f"Result: {low_sum}")
