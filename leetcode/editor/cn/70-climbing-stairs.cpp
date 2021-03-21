//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。 
//
// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？ 
//
// 注意：给定 n 是一个正整数。 
//
// 示例 1： 
//
// 输入： 2
//输出： 2
//解释： 有两种方法可以爬到楼顶。
//1.  1 阶 + 1 阶
//2.  2 阶 
//
// 示例 2： 
//
// 输入： 3
//输出： 3
//解释： 有三种方法可以爬到楼顶。
//1.  1 阶 + 1 阶 + 1 阶
//2.  1 阶 + 2 阶
//3.  2 阶 + 1 阶
// 
// Related Topics 动态规划 
// 👍 1217 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-09-05 21:21:24
*/
#include <iostream>
#include <vector>


using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    const static int maxN = 1000001;

    int climbStairs(int n) {
        int pre2 = 1;
        int pre1 = 1;
        int cur = 0;
        if(n<2)
            return 1;
        for(int i = 2;i<=n;i++){
           cur = pre1+pre2;
           pre2= pre1;
           pre1 = cur;
        }
        return cur;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    //s.method(params*);
    //cout<<s.method(params*);
    
}