# Read file input
with open("input.txt", "r") as f:
	data = [str(i).rstrip('\n') for i in f]

num_bits = len(data[0])

# Calculate frequency of '1' bits at each position
frequencies = [0]*num_bits
for binary_string in data:
	for i,c in enumerate(binary_string):
		if c == '1':
			frequencies[i] += 1
# Calculate gamma rate based on frequencies
gamma_rate = 0
for frequency in frequencies:
	gamma_rate <<= 1
	if frequency > len(data)//2:
		gamma_rate += 1
# Calculate epsilon rate based on gamma rate (binary inverse)
epsilon_rate = 2**num_bits - 1 - gamma_rate

power_consumption = gamma_rate * epsilon_rate
print(f"Result: {power_consumption}")
