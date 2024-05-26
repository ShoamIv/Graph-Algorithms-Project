/*
id:206698359    mail:shoamivgi1234@gmail.com
*/

#ifndef EX1_SW2_ALGORITHMS_HPP
#define EX1_SW2_ALGORITHMS_HPP
#include "Graph.hpp"
#include <vector>
using namespace std;

namespace ariel{
    class Algorithms {
    public:
        static int  isConnected(Graph& g);
        static string isContainsCycle(Graph& g);
        static string shortestPath( Graph& g,int start,int end);
        static string isBipartite(Graph& g);
    };
}

#endif //EX1_SW2_ALGORITHMS_HPP
