#include <iostream>
#include <graphalgorithms.hpp>
#include <buildgraph.hpp>
#include <queue>
#include <unordered_map>
/*
En el reino de grafonia, se ha descubierto un antiguo mapa que representa las relaciones entre diversas regiones.
Se te ha encomendado la tarea de determinar si es posible dividir las regiones en dos grupos de tal manera que no exista ninguna
relación directa entre regiones del mismo grupo.

Tu objetivo es verificar si el mapa es bipartito y así los gobernantes de grafonia puedan comprender mejor la estructura de su reino.
Considere la interfaz:

is_bipartite ( g : Grafo = < N, A> ) : booleano
*/
template <typename T>
bool is_bipartite(const Designar::Graph<T>&);

int main()
{
    Designar::Graph<int> char_graph;

    Designar::Graph<int>::Node* node1 = char_graph.insert_node(1);
    Designar::Graph<int>::Node* node2 = char_graph.insert_node(2);
    Designar::Node<Designar::Graph<int>>* node3 = char_graph.insert_node(3);
    Designar::Node<Designar::Graph<int>>* node4 = char_graph.insert_node(4);
    Designar::Node<Designar::Graph<int>>* node5 = char_graph.insert_node(5);

    char_graph.insert_arc(node1, node2);
    char_graph.insert_arc(node1, node3);
    char_graph.insert_arc(node3, node4);
    char_graph.insert_arc(node4, node1);

    std::cout << "Is Bipartite the char_graph? " << std::boolalpha << is_bipartite(char_graph) << std::endl;

    Designar::Graph<char> bipartite_graph;
    Designar::Graph<char>::Node* a = bipartite_graph.insert_node('a');
    Designar::Graph<char>::Node* b = bipartite_graph.insert_node('b');
    Designar::Graph<char>::Node* c = bipartite_graph.insert_node('c');
    Designar::Graph<char>::Node* d = bipartite_graph.insert_node('d');
    Designar::Graph<char>::Node* p = bipartite_graph.insert_node('p');
    Designar::Graph<char>::Node* q = bipartite_graph.insert_node('q');
    Designar::Graph<char>::Node* r = bipartite_graph.insert_node('r');

    bipartite_graph.insert_arc(a, p);
    bipartite_graph.insert_arc(a, q);
    bipartite_graph.insert_arc(a, r);

    bipartite_graph.insert_arc(b, p);
    bipartite_graph.insert_arc(b, q);
    bipartite_graph.insert_arc(b, r);

    bipartite_graph.insert_arc(c, p);
    bipartite_graph.insert_arc(c, q);
    bipartite_graph.insert_arc(c, r);

    bipartite_graph.insert_arc(d, p);
    bipartite_graph.insert_arc(d, q);
    bipartite_graph.insert_arc(d, r);

    std::cout << "Is Bipartite the bipartite_graph? " << std::boolalpha << is_bipartite(bipartite_graph) << std::endl;

    bipartite_graph.insert_arc(p, q);

    std::cout << "Is Bipartite the bipartite_graph? " << std::boolalpha << is_bipartite(bipartite_graph) << std::endl;

    is_bipartite(Designar::Graph<char>{});

    return EXIT_SUCCESS;
}

template <typename T>
bool is_bipartite(const Designar::Graph<T>& graph)
{
    std::unordered_map<Designar::Node<Designar::Graph<T>>*, int> color;

    bool bipartite = true;

    graph.for_each_node([&color] (auto n)
                        {
                            color[n] = -1; // Inicializamos todos los nodos con color indefinido 
                        });

    std::queue<Designar::Node<Designar::Graph<T>>*> q;

    graph.for_each_node([&](auto n)
                        {
                            if (color[n] == -1)
                            {
                                color[n] = 0; // Coloreamos el nodo actual como 0
                                q.push(n);

                                while (!q.empty())
                                {
                                    auto current = q.front();
                                    q.pop();

                                    graph.for_each_adjacent_arc(current, [&](auto arc)
                                    {
                                        if (color[arc->get_connected_node(current)] == -1)
                                        {
                                            color[arc->get_connected_node(current)] = 1 - color[current]; // Coloreamos el nodo adyacente con el color opuesto
                                            q.push(arc->get_connected_node(current));
                                        }
                                        else if (color[current] == color[arc->get_connected_node(current)])
                                        {
                                            bipartite =  false; // Si encontramos un conflicto, el grafo no es bipartito
                                        }
                                    });
                                }
                            }
                        });

    return bipartite; // Retornamos el resultado de si el grafo es bipartito o no
}