# Read file input
with open("input.txt", "r") as f:
	#data = [i.rstrip('\n') for i in f]
    data = [int(i) for i in f.read().rstrip('\n').split(',')]

# Store fish in array according to which day they replicate
fish = [0]*7 # Maps day to number of fish replicating
new_fish = [0]*7 # Maps day to number of new fish produced

ans = len(data) # Total number of fish

# Initialize fish array
for fish_time in data:
    fish[fish_time] += 1

# Calculate offspring
for i in range(256):
    day = i%7
    next_day = (i+2)%7 # Day of the week when new fish will replicate
    ans += fish[day]
    new_fish[next_day] = fish[day]
    fish[day] += new_fish[day]

print(f"Result: {ans}")
