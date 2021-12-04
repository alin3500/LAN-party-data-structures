#include "elemEchipa.hpp"

elemEchipa::elemEchipa()
{
   ec = echipa(); 
   urmator = NULL;
    
}

void addElem(elemEchipa* &cap, ifstream& devi)
{
    elemEchipa *nou = new elemEchipa();
    devi >> (*nou).ec;

    (*nou).urmator = cap;
    cap = nou;
}

void elemEchipa::delElemUrm()
{
    elemEchipa* aux = (*(*this).urmator).urmator;
    delete (*this).urmator;
    (*this).urmator = aux;
}

void clearLista(elemEchipa*& cap)
{
    elemEchipa* aux = cap;
    while(aux != NULL)
    {
        cap = (*cap).urmator;
        delete aux;
        aux = cap;
    }

}

void elemEchipa::printElem(ostream& devo)
{
    devo << ec;
}

void elemEchipa::readElem(ifstream& devi)
{
    devi >> ec;
}


ifstream& operator>>(ifstream& devi, elemEchipa& tinta)
{
    devi >> tinta.ec;
    return devi;
}

void delElemMin(elemEchipa*& cap, char* inp)
{
    ifstream fin(inp, ios::in);
    int nrEchipe;
    fin >> nrEchipe;
    fin.close();

    elemEchipa *paux;
    paux = cap;

    //Cauta cea mai mare putere a lui 2 mai mica decat numarul de echipe
    int p2_Max = 1;
    while(nrEchipe >= p2_Max * 2)
        p2_Max *= 2;

    //Creeaza un vector cu punctajele fiecarei echipe
    float *vScoruri = new float[nrEchipe];

    int i = 0;
    while(paux != NULL)    
    {
        vScoruri[i] = (*paux).ec.getScor();
        paux = (*paux).urmator;
        i++;
    }

    //Sorteaza crescator vectorul creat mai sus
    float faux;
    for(int i = 0; i < nrEchipe - 1; i++)
        for(int j = i+1; j < nrEchipe; j++)
            if(vScoruri[j] <= vScoruri[i])
            {
                faux = vScoruri[i];
                vScoruri[i] = vScoruri[j];
                vScoruri[j] = faux;
            }
    
    //Parcurge lista in functie de primele (nrEchipe - p2_Max) cele mai mici scoruri din vScoruri si
    //elimina o echipa atunci cand gaseste scorul respectiv
    for(int i = 0; i < nrEchipe - p2_Max; i++)
    {
        paux = cap;

        while(paux != NULL)
        {
            //Cazul in care primul element(capul listei) trebuie eliminat
            if((*paux).ec.getScor() == vScoruri[i] && (paux == cap))
            {
                cap = (*paux).urmator;
                delete paux;
                paux = cap;
                break;
            }
            //Cazul general
            else if((*(*paux).urmator).ec.getScor() == vScoruri[i])
            {
                (*paux).delElemUrm();
                paux = (*paux).urmator;
                break;
            }
            else
                paux = (*paux).urmator;

        }
    }

    delete [] vScoruri;

}
