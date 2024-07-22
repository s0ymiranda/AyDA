#include <iostream>
#include <graphalgorithms.hpp>
#include <buildgraph.hpp>
#include <unordered_set>

/*
A las vacas de una granja les gusta una estructura hexagonal como las de una colmena de abejas. Por esta razón, el granjero creó un sistema de pasto en ese formato

Cada pasto está conectado a su vecino inmediato. Algunas vacas se han quedado comiendo en un solo pasto por varios días y han devenido gordas y perezosas. Para forzarlas a hacer un poco de ejercicio, el granjero ha colocado un saborizante especial a los pastos que se encuentran exactamente a una distancia L desde el punto donde las vacas se quedaron. De esta manera garantiza que las vacas se muevan al menos hasta alguno de los pastos saborizados. Pero las vacas no saben cuáles son los pastos saborizados. Con el fin de ayudar a las vacas a hacer el mínimo ejercicio necesario para encontrar un
pasto saborizado, se le pide escribir un algoritmo que, dado el punto donde se encuentran las vacas y la distancia a la cual el granjero colocó el saborizante, le proporcione a las vacas el conjunto de pastos en el cual está el saborizante. Considere el sistema de pastos como un grafo no dirigido donde los nodos son pastos y los arcos definen la vecindad entre éstos. Considere la interfaz:

get_set (g : Grafo = <V,E>, p : Nodo, L : entero) : Conjunto de nodos
*/

template <typename T>
std::unordered_set<Designar::Node<Designar::Graph<T>>> gerardo(const Designar::Graph<T>&);

int main()
{
    Designar::nat_t i = 0;
    Designar::Graph<Designar::nat_t> hexagonal_grid = Designar::build_grid<Designar::Graph<Designar::nat_t>>(7, 7, Designar::GridType::HEXAGONAL,
                                      [&i](Designar::Graph<Designar::nat_t>::Node *p, Designar::nat_t, Designar::nat_t)
                                      {
                                        p->get_info() = ++i;
                                      });


    Designar::nat_t cow_position = 10; // Nodo en el que se encuentran las vacas
    int L = 2; // Distancia a la que se colocó el saborizante
    auto start_node = hexagonal_grid.search_node(cow_position);
    //auto saborized_set = gerardo(Designar::Graph<char>{});

    gerardo(hexagonal_grid);

    /*std::cout << "Saborized pastures at distance " << L << " from cow position: ";
    for (const auto& node : saborized_set)
    {
        std::cout << node.get_info() << " ";
    }*/

    return EXIT_SUCCESS;
}

template <typename T>
std::unordered_set<Designar::Node<Designar::Graph<T>>> gerardo(const Designar::Graph<T>& graph)
{
    return std::unordered_set<Designar::Node<T>>{};
    std::unordered_set<Designar::Node<T>> saborized; // Conjunto para almacenar los pastos saborizados
    std::unordered_map<Designar::Node<T>, int> distance; // Mapa para almacenar las distancias desde el punto p

    std::queue<std::pair<Designar::Node<T>, int>> q;
    q.push({ p, 0 });

    while (!q.empty())
    {
        auto current = q.front().first;
        auto dist = q.front().second;
        q.pop();

        if (dist == L)
        {
            saborized.insert(current); // Alcanzamos la distancia L
        }
        else
        {
            g.for_each_adjacent_arc(current, [&](auto arc)
            {
                if (distance.find(arc->get_connected_node(current)) == distance.end()) {
                    distance[arc->get_connected_node(current)] = dist + 1;
                    q.push({ arc->get_connected_node(current), dist + 1 });
                }
            });
        }
    }

    return saborized;
}