/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#ifndef EX1_SW2_GRAPH_HPP
#define EX1_SW2_GRAPH_HPP
#include <vector>
#include <list>
#include <string>
#include <map>
#include <iostream>
#include "Linear_Algebra.hpp"
using namespace std;
namespace ariel{
class Graph{
    void clear();
    void Classified();
    int Type{};
    bool directed{};
    static void Valid(const Graph &a,const Graph &b);
public:
    Graph();
    std::vector<std::vector<int>> graph;
    int num_ver{};
    string printGraph();
    void loadGraph(std::vector<std::vector<int>> graph);
    int getType() ;
    bool getDirected() ;
    typedef struct edge {
        int source;
        int dest;
        int weight;
    } Edge;
    std::vector<Edge> edge_list;
    Graph operator+( Graph &b);
    Graph operator+();
    Graph operator+=( Graph &b) ;
    Graph operator*( Graph &b);
    Graph operator-( Graph &b);
    Graph operator-();
    Graph operator-=( Graph &b);
    bool operator==( Graph &b);
    bool operator>( Graph &b) ;
    bool operator>=( Graph &b);
    bool operator<( Graph &b) ;
    bool operator<=( Graph &b);
    bool operator!=( Graph &b);
    Graph  operator++();
    Graph  operator++(int);
    Graph  operator--();
    Graph  operator--(int);
    Graph operator*=(int scalar);
    Graph operator/=(int scalar);
    friend std::ostream& operator<<(std::ostream& os,  Graph& g);
    void print_matrix();
};
}
#endif //EX1_SW2_GRAPH_HPP