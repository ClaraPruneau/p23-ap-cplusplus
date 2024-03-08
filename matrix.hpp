#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <vector> 

class Matrix
{
protected:
  int rows;
  int columns;
  std::vector<int> buffer;

  // pour avoir l'indice dans le vecteur à partir des indices dans la matrice
  int indice(int i, int j) const { 
    if ((i<=0) or (j<=0)){
        throw std::invalid_argument("negative index");
    }
    if ((i>rows) or (j>columns)){
        throw std::invalid_argument("invalid index");
    }
    return ((i - 1) * columns) + (j - 1); };

public:
  Matrix(int lignes, int colonnes, int value = 0) : rows(lignes), columns(colonnes), buffer(lignes * colonnes, value)
  {
    if ((rows <= 0) || (columns <= 0)) 
    {
      throw std::invalid_argument("invalid matrix size");
    }
  }
  float at(int i, int j) const { return buffer[indice(i, j)]; };
  void at(int i, int j, int v) { buffer[indice(i, j)] = v; }
};
