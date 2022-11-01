#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int minPathSum(vector<vector<int>>& nums){
    int rows=nums.size();
    int cols=nums[0].size();
    if(rows==0) return 0;
    vector<vector<int>>dp(rows,vector<int>(cols,0));
    dp[0][0]=nums[0][0];
    for(int i=1;i<rows;i++) dp[i][0]=dp[i-1][0]+nums[i][0];
    for(int j=1;j<cols;j++) dp[0][j]=dp[0][j-1]+nums[0][j];
    for(int i=1;i<rows;i++){
        for(int j=1;j<cols;j++) dp[i][j]=nums[i][j]+min(dp[i-1][j],dp[i][j-1]);
    }
    return dp[rows-1][cols-1];
}
int main(){
    vector<vector<int>>nums={
        {1,2,3},
        {4,5,6},
        {7,8,9}       
    };
    cout<<minPathSum(nums);
    return 0;
}