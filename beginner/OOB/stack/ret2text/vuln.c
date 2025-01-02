#ifdef __linux__
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#endif

#include "../../../../_/setup.c"

void vuln(SOCKET socket){
    uint8_t buffer[16];

    #ifdef __linux__
    // stack oob write
    recv(socket,buffer,128,0);
    // text
    system("echo read 128 bytes.");
    #endif

}

int main() {
    vuln(setup());
    return 0;
}
