#include <iostream>
#include <graphalgorithms.hpp>

int main()
{
    Designar::Graph<char> char_graph;

    Designar::Graph<char>::Node* node1 = char_graph.insert_node('a');
    Designar::Graph<char>::Node* node2 = char_graph.insert_node('b');
    Designar::Node<Designar::Graph<char>>* node3 = char_graph.insert_node('c');
    Designar::Node<Designar::Graph<char>>* node4 = char_graph.insert_node('d');
    Designar::Node<Designar::Graph<char>>* node5 = char_graph.insert_node('e');

    char_graph.insert_arc(node1, node2);
    char_graph.insert_arc(node1, node3);
    char_graph.insert_arc(node3, node4);
    char_graph.insert_arc(node4, node1);

    unsigned short counter = 0;
    char_graph.for_each_arc([&counter] (Designar::Graph<char>::Arc* arc)
    {
        std::cout << "For Arc Number: " << ++counter << ", We Have Source Node: " << arc->get_src_node()->get_info() << ", And Target Node: " << arc->get_tgt_node()->get_info() << std::endl;
    });

    Designar::DotGraph<Designar::Graph<char>>().write_graph(char_graph, "graph.dot");

    //

    Designar::Digraph<char> char_digraph;

    Designar::Digraph<char>::Node* dinode1 = char_digraph.insert_node('a');
    Designar::Digraph<char>::Node* dinode2 = char_digraph.insert_node('b');
    Designar::Digraph<char>::Node* dinode3 = char_digraph.insert_node('c');
    Designar::Digraph<char>::Node* dinode4 = char_digraph.insert_node('d');
    Designar::Digraph<char>::Node* dinode5 = char_digraph.insert_node('e');

    char_digraph.insert_arc(dinode1, dinode2);
    char_digraph.insert_arc(dinode1, dinode3);
    char_digraph.insert_arc(dinode3, dinode4);
    char_digraph.insert_arc(dinode4, dinode1);

    counter = 0;
    char_digraph.for_each_arc([&counter] (Designar::Digraph<char>::Arc* arc)
    {
        std::cout << "For Arc Number: " << ++counter << ", We Have Source Node: " << arc->get_src_node()->get_info() << ", And Target Node: " << arc->get_tgt_node()->get_info() << std::endl;
    });

    Designar::DotGraph<Designar::Digraph<char>>().write_graph(char_digraph, "digraph.dot");

    return EXIT_SUCCESS;
}