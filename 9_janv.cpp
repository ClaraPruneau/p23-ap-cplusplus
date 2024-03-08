#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <vector>

/* on cherche à implémenter la représentation par sommets adjacents*/

class Vertex;

class Edge
{
  friend class Vertex;
  friend class Graph;

private:
  Vertex *start = nullptr;
  Vertex *target = nullptr;
  double value = 0.0;

public:
  Edge() = default;
  Edge(Vertex *cible, double valeur) : target(cible), value(valeur)
  {
  }
};

class Graph;

class Vertex
{
  friend class Edge;
  friend class Graph;

private:
  std::vector<Edge> buffer;

public:
  Vertex() = default;
  void add_edge(Vertex *cible, int valeur)
  {
    buffer.push_back(Edge(cible, valeur));
  }
  void parcours()
  {
    std ::cout << buffer << std ::endl;
  }
};

class Graph
{
  friend class Edge;
  friend class Vertex;

  std::vector<Vertex> vertice;

public:
  void add_vertex(int i)
  {
    vertice.push_back(Vertex /*???*/); // QUESTION : quand je cherche à complier, cette ligne pose problème. J'ai essayé plein de 
    //types en argument mais je ne sais pas comment relier le vertex que je souhaite ajouter à l'entier que j'ai mis en argument. 
    //une fois ce problème réglé mon code devrait pouvoir compiler.
  }

  void add_edge(int depart, int cible, double valeur)
  {
    vertice[depart].add_edge(&vertice[cible], valeur);
  }
  void parcours()
  {
    // initialisation d'une matrice avec que des zéros (aucun sommet n'a été visité)
    if (vertice.size() <= 0)
    {
      throw "graphe vide";
    }
    auto taille{vertice.size()};
    int matrice[taille][taille];
    for (int i = 0; i < taille; i++)
    {
      for (int j = 0; j < taille; j++)
      {
        matrice[i][j] = 0;
      }
    }
    // QUESTION : cette initialisation est-elle vraiment nécessaire étant donné que 0 ets le caractère nul des entiers ?
    for (int i = 0; i < taille; i++)
    {
      if (matrice[i][i] = 0)
      {
        (vertice[i]).parcours();
      }
      matrice[i][i] = 1;
      for (int j = 0; j < ((vertice[i]).buffer).size(); j++)
      {
        if (matrice[j][j] = 0)
        {
          (vertice[j]).parcours();
          matrice[j][j] = 0;
        }
        if (matrice[i][j] = 0)
        {
          (vertice[j]).parcours();
          matrice[i][j] = 0;
          matrice[j][i] = 0;
        } // un peu redondant, je sais, mais permet de s'assurer d'avoir tout visiter
      }
    }
  }
};

int main()
{
  Graph g;
  g.add_vertex(0);
  g.add_vertex(1);
  g.add_edge(0, 1, 17.4);
}