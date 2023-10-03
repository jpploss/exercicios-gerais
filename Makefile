all:
	gcc *.c -o prog

masc:
	mv ../.correcao.sh ./
	chmod 777 ./correcao.sh

rsc:
	./correcao.sh --valgrind

pastas:
	mkdir Respostas
	mkdir Respostas/JoaoLoss
	cd Respostas/JoaoLoss