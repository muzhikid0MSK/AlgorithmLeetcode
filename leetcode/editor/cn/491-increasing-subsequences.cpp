//给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。 
//
// 示例: 
//
// 
//输入: [4, 6, 7, 7]
//输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7
//]] 
//
// 说明: 
//
// 
// 给定数组的长度不会超过15。 
// 数组中的整数范围是 [-100,100]。 
// 给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。 
// 
// Related Topics 深度优先搜索 
// 👍 173 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-08-25 20:39:19
*/
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    set<vector<int> > ansSet ;
    vector<vector<int> >ans;
    bool visited[15];
    void init(){
        for (int i = 0; i < 15; ++i) {
            visited[i]= false;
        }
    }
    void dfs(int depth,vector<int>& nums,vector<int>& temp){
        if(depth==nums.size())
            return;

        visited[depth] = true;
        if(temp.empty()||nums[depth]>=temp.back()){
            temp.push_back(nums[depth]);
            if(temp.size()>=2){
                ansSet.insert(temp);
            }

        }

        for(int i =depth+1;i<nums.size();i++){
            vector<int>temp_i;
            temp_i = temp;
            if(!visited[i]){
                dfs(i,nums,temp_i);
                visited[i]= false;
            }
        }
    }
    vector<vector<int> > findSubsequences(vector<int>& nums) {

        init();
        for(int i =0;i<nums.size();i++){
            vector<int>temp;
            dfs(i,nums,temp);
        }

        for(const auto & i : ansSet){
            ans.push_back(i);

        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    vector<int>test;
    test.push_back(4);
    test.push_back(6);
    test.push_back(7);
    test.push_back(7);
    s.findSubsequences(test);
    //s.method(params*);
    //cout<<s.method(params*);
    
}