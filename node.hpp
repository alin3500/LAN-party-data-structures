#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

#include "elemEchipa.hpp"
class node
{
public:
    node* left;
    node* right;
    echipa ec;
    int height;

    node()
    {
        left = NULL;
        right = NULL;
        height = 0;
    }
    node(echipa sursa)
    {
        left = NULL;
        right = NULL;
        ec = sursa;
        height = 0;
    }

    echipa getEchipa() const
    {
        return ec;
    }
};
#endif