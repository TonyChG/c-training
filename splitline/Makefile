all:
	gcc *.c -o splitline
test: all
	./splitline "Hello      Les amis    "
	./splitline " \«æ\€«\€\«æ€   Hello     		 Les amis    "
	./splitline "    		"
	./splitline " "
	./splitline "Hello"
	./splitline ""
