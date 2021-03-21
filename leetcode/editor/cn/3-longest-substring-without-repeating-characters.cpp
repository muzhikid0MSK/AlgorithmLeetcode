//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。 
//
// 示例 1: 
//
// 输入: "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 
//
// 示例 2: 
//
// 输入: "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 
//
// 示例 3: 
//
// 输入: "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 
// Related Topics 哈希表 双指针 字符串 Sliding Window 
// 👍 4209 👎 0

#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)


class Solution {
public:
    /**
    * 尝试拓展到char范围即-128~127;
    */


    bool loc[256];            //用于记录对应字符出现的位置
    void init(){
        for(int i=0;i<256; i++){
            loc[i]= false;
        }
    }
    //更好一点的方法
    int lengthOfLongestSubstring(string s){
        init();
        string temp;
        int maxLen = 0;
        for(int i =0;i<s.length();i++){
            if(!loc[s[i]+128]){
                temp+=s[i];
                loc[s[i]+128]=true;
            }else{
                if(maxLen<temp.length())
                    maxLen = temp.length();
                int tempIndex = temp.find(s[i]);
                //loc[s[i]+128]= false;
                temp = temp.substr(tempIndex+1);
                temp+=s[i];
            }
        }
        if(maxLen<temp.length()){
            maxLen = temp.length();
        }
        return maxLen;
    }
    /**

    bool cap[256];
    void init(){
        for (int i = 0; i < 256; ++i) {
            cap[i]= false;
            loc[i]=-1;
        }
    }
    void initByIndex(int start_i,int end_i,string s){
        for(int i=start_i;i<end_i;i++){
            cap[s[i]+128] = false;
            loc[s[i]+128] = -1;
        }
    }
    int lengthOfLongestSubstring(string s) {
        init();
        if(s.empty())
            return 0;
        int lastIndex =0;
        int curLen =0;
        int maxLen = 0;
       // bool flag = true;               //是否没有重复字符
        for(int i=0;i<s.length();i++){
            if (!cap[s[i]+128]){
                cap[s[i]+128]=true;
                loc[s[i]+128]=i;
                curLen++;
            }else {

                lastIndex = loc[s[i]+128];
                loc[s[i]+128]=i;
                initByIndex(lastIndex+1,i+1,s);
                if(maxLen<curLen){
                    maxLen = curLen;
                }
                i=lastIndex;
                curLen = 0;
            }


        }
        if(maxLen<curLen){
            maxLen = curLen;
        }
        return maxLen;
    }
     **/
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    cout<<s.lengthOfLongestSubstring("");

    //s.method(params*);
    //cout<<s.method(params*);
    
}