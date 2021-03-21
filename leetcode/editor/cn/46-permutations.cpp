//给定一个 没有重复 数字的序列，返回其所有可能的全排列。 
//
// 示例: 
//
// 输入: [1,2,3]
//输出:
//[
//  [1,2,3],
//  [1,3,2],
//  [2,1,3],
//  [2,3,1],
//  [3,1,2],
//  [3,2,1]
//] 
// Related Topics 回溯算法 
// 👍 854 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-08-26 11:20:49
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
    vector<vector<int> >ansSet;
    bool visited[101];         //没有说明最多个数
    void dfs(int start,vector<int> &temp,vector<int>&nums){

        visited[start]=true;
        temp.push_back(nums[start]);
        if(temp.size()==nums.size()){
            ansSet.push_back(temp);
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
    vector<vector<int>> permute(vector<int>& nums) {
        init();
        for(int i =0;i<nums.size();i++){
            vector<int>temp;

            dfs(i,temp,nums);
        }
        return ansSet;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    vector<int>test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    s.permute(test);
    //s.method(params*);
    //cout<<s.method(params*);
    
}