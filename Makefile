build: main.o Player.o echipa.o elemEchipa.o meci.o coada.o stiva.o BST.o AVL.o
	g++ main.o Player.o echipa.o elemEchipa.o meci.o coada.o stiva.o BST.o AVL.o -o lanParty

main.o: main.cpp
	g++ -c main.cpp

Player.o: Player.cpp
	g++ -c Player.cpp

echipa.o: echipa.cpp
	g++ -c echipa.cpp

elemEchipa.o: elemEchipa.cpp
	g++ -c elemEchipa.cpp

meci.o: meci.cpp
	g++ -c meci.cpp

coada.o: coada.cpp
	g++ -c coada.cpp

stiva.o: stiva.cpp
	g++ -c stiva.cpp

BST.o: BST.cpp
	g++ -c BST.cpp

AVL.o: AVL.cpp
	g++ -c AVL.cpp

clean:
	rm -rf *.o lanParty

