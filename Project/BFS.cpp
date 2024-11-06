/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#include <iostream>
#include <queue>
#include "BFS.hpp"


string BFS::BFS_init(int source,int dest,ariel::Graph &g ) {
    std::vector<int>d(g.num_ver);std::vector<int>p(g.num_ver);std::vector<int>color(g.num_ver);
    BFS_SET(d,p,color);
    string ans;
    std::queue<int> q;
    color[source] = Traverse::GRAY;
    d[source] = 0;
    q.push(source);
    while (!q.empty()) {
        int u = q.front();
        std::vector<int>neighbors_list = g.graph[u]; // Assuming neighbors is now a vector
        q.pop();
        ans+=to_string(u) + "->";
        for (int adjacentVertex=0;adjacentVertex<neighbors_list.size(); adjacentVertex++) {
            if(g.graph[u][adjacentVertex]==0)continue;
            if (color[adjacentVertex] == Traverse::WHITE) {
                color[adjacentVertex] = Traverse::GRAY;
                d[adjacentVertex]= d[u]+1;
                p[adjacentVertex]= p[u];
                q.push(adjacentVertex);
            }
        }
        color[source]=Traverse::BLACK;
    }
    if(color[dest]==Traverse::WHITE) {
         ans="There is no path between " + to_string(source) + " and "+to_string(dest);
    }else {
         ans=ans.substr(0, ans.size() - 2);
    }
    return ans;
}



void BFS:: BFS_SET(vector<int>&d,vector<int>&p,vector<int>&color){
    for(int i=0; i<d.size();  i++){
        color[i]=Traverse::WHITE;
       d[i]=0;p[i]=-1;
    }
}

