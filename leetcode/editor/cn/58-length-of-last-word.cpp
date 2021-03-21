//给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。 
//
// 如果不存在最后一个单词，请返回 0 。 
//
// 说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。 
//
// 
//
// 示例: 
//
// 输入: "Hello World"
//输出: 5
// 
// Related Topics 字符串 
// 👍 238 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-08-27 17:03:33
*/
#include <iostream>
//#include <map>
//#include <queue>
//#include <vector>
#include <algorithm>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        for(int i =0;i<s.length();i++){
            if(isalpha(s[i])){
                if(i>=1&&s[i-1]==' ')
                    len = 0;
                len++;
            }

        }
        return len;
        //return s.substr(s.find_last_of(' ')+1).length();
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    //s.method(params*);
    //cout<<s.method(params*);
    
}