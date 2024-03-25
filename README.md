# pwn-exercises
Some pwn samples and exps.

We use libpwntools, the makefile required for compilation is:
————————————————————————————————————————————————————————————
all：
        g++ exp.cpp -o exp -pthread -lpwntools -std=c++17
clean:
        exp
————————————————————————————————————————————————————————————
