//给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。 
//
// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0]
//输出：[[],[0]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10 
// -10 <= nums[i] <= 10 
// nums 中的所有元素 互不相同 
// 
// Related Topics 位运算 数组 回溯算法 
// 👍 1051 👎 0

/**
 *   @Author: muzhikid
 *   @CreatedTime: 2021-03-15 14:58:24
 *   @FinishedTime:
 *   @Remarks:
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>


using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> >ans;
        //[0,2^(l)-1]
        ans.push_back(vector<int>{});
        for(int i =1;i<pow(2,nums.size());i++){
            int temp = i;
            int j =0;
            vector<int>singleRow;
            while (temp!=0){
                if(temp%2){
                    singleRow.push_back(nums[j]);
                }
                temp/=2;
                j++;
            }
            ans.push_back(singleRow);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


//input
void input(){
    string path="";
    ifstream f;
    
    if(f.is_open()){
        //TODO
        
    }else{
        cerr<<"File opened fail"<<endl;
    }
    
}
int main(){
    Solution s;
    //s.method(params*);
    //cout<<s.method(params*);
    
}