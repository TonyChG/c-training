all:
	gcc *.c -o pt
test: all
	./pt "^int.+" pt.c
	./pt '^#.+' pt.c
