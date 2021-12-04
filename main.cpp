#include "coada.hpp"
#include "elemEchipa.hpp"
#include "stiva.hpp"
#include "BST.hpp"
#include "AVL.hpp"
int main(int argc, char** argv)
{
    elemEchipa *cap = new elemEchipa();
    ifstream cer(argv[1], ios::in);
    //Creeaza un vector in care sunt stocate datele din cerinte.in
    int *buf = new int[5];

    for(int i = 0; i < 5; i++)
        cer >> buf[i];


    //Cerinta 1
    if(buf[0] == 1)
    {
        ofstream fout(argv[3], ios::out);
        ifstream fin(argv[2], ios::in);

        int nrEchipe;
        fin >> nrEchipe;
        (*cap).readElem(fin);

        for(int i = 1; i < nrEchipe; i++)
            addElem(cap, fin);
    
        
        elemEchipa *aux;
        aux = cap;
        
        while(aux != NULL)    
        {
            fout << (*aux).ec.getNume() << endl;
            aux = (*aux).urmator;
        }
        fin.close();
        fout.close();
    }

    int nrEchipe = 0;
    //Cerinta 2
    if(buf[1] == 1)
    {   
        
        nrEchipe = 0;
        ofstream fout2(argv[3], ios::out);
        delElemMin(cap, argv[2]);
        elemEchipa* aux = cap;

        while(aux != NULL)    
        {
            nrEchipe++;
            fout2 << (*aux).ec.getNume() << endl;
            aux = (*aux).urmator;
        }
        fout2.close();
    }

    elemEchipa* lista_8;
    
    //Cerinta 3
    if(buf[2] == 1)
    {
        ofstream fout3(argv[3], ios::app);

        stiva Winners;
        stiva Losers;

        int runda = 1;
        while(nrEchipe > 1)
        {
            coada Coada;
            elemEchipa* aux = cap;
            for(int i = 0; i < nrEchipe / 2; i++)
            {   
                if(aux != NULL)
                {
                    //Adaugare meciuri in coada
                    meci meciAux((*aux).ec, (*(*aux).urmator).ec);

                    Coada.addMeci(meciAux);

                    aux = (*(*aux).urmator).urmator;

                    //Impartirea echipelor in stivele de castigatori, respectiv pierzatori
                    Winners.addEchipa(meciAux.getWinner());
                    Losers.addEchipa(meciAux.getLoser());
                    

                }
            }
            stiva winAux;
            echipa* winCap = Winners.getCap();
            //Goleste lista de echipe;
            clearLista(cap);

            //Copiaza stiva de castigatori in ordine inversa
            for(int i = 0; i < nrEchipe / 2; i++)
            {
                echipa* nou = new echipa(*winCap);
                winAux.addEchipa(*nou);
                winCap = (*winCap).urmator; 
                if(nou != NULL)
                    delete nou;
            }

            winCap = winAux.getCap();
        
            //Copiaza elementele din stiva de castigatori in lista
            for(int i = 0; i < nrEchipe / 2; i++)
            {
                elemEchipa *nou = new elemEchipa();
                (*nou).ec = (*winCap);
                (*nou).urmator = cap;
                (winCap) = (*winCap).urmator;
                cap = nou;
            }

            Losers.clearStiva();
            //Scrie meciurile
            fout3 << endl << "--- ROUND NO:" << runda << endl;
            Coada.printCoada(fout3);

            //Scrie castigatorii
            fout3 << endl << "WINNERS OF ROUND NO:" << runda;
            Winners.printStiva(fout3);
            fout3 << endl;

            //Stocarea celor 8 echipe castigatoare
            if(nrEchipe == 16)
            {
                lista_8 = new elemEchipa(*cap);

                (*lista_8).urmator = NULL;
                elemEchipa* aux = (*cap).urmator;

                
                while(aux != NULL)
                {
                    elemEchipa* nou = new elemEchipa(*aux);
                    (*nou).urmator = lista_8;
                    lista_8 = nou;
                    aux = (*aux).urmator;
                }
            }

            //Sterge elementele din stive si coada
            Winners.clearStiva();
            Coada.clearCoada();
            winAux.clearStiva();

            runda++;
            nrEchipe /= 2;
        }
        fout3.close();
        
    }

    if(buf[3] == 1)
    {
        ofstream fout4(argv[3], ios::app);
        BST arBST;
        elemEchipa* aux = lista_8;

        while(aux != NULL)
        {
            arBST.insert(arBST.getRoot(), (*aux).ec);
            aux = (*aux).urmator;
        }

        fout4 << endl << "TOP 8 TEAMS:";
        arBST.printBST(arBST.getRoot(), fout4);
        
        clearLista(lista_8);
        arBST.copy(lista_8);
        arBST.clearTree();

        fout4.close();
    }

    if(buf[4] == 1)
    {
        ofstream fout5(argv[3], ios::app);
        AVL arAVL;
        elemEchipa* aux = lista_8;
        while(aux != NULL)
        {
            arAVL.insert((*aux).ec);
            aux = (*aux).urmator;
        }
        fout5 << endl << endl << "THE LEVEL 2 TEAMS ARE:";
        arAVL.printTree(fout5);
        
        arAVL.clearTree();
        fout5.close();
    }
    delete [] buf;
    if(cap != NULL)
        clearLista(cap);
    
    if(lista_8 != NULL)
        clearLista(lista_8);
    return 0;
}
