#include "coada.hpp"

coada::coada()
{
    intrare = NULL;
    iesire = NULL;
}

void coada::addMeci(meci& sursa)
{
    if(intrare == NULL)
    {
        intrare = new meci(sursa);
        (*intrare).urmator = NULL;
        iesire = intrare;
    }

    else
    {
        meci* nou = new meci(sursa);
        (*intrare).urmator = nou;
        intrare = nou;
        (*intrare).urmator = NULL;
    }
}

void coada::printCoada(ostream& devo) const
{
    meci* aux = iesire;
    while(aux != NULL)
    {
        (*aux).printMeci(devo);
        aux = (*aux).urmator;
    }
}

void coada::clearCoada()
{
    meci* aux = iesire;
    while(aux != NULL)
    {
        iesire = (*iesire).urmator;
        delete aux;
        aux = iesire;
    }
}