def binary_to_decimal(s):
    num = 0
    for c in s:
        num <<= 1
        if c == '1':
            num += 1
    return num

# Read file input
with open("input.txt", "r") as f:
    data = [str(i).rstrip('\n') for i in f]
num_bits = len(data[0])

# Calculate oxygen generator rating
possible_numbers = set(data)
current_indices = [i for i in range(len(data))]
for i in range(num_bits):
    # Calculate most frequent bit
    frequency = 0
    for idx in current_indices:
        if data[idx][i] == '1':
            frequency += 1
    if frequency >= len(current_indices)/2:
        bit = '1'
    else:
        bit = '0'
    # Remove non-matching binary strings
    next_indices = []
    for idx in current_indices:
        if data[idx][i] == bit:
            next_indices.append(idx)
        else:
            possible_numbers.remove(data[idx])
            if len(possible_numbers) == 1:
                next_indices = []
                break
    current_indices = next_indices
oxygen_rating = binary_to_decimal(list(possible_numbers)[0])

# Calculate CO2 scrubber rating
possible_numbers = set(data)
current_indices = [i for i in range(len(data))]
for i in range(num_bits):
    # Calculate least frequent bit
    frequency = 0
    for idx in current_indices:
        if data[idx][i] == '1':
            frequency += 1
    if frequency >= len(current_indices)/2:
        bit = '0'
    else:
        bit = '1'
    # Remove non-matching binary strings
    next_indices = []
    for idx in current_indices:
        if data[idx][i] == bit:
            next_indices.append(idx)
        else:
            possible_numbers.remove(data[idx])
            if len(possible_numbers) == 1:
                next_indices = []
                break
    current_indices = next_indices
scrubber_rating = binary_to_decimal(list(possible_numbers)[0])

life_support_rating = oxygen_rating * scrubber_rating
print(f"Result: {life_support_rating}")
