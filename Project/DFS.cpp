/*
id:206698359    mail:shoamivgi1234@gmail.com
*/

#include "DFS.hpp"

void DFS::DFS_Visit(ariel::Graph &g, std::vector<int> &p, std::vector<int> &color) {
    Set_DFS(p,color);
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int top=q.front(); q.pop();
        color[top] = Traverse::GRAY;
        vector<int> neighbors_list = g.graph[top]; // Assuming neighbors is now a vector
        for (int adjacentVertex=0; adjacentVertex<neighbors_list.size(); adjacentVertex++) {
          if(neighbors_list.at(adjacentVertex)==0) continue;
            if (color[adjacentVertex] == Traverse::WHITE) {
                p[adjacentVertex] = top;
                q.push(adjacentVertex);
            }
        }
        color[top] = Traverse::BLACK;
    }
}

string DFS::is_Cyclic(ariel::Graph &g) {
    bool FLAG = false;
    vector<int>cycle_vec;
    vector<int>color(g.num_ver);
    vector<int>p(g.num_ver);
    for(int i=0;i<g.num_ver;++i){
        color[i] = 1;
            FLAG = Cycle_util(g,i,p,color,cycle_vec);
            if(FLAG) break;
    }
    string ans;
    if(!FLAG){ans="no cycle detected.";}else{
        ans=Rev_Cycle(cycle_vec);
    }
    return ans;
}
int DFS::isConnected_ByDFS(ariel::Graph &g) {
    vector<int>color(g.num_ver);
    vector<int>p(g.num_ver);
    int flag= 1;
    DFS_Visit(g, p, color);
    for(int i=0; i<g.num_ver; i++){
        if(color[i]== Traverse::WHITE) flag=0;}
    if(!g.getDirected()) return flag;
    Graph t= Traverse::Transpose(g);
    DFS_Visit(t, p, color);
    for(int i=0; i<g.num_ver; i++){
        if(color[i]== Traverse::WHITE) {
            flag=0; break;
        }
    }
    return flag;
}
string DFS::Rev_Cycle(vector<int>cycle) {
    string reverse_cycle;
for(int i=(int)cycle.size()-1; i>=1; i--){
    reverse_cycle+=to_string(cycle.at(i))+"->";
    }
    reverse_cycle+=to_string(cycle.at(0));
    return reverse_cycle;
}

bool DFS::Cycle_util(ariel::Graph &g,int vertex,vector<int>&p,vector<int>&color,vector<int>&cycle_vec){
    color[vertex] = Traverse::GRAY;
    for (int i = 0; i < g.num_ver; ++i) {
        if (g.graph[vertex][i] == 0) continue;
        if (color[i] == Traverse::GRAY && p[vertex] != i) {
            int curr = vertex;
            cycle_vec.push_back(i);
            while (curr != i) {
                cycle_vec.push_back(curr);
                curr = p[curr];
          }cycle_vec.push_back(curr);
            return true;
        }
        if (color[i] == Traverse::WHITE) {
            p[i] = vertex;
            if (Cycle_util(g,i,p,color,cycle_vec)) return true;
        }
    }
    color[vertex] = Traverse::BLACK;
    return false;
}

void DFS::Set_DFS(vector<int>p,vector<int>color) {
    for(int i=0; i<p.size(); i++){
        color[i]=Traverse::WHITE;
        p[i]=-1;
    }
}




