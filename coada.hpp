#ifndef COADA_HPP_INCLUDED
#define COADA_HPP_INCLUDED

#include "meci.hpp"
class coada
{

    meci *intrare;
    meci *iesire;

public:
    coada();

    void addMeci(meci&);
    void printCoada(ostream&) const;
    void clearCoada();
};

#endif