all: programme

programme: main.o alerte.o unite.o menu.o outils.o
	gcc -o programme main.o alerte.o unite.o menu.o outils.o

main.o:
	gcc -o main.o -c main.c

alerte.o:
	gcc -o alerte.o -c alerte.c

unite.o:
	gcc -o unite.o -c unite.c

menu.o:
	gcc -o menu.o -c menu.c

outils.o:
	gcc -o outils.o -c outils.c

clean:
	rm -rf *.o

mrproper:
	rm -f programme
