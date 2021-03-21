//给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。 
//
// 示例 1: 
//
// 输入: 2
//输出: [0,1,1] 
//
// 示例 2: 
//
// 输入: 5
//输出: [0,1,1,2,1,2] 
//
// 进阶: 
//
// 
// 给出时间复杂度为O(n*sizeof(integer))的解答非常容易。但你可以在线性时间O(n)内用一趟扫描做到吗？ 
// 要求算法的空间复杂度为O(n)。 
// 你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount）来执行此操作。 
// 
// Related Topics 位运算 动态规划 
// 👍 450 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-11-22 16:07:16
*   @FinishedTime:
*   @Remarks:
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
    vector<int> countBits(int num) {
        vector<int>ans;
        ans.emplace_back(0);
        ans.emplace_back(1);
        if(num==0){
            ans.pop_back();
            return ans;
        }else if(num==1){
            return ans;
        }else{
            for(int i =2;i<=num;i++){
                if(i%2==0){
                    ans.emplace_back(ans[i/2]);
                }else{
                    ans.emplace_back(ans[i/2]+1);
                }
            }
            return ans;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    //s.method(params*);
    //cout<<s.method(params*);
    
}