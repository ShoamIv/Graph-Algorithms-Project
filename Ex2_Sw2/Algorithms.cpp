/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#include "Algorithms.hpp"
#include "Traverse.hpp"
#include <vector>
using namespace ariel;


int Algorithms::isConnected(ariel::Graph& g) {
    return DFS::isConnected_ByDFS(g);}

string Algorithms::isContainsCycle(ariel::Graph& g) {
    string ans;
    if (g.getType() == NegativeWeight) {ans=Belman_Ford::DetectCycle(g);}
    else{
         ans=DFS::is_Cyclic(g);
        }
    return ans;    
}

string Algorithms::shortestPath(ariel::Graph& g, int start, int end) {
    string ans;
    string cycle;
    /*
    switch(g.getType()){
        case NoneWeight:
            cycle=isContainsCycle(g);
            if(cycle=="no cycle detected."){
            ans=BFS::BFS_init(start, end, g);
            }else ans=Dijkstra::Initiate(start, end, g);
            break;     
        case Weight:
            ans=Dijkstra::Initiate(start, end, g);
            break;
        case NegativeWeight:
            ans=Belman_Ford::PrintPath(start,end,g);
            break;
        default:
            break;}
            */
        return ans;    
        }

string Algorithms::isBipartite(ariel::Graph& g) {
    return Bipartite::is_Bip(g,0);}
