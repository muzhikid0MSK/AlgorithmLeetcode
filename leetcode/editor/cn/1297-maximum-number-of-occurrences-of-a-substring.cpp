//给你一个字符串 s ，请你返回满足以下条件且出现次数最大的 任意 子串的出现次数： 
//
// 
// 子串中不同字母的数目必须小于等于 maxLetters 。 
// 子串的长度必须大于等于 minSize 且小于等于 maxSize 。 
// 
//
// 
//
// 示例 1： 
//
// 输入：s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
//输出：2
//解释：子串 "aab" 在原字符串中出现了 2 次。
//它满足所有的要求：2 个不同的字母，长度为 3 （在 minSize 和 maxSize 范围内）。
// 
//
// 示例 2： 
//
// 输入：s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
//输出：2
//解释：子串 "aaa" 在原字符串中出现了 2 次，且它们有重叠部分。
// 
//
// 示例 3： 
//
// 输入：s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3
//输出：3
// 
//
// 示例 4： 
//
// 输入：s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 10^5 
// 1 <= maxLetters <= 26 
// 1 <= minSize <= maxSize <= min(26, s.length) 
// s 只包含小写英文字母。 
// 
// Related Topics 位运算 字符串 
// 👍 32 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-10-04 16:25:45
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxFreq(string &s, int maxLetters, int minSize, int maxSize) {
        int record[26];
        memset(record,0,sizeof(record));
        unordered_map<string,int>ans;
        int curDifferentLetter=0;
        for(int i =0;i<s.length();i++){
            int j;

            for(j=0;j<minSize-1;j++){
                if(!record[s[i+j]-'a']){
                    curDifferentLetter++;
                }
                record[s[i+j]-'a']++;
            }
            for(;j<maxSize;j++){
                if(!record[s[i+j]-'a']){
                    curDifferentLetter++;
                }
                record[s[i+j]-'a']++;
                if(curDifferentLetter<=maxLetters)
                    ans[s.substr(i,j+1)]++;
            }
            if(!(--record[s[i]-'a']) ){ //自减后等于0
                curDifferentLetter--;
            }

        }
        int curAns=INT32_MIN;
        for(auto &iter:ans){
           if(iter.second>curAns){
               curAns=iter.second;
           }
        }
        return curAns;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    string ss="aababcaab";
    cout<<s.maxFreq(ss,2,3,4);
    //s.method(params*);
    //cout<<s.method(params*);
    
}