//你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋
//装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。 
//
// 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。 
//
// 示例 1: 
//
// 输入: [2,3,2]
//输出: 3
//解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
// 
//
// 示例 2: 
//
// 输入: [1,2,3,1]
//输出: 4
//解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
//     偷窃到的最高金额 = 1 + 3 = 4 。 
// Related Topics 动态规划 
// 👍 368 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-09-11 10:44:39
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
    int robRange(vector<int>&nums,int start,int end){

        //int dp_i1 = nums[start+1];
        //int dp_i2 = nums[start];
        int dp[nums.size()];
        if(end-start==2){
            return max(nums[start+1],nums[start]);
        }

        //int dp_i = 0;
        dp[start] = nums[start];
        dp[start+1]=max(nums[start+1],dp[start]);
        for(int i =start+2;i<end;i++){
            dp[i]= max(dp[i-1],nums[i]+dp[i-2]);
        }
        return *max_element(dp+start,dp+end);
    }
    int rob(vector<int>& nums) {
        //vector<int>dp;
        if(nums.empty()){
            return 0;
        }
        if(nums.size() == 1){
            return nums[0];
        }else if(nums.size() == 2){
            return max(nums[0],nums[1]);
        }else{
            return max(robRange(nums,0,nums.size()-1),robRange(nums,1,nums.size()));
        }
        //dp.resize(nums.size());
    }
};
//leetcode submit region end(Prohibit modification and deletion)

void inputTestData(vector<int> &nums ){
    int num;
    while (cin>>num){nums.push_back(num);}
}
int main(){
    Solution s;
    vector<int>nums;
    inputTestData(nums);
    cout<<s.rob(nums);
    //s.method(params*);
    //cout<<s.method(params*);
    
}