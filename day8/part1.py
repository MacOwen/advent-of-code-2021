"""
Number of segments used per number:
0: 6
1: 2
2: 5
3: 5
4: 4
5: 5
6: 6
7: 3
8: 7
9: 6
Unique segment count numbers: 1, 4, 7, 8
"""

# Read file input
with open("input.txt", "r") as f:
    data = [i.rstrip('\n').split(" | ") for i in f]

# Count number of occurrences of 1s, 4s, 7s, and 8s (unique segment counts)
ans = 0
unique = {2,4,3,7} # Segment counts of 1,4,7,8
for patterns, output in data:
    for pattern in output.split(' '):
        if len(pattern) in unique:
            ans += 1

print(f"Result: {ans}")
