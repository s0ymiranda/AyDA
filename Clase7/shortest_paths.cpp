#include <iostream>
#include <graphalgorithms.hpp>
#include <buildgraph.hpp>

struct Road
{
    int length;
    int speed_limit;
    bool available;
};

struct Cmp
{
    bool operator () (float a, float b) const
    {
        return a < b;
    }
};

struct DistTime
{
public:
    using Type = float;
    static constexpr Type ZERO = 0.0f;

    Type operator () (Designar::Arc<Designar::Graph<char, Road>>* r) const
    {
        std::cout << "From Node " << r->get_src_node()->get_info() << " to Node " << r->get_tgt_node()->get_info() << ":\n";
        if (r->get_info().available)
        {
            float temp = static_cast<float>(r->get_info().speed_limit) * 1000.0f/3600.0f;
            std::cout << "length m: " << r->get_info().length * 1000 << " | speed_limit m/s: " << temp << std::endl;
            float time = static_cast<float>(r->get_info().length) * 1000 / temp;
            std::cout << "Result time in s: " << time << " | in h: " << time/3600 << std::endl << std::endl;
            return time;
        }
        else
        {
            std::cout << "Road not Available" << std::endl << std::endl;
            return std::numeric_limits<float>::max();
        }
    }
};

struct Dist
{
public:
    using Type = float;
    static constexpr Type ZERO = 0.0f;

    Type operator () (Designar::Arc<Designar::Graph<char, Road>>* r) const
    {
        if (r->get_info().available)
        {
            return r->get_info().length;
        }
        else
        {
            return std::numeric_limits<float>::max();
        }
    }
};

int main()
{
    Designar::Graph<char, Road> graph;

    Designar::Graph<char, Road>::Node* nodeA = graph.insert_node('A');
    Designar::Graph<char, Road>::Node* nodeB = graph.insert_node('B');
    Designar::Graph<char, Road>::Node* nodeC = graph.insert_node('C');
    Designar::Graph<char, Road>::Node* nodeD = graph.insert_node('D');
    Designar::Graph<char, Road>::Node* nodeE = graph.insert_node('E');

    graph.insert_arc(nodeA, nodeB, Road{10, 5, true});
    graph.insert_arc(nodeA, nodeC, Road{15, 5, true});
    graph.insert_arc(nodeB, nodeC, Road{20, 10, true});
    graph.insert_arc(nodeB, nodeD, Road{25, 15, true});
    graph.insert_arc(nodeC, nodeD, Road{30, 20, true});
    graph.insert_arc(nodeC, nodeE, Road{5, 2, true});
    graph.insert_arc(nodeD, nodeE, Road{35, 35, true});
    graph.insert_arc(nodeE, nodeA, Road{1, 2, false});

    // Designar::Graph<char, Road> result_dijkstra = Designar::Dijkstra<Designar::Graph<char, Road>, DistTime, Cmp>().build_min_path_tree(graph, nodeC);
    Designar::Graph<char, Road> result_dijkstra = Designar::Dijkstra<Designar::Graph<char, Road>, Dist, Cmp>().build_min_path_tree(graph, nodeC);

    Designar::Graph<char, std::string> printable_graph;
    std::unordered_map<Designar::Node<Designar::Graph<char, Road>>*, Designar::Node<Designar::Graph<char, std::string>>*> relation;

    result_dijkstra.for_each_node([&printable_graph, &relation] (Designar::Node<Designar::Graph<char, Road>>* node)
                                        {
                                            relation[node] = printable_graph.insert_node(node->get_info());
                                        });

    result_dijkstra.for_each_arc([&printable_graph, &relation] (Designar::Arc<Designar::Graph<char, Road>>* arc)
                                        {
                                            std::string text = std::to_string(arc->get_info().length) + " / " + std::to_string(arc->get_info().speed_limit);
                                            printable_graph.insert_arc(relation[arc->get_src_node()], relation[arc->get_tgt_node()], text);
                                        });

    Designar::DotGraph<Designar::Graph<char, std::string>>().write_graph(printable_graph, "result_dijkstra.dot");
    Designar::DotGraph<Designar::Graph<char, std::string>>().write_graph(printable_graph, "result_dijkstra.dot");

    return EXIT_SUCCESS;
}