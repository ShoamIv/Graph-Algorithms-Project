/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#ifndef EX1_SW2_BIPARTITE_HPP
#define EX1_SW2_BIPARTITE_HPP

#include "Traverse.hpp"
#include <map>
#include <queue>
#include <iostream>
#include "Graph.hpp"

class Bipartite {
    static string Print_Bip(const map<int,int>&color);
    static bool Biputil(ariel::Graph &g, int vertex,map<int,int>&color);

public:
    static string is_Bip(ariel::Graph &g, int vertex);


};
#endif //EX1_SW2_BIPARTITE_HPP
