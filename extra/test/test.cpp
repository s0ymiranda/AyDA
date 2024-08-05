#include <iostream>
#include <graphalgorithms.hpp>
#include <buildgraph.hpp>

// using namespace Designar;

// template <typename GT>
//   SLList<SLList<Node<GT>*>> topological_ranks(const GT &g)
//   {
//     if (!g.is_digraph())
//       throw std::domain_error("Argument must be a directed graph");

//     g.reset_node_counter();

//     g.for_each_arc([](Arc<GT> *a)
//                    { ++a->get_tgt_node()->counter(); });

//     ListQueue<Node<GT> *> queue;

//     g.for_each_node([&queue](Node<GT> *p)
//                     {
// 		      if (p->counter() == 0)
// 			queue.put(p); });

//     SLList<SLList<Node<GT> *>> ret;

//     while (!queue.is_empty())
//     {
//       ListQueue<Node<GT> *> aqueue;

//       SLList<Node<GT> *> &l = ret.append(SLList<Node<GT> *>());

//       while (!queue.is_empty())
//       {
//         Node<GT> *p = queue.get();

//         l.append(p);

//         for (AdArcIt<GT> it(g, p); it.has_current(); it.next())
//         {
//           Node<GT> *q = it.get_tgt_node();

//           if (--q->counter() == 0)
//             aqueue.put(q);
//         }
//       }

//       queue = std::move(aqueue);
//     }

//     return ret;
//   }


int main()
{
    Designar::Digraph<char, int> graph;
    Designar::Digraph<char, int>::Node* nodeA = graph.insert_node('A');
    Designar::Digraph<char, int>::Node* nodeB = graph.insert_node('B');
    Designar::Digraph<char, int>::Node* nodeC = graph.insert_node('C');
    Designar::Digraph<char, int>::Node* nodeD = graph.insert_node('D');
    Designar::Digraph<char, int>::Node* nodeE = graph.insert_node('E');
    graph.insert_arc(nodeA, nodeB, 10);
    graph.insert_arc(nodeA, nodeC, 15);
    graph.insert_arc(nodeB, nodeC, 20);
    graph.insert_arc(nodeC, nodeB, 10);
    graph.insert_arc(nodeB, nodeD, 30);
    graph.insert_arc(nodeC, nodeD, 30);
    graph.insert_arc(nodeD, nodeE, 35);
    auto p = Designar::topological_ranks(graph);

  Designar::DotGraph<Designar::Digraph<char, int>>().write_graph(graph, "test.dot");

    for (auto &t : p)
    {
      for (auto &i : t)
      {
        std::cout << i->get_info() << " ";
      }
      std::cout << std::endl;
    }

    return 0;
}