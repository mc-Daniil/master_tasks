target = [97, 123, 36, 176, 40, 94, 47, 126, 94, 160, 182, 199, 202, 233, 134, 34, 72, 115, 212, 172, 8, 118, 254, 25, 19, 201, 80, 217, 174]
xor_const = 7

for index in range(len(target)):
    current = ((target[index] - index) & 255) ^ xor_const
    xor_const = ((xor_const * 3) + 1) & 255
    print(chr(current), end="")
    
    