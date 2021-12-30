from collections import deque

# Read file input
with open("input.txt", "r") as f:
	depths = [int(i) for i in f]

window = deque()
window_depth = 0
# Add first 3 depths to window
for depth in depths[0:3]:
	window.append(depth)
	window_depth += depth

# Slide window one depth reading at a time, incrementing whenever window size increases
num_increases = 0
prev_window_depth = window_depth
for depth in depths[3:]:
	window_depth -= window[0]
	window_depth += depth
	if window_depth > prev_window_depth:
		num_increases += 1
	window.popleft()
	window.append(depth)
	prev_window_depth = window_depth

# Output final number of depth increases
print(f"Result: {num_increases}")
