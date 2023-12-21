.PHONY: build run test clean

minLabNum = 1
maxLabNum = 7

build: clean
	@if [ $(labNum) -ge $(minLabNum) ] && [ $(labNum) -le $(maxLabNum) ]; then\
		mkdir ./lab$(labNum)/build;\
		git submodule init;\
		git submodule update;\
		cd ./lab$(labNum)/build; cmake -DLAB_NUMBER=lab$(labNum) ../..; make all;\
	fi

run:
	@if [ $(labNum) -ge $(minLabNum) ] && [ $(labNum) -le $(maxLabNum) ]; then\
		./lab$(labNum)/build/*_exe;\
	else\
		echo "lab$(labNum) doesn't exists";\
	fi

test:
	@if [ $(labNum) -ge $(minLabNum) ] && [ $(labNum) -le $(maxLabNum) ]; then\
		./lab$(labNum)/build/*_test ;\
	else\
		echo "lab$(labNum) doesn't exists";\
	fi

clean:
	@if [ $(labNum) -ge $(minLabNum) ] && [ $(labNum) -le $(maxLabNum) ]; then\
		rm -rf ./lab$(labNum)/build/;\
		echo "Build deleted";\
	else\
		echo "lab$(labNum) doesn't exists";\
	fi
