//给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。 
//
// 示例 1: 
//
// 输入: 2
//输出: 1
//解释: 2 = 1 + 1, 1 × 1 = 1。 
//
// 示例 2: 
//
// 输入: 10
//输出: 36
//解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。 
//
// 说明: 你可以假设 n 不小于 2 且不大于 58。 
// Related Topics 数学 动态规划 
// 👍 366 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-09-06 16:54:00
*/
#include <iostream>
#include <cstring>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=dp[1]=0;
        dp[2]=1;
        for(int i = 2;i<=n;i++){
            int curMax = dp[i];
            for(int j=1;j<i;j++){
                curMax=max(dp[i-j]*j,max((i-j)*j,curMax));
            }
            dp[i]=curMax;
        }

        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    cout<<s.integerBreak(8);
    //s.method(params*);
    //cout<<s.method(params*);
    
}