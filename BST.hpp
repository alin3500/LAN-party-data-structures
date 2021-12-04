#ifndef BTS_HPP_INCLUDED
#define BTS_HPP_INCLUDED

#include"node.hpp"

class BST
{
private:
    node* root;
    void clearTree(node*);
    void copy(node*, elemEchipa*&);
    
public:
    BST();

    void insert(node* , echipa&);

    void printBST(node*, ostream&);
    
    node* getRoot() const;

    void clearTree()
    {
        clearTree(root);
    }

    void copy(elemEchipa*& tinta)
    {
        copy(root, tinta);
    }
};

#endif
