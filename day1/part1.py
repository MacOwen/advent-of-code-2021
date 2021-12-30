# Read file input
with open("input.txt", "r") as f:
	depths = [int(i) for i in f]

previous_depth = depths[0]
num_increases = 0

# Read all depths, incrementing when depth is greater than previous depth
for depth in depths:
	if depth > previous_depth:
		num_increases += 1
	previous_depth = depth

# Output final number of depth increases
print(f"Result: {num_increases}")
