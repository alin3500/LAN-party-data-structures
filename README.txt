Tataru Alin-Constantin - 321AA - Tema 1

Sunt implementate solutiile pentru toate cele 5 probleme sub forma a 5 IF-uri.
Pentru IF-uri este folosit vectorul "buf", in care sunt stocate valorile din fisierul "c.in".

Pentru cerinta 1 am implementat clasele Player, echipa si elemEchipa.
Clasa Player stocheaza informatii despre fiecare jucator in parte(nume, prenume, puncte).
Clasa echipa stocheaza numele echipei, numarul de jucatori si vectorul de jucatori sub forma Player*.
Clasa elemEchipa e folosita pentru implementarea listei(pe care am facut-o in main) si contine un atribut
de tip echipa si unul de timp elemEchipa*, pointer catre urmatorul element din lista.

Datele despre fiecare echipa in parte sunt citite din fisier cu ajutorul functiei elemEchipa::readElem(ifstream&)
si al functiei elemEchipa::addElem(elemEchipa*, ifstream&).
In functia readElem() este folosit operatorul supradefinit de citire ">>" pentru a prelua datele din fisier si a
le memora in zonele alocate de catre constructori;

Afisarea in fisier se face folosind ofstream-ul "fout", catre care este pasat numele echipei, returnat de
functia echipa::getNume().

Pentru rezolvarea cerintei 2 a fost implementata functia friend "delElemmin(elemEchipa*&, char*), care ia drept
parametri pointerul catre capul listei("cap") si fisierul in care sunt stocate informatiile("d.in") pentru a
citi numarul de echipe din acesta.

Cerinta 3 a necesitat noile clase meci, stiva si coada.

In obiectele de tip "meci" sunt stocate informatiile despre doua echipe si un pointer catre alt element de tip "meci".
Cele 3 functii din clasa "meci" sunt pentru afisare(meci::printMeci(ostream&)) si pentru a returna echipa castigatoare
si, respectiv, invinsa.

Clasa "stiva" contine un pointer catre un obiect de tip "echipa", care este si capul(punctul de intrare/iesire)
al stivei si 4 functii de baza:
addEchipa - pentru a adauga elemente de tip echipa in stiva
printStiva - pentru afisare
clearStiva - pentru eliberarea memoriei si golirea stivei cand era necesara refolosirea acesteia
getCap - returneaza un pointer catre "capul" stivei, care este privat

Clasa "coada" este foarte asemanatoare cu "stiva", dar nu in totalitate.
Are doua atribute de tip pointer catre obiecte de tip "meci", care reprezinta capatul de intrare, respectiv de iesire
al datelor in/din coada.
Are 3 metode, addMeci (pentru adaugare de meciuri in coada), printCoada(pentru afisare) si clearCoada(pentru golirea
de elemente si eliberarea memoriei)

Cerinta 4 este rezolvata folosind clasele BST si node
Clasa node este implementata direct in fisierul "node.hpp", deoarece este de dimensiuni foarte mici.
Fiind un nod de arbore, contine pointeri catre alte doua noduri, "left" si "right", key-ul(sub forma atributului de tip echipa "ec")
si "height", care reprezinta inaltimea arborelui pentru care acesta este radacina.

Clasa BST contine implementari recursive pentru golire/eliberare de memorie, inserare de elemente, afisare si copierea sa
intr-o lista(functionalitate necesara pentru rezolvarea cerintei 5).

Pentru cerinta 5 am implementat clasa AVL, asemanatoare cu BST, dar cu functionalitatile si proprietatile specifice
unui arbore de tip AVL, anume s/Right/LeftRotate pentru echilibrat


--------------------------------------------------
                   FEEDBACK
--------------------------------------------------

A fost prima tema la programare ampla(d.p.d.v. al dimensiunii, cunostintelor necesare si dificultatii),
ceea ce chiar ma bucura, deoarece, cel putin in anul 1, am fost dezamagit de cantitatea foarte mica de informatie
din programa si de temele care erau doar "de dragul de a avea teme". Pe langa asta, mi-a imbunatatit si abilitatea
de debugging.

Sunt de parere ca este o implementare medie, care sigur mai poate fi optimizata, din cauza ca m-am apucat destul de
tarziu de rezolvarea ei si timpul nu a fost de partea mea.
