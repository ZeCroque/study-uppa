#ifndef _L2INFO_PPMFile__h
#define _L2INFO_PPMFile__h

#include <iostream>
#include <vector>
#include <array>

namespace L2Info{
class PPMFile
{
  private:
    int _npixels; // nombre de pixels dans l'image
    int _n,_m;//nombre de pixels dans chaque direction
    int _vmax;// valeur de codage maximum pour chaque couleur (le plus souvent égal à 255)
    std::string _filename;// nom du fichier
    typedef std::vector<std::array<int ,3> > pixelmap;// définition d'un type pour stocker la couleur des pixels en rgb
    pixelmap _pixels;// tableau des couleurs des pixels.
  public :
   PPMFile ();// constrcuteur sans paramètre
   PPMFile(const std::string& filename);// constructeur avec le nom du fichier en paramètre.
   std::array<int ,3>& operator()(int i,int j);// opérateur () pour récupérer la couleur du pixel i,j
   const std::array<int ,3> & operator()(int i,int j) const;// opérateur () pour récupérer la couleur du pixel i,j
   int getNPixels() const ; //renvoie le nombre de pixel
   int getNColumns() const ;//renvoie le nombre de pixel en x
   int getNLines() const ;//renvoie le nombre de pixel en y
   const std::string & getFilename() const; // renvoie le nom du fichier
   void setFilename(const std::string& filename);// initialise le nom du fichier
   void readFile();// lecture du fichier

   // les trois fonctions qui suivent sont à écrire
   void writeNegFile(const std::string& outfilename) const; // passage de l'image en négatif
   void writeContourFile(const std::string& outfilename, int seuil) const;// détection des contours
   void writeExtractColor(int r, int g, int b, int seuil, const std::string& outfilename) const;// extraction à l'aide d'une couleur.


};
}
#endif
