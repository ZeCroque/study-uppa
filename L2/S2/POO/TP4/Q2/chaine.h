#ifndef chaine_h
#define chaine_h

#define DEFAULT_SIZE 10

class Chaine
{
  private :
    char** _tab;
    int _size;
    int _length;
  public :
    Chaine();
    Chaine(const Chaine& c);
    ~Chaine();
    Chaine& operator = (const Chaine& c);
    void setText(char* c);
    char* getText();
    void affiche();
};

#endif
