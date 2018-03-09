#include "ppmfile.h"


using namespace L2Info;
int main()
{
   PPMFile file("fleurs3");
   file.writeNegFile("image4neg");
   file.writeContourFile("image4contour",150);
   file.writeExtractColor(255,0,0,50,"image4red");
}
