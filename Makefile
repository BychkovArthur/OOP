.PHONY: build run test

build: clean
	mkdir ./lab$(labNum)/build
	git submodule init
	git submodule update
	cd ./lab$(labNum)/build; cmake -DLAB_NUMBER=lab$(labNum) ../..; make all

run:
	./lab$(labNum)/build/*_exe

test:
	./lab$(labNum)/build/*_test

clean:
	rm -rf ./lab$(labNum)/build/
