/*
id:206698359    mail:shoamivgi1234@gmail.com
*/

#ifndef EX1_SW2_BFS_HPP
#define EX1_SW2_BFS_HPP

#include "Traverse.hpp"
using namespace ariel;

class BFS {
    static void BFS_SET(std::vector<int>&d,std::vector<int>&p,std::vector<int>&color);
    static bool * visit;
    public:
    static string BFS_init(int vertex,int target,Graph &g);

};


#endif //EX1_SW2_BFS_HPP
