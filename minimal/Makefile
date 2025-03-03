#all: oxymetre

affichage.o: affichage.c affichage.h
	gcc -c affichage.c

fichiers.o: fichiers.c fichiers.h
	gcc -c fichiers.c

fir.o: fir.c fir.h
	gcc -c fir.c

iir.o: iir.c iir.h
	gcc -c iir.c

mesure.o: mesure.c mesure.h
	gcc -c mesure.c

oxymetre: affichage.o fichiers.o fir.o iir.o mesure.o
	gcc -o oxymetre affichage.o fichiers.o fir.o iir.o mesure.o