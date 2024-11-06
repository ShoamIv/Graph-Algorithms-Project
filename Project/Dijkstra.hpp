/*
id:206698359    mail:shoamivgi1234@gmail.com
*/

#ifndef EX1_SW2_DIJKSTRA_HPP
#define EX1_SW2_DIJKSTRA_HPP
#include "Traverse.hpp"
#include <vector>
//Single source None negative weighted  shortest path


class Dijkstra {
public:
    static string Initiate(int source, int dest,ariel::Graph& g);
    static string PrintDijkstra(int source, int target,ariel::Graph& g,vector<int>&p);
};


#endif //EX1_SW2_DIJKSTRA_HPP
