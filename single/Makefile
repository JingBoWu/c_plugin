all:
	gcc -shared -o libtest.so test_lib.c 
	gcc -fPIC -shared  -o plugin.so plugin.c -L . -ltest
	gcc main.c -o test -ldl -L . -ltest

.PHONY: clean test

clean:
	rm -f test *.so

PWD=$(shell pwd)


# export LD_LIBRARY_PATH=${PWD} 
test:
	@export LD_LIBRARY_PATH=${PWD} ;  \
	echo "========================== no plugin =======================" ; \
	./test  ;\
	echo "========================== load plugin =======================" ; \
	./test ./plugin.so