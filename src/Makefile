exe : interfacetest.c fonction_calcul.o fonction_transfers.o
	gcc -o exe interfacetest.c fonction_transfers.c fonction_calcul.c `sdl-config --cflags --libs` -lSDL -lSDL_gfx -lSDL_ttf
fonction_calcul.o : fonction_calcul.c fonction_transfers.o
	gcc -c fonction_calcul.c  fonction_transfers.o
fonction_tranfers.o : fonction_transfers.c 
	gcc -c fonction_transfers.c


