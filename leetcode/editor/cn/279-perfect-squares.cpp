//给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。 
//
// 示例 1: 
//
// 输入: n = 12
//输出: 3 
//解释: 12 = 4 + 4 + 4. 
//
// 示例 2: 
//
// 输入: n = 13
//输出: 2
//解释: 13 = 4 + 9. 
// Related Topics 广度优先搜索 数学 动态规划 
// 👍 581 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-09-06 20:32:13
*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int>dp;
    vector<int>squares;
    int determineIndex(int tbd,int len){
        for(int i =1;i<=len;i++){
            if(tbd<squares[i]){
                return i-1;
            }else if(tbd == squares[i]){
                return i;
            }
        }
        return len;
    }
    int getMin(int tempLen,int curIndex){
        int lastMin = INT32_MAX;
        for(int i =1; i<=tempLen;i++){
            lastMin = min(dp[curIndex - squares[i]],lastMin);
        }
        return lastMin+1;
    }
    int numSquares(int n) {
        dp.resize(n+1);
        dp[1] = 1;
        int base = sqrt(n);
        if(n == base*base)
            return 1;
        squares.resize(base+2);
        for(int i =1;i<=base+1;i++){
            squares[i]=i*i;
        }

        for(int i =2 ;i<=n;i++){
            int index = determineIndex(i,base+1);
            dp[i] = getMin(index,i);
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    cout<<s.numSquares(12);
    //s.method(params*);
    //cout<<s.method(params*);
    
}