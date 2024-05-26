/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#include "Bipartite.hpp"

string Bipartite::is_Bip(ariel::Graph &g, int vertex) {
    std::map<int,int>color;
    bool flag=true;
    string ans;
    for(int i=0; i<g.num_ver; i++){
        color[i]=Traverse::GRAY;
    }
        for (int i = 0; i < g.num_ver; i++) {
            if (color[i] == Traverse::GRAY) {
               flag=Biputil(g, i, color);
               if(!flag)break;
            }
    }
    if(!flag)ans="0";else{
        ans=Print_Bip(color);
    }
    return ans;
}

bool Bipartite::Biputil(ariel::Graph &g, int vertex,map<int,int>&color) {
    int bip_flag=1;
    for(int ver=0; ver<g.num_ver; ver++){
        color[ver]=Traverse::GRAY;
    }
    queue<int> q;
    color[vertex] = Traverse::WHITE;
    q.push(vertex);
    while (!q.empty()) {
        int u=q.front();
        vector<int> neighbors_list = g.graph[u]; // Assuming neighbors is now a vector
        q.pop();
        for (int adjacentVertex=0; adjacentVertex<neighbors_list.size(); adjacentVertex++) {
            if(adjacentVertex!=u && neighbors_list[adjacentVertex]!=0){
                if(color[adjacentVertex]==color[u]){
                    bip_flag=false;
                }
                if (color[adjacentVertex] == Traverse::GRAY && g.graph[u][adjacentVertex] != 0) {
                    if (color[u] == Traverse::WHITE) {
                        color[adjacentVertex] = Traverse::BLACK;
                    } else color[adjacentVertex] = Traverse::WHITE;
                    q.push(adjacentVertex);
            }
          }
        }
    }
    return bip_flag;
}

string Bipartite::Print_Bip(const map<int, int>& color) {
    std::vector<int>White_Team;
    std::vector<int>Black_Team;
    string ans;
    for (const auto& pair : color) {
        if(pair.second==Traverse::WHITE)
                White_Team.push_back(pair.first);
        else Black_Team.push_back(pair.first);
    }
    ans+="The graph is bipartite: A={";
    for(int i : White_Team) {
        ans+=to_string(i)+", ";
    }
    ans=ans.substr(0,ans.size()-2);
    ans+="}, B={";
    for(int i : Black_Team) {
         ans+=to_string(i)+", ";
        }
        ans=ans.substr(0,ans.size()-2);
        ans+="}";
        return ans;
    }


