#include <iostream>
#include <stdexcept>
class Stack
{
private:
    int nb;
    int size;
    char *tab;
public: 
    Stack(int n);
    Stack(const Stack &rs);
    void push(char c);
    void pop();
    bool isempty() const;
    bool isfull() const;
    void print() const;
    char top() const;
    ~Stack();
};
/*
ici, toutes les fonctions et tous les constructeurs dsont déclarés dans la classe mais pas définis
Pour les définir en dehors de la classe, il faut écrire :
inline typerenvoyé Stack::nomfonction (arguments) {...}
Sinon, on peut les définir directement et normalement dans la classe*/

// constructeur à partir d'un entier :
Stack::Stack(int n) : nb(0), size(n)
{ // liste d'initialisation
    if (size <= 0)
    {
        throw std::invalid_argument("wrong stack size");
    }
    tab = new char[size];
}

// copy constructor :
Stack::Stack(const Stack &rs) : nb(rs.nb), size(rs.size)
{
    tab = new char[size];
    for (int i = 0; i < nb; i++)
    {
        tab[i] = rs.tab[i];
    }
}

// si on écrit "Stack(const Stack &rs)= delete;" on interdit la copie du stack

// &obj = adresse de l'objet, obj& = référence de l'objet
// en appelant &object, on appelle à la fois l'objet et son contenu; object appelle le contenu directement

Stack::~Stack() { delete[] tab; }

inline void Stack::push(char c)
{
    if (isfull())
    {
        throw "stop";
    }
    tab[nb] = c;
    nb = nb + 1;
}

inline void Stack::pop()
{
    if (isempty())
    {
        throw "non";
    }
    tab[nb - 1] = '\0';
    nb = nb - 1;
}

inline bool Stack::isempty() const
{
    return nb == 0;
}

inline bool Stack::isfull() const
{
    return nb == size;
}

inline void Stack::print() const
{
    for (int i = 0; i < nb; i++)
    {
        std ::cout << tab[i] << ' ' << std ::endl;
    }
}

inline char Stack::top() const
{
    if (isempty())
    {
        throw "non";
    }
    return tab[nb - 1];
}
/*
 option plus globale sans modif la classe
 char c = (*this).pop();
 (*this).push(c);
 return c
 */

int main()
{
    try
    {
        Stack s1(-3);
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
    }
    /*s1.push('b');
    s1.push('l');
    s1.push('o');
    s1.push('u');
    s1.push('p');
    s&.print()*/

    Stack s = 12;
    Stack s2 = s; // copy constructor (il faut le définir)
    s = s2;       // assignment
}
/* dans le terminal :
g++ -g main.cpp        génère a.out (-g => débugage)
valgrind ./a.out        exécute dans valgrind*/

/* shift + alt + f pour indenter correctement automatiquement*/
