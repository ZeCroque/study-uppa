#include <cmath> // 'std::abs', etc.
#include <cstdlib> // 'std::srand', etc.
#include <ctime>

#include "Tirage_loto.h"

const int Tirage_loto::_Nombre = 48;

Tirage_loto::Tirage_loto() {
    _resultat_tirage = new int[_Nombre];
}

Tirage_loto::~Tirage_loto() {
    delete[] _resultat_tirage;
}

void Tirage_loto::tirage() {
    time_t t;
    std::srand(std::time(&t));
    for (int i = 0; i < _Nombre; i++) _resultat_tirage[i] = tirage_interne(i);
}

int Tirage_loto::tirage_interne(const int& i) const {
    int resultat = std::abs(std::rand() % 49); // On tire un nombre positif entre 0 et 49
    bool deja_tire = false; // On fait l'hypothèse que ce nombre n'a pas encore été tiré...
    for (int j = 0; j < i; j++) { // On regarde le début du tableau pour vérifier ce qui a déjà été tiré...
        if (resultat == _resultat_tirage[j]) { // Si déjà tiré...
            deja_tire = true;
            break; // On arrête brutalement la boucle 'for', inutile d'aller plus loin...
        }
    }
    if (deja_tire) return tirage_interne(i); // On recommence le tirage
    return resultat; // Sinon, c'est bon
}