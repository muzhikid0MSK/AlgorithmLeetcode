//在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。 
//
// 示例: 
//
// 输入: 
//
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//
//输出: 4 
// Related Topics 动态规划 
// 👍 542 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-09-09 09:18:22
*/
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int dp[row][col];
        for(int i=0;i<row;i++){
            for(int j =0;j<col;j++){
                if(matrix[i][j]=='0'){
                    dp[i][j]=0;
                }else{
                    if(i==0 or j == 0){
                        dp[i][j]=1;
                    }else{
                        dp[i][j]= min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                    }
                }
            }
        }
        int curMax = 0;
        for(int i =0;i<row;i++){
            for(int j =0;j<col;j++){
                if(dp[i][j]>curMax)
                    curMax = dp[i][j];
            }
        }
        return curMax*curMax;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    //s.method(params*);
    //cout<<s.method(params*);
    
}