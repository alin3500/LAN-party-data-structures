#include "stiva.hpp"

stiva::stiva()
{
    cap = NULL;
}

void stiva::addEchipa(echipa& sursa)
{
    if(cap == NULL)
    {
        cap = new echipa(sursa);
        (*cap).urmator = NULL;
    }

    else
    {
        echipa* nou = new echipa(sursa);
        (*nou).urmator = cap;
        cap = nou;
    }
}

void stiva::printStiva(ostream& devo) const
{
    echipa* aux = cap;
    while(aux != NULL)
    {
        (*aux).printEchipa(devo);
        aux = (*aux).urmator;
    }
}

void stiva::clearStiva()
{
    echipa* aux = cap;
    while(aux != NULL)
    {
        cap = (*cap).urmator;
        delete aux;
        aux = cap;
    }
}

echipa* stiva::getCap() const
{
    return cap;
}