#include <iostream>
#include <string>
#include <graphalgorithms.hpp>
#include <buildgraph.hpp>


/*
Dado un grafo no dirigido G = <I, P> que representa un laberinto, donde los nodos I representan las intersecciones
del laberinto y los arcos P representan los pasillos,se te pide encontrar un camino que pase por un nodo inicial s,
un nodo intermedio m y un nodo final e.
El objetivo es encontrar el camino más corto que conecte estos tres nodos. Considere la interfaz:

get_shortest_path ( g  Grafo = <I, P>, s : Nodo Inicial, m : Nodo Intermedio, e : Nodo Final) : Conjunto de nodos
*/


int main()
{
    Designar::Graph<std::string> G{};
    std::vector<std::vector<Designar::Graph<std::string>::Node*>> nodes_matrix{};

    for (size_t i = 0; i <= 5; ++i)
    {
        std::vector<Designar::Graph<std::string>::Node*> temp{};
        for (size_t j = 0; j <= 4; j++)
        {
            temp.push_back(G.insert_node(std::to_string(i) +", "+ std::to_string(j)));
        }
        nodes_matrix.push_back(temp);
    }

    G.insert_arc(nodes_matrix[1][0], nodes_matrix[0][0]);
    G.insert_arc(nodes_matrix[0][1], nodes_matrix[0][0]);

    G.insert_arc(nodes_matrix[1][1], nodes_matrix[0][1]);
    G.insert_arc(nodes_matrix[1][1], nodes_matrix[1][2]);

    G.insert_arc(nodes_matrix[0][2], nodes_matrix[0][3]);
    G.insert_arc(nodes_matrix[0][2], nodes_matrix[1][2]);

    G.insert_arc(nodes_matrix[0][4], nodes_matrix[0][3]);

    Designar::DotGraph<Designar::Graph<std::string>>().write_graph(G, "G.dot");

    return EXIT_SUCCESS;
}