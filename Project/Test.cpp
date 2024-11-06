/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <string>
#include <sstream>
using namespace std;

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;

    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
        ariel::Graph exp;
        exp.loadGraph(expectedGraph);
    CHECK(g3.printGraph() == exp.printGraph());
    ariel::Graph g4=g3+g1;
    vector<vector<int>> expectedGraph2 = {
        {0, 3, 1},
        {3, 0, 4},
        {1, 4, 0}};
        ariel::Graph exp2;
    exp2.loadGraph(expectedGraph2);

      vector<vector<int>> expectedGraph3 = {
        {0, 5, 2},
        {5, 0, 7},
        {2, 7, 0}};
        ariel::Graph exp3;
    exp3.loadGraph(expectedGraph3);
    CHECK(g4.printGraph() == exp2.printGraph());
    g4+=g3;
    CHECK(g4.printGraph() == exp3.printGraph());
}

TEST_CASE("Test graph subtraction")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 - g2;
    vector<vector<int>> expectedGraph = {
        {0,0,-1},
        {0,0,-1},
        {-1,-1,0}};
    ariel::Graph exp;
    exp.loadGraph(expectedGraph);
    CHECK(g3.printGraph() == exp.printGraph());
    
    ariel::Graph g4=g3-g1;
    vector<vector<int>> expectedGraph2 = {
        {0, -1, -1},
        {-1, 0, -2},
        {-1, -2, 0}};
        ariel::Graph exp2;
        exp2.loadGraph(expectedGraph2);

         vector<vector<int>> expectedGraph3 = {
        {0, -2, -1},
        {-2, 0, -3},
        {-1, -3, 0}};
        ariel::Graph exp3;
        exp3.loadGraph(expectedGraph3);

    CHECK(g4.printGraph() == exp2.printGraph());
    g4-=g1;
    CHECK(g4.printGraph() == exp3.printGraph());
}

  
TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    ariel::Graph g5= g4*g2;
    ariel::Graph g6= g5*g4;
    vector<vector<int>> expectedGraph = {
        {0, 0, 2},
        {1, 0, 1},  
        {1, 0, 0}};
    ariel:: Graph exp; exp.loadGraph(expectedGraph);
     
    vector<vector<int>> expectedGraph2 = {
        {0, 4, 0},
        {1, 0, 1},  
        {0,1, 0}};  
    ariel:: Graph exp2; exp2.loadGraph(expectedGraph2); 

    vector<vector<int>> expectedGraph3 = {
        {0, 0, 4},
        {1, 0, 2},  
        {1, 0, 0}};
        
    ariel:: Graph exp3; exp3.loadGraph(expectedGraph3); 

    
    vector<vector<int>> expectedGraph4 = {
        {0, 100, 0},
        {100, 0, 100},  
        {0, 100, 0}};
        
    ariel:: Graph exp4; exp4.loadGraph(expectedGraph4);
    
    vector<vector<int>> expectedGraph5 = {
        {0, 50, 0},
        {50, 0, 50},  
        {0, 50, 0}};
        
    ariel:: Graph exp5; exp5.loadGraph(expectedGraph5);

    CHECK(g4.printGraph() == exp.printGraph());
    CHECK(g4.printGraph() == "[0,0,2]\n[1,0,1]\n[1,0,0]\n");
    CHECK(g5.printGraph() == exp2.printGraph());
    CHECK(g6.printGraph() == exp3.printGraph());

    g1*=100;
    CHECK(g1.printGraph() == exp4.printGraph());
    g1/=2;
    CHECK(g1.printGraph() == exp5.printGraph());
}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g5 + g1);
    CHECK_THROWS(g5 - g1);
    CHECK_THROWS(g5 += g1);
    CHECK_THROWS(g5 -= g1);
    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}
TEST_CASE("Test graph opeartors")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    
    CHECK(g2>g1);
    CHECK(g2>=g1);
    CHECK(g1<g2);
    CHECK(g1<=g2);
    CHECK_FALSE(g1>g2);
    g1++;
    CHECK(g1.printGraph() == "[0,2,0]\n[2,0,2]\n[0,2,0]\n");
    g1--;
    CHECK(g1.printGraph() == "[0,1,0]\n[1,0,1]\n[0,1,0]\n");
    CHECK(g1!=g2);
    ariel::Graph g3=g1+g2;
    CHECK(g2==g3);
    CHECK_FALSE(g3==g1);
    -g1;
    CHECK(g1.printGraph() == "[0,-1,0]\n[-1,0,-1]\n[0,-1,0]\n");
    +g1;
    CHECK(g1.printGraph() == "[0,-1,0]\n[-1,0,-1]\n[0,-1,0]\n");
    ostringstream os; os<<g1;
    string exp="Number of Vertices: "+to_string(g1.num_ver);
    exp+="\nNumber of Edges: "+to_string(g1.edge_list.size());
    exp+="\nNegative Weighted Graph";
    CHECK(os.str() == exp);
    -g1;
    string exp2="Number of Vertices: "+to_string(g1.num_ver);
    exp2+="\nNumber of Edges: "+to_string(g1.edge_list.size());
    exp2+="\nNonWeighted Graph";
    ostringstream os2; os2<<g1;
    CHECK(os2.str() == exp2);
}    
