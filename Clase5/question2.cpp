#include <iostream>
#include <string>
#include <graphalgorithms.hpp>
#include <buildgraph.hpp>
#include <unordered_set>

/*
Dado un grafo no dirigido G = <I, P> que representa un laberinto, donde los nodos I representan las intersecciones
del laberinto y los arcos P representan los pasillos,se te pide encontrar un camino que pase por un nodo inicial s,
un nodo intermedio m y un nodo final e.
El objetivo es encontrar el camino más corto que conecte estos tres nodos. Considere la interfaz:

get_shortest_path ( g  Grafo = <I, P>, s : Nodo Inicial, m : Nodo Intermedio, e : Nodo Final) : Conjunto de nodos
*/

template <typename T>
Designar::Path<Designar::Graph<T>> get_shortest_path(const Designar::Graph<T>& g, Designar::Node<Designar::Graph<T>>* s, Designar::Node<Designar::Graph<T>>* m, Designar::Node<Designar::Graph<T>>* e);

int main()
{
    Designar::Graph<std::string> G{};
    std::vector<std::vector<Designar::Graph<std::string>::Node*>> nodes_matrix{};

    for (size_t i = 0; i <= 4; ++i)
    {
        std::vector<Designar::Graph<std::string>::Node*> temp{};
        for (size_t j = 0; j <= 5; j++)
        {
            temp.push_back(G.insert_node("(" + std::to_string(i) +", "+ std::to_string(j) + ")"));
        }
        nodes_matrix.push_back(temp);
    }

    G.insert_arc(nodes_matrix[0][0], nodes_matrix[1][0]);
    G.insert_arc(nodes_matrix[0][0], nodes_matrix[0][1]);

    G.insert_arc(nodes_matrix[0][1], nodes_matrix[1][1]);
    G.insert_arc(nodes_matrix[1][1], nodes_matrix[1][2]);

    G.insert_arc(nodes_matrix[1][2], nodes_matrix[0][2]);
    G.insert_arc(nodes_matrix[0][2], nodes_matrix[0][3]);

    G.insert_arc(nodes_matrix[0][3], nodes_matrix[0][4]);

    G.insert_arc(nodes_matrix[1][2], nodes_matrix[1][3]);
    G.insert_arc(nodes_matrix[1][3], nodes_matrix[1][4]);
    G.insert_arc(nodes_matrix[1][3], nodes_matrix[2][3]);

    G.insert_arc(nodes_matrix[2][3], nodes_matrix[2][2]);
    G.insert_arc(nodes_matrix[2][2], nodes_matrix[2][1]);
    G.insert_arc(nodes_matrix[2][2], nodes_matrix[3][2]);

    G.insert_arc(nodes_matrix[2][1], nodes_matrix[3][1]);

    G.insert_arc(nodes_matrix[3][1], nodes_matrix[3][0]);
    G.insert_arc(nodes_matrix[3][0], nodes_matrix[2][0]);

    G.insert_arc(nodes_matrix[3][2], nodes_matrix[3][3]);

    G.insert_arc(nodes_matrix[3][2], nodes_matrix[4][2]);
    G.insert_arc(nodes_matrix[4][2], nodes_matrix[4][1]);
    G.insert_arc(nodes_matrix[4][2], nodes_matrix[4][3]);

    G.insert_arc(nodes_matrix[4][1], nodes_matrix[4][0]);

    G.insert_arc(nodes_matrix[4][3], nodes_matrix[4][4]);
    G.insert_arc(nodes_matrix[4][4], nodes_matrix[3][4]);

    G.insert_arc(nodes_matrix[3][4], nodes_matrix[2][4]);

    G.insert_arc(nodes_matrix[2][4], nodes_matrix[2][5]);
    G.insert_arc(nodes_matrix[2][5], nodes_matrix[1][5]);
    G.insert_arc(nodes_matrix[2][5], nodes_matrix[3][5]);

    G.insert_arc(nodes_matrix[1][5], nodes_matrix[0][5]);

    G.insert_arc(nodes_matrix[3][5], nodes_matrix[4][5]);

    // G.insert_arc(nodes_matrix[1][4], nodes_matrix[0][5]);
    // G.insert_arc(nodes_matrix[1][4], nodes_matrix[4][5]);

    auto result = get_shortest_path(G, nodes_matrix[0][0], nodes_matrix[3][3], nodes_matrix[4][5]);

    Designar::DotGraph<Designar::Graph<std::string>>().write_graph(G, "G.dot");

    std::cout << "El camino resultante es: " << std::endl;

    ushort step = 0;
    result.for_each([&step] (Designar::Node<Designar::Graph<std::string>>* node, Designar::Arc<Designar::Graph<std::string>>* arc)
            {
                std::cout << ((step < 10) ? "0" : "") << step << ") " << node->get_info() << std::endl;
                ++step;
            });

    return EXIT_SUCCESS;
}

template <typename T>
Designar::Path<Designar::Graph<T>> get_shortest_path(const Designar::Graph<T>& g, Designar::Node<Designar::Graph<T>>* s, Designar::Node<Designar::Graph<T>>* m, Designar::Node<Designar::Graph<T>>* e)
{
    Designar::Path<Designar::Graph<T>> path1 = Designar::breadth_first_search_path(g, s, m);

    Designar::Path<Designar::Graph<T>> path2 = Designar::breadth_first_search_path(g, m, e);

    Designar::Path<Designar::Graph<T>> final_path(g);

    final_path.init(s);

    auto path1_arcs = path1.arcs();

    for (auto it = path1_arcs.begin(); it != path1_arcs.end(); ++it)
    {
        final_path.append(*it);
    }

    auto path2_arcs = path2.arcs();

    for (auto it = path2_arcs.begin(); it != path2_arcs.end(); ++it)
    {
        final_path.append(*it);
    }

    return final_path;
}