//给定一个整数，将其转化为7进制，并以字符串形式输出。 
//
// 示例 1: 
//
// 
//输入: 100
//输出: "202"
// 
//
// 示例 2: 
//
// 
//输入: -7
//输出: "-10"
// 
//
// 注意: 输入范围是 [-1e7, 1e7] 。 
// 👍 60 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-09-26 21:59:29
*/
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string convertToBase7(int num) {
        bool isPositive = num>=0;
        num=abs(num);
        string s;

        while (num>=7){
            s+=(num%7+'0');
            num/=7;
        }
        s+=(num+'0');
        if(!isPositive)
            s.push_back('-');
        reverse(s.begin(),s.end());
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    //s.method(params*);
    //cout<<s.method(params*);
    
}