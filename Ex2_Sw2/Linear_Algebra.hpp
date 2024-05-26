#ifndef EX1_SW2_ALGORITHMS_HPP
#define EX1_SW2_ALGORITHMS_HPP
#include "Graph.hpp"
using namespace std;

class Linear_Algebra{
public:
    static vector<vector<int>> Addition(const vector<vector<int>> &a,const vector<vector<int>>&b);
    static vector<vector<int>> Subtraction(const vector<vector<int>> &a,const vector<vector<int>>&b);
    static vector<vector<int>> Multiply(const vector<vector<int>> &a,const vector<vector<int>>&b);


};
#endif