//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。 
//
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。 
//
// 问总共有多少条不同的路径？ 
//
// 
//
// 例如，上图是一个7 x 3 的网格。有多少可能的路径？ 
//
// 
//
// 示例 1: 
//
// 输入: m = 3, n = 2
//输出: 3
//解释:
//从左上角开始，总共有 3 条路径可以到达右下角。
//1. 向右 -> 向右 -> 向下
//2. 向右 -> 向下 -> 向右
//3. 向下 -> 向右 -> 向右
// 
//
// 示例 2: 
//
// 输入: m = 7, n = 3
//输出: 28 
//
// 
//
// 提示： 
//
// 
// 1 <= m, n <= 100 
// 题目数据保证答案小于等于 2 * 10 ^ 9 
// 
// Related Topics 数组 动态规划 
// 👍 675 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-09-11 09:41:53
*/
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int row = n,col = m;
        int dp[row][col];
        //long long ans =0;
        dp[0][0] = 1;
        for(int i =0;i<row;i++){
            for(int j =0;j<col;j++){
                if(i == 0 and j ==0 ){
                    ;
                }else if(i==0){

                    dp[i][j]=dp[i][j-1];
                   // printf("---debug---\n");
                   // printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
                }else if(j==0){
                    dp[i][j]=dp[i-1][j];
                   // printf("---debug---\n");
                   // printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
                }else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                   // printf("---debug---\n");
                   // printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
                }
            }
        }
        return dp[row-1][col-1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    cout<<s.uniquePaths(3,2);
    //s.method(params*);
    //cout<<s.method(params*);
    
}