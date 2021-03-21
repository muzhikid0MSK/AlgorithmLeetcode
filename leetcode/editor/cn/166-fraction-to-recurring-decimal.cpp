//给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。 
//
// 如果小数部分为循环小数，则将循环的部分括在括号内。 
//
// 示例 1: 
//
// 输入: numerator = 1, denominator = 2
//输出: "0.5"
// 
//
// 示例 2: 
//
// 输入: numerator = 2, denominator = 1
//输出: "2" 
//
// 示例 3: 
//
// 输入: numerator = 2, denominator = 3
//输出: "0.(6)"
// 
// Related Topics 哈希表 数学 
// 👍 170 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-10-07 20:04:27
*/
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int divisor=denominator;    //除数
        int dividend=numerator;  //被除数
        int intPart;
        intPart=dividend/divisor;
        string intPartStr, fracPartStr;
        intPartStr = to_string(intPart);
        dividend=(dividend%divisor)*10;
        unordered_map<int,int>isBeen;
        isBeen[dividend]=0;
        if(dividend==0)
            return intPartStr;
        //int lastDividend;
        do {
            string curChar =to_string(dividend/divisor);    //商
            dividend=(dividend%divisor)*10; //新被除数
            //todo 回溯
            if(isBeen[dividend]){
                fracPartStr+="("+curChar+")";
                break;
            }else{
                fracPartStr+=curChar;
            }

        }while (dividend!=0);
        return intPartStr+"."+fracPartStr;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    s.fractionToDecimal(4,333);
    //s.method(params*);
    //cout<<s.method(params*);
    
}