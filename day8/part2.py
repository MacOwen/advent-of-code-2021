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

# Return number of 1 bits in x
def popcount(x):
    s = 0
    while (x > 0):
        x &= (x-1) # Remove least-significant 1 bit
        s += 1
    return s

# Converts a segment display pattern (fdgacbe) into binary representation
def pattern_to_int(pattern):
    s = 0
    for c in pattern:
        s += 1<<(ord(c)-ord('a'))
    return s

# Read file input
data = []
with open("input.txt", "r") as f:
    for line in f:
        signals = [pattern_to_int(i) for i in line.rstrip('\n').split(" | ")[0].split(' ')]
        outputs = [pattern_to_int(i) for i in line.rstrip('\n').split(" | ")[1].split(' ')]
        data.append([signals,outputs])

ans = 0

# Find output num for each signal output
for signals, outputs in data:
    patterns = [0]*10 # 7-segment representation for each number
    values = {} # Maps signal to real value
    # Find 1,4,7,8 (unique segment counts)
    for i in signals:
        if popcount(i) == 2: # Found 1
            values[i] = 1
            patterns[1] = i
        elif popcount(i) == 4: # Found 4
            values[i] = 4
            patterns[4] = i
        elif popcount(i) == 3: # Found 7
            values[i] = 7
            patterns[7] = i
        elif popcount(i) == 7: # Found 8
            values[i] = 8
            patterns[8] = i
    signals.remove(patterns[1])
    signals.remove(patterns[4])
    signals.remove(patterns[7])
    signals.remove(patterns[8])
    cf = patterns[1]
    bd = patterns[4] & ~cf
    # Find 3
    for i in signals:
        if popcount(i & ~cf) == 3:
            values[i] = 3
            patterns[3] = i
    signals.remove(patterns[3])
    # Find 9
    for i in signals:
        if popcount(i & patterns[3]) == 5:
            values[i] = 9
            patterns[9] = i
    signals.remove(patterns[9])
    adg = patterns[3] & ~cf
    # Find 0
    for i in signals:
        if popcount(i & adg) == 2:
            values[i] = 0
            patterns[0] = i
    signals.remove(patterns[0])
    # Find 6
    for i in signals:
        if popcount(i & ~adg) == 3:
            values[i] = 6
            patterns[6] = i
    signals.remove(patterns[6])
    # Find 5 and 2
    for i in signals:
        if popcount(i & bd) == 2:
            values[i] = 5
            patterns[5] = i
        else:
            values[i] = 2
            patterns[2] = i
    num = 0
    for i in outputs:
        num *= 10
        num += values[i]
    ans += num 

print(f"Result: {ans}")
