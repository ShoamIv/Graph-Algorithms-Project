//
// Created by vboxuser on 4/25/24.
//

#ifndef EX1_SW2_TRAVERSE_HPP
#define EX1_SW2_TRAVERSE_HPP
#include "Graph.hpp"
#include "BFS.hpp"
#include "DFS.hpp"
#include "Bipartite.hpp"
#include "Dijkstra.hpp"
#include "Belman_Ford.hpp"
#include <limits>
#include <map>
#define  MAX std::numeric_limits<int>::max();
#define NoneWeight 0
#define Weight 1
#define NegativeWeight 2
#include <vector>
using namespace ariel;
using namespace std;
class Traverse {

public:

    static void relax(int a,int b,Graph &g,vector<int>&d,vector<int>&p);
    enum color { WHITE,GRAY,BLACK};
    static Graph Transpose(Graph &g);
};


#endif //EX1_SW2_TRAVERSE_HPP
