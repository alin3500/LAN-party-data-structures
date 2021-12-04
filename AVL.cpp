#include "AVL.hpp"

AVL::AVL()
{
    root = NULL;
}

node* AVL::insert(node* nod, echipa& e)
{
    if(nod == NULL)
    {
        nod = new node();
        (*nod).ec = e;
        (*nod).height = 0;
        (*nod).left = (*nod).right = NULL;
    }

    else if(e.getScor() < (*nod).ec.getScor())
        (*nod).left = insert((*nod).left, e);

    else if(e.getScor() > (*nod).ec.getScor())
        (*nod).right = insert((*nod).right, e);

    else if(e.getNume() < (*nod).ec.getNume())
        (*nod).left = insert((*nod).left, e);

    else if(e.getNume() > (*nod).ec.getNume())
        (*nod).right = insert((*nod).right, e);
    
    else
        return nod;
    
    (*nod).height = max(height((*nod).left), height((*nod).right)) + 1;
    int k = height((*nod).left) - height((*nod).right);

    if(k > 1 && ((e.getScor() < (*nod).ec.getScor()) || (e.getScor() == (*nod).ec.getScor() && e.getNume() < (*nod).ec.getNume())))
        return sRightRotate(nod);
    
    if(k < -1 && ((e.getScor() > (*nod).ec.getScor()) || (e.getScor() == (*nod).ec.getScor() && e.getNume() > (*nod).ec.getNume())))
        return sLeftRotate(nod);

    if(k > 1 && ((e.getScor() <= (*nod).ec.getScor()) || (e.getScor() == (*nod).ec.getScor() && e.getNume() < (*nod).ec.getNume())))
        return dLeftRotate(nod);

    if(k > 1 && ((e.getScor() >= (*nod).ec.getScor()) || (e.getScor() == (*nod).ec.getScor() && e.getNume() > (*nod).ec.getNume())))
        return dRightRotate(nod);
    
    return nod;
}

node* AVL::sRightRotate(node*& nod)
{
    node* aux = (*nod).left;
    (*nod).left = (*aux).right;
    (*aux).right = nod;
    (*nod).height = max(height((*nod).left), height((*nod).right)) + 1;
    (*aux).height = max(height((*aux).left), (*nod).height) + 1;

    return aux;
}

node* AVL::sLeftRotate(node*& nod)
{
    node* aux = (*nod).right;
    (*nod).right = (*aux).left;
    (*aux).left = nod;
    (*nod).height = max(height((*nod).left), height((*nod).right)) + 1;
    (*aux).height = max(height((*nod).right), (*nod).height) + 1;

    return aux;
}

node* AVL::dLeftRotate(node*& nod)
{
    (*nod).right = sRightRotate((*nod).right);

    return sLeftRotate(nod);
}

node* AVL::dRightRotate(node*& nod)
{
    (*nod).left = sLeftRotate((*nod).left);

    return sRightRotate(nod);
}

int AVL::height(node* nod)
{
    if(nod == NULL)
        return -1;
    
    else
        return (*nod).height;
}

void AVL::printTree(node* nod, ostream& devo)
{
    if(nod == NULL)
        return;
    
    devo << endl << (*(*(*root).right).right).ec.getNume();
    devo << endl << (*(*(*root).right).left).ec.getNume();
    devo << endl << (*(*(*root).left).right).ec.getNume();
    devo << endl << (*(*(*root).left).left).ec.getNume();

}

void AVL::clearTree(node* nod)
{
    if(nod == NULL)
        return;
    clearTree((*nod).left);
    clearTree((*nod).right);
    delete nod;
}