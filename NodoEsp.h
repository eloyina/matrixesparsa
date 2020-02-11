#ifndef NODOESP_H
#define NODOESP_H

template<class T>
class NodoEsp
{
    public:
        int fil;
        int col;
        NodoEsp<T>* sgtfil;
        NodoEsp<T>* sgtcol;
        NodoEsp();
        T m_dato;
        NodoEsp(T d, int f,int c)
        {
            m_dato=d;
            fil=f;
            col=c;
            sgtfil=sgtcol=0;
        }
    protected:
    private:
};

#endif // NODOESP_H
