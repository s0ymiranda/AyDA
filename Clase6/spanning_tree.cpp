#include <iostream>
#include <graphalgorithms.hpp>
#include <buildgraph.hpp>

int main()
{
    Designar::Graph<char, int> graph;

    Designar::Graph<char, int>::Node* nodeA = graph.insert_node('A');
    Designar::Graph<char, int>::Node* nodeB = graph.insert_node('B');
    Designar::Graph<char, int>::Node* nodeC = graph.insert_node('C');
    Designar::Graph<char, int>::Node* nodeD = graph.insert_node('D');
    Designar::Graph<char, int>::Node* nodeE = graph.insert_node('E');

    graph.insert_arc(nodeA, nodeB, 10);
    graph.insert_arc(nodeA, nodeC, 15);
    graph.insert_arc(nodeB, nodeC, 20);
    graph.insert_arc(nodeB, nodeD, 25);
    graph.insert_arc(nodeC, nodeD, 30);
    graph.insert_arc(nodeD, nodeE, 35);
    //graph.insert_arc(nodeE, nodeA, 1);

    Designar::Graph<char, int> result_tree_kruskal = Designar::Kruskal<Designar::Graph<char, int>>().build_min_spanning_tree(graph);
    Designar::Graph<char, int> result_tree_prim = Designar::Prim<Designar::Graph<char, int>>().build_min_spanning_tree(graph);

    Designar::DotGraph<Designar::Graph<char, int>>().write_graph(graph, "original_graph.dot");
    Designar::DotGraph<Designar::Graph<char, int>>().write_graph(result_tree_kruskal, "result_tree_kruskal.dot");
    Designar::DotGraph<Designar::Graph<char, int>>().write_graph(result_tree_prim, "result_tree_prim.dot");

    return EXIT_SUCCESS;
}