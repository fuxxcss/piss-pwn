from pwn import *

print("""
      
    ————————————  Piss Pwn  —————————————
      
    """)

io   = remote('127.0.0.1',70776)

bash = listen(70777).wait_for_connection()