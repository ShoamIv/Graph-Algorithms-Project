#include "Linear_Algebra.hpp"


std::vector<std::vector<int>> Linear_Algebra::Addition(const std::vector<std::vector<int>> &a,const std::vector<std::vector<int>> &b)
{
    std::vector<std::vector<int>> ans(a.size(), std::vector<int>(a.size()));
     for(int row=0; row<a.size(); row++){
            for(int col=0; col<a.size(); col++){
                if(row==col) ans[row][col]=0;else
                ans[row][col]=a[row][col]+b[row][col];
            }
    }

    return ans;
}

std::vector<std::vector<int>> Linear_Algebra::Subtraction(const std::vector<std::vector<int>> &a,const std::vector<std::vector<int>> &b){
        std::vector<std::vector<int>> ans(a.size(), std::vector<int>(a.size()));
            for(int row=0; row<a.size(); row++){
            for(int col=0; col<a.size(); col++){
                ans[row][col]=a[row][col]-b[row][col];
            }
    }
    return ans;
}

std::vector<std::vector<int>> Linear_Algebra::Multiply(const std::vector<std::vector<int>> &a,const std::vector<std::vector<int>> &b)
{
    std::vector<std::vector<int>> ans(a.size(), std::vector<int>(a.size())); 
        for(int row=0; row<a.size(); row++){
            for(int col=0; col<a.size(); col++){
                 for (int k = 0; k < a.size(); k++){
                 if(col==row) ans[row][col]=0;else
                  ans[row][col] += a[row][k]*b[k][col];
                 }
            }
     }
    return ans;
}