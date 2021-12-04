#ifndef STIVA_HPP_INCLUDED
#define STIVA_HPP_INCLUDED

#include "echipa.hpp"

class stiva
{
    echipa *cap;

public:
    stiva();

    void addEchipa(echipa&);
    void printStiva(ostream&) const;
    void clearStiva();
    echipa* getCap() const;
};

#endif