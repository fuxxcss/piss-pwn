# ret2text

## Linux
``` shell
```
gcc -no-pie vuln.c -o vuln
./vuln
### checkc
``` shell
checkc --file=./vuln
File                        ./vuln
RELRO                       Partial RELRO
STACK CANARY                No Canary found
NX                          NX enabled
PIE                         No PIE
RPATH                       NO RPATH
RUNPATH                     NO RUNPATH
Stripped                    Not Stripped
```
### ida
vuln	                000000000040127F
system@@GLIBC_2.2.5	    0000000000404078

### ROPgadget

## Windows
...
