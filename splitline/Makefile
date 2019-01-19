all:
	gcc *.c -o splitline
test: all
	./splitline "Je suis un super developpeur"
	./splitline "Hello      Les amis    "
	./splitline " \«æ\€«\€\«æ€   		Hello     		 Les amis    "
	./splitline "    		"
	./splitline " "
	./splitline "Hello"
