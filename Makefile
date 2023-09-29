all:
	gcc *.c -o prog

sc:
	mv ../.correcao.sh ./
	chmod 777 ./correcao.sh
	./correcao.sh --valgrind