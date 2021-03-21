//一条包含字母 A-Z 的消息通过以下方式进行了编码： 
//
// 'A' -> 1
//'B' -> 2
//...
//'Z' -> 26
// 
//
// 给定一个只包含数字的非空字符串，请计算解码方法的总数。 
//
// 示例 1: 
//
// 输入: "12"
//输出: 2
//解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
// 
//
// 示例 2: 
//
// 输入: "226"
//输出: 3
//解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
// 
// Related Topics 字符串 动态规划 
// 👍 493 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-09-08 15:15:33
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
    int numDecodings(string s) {
        vector<int>dp(s.length()+1,0);
        if(s[0]=='0'){
            return 0;
        }
        dp[1]=1;
        dp[0]=1;
       // bool flag = false;
        for(int i=1;i<s.length();i++){
            if(s[i]=='0'){
                if(s[i-1]=='1' or s[i-1] =='2'){
                            dp[i+1] = dp[i-1];
                }
                else
                    return 0;
            }else if(s[i-1]=='1'){

                    dp[i+1] = dp[i]+dp[i-1];
            }else if(s[i-1]=='2'){
                if(s[i]>='1' and s[i]<='6'){
                    dp[i+1] = dp[i]+dp[i-1];
                }else{
                    dp[i+1] = dp[i];
                }
            }else{
                dp[i+1] = dp[i];
            }
        }

        return dp[s.length()];
    }
};
//leetcode submit region end(Prohibit modification and deletion)22

int main(){
    Solution s;
    cout<<s.numDecodings("291")<<endl;
    //s.method(params*);
    //cout<<s.method(params*);
    
}