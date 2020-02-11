#ifndef MATRIZESP_H
#define MATRIZESP_H
#include "NodoEsp.h"
#include <iostream>
using namespace std;
template<class T,int fil=5,int col=5>
class MatrizEsp
{
    public:
        NodoEsp<T>**pfilas;
        NodoEsp<T>**pcolum;
        MatrizEsp()
        {
            pfilas=new NodoEsp<T>*[fil];
            pcolum=new NodoEsp<T>*[col];
            for(int i=0;i<fil;i++)
            {
                    pfilas[i]=0;
            }
            for(int j=0;j<col;j++)
            {
                    pcolum[j]=0;
            }
        }
        bool find_fil(int x, int y,NodoEsp<T>**&p)
        {
            p=&(pcolum[y]);
            while(*p)
            {
                if((*p)->fil==x) return 1;
                if((*p)->fil>x) return 0;
                p=&((*p)->sgtfil);
            }
            return 0;
        }
        bool find_col(int x, int y,NodoEsp<T>**&p)
        {
            p=&(pfilas[x]);
            while(*p)
            {
                if((*p)->col==y) return 1;
                if((*p)->col>y) return 0;
                p=&((*p)->sgtcol);
            }
            return 0;
        }
        void Add(T d,int f, int c)
        {
            NodoEsp<int>**p;
            NodoEsp<int>**q;
            if(!find_fil(f, c,p)&&!find_col(f, c,q))
            {
                NodoEsp<T> *  nuevo = new NodoEsp<T> (d,f,c);
                nuevo->sgtfil=*p;
                nuevo->sgtcol=*q;
                (*p)=(*q)=nuevo;
            }
        }
        void print()
        {
            NodoEsp<T> **p;
            for(int i=0;i<fil;i++)
            {
                cout<<endl;
                for(int j=0;j<col;j++)
                {

                    if(find_col(i,j,p))
                       cout<<(*p)->m_dato;
                    else
                      cout<<"0";
                }
            }
        }
        //virtual ~MatrizEsp();
    protected:
    private:
};

#endif // MATRIZESP_H
