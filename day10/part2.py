# Read file input
with open("input.txt", "r") as f:
    data = [i.rstrip('\n') for i in f]

points = {')':1,']':2,'}':3,'>':4}
closing = {'(':')','[':']','{':'}','<':'>'}

# Calculate completion score for each incomplete line
completion_scores = []
for line in data:
    current = [] # Stack containing necessary closing characters
    for c in line:
        if c in closing:
            current.append(closing[c])
        else:
            if current and current[-1] == c:
                current.pop()
            else:
                current = []
                break
    # Incomplete line
    if current:
        score = 0
        for c in current[::-1]:
            score *= 5
            score += points[c]
        completion_scores.append(score)

# Take median score
completion_scores.sort()
middle_score = completion_scores[len(completion_scores)//2]

print(f"Result: {middle_score}")
