/*
id:206698359    mail:shoamivgi1234@gmail.com
*/

#ifndef EX1_SW2_DFS_HPP
#define EX1_SW2_DFS_HPP
#include <utility>
#include <vector>
#include "Traverse.hpp"


class DFS {
    static void DFS_Visit(ariel::Graph &g, vector<int> &p, vector<int> &color);
    static string Rev_Cycle(vector<int>cycle);
    static bool Cycle_util(ariel::Graph &g,int vertex,vector<int>&p,vector<int>&color,vector<int>&cycle_vec);
    static void Set_DFS(vector<int>p,vector<int>color);
public:
    static int isConnected_ByDFS(ariel::Graph &g);
    static string is_Cyclic(ariel::Graph &g);
};


#endif //EX1_SW2_DFS_HPP
