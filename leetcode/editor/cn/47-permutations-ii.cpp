//给定一个可包含重复数字的序列，返回所有不重复的全排列。 
//
// 示例: 
//
// 输入: [1,1,2]
//输出:
//[
//  [1,1,2],
//  [1,2,1],
//  [2,1,1]
//] 
// Related Topics 回溯算法 
// 👍 381 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-08-27 11:52:17
*/
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    set<vector<int> >ansSet;
    vector<vector<int> >ans;
    bool visited[101];         //没有说明最多个数
    void dfs(int start,vector<int> &temp,vector<int>&nums){
        visited[start]=true;
        temp.push_back(nums[start]);
        if(temp.size()==nums.size()){
            ansSet.insert(temp);
            visited[start]= false;
            return;
        }
        for(int i =0;i<nums.size();i++){
            vector<int>temp_i = temp;
            if(!visited[i]){
                dfs(i,temp_i,nums);
            }

        }
        visited[start]= false;

    }
    void init(){
        for(int i =0;i<101;i++){
            visited[i]= false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        init();
        for(int i =0;i<nums.size();i++){
            vector<int>temp;
            dfs(i,temp,nums);
        }
        for(auto &i:ansSet){
            ans.push_back(i);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    //s.method(params*);
    //cout<<s.method(params*);
    
}