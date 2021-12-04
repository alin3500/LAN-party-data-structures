#include"BST.hpp"

BST::BST()
{
    root = NULL;
}

void BST::insert(node* nod, echipa& e)
{
    if(nod == NULL)
    {
        nod = new node(e);
        root = nod;
    }
    else
    {
        if(e.getScor() < (*nod).getEchipa().getScor())
        {
            if(!(*nod).left)
            {
                node* auxNod = new node(e);
                (*nod).left = auxNod;
            }
            else
                insert((*nod).left, e);
        }
        else if(e.getScor() > (*nod).getEchipa().getScor())
        {
            if (!(*nod).right)
            {
                node *auxNod = new node(e);                         
                (*nod).right = auxNod;
            }
            else
                insert((*nod).right, e);
        }
        else
        {
            if(e.getNume() > (*nod).getEchipa().getNume())
            {
                if (!(*nod).right)
                {
                    node *auxNod = new node(e);                         
                    (*nod).right = auxNod;
                }
                else
                    insert((*nod).right, e);
            }
            else
            {
                if(!(*nod).left)
                {
                    node* auxNod = new node(e);
                    (*nod).left = auxNod;
                }
                else
                    insert((*nod).left, e);
            }
            
        }
        
    }
}

void  BST::printBST(node* nod, ostream &devo)
{
    if(nod == NULL)
        return;

    printBST((*nod).right, devo);
    (*nod).ec.printEchipa(devo);
    printBST((*nod).left, devo);
}

node* BST::getRoot() const
{
    return root;
}

void BST::clearTree(node* nod)
{
    if(nod == NULL)
        return;
    clearTree((*nod).left);
    clearTree((*nod).right);
    delete nod;
}

void BST::copy(node* nod, elemEchipa*& tinta)
{
    if(nod == NULL)
        return;

    copy((*nod).right, tinta);
    elemEchipa* aux = new elemEchipa();

    (*aux).ec = (*nod).ec;
    (*aux).urmator = NULL;

    if(tinta == NULL)
        tinta = aux;
    else
    {
        elemEchipa *nod = tinta;
        while((*nod).urmator != NULL)
            nod = (*nod).urmator;
        (*nod).urmator = aux;
    }
    copy((*nod).left, tinta);
}

