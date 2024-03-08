#include <vector>
#include <iostream>
#include "shape.hpp"

class Rectangle : public Shape
{
    int length;
    int height;

public:
    Rectangle Rectangle(int posx, int posy, int l, int h, int col) : length(l), height(h), Shape(posx, posy) {}
    float area() { return lenght * height; }
}