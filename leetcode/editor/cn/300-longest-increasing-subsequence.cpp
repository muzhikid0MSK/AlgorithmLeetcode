//给定一个无序的整数数组，找到其中最长上升子序列的长度。 
//
// 示例: 
//
// 输入: [10,9,2,5,3,7,101,18]
//输出: 4 
//解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。 
//
// 说明: 
//
// 
// 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。 
// 你算法的时间复杂度应该为 O(n2) 。 
// 
//
// 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗? 
// Related Topics 二分查找 动态规划 
// 👍 1083 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-10-16 14:28:54
*/
#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
//        vector<int>dp;
//        for(int i =0;i<nums.size();i++){
//            if(dp.empty() or dp.back()<nums[i]){
//                dp.emplace_back(nums[i]);
//            }else if(dp.back()>=nums[i]){
//                *lower_bound(dp.begin(),dp.end(),nums[i])=nums[i];
//            }
//        }
        if(nums.empty())
            return 0;
        vector<int>S(nums.size(),0);
        vector<int>L(nums.size(),1);

        for(int i =1;i<nums.size();i++){
            int curMax = 0;
            int record = -1;
            for(int j = 0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(curMax<L[j]+1){
                        curMax = L[j]+1;
                        record = j;
                    }
                }
            }
            L[i]= max(curMax,1);
            if(record==-1){
                S[i]=i;
            }else{
                S[i]=record;
            }


        }
        int index = 0;
        //int recordMax = 0;
        for(int i =0;i<L.size();i++){
            if(L[index]<L[i]){
                index = i;
            }
        }
        stack<int>ans;
        while (index!=S[index]){
            ans.push(nums[index]);
            index = S[index];
        }
        ans.push(index);
        while (!ans.empty()){
            cout<<ans.top()<<' ';
            ans.pop();
        }

        cout<<endl;
        return *max_element(L.begin(),L.end());
    }
};
//leetcode submit region end(Prohibit modification and deletion)
vector<int>test;
void b(int a){
    test.emplace_back(a);
}
int main(){
    Solution s;
    b(10);
    b(9);
    b(2);
    b(5);
    b(3);
    b(7);
    b(101);
    b(18);

    cout<<s.lengthOfLIS(test);
    //s.method(params*);
    //cout<<s.method(params*);
    
}