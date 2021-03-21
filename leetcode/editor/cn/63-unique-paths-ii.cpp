//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。 
//
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。 
//
// 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？ 
//
// 
//
// 网格中的障碍物和空位置分别用 1 和 0 来表示。 
//
// 说明：m 和 n 的值均不超过 100。 
//
// 示例 1: 
//
// 输入:
//[
//  [0,0,0],
//  [0,1,0],
//  [0,0,0]
//]
//输出: 2
//解释:
//3x3 网格的正中间有一个障碍物。
//从左上角到右下角一共有 2 条不同的路径：
//1. 向右 -> 向右 -> 向下 -> 向下
//2. 向下 -> 向下 -> 向右 -> 向右
// 
// Related Topics 数组 动态规划 
// 👍 408 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-09-11 10:02:06
*/
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        int dp[row][col];
        dp[0][0]=1;
        if(row ==1 and col ==1 and obstacleGrid[0][0]==1){
            return 0;
        }
        for(int i=0;i<row;i++){
            for(int j =0;j<col;j++){

                if(i == 0 and j == 0){
                    ;
                }else if(obstacleGrid[i][j]){
                    dp[i][j]=0;
                }
                else if(i == 0 and obstacleGrid[i][j-1]){
                    dp[i][j]=0;
                }else if(i==0 and !obstacleGrid[i][j-1]){
                    dp[i][j] = dp[i][j-1];
                }else if(j == 0 and obstacleGrid[i-1][j]){
                    dp[i][j]=0;
                }else if(j == 0 and !obstacleGrid[i-1][j]){
                    dp[i][j] = dp[i-1][j];
                }else if (i and j and obstacleGrid[i-1][j] and !obstacleGrid[i][j-1]){
                    dp[i][j]=dp[i][j-1];
                }else if(i and j and !obstacleGrid[i-1][j] and obstacleGrid[i][j-1]){
                    dp[i][j] = dp[i-1][j];
                }else if(i and j and !obstacleGrid[i-1][j] and !obstacleGrid[i][j-1]){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }else{
                    dp[i][j]=0;
                }
            }
        }
        return dp[row-1][col-1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    vector<vector<int> >test;
    vector<int>temp;
    temp.push_back(0);
    temp.push_back(1);
    test.push_back(temp);
    s.uniquePathsWithObstacles(test);
    //s.method(params*);
    //cout<<s.method(params*);
    
}