.Phony hello: hello.o hello.c
	clang-14 -no-pie -g -O0 hello.c hello.o && ./hello


hello.o: hello.s
	nasm -f elf64 -g -l hello.lst hello.s