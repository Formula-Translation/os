import time

# in memory
def calculate_average(numbers):
    return sum(numbers) / len(numbers)

# read numbers from a file and calculate the average
def calculate_average_from_file(filename):
    with open(filename, 'r') as file:
        numbers = [float(line.strip()) for line in file]
        return sum(numbers) / len(numbers)

# list of numbers
numbers = list(range(1, 1000000))

# Save the numbers to a file
filename = 'numbers.txt'
with open(filename, 'w') as file:
    for num in numbers:
        file.write(str(num) + '\n')

# calculation time in memory 
start_time = time.time()
average_memory = calculate_average(numbers)
end_time = time.time()
# print(f"Average calculated in memory: {average_memory}")
print(f"Time taken (memory): {end_time - start_time} seconds")

# calculation time from the file
start_time = time.time()
average_file = calculate_average_from_file(filename)
end_time = time.time()
# print(f"Average calculated from file: {average_file}")
print(f"Time taken (file): {end_time - start_time} seconds")
