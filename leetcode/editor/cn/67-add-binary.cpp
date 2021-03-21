//给你两个二进制字符串，返回它们的和（用二进制表示）。 
//
// 输入为 非空 字符串且只包含数字 1 和 0。 
//
// 
//
// 示例 1: 
//
// 输入: a = "11", b = "1"
//输出: "100" 
//
// 示例 2: 
//
// 输入: a = "1010", b = "1011"
//输出: "10101" 
//
// 
//
// 提示： 
//
// 
// 每个字符串仅由字符 '0' 或 '1' 组成。 
// 1 <= a.length, b.length <= 10^4 
// 字符串如果不是 "0" ，就都不含前导零。 
// 
// Related Topics 数学 字符串 
// 👍 461 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-08-27 17:18:47
*/
#include <iostream>
//#include <map>
//#include <queue>
//#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string addBinary(string a, string b) {
        string ansCal ;
        stack<char> ansStack;
        short ans = 0;
        short isUp = 0;
        int len;
        a.length()>b.length()?len=b.length():len=a.length();
        int i =a.length()-1;
        int j =b.length()-1;
        while (i>=0&&j>=0){
            short aNum = a[i]-'0';
            short bNum = b[j]-'0';
            ans = (aNum+bNum+isUp)%2;
            if(aNum+bNum+isUp>=2)
                isUp=1;
            else
                isUp=0;
            ansStack.push(ans+'0');
            //ansCal+=ans+'0';
            i--;
            j--;
        }
        while (i>=0){
            short aNum = a[i]-'0';
            ans = (aNum+isUp)%2;
            ansStack.push(ans+'0');
            //ansCal+=(ans+'0');
            if(aNum+isUp>=2)
                isUp = 1;
            else
                isUp = 0;
            i--;
        }
        while (j>=0){
            short bNum = b[j]-'0';
            ans = (bNum+isUp)%2;
            ansStack.push(ans+'0');
            //ansCal+=(ans+'0');
            if(bNum+isUp>=2)
                isUp = 1;
            else
                isUp = 0;
            j--;
        }
        if(isUp)
            ansStack.push('1');
        while (!ansStack.empty()){
            ansCal+= ansStack.top();
            ansStack.pop();
        }
        return ansCal;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    cout<<s.addBinary("11","1");
    //s.method(params*);
    //cout<<s.method(params*);
    
}