//给定一个非负整数数组，你最初位于数组的第一个位置。 
//
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。 
//
// 你的目标是使用最少的跳跃次数到达数组的最后一个位置。 
//
// 示例: 
//
// 输入: [2,3,1,1,4]
//输出: 2
//解释: 跳到最后一个位置的最小跳跃数是 2。
//     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
// 
//
// 说明: 
//
// 假设你总是可以到达数组的最后一个位置。 
// Related Topics 贪心算法 数组 
// 👍 755 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-11-22 11:28:54
*   @FinishedTime:2020年11月22日15:03:56
*   @Remarks:思路① 转换为图最短路径问题 ；*错误！ n^2复杂度会导致超时。**题解说，如果用Java实现不会超时...
 *           思路② 查看题解后发现原始思路,单纯的贪心即可（这种方法在跳跃游戏(55)中会出错，不知道为什么在这里可以使用并正确）2020年11月22日14:44:59
 *           对思路②的补充：贪心策略为当前步数+下一步到达的步数 的最大者。之前的贪心策略有问题（只考虑了下一步到达的步数）。
 *           执行耗时:24 ms,击败了49.20% 的C++用户
			 内存消耗:15.6 MB,击败了15.54% 的C++用户
*/
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
void input(vector<int> &pVector);
//leetcode submit region begin(Prohibit modification and deletion)

class Solution {
public:

    int jump(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        int cnt = 0;
        for(int i =0;i<nums.size();i++){
            int steps = nums[i];
            int maxStep = 0;
            int record = 0;
            for(int j = 1;j<=steps and i+j <nums.size();j++){
                if(i+j>=nums.size()-1){
                    cnt++;
                    goto END;
                }
                if(j+nums[i+j]>=maxStep){
                    maxStep = nums[i+j]+j;
                    record = i+j;
                }

            }
            cnt++;
            i = record-1;

        }
        END:
        return cnt;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    vector<int>nums;
    input(nums);
    int ans = s.jump(nums);
    cout<<ans<<endl;
    //s.method(params*);
    //cout<<s.method(params*);
}
void input(vector<int> &pVector) {
    string s;

    while (cin>>s and s!="#"){
        pVector.emplace_back(stoi(s));
    }
}