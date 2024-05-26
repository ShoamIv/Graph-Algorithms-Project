/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#include <queue>
#include "Dijkstra.hpp"
#include "Traverse.hpp"

string Dijkstra::Initiate(int source, int dest,Graph& g) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    vector<int>d(g.num_ver);
    vector<int>p(g.num_ver);
    vector<int>color(g.num_ver);
    for(int v=0; v<g.num_ver; v++){
        d[v]= MAX;
        p[v]=-1;
        color[v]=Traverse::WHITE;
    }
    d[source]=0;
    pq.push(std::pair<int, int>(source, 0));
    while(!pq.empty()){
        int first=pq.top().first;
        color[first]=Traverse::GRAY;
        pq.pop();
        vector<int> neighbors_list = g.graph[first];
        for(int v=0; v<neighbors_list.size(); v++) {
                if(g.graph[first][v]==0)continue;
                Traverse::relax(first, v, g,d,p);
                if(color[v]==Traverse::WHITE){
                pq.push(make_pair(v, d[v]));
            }
        }
    }
    string ans;
    if(color[dest]==Traverse::WHITE){
         ans = "There is no path between " + to_string(source) + " and " + to_string(dest);
         }
    else{
        ans=PrintDijkstra(source,dest,g,p);
    }
    return ans;
  }

string Dijkstra::PrintDijkstra(int source, int target,ariel::Graph &g,vector<int>&p) {
    int v = target;
    vector<int> path;
    string ans;
    while (v != source || v>0) {
        path.push_back(v);
        v = p[v];
    }
        path.push_back(v);
        for (int i = (int) path.size() - 1; i >= 1; i--) {
            ans+=std::to_string(path[i]);
            ans+="->";
        }
        ans+=std::to_string(path[0]);
        return ans;
}


