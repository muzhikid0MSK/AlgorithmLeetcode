//给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。 
//
// 说明： 
//
// 
// 拆分时可以重复使用字典中的单词。 
// 你可以假设字典中没有重复的单词。 
// 
//
// 示例 1： 
//
// 输入: s = "leetcode", wordDict = ["leet", "code"]
//输出: true
//解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
// 
//
// 示例 2： 
//
// 输入: s = "applepenapple", wordDict = ["apple", "pen"]
//输出: true
//解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
//     注意你可以重复使用字典中的单词。
// 
//
// 示例 3： 
//
// 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//输出: false
// 
// Related Topics 动态规划 
// 👍 717 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-10-19 20:06:57
*   @FinishedTime: 2020年11月23日20:11:03
*   @remarks:执行耗时:16 ms,击败了71.40% 的C++用户
			 内存消耗:9.5 MB,击败了72.83% 的C++用户
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
    bool check(string word,vector<string>& wordDict){
        if(word == "" ){
            return true;
        }
        for(const auto& item:wordDict){
            if(item == word){
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.size()+1, false);
        dp[0]=true;
        for(int i =1;i<=s.size();i++){
            for(int j =i-1;j>=0;j--){
                dp[i]=dp[j]&&check(s.substr(j,i-j),wordDict);
                //cout<<"dp "<<i<<" "<<dp[i]<<endl;
                if(dp[i])
                    break;
            }
        }
        return dp[s.size()];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    //s.method(params*);
    //cout<<s.method(params*);
    
}