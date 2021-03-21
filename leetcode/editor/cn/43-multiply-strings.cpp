//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。 
//
// 示例 1: 
//
// 输入: num1 = "2", num2 = "3"
//输出: "6" 
//
// 示例 2: 
//
// 输入: num1 = "123", num2 = "456"
//输出: "56088" 
//
// 说明： 
//
// 
// num1 和 num2 的长度小于110。 
// num1 和 num2 只包含数字 0-9。 
// num1 和 num2 均不以零开头，除非是数字 0 本身。 
// 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。 
// 
// Related Topics 数学 字符串 
// 👍 470 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-09-04 21:04:28
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
    void add(vector<char> curAns,vector<char> &ans){
        if(ans.empty())
            ans = curAns;
        else{
            int i = curAns.size()-1;
            int j = ans.size()-1;
            unsigned carry =0;
            vector<char>addAns;
            while (i>=0 and j>=0){
                unsigned temp;
                temp = ((curAns[i]-'0')+(ans[j]-'0')+carry);
                if(temp>=10){
                    carry = temp/10;
                }else{
                    carry = 0;
                }
                temp = temp%10;
                addAns.insert(addAns.begin(),temp+'0');
                i--;
                j--;
            }
            while (i>=0){
                unsigned  temp;
                temp = (curAns[i]-'0')+carry;
                if(temp>=10){
                    carry = temp/10;
                }else{
                    carry = 0;
                }
                temp %=10;
                addAns.insert(addAns.begin(),temp+'0');
                i--;
            }
            if(i == -1 and carry != 0){
                addAns.insert(addAns.begin(),carry+'0');
            }
            ans = addAns;
        }
    }
    void vech_to_str(string & str,vector<char> rawAns){
        str.resize(rawAns.size());
        for(int i=0;i<rawAns.size();i++){
            str[i]=rawAns[i];
        }
    }
    string multiply(string num1, string num2) {
        if((num1.size() ==1 and num1[0]=='0') or (num2.size() ==1 and num2[0]=='0')){
            return "0";
        }

        if(num1.size()<=num2.size()){
            string temp = num1;
            num1 = num2;
            num2 = temp;
        }
        int i = num1.size()-1;
        int j = num2.size()-1;
        vector<char>ans;
        while (j>=0){
            i = num1.size()-1;
            unsigned carry = 0;
            vector<char>curAns;

            while (i>=0){
                unsigned tempAns;
                tempAns = ((num1[i]-'0')*(num2[j]-'0')+carry);
                if(tempAns>=10){
                    carry = tempAns/10;
                }else{
                    carry = 0;
                }
                tempAns %= 10;
                curAns.insert(curAns.begin(),tempAns+'0');
                if(i==0 and carry !=0)
                    curAns.insert(curAns.begin(),carry+'0');
                i--;
            }
             int bits = num2.size()-1-j;
            while (bits--){
                curAns.insert(curAns.end(),'0');
            }
            add(curAns,ans);
            j--;
        }
        string finalAns;
        vech_to_str(finalAns,ans);
        return finalAns;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    cout<<s.multiply("123","456");
    //s.method(params*);
    //cout<<s.method(params*);
    
}