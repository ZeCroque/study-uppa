#ifndef _Tirage_loto_h
#define _Tirage_loto_h

class Tirage_loto {
    const int static _Nombre;
    int* _resultat_tirage;
private:
    int tirage_interne(const int&) const;
public:
    Tirage_loto();
    ~Tirage_loto();
    void tirage();
};

#endif
