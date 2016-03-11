all: LinkList Plink
LinkList: linklist.c
	gcc -o linklist.o -g linklist.c

Plink: plink.c
	gcc -o plink.o -g plink.c
