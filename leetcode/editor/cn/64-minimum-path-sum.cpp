//给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。 
//
// 说明：每次只能向下或者向右移动一步。 
//
// 示例: 
//
// 输入:
//[
//  [1,3,1],
//  [1,5,1],
//  [4,2,1]
//]
//输出: 7
//解释: 因为路径 1→3→1→1→1 的总和最小。
// 
// Related Topics 数组 动态规划 
// 👍 656 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-09-06 12:51:24
*/
#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m =grid.size();
        int n = grid[0].size();
        int dp[m][n];
        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++){
                dp[i][j]=0;
            }
        }
        dp[0][0]=grid[0][0];
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(i == 0 and j>=1){
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                }else if(i >=1 and j==0){
                    dp[i][j] = dp[i-1][j]+grid[i][j];
                }else if(i >=1 and j >= 1){
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j];
                }else{
                    ;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    //s.method(params*);
    //cout<<s.method(params*);
    
}