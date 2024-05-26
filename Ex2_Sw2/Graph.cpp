/*
id:206698359    mail:shoamivgi1234@gmail.com
*/

#include "Graph.hpp"
#include <iostream>

using namespace ariel;
using namespace std;

void ariel::Graph::Valid(const Graph &a, const Graph &b)
{
     if (a.graph.size() != b.graph.size()) {
        throw std::invalid_argument("The two graphs have different sizes.");
    }
}

Graph::Graph() = default;

void Graph::loadGraph(vector<vector<int>> graph_matrix) {
    clear();
    vector<int> vect;
    bool flag=true;
     if (graph_matrix.size() != graph_matrix[0].size()) {
        throw std::invalid_argument("Invalid graph: The graph is not a square matrix");
    }
    if(flag) {
        this-> graph =graph_matrix;
        this-> num_ver=(int)graph.size();
        this->directed=true;
        this->edge_list=std::vector<Edge>();
        Classified();
    }
}

string Graph::printGraph() {
    string ans;
    int count_edges=0;
    for(size_t i=0; i<graph[0].size(); i++){
        ans+="[";
        for(size_t j=0; j<graph[0].size(); j++){
            int m=this->graph[i][j];
            if(j!=graph.size()-1){
                ans+=to_string(m)+",";}else
                ans+=to_string(m)+"]\n";
        }
    }
    return ans;
}


void Graph::Classified() {
    Type=0;
    for(int src=0; src<this->num_ver; src++){
        for(int dest=0; dest<this->num_ver; dest++) {
            if (this->graph[src][dest] != this->graph[dest][src])this->directed = false;
            if (this->graph[src][dest] != 0)
                this->edge_list.push_back({src,dest,this->graph[src][dest]});
            if(Type!=2) {
                if (graph[src][dest] > 1) Type = 1;  // Weighted
                if (graph[src][dest] < 0) Type = 2;         //NegativeWeighted
                }
            }
        }
    }
void Graph::clear() {
    graph.clear();
    num_ver = 0;
    edge_list.clear();
    Type = 0;

}

int Graph::getType()  {
    return this->Type;
}

bool Graph::getDirected()  {
    return this->directed;
}

Graph ariel::Graph::operator+=( Graph &b)
{
   Valid(*this,b);
    vector<std::vector<int>> m = Linear_Algebra::Addition(this->graph,b.graph);
    this->loadGraph(m);
    return *this;
}

Graph ariel::Graph::operator*( Graph &b)
{
    Valid(*this,b);
    vector<std::vector<int>> m = Linear_Algebra::Multiply(this->graph, b.graph);
    Graph resultGraph;
    resultGraph.loadGraph(m);
    return resultGraph;
}

Graph ariel::Graph::operator-( Graph &b)
{
    Valid(*this,b);
    vector<std::vector<int>> m = Linear_Algebra::Subtraction(this->graph,b.graph);
    Graph resultGraph;
    resultGraph.loadGraph(m);
    return resultGraph;
}

Graph ariel::Graph::operator-()
{
    (*this)*=-1;
    return *this;
}

Graph ariel::Graph::operator-=( Graph &b)
{
    Valid(*this,b);
    vector<std::vector<int>> m = Linear_Algebra::Subtraction(this->graph,b.graph);
    this->loadGraph(m);
    return *this;
}

bool ariel::Graph::operator==( Graph &b)
{
    return (!(*this>b) && !(b>*this));
}

bool ariel::Graph::operator>(Graph &b)
{
 bool flag=true;
    int min=int(std::min(this->graph.size(),b.graph.size()));
    for(size_t i=0; i<min;i++){
        for(size_t j=0; j<min;j++){
        if(b.graph[i][j]!=this->graph[i][j])flag=false;
        } 
    }
    if(flag)return true;
    if(this->edge_list.size()>b.edge_list.size())return true;
    if(this->num_ver>b.num_ver)return true;else return false;
}

bool ariel::Graph::operator>=( Graph &b)
{
    if(*this>b)return true;else return (*this==b);
}

bool ariel::Graph::operator<( Graph &b)
{
    return !(*this>b);
}

bool ariel::Graph::operator<=( Graph &b)
{
    if(*this<b) return true;else return *this==b;
}

bool ariel::Graph::operator!=( Graph &b)
{
    return this != &b;
}

Graph ariel::Graph::operator++()
{
    for(int i=0; i<this->edge_list.size(); i++){
        this->graph[this->edge_list.at(i).source][this->edge_list.at(i).dest]++;
    }
    this->loadGraph(this->graph);
    return *this;
}


Graph ariel::Graph::operator--()
{
    for(int i=0; i<this->edge_list.size(); i++){
        this->graph[this->edge_list.at(i).source][this->edge_list.at(i).dest]--;
    }
    this->loadGraph(this->graph);
    return *this;
}

Graph ariel::Graph::operator*=(int scalar){
    for(int i=0;i<this->edge_list.size(); i++){
        this->edge_list.at(i).weight*=scalar;
        this->graph[edge_list.at(i).source][edge_list.at(i).dest]=this->edge_list.at(i).weight;
    }
    this->loadGraph(this->graph);
    return *this;
}

Graph ariel::Graph::operator/=(int scalar){
    for(int i=0;i<this->edge_list.size(); i++){
        this->edge_list.at(i).weight/=scalar;
        this->graph[edge_list.at(i).source][edge_list.at(i).dest]=this->edge_list.at(i).weight;
    }
    this->loadGraph(this->graph);
    return *this;
}

namespace  ariel {
    std::ostream &operator<<(std::ostream &os, Graph &g) {
        string ty;
        if(g.getType()==2) ty="Negative Weighted Graph";
        else if(g.getType()==1) ty="Weighted Graph";else{
        ty="NonWeighted Graph";
        }
        os << "Number of Vertices: " << g.num_ver << std::endl;
        os << "Number of Edges: " << g.edge_list.size() << std::endl;
        os << ty;
        return os;
    }
}


Graph Graph::operator+( Graph &b)  {
      Valid(*this,b);
      vector<vector<int>>m=Linear_Algebra::Addition(this->graph,b.graph);
      Graph resultGraph;
      resultGraph.loadGraph(m); 
      return resultGraph;
}

Graph ariel::Graph::operator+()
{
    return *this;
}

void Graph::print_matrix() {
for(int i=0; i<this->num_ver; i++){
    for(int j=0; j<this->num_ver; j++){
        std::cout<<this->graph[i][j]<<"  ";
    }
    std::cout<<endl;
}
}

Graph Graph::operator++(int) {
    Graph copy = *this;
     ++(*this);
    this->loadGraph(this->graph);
    return copy;
}

Graph Graph::operator--(int) {
    Graph copy = *this;
    --(*this);
    this->loadGraph(this->graph);
    return copy;
}