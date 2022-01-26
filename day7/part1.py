# Read file input
with open("input.txt", "r") as f:
    data = [int(i) for i in f.read().rstrip('\n').split(',')]

data.sort()

target = data[len(data)//2] # Target position for crabs to align on (median position)

ans = 0
for pos in data:
    ans += abs(target-pos)

print(f"Result: {ans}")
