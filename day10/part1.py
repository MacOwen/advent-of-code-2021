# Read file input
with open("input.txt", "r") as f:
    data = [i.rstrip('\n') for i in f]

points = {')':3,']':57,'}':1197,'>':25137}
closing = {'(':')','[':']','{':'}','<':'>'}

# Calculate score for each line
total_score = 0
for line in data:
    current = [] # Stack containing necessary closing characters
    for c in line:
        if c in closing:
            current.append(closing[c])
        else:
            if current and current[-1] == c:
                current.pop()
            else:
                total_score += points[c]
                break

print(f"Result: {total_score}")
