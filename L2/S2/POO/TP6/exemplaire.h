#ifndef exemplaire_h
#define exemplaire_h


class Exemplaire
{
  private :
    int _reference;
  public :
    Exemplaire();
    Exemplaire(int ref);
    ~Exemplaire();
    bool operator == (const Exemplaire& e);
    int getRef();
};

#endif
