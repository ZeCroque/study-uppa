#include "ppmfile.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace L2Info;
//-------------------------------------------------------------
PPMFile::PPMFile ():_npixels(0),_n(0),_m(0),_filename("")
{}
//-------------------------------------------------------------
PPMFile::PPMFile(const std::string & filename):_npixels(0),_n(0),_m(0),_filename(filename)
{
    readFile();
}
//-------------------------------------------------------------
std::array<int ,3>& PPMFile::operator()(int i,int j)
{
    std::array<int ,3> & pixel=_pixels[j*_n+i];
    return pixel;
}
//-------------------------------------------------------------
const std::array<int ,3>& PPMFile::operator()(int i,int j) const
{
    const std::array<int ,3> & pixel=_pixels[j*_n+i];
    return pixel;
}
//-------------------------------------------------------------
int PPMFile::getNPixels() const
{
    return _npixels;
}
//-------------------------------------------------------------
int PPMFile::getNColumns() const
{
    return _m;
}
//-------------------------------------------------------------
int PPMFile::getNLines() const
{
    return _n;
}
//-------------------------------------------------------------
const std::string & PPMFile::getFilename() const
{
  return _filename;
}
//-------------------------------------------------------------
void PPMFile::setFilename(const std::string& filename)
{
    _filename=filename;
}

//-------------------------------------------------------------
void PPMFile::readFile()
{
  std::ifstream infile(_filename+".ppm");
  std::string inputLine;
  getline(infile,inputLine);
  getline(infile,inputLine);
  infile>>_n>>_m;
  _npixels=_n*_m;
  infile>>_vmax;
  _pixels.reserve(_npixels);
  _pixels.resize(_npixels);
  for (int i=0; i<_npixels; i++)
  {
      std::array<int ,3> & pixel=_pixels[i];
      infile>>pixel[0]>>pixel[1]>>pixel[2];
  }
  infile.close();
}
//-------------------------------------------------------------
void PPMFile::writeNegFile(const std::string& outfilename) const
{
    std::array<int ,3> tmp;
    int i,j;

    std::ofstream outfile(outfilename+".ppm");
    outfile<<"P3\n";
    outfile<<"# "<<outfilename+".ppm"<<'\n';
    outfile<<getNLines()<<" "<<getNColumns()<<"\n";
    outfile<<_vmax<<"\n";
    for(i=0; i<getNPixels(); i++)
    {
        tmp=_pixels[i];
        for(j=0; j<3; j++)
        {
          outfile<<_vmax-tmp[j]<<" ";
        }
      outfile<<"\n";
    }
    outfile.close();
}
//-------------------------------------------------------------
void PPMFile::writeContourFile(const std::string& outfilename, int seuil) const
{
  int i,j,k;
  int color;
  pixelmap pixeltmp;
  pixeltmp.reserve(_npixels);
  pixeltmp.resize(_npixels);
  std::array<int ,3> tmp;

  for(i=0; i<_npixels; i++)
  {
      tmp=pixeltmp[i];
      for(j=0; j<3;j++)
      {
        tmp[j]=255;
      }
  }

  std::ofstream outfile(outfilename+".ppm");
  outfile<<"P3\n";
  outfile<<"# "<<outfilename+".ppm"<<'\n';
  outfile<<_n<<" "<<_m<<'\n';
  outfile<<_vmax<<'\n';
  for(i=1;i<_n-1;i++)
  {
    for(j=1;j<_m-1;j++)
    {
      tmp=(*this)(i,j);
      color=0;
      for(k=0; k<3; k++)
      {
        color+=fabs((tmp[k]*4)-(*this)(i+1,j)[k]-(*this)(i,j+1)[k]-(*this)(i-1,j)[k]-(*this)(i,j-1)[k]);
      }
      if(color>seuil)
      {
        tmp=pixeltmp[i];
        for(k=0; k<3; k++)
        {
          tmp[k]=0;
        }
      }
    }
  }
  for(i=0; i<getNPixels(); i++)
  {
      for(j=0; j<3; j++)
      {
        tmp=pixeltmp[i];
        outfile<<tmp[j]<<" ";
      }
    outfile<<"\n";
  }

  outfile.close();
}
//-------------------------------------------------------------
void PPMFile::writeExtractColor(int r, int g, int b, int seuil, const std::string& outfilename) const
{
  std::array<int ,3> tmp;
  int i,j;
  int color;
  int gris;

  std::ofstream outfile(outfilename+".ppm");
  outfile<<"P3\n";
  outfile<<"# "<<outfilename+".ppm"<<'\n';
  outfile<<getNLines()<<" "<<getNColumns()<<"\n";
  outfile<<_vmax<<"\n";
  for(i=0; i<getNPixels(); i++)
  {
      tmp=_pixels[i];
      color=fabs(tmp[0]-r)+fabs(tmp[1]-g)+fabs(tmp[2]-b);
      if(color>seuil)
      {
        gris=(tmp[0]+tmp[1]+tmp[2])/3;

        for(j=0; j<3; j++)
        {
          tmp[j]=gris;
        }
      }
      for(j=0; j<3; j++)
      {
        outfile<<tmp[j]<<" ";
      }
    outfile<<"\n";
  }
  outfile.close();
}
