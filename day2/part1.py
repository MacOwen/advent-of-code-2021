# Read file input
with open("input.txt", "r") as f:
	instructions = [(str(i.split(" ")[0]), int(i.split(" ")[1])) for i in f]
	
pos_horiz = 0
pos_vert = 0
for instruction in instructions:
	if instruction[0] == "forward":
		pos_horiz += instruction[1]
	elif instruction[0] == "down":
		pos_vert += instruction[1]
	elif instruction[0] == "up":
		pos_vert -= instruction[1]

pos_product = pos_horiz * pos_vert
print(f"Result: {pos_product}")
