//给定一个非负整数数组，你最初位于数组的第一个位置。 
//
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。 
//
// 判断你是否能够到达最后一个位置。 
//
// 示例 1: 
//
// 输入: [2,3,1,1,4]
//输出: true
//解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
// 
//
// 示例 2: 
//
// 输入: [3,2,1,0,4]
//输出: false
//解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
// 
// Related Topics 贪心算法 数组 
// 👍 934 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-11-22 10:10:12
*   @FinishedTime:2020年11月22日11:30:27
*   @Remarks:执行耗时:16 ms,击败了97.93% 的C++用户 内存消耗:13 MB,击败了17.41% 的C++用户
*/
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()<=1)
            return true;
        int cur = nums.size()-1-1;  //终点之前的点。
        int dest = nums.size()-1;
        while (cur!=0){
            if(cur+nums[cur]>=dest){//当前点可以到达dest
                bool flag = false;
                for(int i =cur-1;i>=0;i--){
                    if(nums[i]+i>=cur){ //可以由其他点到达cur
                        dest = cur;
                        cur = i;
                        flag = true;
                        break;
                    }
                }
                if(!flag){  //放弃cur
                    cur--;
                }
            }else{
                cur --;
            }
        }
        if(cur+nums[cur]>=dest)
            return true;
        else
            return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

void input(vector<int> &pVector);

int main(){
    Solution s;
    vector<int>nums;
    input(nums);
    s.canJump(nums);
    //s.method(params*);
    //cout<<s.method(params*);
    
}

void input(vector<int> &pVector) {
    string s;

    while (cin>>s and s!="#"){
        pVector.emplace_back(stoi(s));
    }
}
