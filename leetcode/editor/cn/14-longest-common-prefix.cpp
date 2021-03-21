//编写一个函数来查找字符串数组中的最长公共前缀。 
//
// 如果不存在公共前缀，返回空字符串 ""。 
//
// 示例 1: 
//
// 输入: ["flower","flow","flight"]
//输出: "fl"
// 
//
// 示例 2: 
//
// 输入: ["dog","racecar","car"]
//输出: ""
//解释: 输入不存在公共前缀。
// 
//
// 说明: 
//
// 所有输入只包含小写字母 a-z 。 
// Related Topics 字符串 
// 👍 1232 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-08-26 12:29:09
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
    //int len [1000];         //未说明最多字符串个数
    string longestCommonPrefix(vector<string>& strs) {

        string ans ;
        if(strs.empty())
            return ans;
        for(int i = 0;i<INT32_MAX;i++){
            char ch = strs[0][i];
            bool flag = true;
            for(int j = 0;j<strs.size();j++){
                if(i>=strs[j].length()){
                    return ans;
                }
                else if(ch != strs[j][i]){
                    return ans;
                }
            }
                ans+= ch;
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