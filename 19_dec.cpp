#include <iostream>
#include <vector>
class Circle_
{
    int x;
    int y;
    int color;
    int radius;
};

class Rectangle_
{
    int x;
    int y;
    int color;
    int w, h;
};

/* TRES REDONDANT -> on fait une classe commune à tous les objets à dessiner*/

class Shape
{
protected:
    int x;
    int y;
    int color;
    Shape(int posx, int posy, int col) : x(posx), y(posy), color(col) {}

public:
    void move(int dx, int dy)
    {
        x = x + dx;
        y = y + dy;
    }
    virtual float area() { return 99;} // nimporte quoi
};

class Circle : public Shape
{
    int radius;

public:
    Circle Circle(int posx, int posy, int r, int col) : radius(r), Shape(posx, posy) {}
    float area() { return 3.14 * radius * radius; }
};

int main()
{
    Circle c1(10, 20, 3, 230);
    std::cout << c1.area() << std::endl;
    Shape *s = &c1; // Shape* veut dire que s est l'adresse d'une shape ; *s désignerait alors la shape pointée par s; &c1 désigne l'adresse de c1
    std::cout << s->area() << std::endl;
    return 0;
}
