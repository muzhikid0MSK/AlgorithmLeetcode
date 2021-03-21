//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。 
//
// 示例 1： 
//
// 输入: "babad"
//输出: "bab"
//注意: "aba" 也是一个有效答案。
// 
//
// 示例 2： 
//
// 输入: "cbbd"
//输出: "bb"
// 
// Related Topics 字符串 动态规划 
// 👍 2602 👎 0

#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    const static int maxN = 1000;
    bool dp[maxN][maxN];
    void init(int len){
        for(int i =0;i<len;i++){
            for(int j =0;j<len;j++){
                if(i==j){
                    dp[i][j]= true;
                }else{
                    dp[i][j] = false;
                }
            }
        }
    }
    string longestPalindrome(string s) {
        init(s.length());
        int curLen = 0;
        int curI = 0;
        for(int j=1;j<s.length();j++){
            for(int i=0;i<j;i++){
                if(j-i<=2){
                    dp[i][j]= (s[i]==s[j]);
                }else{
                    dp[i][j]=(s[i]==s[j])&&dp[i+1][j-1];
                }
                if(dp[i][j]){
                    if(curLen<j-i){
                        curLen=j-i;
                        curI=i;
                    }
                }
            }
        }
        string ans = s.substr(curI,curLen+1);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    //s.method(params*);
    cout<<s.longestPalindrome("abbaa");

}