//给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。 
//
// candidates 中的数字可以无限制重复被选取。 
//
// 说明： 
//
// 
// 所有数字（包括 target）都是正整数。 
// 解集不能包含重复的组合。 
// 
//
// 示例 1： 
//
// 输入：candidates = [2,3,6,7], target = 7,
//所求解集为：
//[
//  [7],
//  [2,2,3]
//]
// 
//
// 示例 2： 
//
// 输入：candidates = [2,3,5], target = 8,
//所求解集为：
//[
//  [2,2,2,2],
//  [2,3,3],
//  [3,5]
//] 
//
// 
//
// 提示： 
//
// 
// 1 <= candidates.length <= 30 
// 1 <= candidates[i] <= 200 
// candidate 中的每个元素都是独一无二的。 
// 1 <= target <= 500 
// 
// Related Topics 数组 回溯算法 
// 👍 1185 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2021-03-01 23:14:51
*   @FinishedTime:
*   @Remarks:
*/
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>
#include <fstream>


using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int> >ans ;
    vector<int>candidates_2;
    int target_2;
    void generate(vector<int>method,int presentSum){
        if(presentSum==target_2){
            ans.push_back(method);
            return;
        }
        else if(presentSum>target_2){
            return;
        }
        for(int i =0;i<candidates_2.size();i++){
                if(!method.empty() and candidates_2[i]<method.back()){
                    continue;
                }
                method.push_back(candidates_2[i]);
                presentSum+=candidates_2[i];

                generate(method,presentSum);
                method.pop_back();
                presentSum-=candidates_2[i];
        }


    }
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        //sort(candidates.begin(),candidates.end());
        candidates_2 = candidates;
        target_2 = target;
        vector<int>empty;

        generate(empty,0);
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