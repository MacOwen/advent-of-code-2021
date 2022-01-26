# Read file input
with open("input.txt", "r") as f:
    data = [int(i) for i in f.read().rstrip('\n').split(',')]

largest = max(data)

# Total cost of fuel for each possible position
fuel = [0]*(largest+1)

# Calculate fuel cost for each position, one crab at a time
for crab_pos in data:
    # Fill right
    cost = 1
    for i in range(crab_pos+1,len(fuel),1):
        fuel[i] += (cost*(cost+1))//2
        cost+=1
    # Fill left
    cost = 1
    for i in range(crab_pos-1,-1,-1):
        fuel[i] += (cost*(cost+1))//2
        cost+=1

ans = min(fuel)

print(f"Result: {ans}")
