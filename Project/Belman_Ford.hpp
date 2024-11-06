/*
id:206698359    mail:shoamivgi1234@gmail.com
*/

#ifndef EX1_SW2_BELMAN_FORD_HPP
#define EX1_SW2_BELMAN_FORD_HPP

//Single source negative weighted shortest path

#include "Graph.hpp"
using namespace std;
using namespace ariel;
class Belman_Ford {
    static bool  neg_cycle;
public:
    static string PrintPath(int a, int b,ariel::Graph &g);
    static bool BF_ShortestPath(ariel::Graph &g,int start,vector<int>&d,vector<int>&p);
    static string DetectCycle(ariel::Graph &g);

};
#endif //EX1_SW2_BELMAN_FORD_HPP
