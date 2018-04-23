#ifndef carte_h
#define carte_h

class Carte
{
  private:
    char famille;
    int valeur;
  public:
    Carte();
    Carte(Carte& c);
    ~Carte();
    Carte& operator = (const Carte& c);
};

#endif
