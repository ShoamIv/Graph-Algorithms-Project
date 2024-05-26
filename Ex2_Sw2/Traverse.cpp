/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#include <queue>
#include "Traverse.hpp"

void Traverse::relax(int a, int b, Graph &g,vector<int>&d,vector<int>&p) {
    if(d[b]>d[a]+ g.graph[a][b]){
        d[b]=d[a]+g.graph[a][b];
        p[b]=a;
    }
}
Graph Traverse::Transpose(Graph &g) {
    Graph t;
        vector<vector<int>>gt=vector<vector<int>>(g.num_ver, vector<int>(g.num_ver));
    for(int i=0; i<g.num_ver; i++){
        for(int j=0; j<g.num_ver; j++){
            gt[i][j]=g.graph[j][i];
        }
    }
    t.loadGraph(gt);
    return t;
}

