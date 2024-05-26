/*
id:206698359    mail:shoamivgi1234@gmail.com
*/

#include <iostream>
#include "Belman_Ford.hpp"
#include "Traverse.hpp"
#include <vector>
using namespace std;

bool Belman_Ford::neg_cycle = true;



string Belman_Ford::DetectCycle(ariel::Graph &g) {
    int currsize=g.graph.size();
    std::vector<int>d(currsize);std::vector<int>p(currsize);std::vector<int>color(currsize);
    vector<vector<int>> matrix (currsize,vector<int>(currsize));
    for(int i=0; i<g.num_ver; i++){
        for(int j=0; j<g.num_ver; j++){
            matrix[i][j]=g.graph[i][j];
        }
    }
    for(int i=0;i<currsize; i++){
        matrix[currsize-1][i]=1000;
        }
     g.loadGraph(matrix);
    for (size_t v=0; v<currsize; v++) {
        d[v] = 1000000;
        p[v] = -1;
    }
    d[currsize] = 0;
    for (size_t E = 0; E < currsize-1; E++) {
        for (auto &edge : g.edge_list) {
            if(d[edge.dest]>d[edge.source]+ edge.weight) {
                d[edge.dest] = d[edge.source] + edge.weight;
                p[edge.dest] = edge.source;
            }
        }
    }
    std:: vector<int>Neg_Cycle;
    for(auto &edge : g.edge_list)
    {
        if (d[edge.dest] > d[edge.source] + edge.weight) {
            int curr = edge.dest;
            for (int i = 0; i < currsize; i++) {
                color[i] = Traverse::WHITE;
            }
            while (color[curr] != Traverse::BLACK) {
                Neg_Cycle.push_back(curr);
                if (color[curr] == Traverse::GRAY) color[curr] = Traverse::BLACK;
                else color[curr] = Traverse::GRAY;
                curr = p[curr];
            }
        }
        break;
    }
    string cycle;
    if(Neg_Cycle.empty()){
        neg_cycle=false;
        cycle="No Cycle Detected.";
    }
        else{
            neg_cycle=true;
            int count=0;
            int marker=Neg_Cycle.at(Neg_Cycle.size()-1);
        for(int i=(int)Neg_Cycle.size()-1; i>=0; i--){
                    if(count==2)break;
                    if(Neg_Cycle.at(i)==marker)count++;
                    cycle+=to_string(Neg_Cycle.at(i))+"->";
        }
        cycle=cycle.substr(0,cycle.size()-2);
    }
        return cycle;
}




bool Belman_Ford::BF_ShortestPath(ariel::Graph &g,int start,vector<int>&d,vector<int>&p) {
    int flag= false;
    for (int v=0; v<g.num_ver; v++) {
        d[v] = 1000000;
        p[v] = -1;
    }
    d[start] = 0;
    for (int E = 0; E < g.num_ver - 1; E++) {
        for (auto &edge : g.edge_list) {
            if(d[edge.dest]>d[edge.source]+ edge.weight) {
                d[edge.dest] = d[edge.source] + edge.weight;
                p[edge.dest] = edge.source;
            }
        }
    }
    for(auto &edge : g.edge_list){
        if (d[edge.dest] > d[edge.source] + edge.weight) {
                flag=true; break;
            }
        }
    return flag;
}

string Belman_Ford::PrintPath(int a, int b, ariel::Graph &g) {
    vector<int>d(g.num_ver);vector<int>p(g.num_ver);
    neg_cycle= BF_ShortestPath(g,a,d,p);
    string ans1;
    if(neg_cycle){
        return "-1";
    }
    vector<int>ans;
    while(b!=a){
        ans.push_back(p[b]);
        b=p[b];
    }
    for(int an : ans){
        ans1+=p[b];
        ans1+="->";
    }
    return ans1;
}

