strtest: stringy.c
	gcc stringy.c -o strtest

run: strtest
	./strtest