all:
	gcc -shared -o libtest.so test_lib.c 
	gcc -fPIC -shared  -o plugin_a.so plugin_a.c -L . -ltest
	gcc -fPIC -shared  -o plugin_b.so plugin_b.c -L . -ltest
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
	echo "========================== load plugin_a =======================" ; \
	./test ./plugin_a.so ; \
	echo "========================== load plugin_a & plugin_b =======================" ; \
	./test ./plugin_a.so ./plugin_b.so