## pwnies
#fuzz
we use libAFL/AFL/AFL++

#exploit
We use libpwntools, the makefile required for compilation is:
```makefile
all：
        g++ exp.cpp -o exp -pthread -lpwntools -std=c++17
clean:
        exp
```
