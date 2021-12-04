#ifndef AVL_HPP_INCLUDED
#define AVL_HPP_INCLUDED

#include "node.hpp"
class AVL
{
    node* root;

    node* sRightRotate(node*&);
    node* sLeftRotate(node*&);
    node* dRightRotate(node*&);
    node* dLeftRotate(node*&);
    int height(node*);
    void printTree(node*, ostream&);
    void clearTree(node*);
public:
    AVL();

    node* insert(node*, echipa&);
    void insert(echipa& nod)
    {
        root = insert(root, nod);
    }

    void printTree(ostream& devo)
    {
        printTree(root, devo);
    }

    void clearTree()
    {
        clearTree(root);
    }
};

#endif