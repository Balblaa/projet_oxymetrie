all: oxymetre

main_sim.o: main_sim.c
	gcc -c main_sim.c

affichage.o: affichage.c affichage.h define.h
	gcc -c affichage.c

fichiers.o: fichiers.c fichiers.h define.h
	gcc -c fichiers.c

fir.o: fir.c fir.h define.h fichiers.h
	gcc -c fir.c

iir.o: iir.c iir.h define.h
	gcc -c iir.c

mesure.o: mesure.c mesure.h define.h
	gcc -c mesure.c

autotests.o: autotests.c autotests.h define.h affichage.h fichiers.h fir.h iir.h mesure.h
	gcc -c autotests.c

oxymetre: main_sim.o affichage.o fichiers.o fir.o iir.o mesure.o autotests.o
	gcc -o oxymetre main_sim.o affichage.o fichiers.o fir.o iir.o mesure.o autotests.o

.PHONY: run

run: oxymetre
	./oxymetre