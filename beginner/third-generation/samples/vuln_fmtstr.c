#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

void setup(){
    setvbuf(stdin,NULL,_IONBF,0);
    setvbuf(stdout,NULL,_IONBF,0);
    setvbuf(stderr,NULL,_IONBF,0);
}
void vuln_fun(char *s){
        int num=0;
    while(num <256){
        num+=read(0,s,256);
        printf(s);
    }
}

int main(){
    char s[256];
    setup();
    vuln_fun(s);
    printf("pwned\n");
}