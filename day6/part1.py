# Read file input
with open("input.txt", "r") as f:
	#data = [i.rstrip('\n') for i in f]
    data = [int(i) for i in f.read().rstrip('\n').split(',')]

# Fill dp array for number of lanternfish spawned from a 0-day fish after i days for i=0..80
dp = [0]*81
dp[0] = 1
lanternfish = [0]
for day in range(1,81):
    for i in range(len(lanternfish)-1,-1,-1):
        if lanternfish[i] == 0:
            lanternfish[i] = 6
            lanternfish.append(8)
        else:
            lanternfish[i] -= 1
    dp[day] = len(lanternfish)

# Calculate total number of fish based on dp array
num_fish = 0
for days in data:
    num_fish += dp[80-days]

print(f"Result: {num_fish}")
