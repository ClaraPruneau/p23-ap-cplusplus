#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <vector>

#include "matrix.hpp"

int main()
{
    Matrix matrice(2, 2);
    matrice.print();

    matrice.at(1, 1, 2);
    matrice.at(1, 2, 5);
    matrice.at(2, 1, 4);
    matrice.at(2, 2, 8);

    matrice.print();

    try
    {
        Matrix m1(0, 0);
    }
    catch (const char *e)
    {
        std::cout << "Erreur : " << e << std::endl;
    }
    try
    {
        Matrix m2(-4, 5);
    }
    catch (std::length_error &e)
    {
        std::cout << "Erreur: Length_error de std::vector : " << e.what() << std::endl;
    }
}
