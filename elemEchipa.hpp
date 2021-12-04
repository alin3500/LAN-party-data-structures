#ifndef LISTAECHIPA_HPP_INCLUDED
#define LISTAECHIPA_HPP_INCLUDED

#include "echipa.hpp"

class elemEchipa
{
public:
    echipa ec;
    elemEchipa *urmator;

    elemEchipa();
    elemEchipa(echipa&, elemEchipa&);

    void printElem(ostream& devo);
    void readElem(ifstream&);
    void delElemUrm();
    
    friend void clearLista(elemEchipa*&);
    friend void addElem(elemEchipa*&, ifstream&);
    friend ifstream& operator>>(ifstream&, elemEchipa&);
    friend void delElemMin(elemEchipa*&, char*);
};

#endif