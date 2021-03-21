//给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。 
//
// 你可以对一个单词进行如下三种操作： 
//
// 
// 插入一个字符 
// 删除一个字符 
// 替换一个字符 
// 
//
// 
//
// 示例 1： 
//
// 输入：word1 = "horse", word2 = "ros"
//输出：3
//解释：
//horse -> rorse (将 'h' 替换为 'r')
//rorse -> rose (删除 'r')
//rose -> ros (删除 'e')
// 
//
// 示例 2： 
//
// 输入：word1 = "intention", word2 = "execution"
//输出：5
//解释：
//intention -> inention (删除 't')
//inention -> enention (将 'i' 替换为 'e')
//enention -> exention (将 'n' 替换为 'x')
//exention -> exection (将 'n' 替换为 'c')
//exection -> execution (插入 'u')
// 
// Related Topics 字符串 动态规划 
// 👍 1191 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-10-13 10:52:19
*/
#include <iostream>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minDistance(string word1, string word2) {
        word1 = " "+word1;
        word2 = " "+word2;
        int len1 = word1.length();
        int len2 = word2.length();
        int dp[len1][len2];
        for(int i =0;i<len2;i++){
            dp[0][i]=i;
        }
        for(int j=0;j<len1;j++){
            dp[j][0]=j;
        }
        string B[len1][len2];
        for(int i =1;i<len1;i++){
            for(int j =1;j<len2;j++){
                dp[i][j] = min(min(dp[i][j-1]+1,dp[i-1][j]+1),dp[i-1][j-1]+(word1[i]!=word2[j]));
                //printf("%d",dp[i][j]);
                /**
                 * 构造最优解
                 */
                 if(dp[i][j]==(dp[i-1][j-1]+(word1[i]!=word2[j]))){
                    B[i][j]=to_string(dp[i][j])+'Q';
                 }else if(dp[i][j] == dp[i-1][j]+1){
                     B[i][j]=to_string(dp[i][j])+'U';
                 }else {
                     B[i][j]=to_string(dp[i][j])+'L';
                 }
            }
           // printf("\n");
        }
        for(int i =1;i<len1;i++){
            for (int j =1;j<len2;j++){
                cout<<B[i][j]<<"  ";
            }
           cout<<endl;
        }
        return dp[len1-1][len2-1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    //s.method(params*);
    //cout<<s.method(params*);
    
}