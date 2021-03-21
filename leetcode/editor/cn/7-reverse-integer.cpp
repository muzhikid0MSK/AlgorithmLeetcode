//给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。 
//
// 示例 1: 
//
// 输入: 123
//输出: 321
// 
//
// 示例 2: 
//
// 输入: -123
//输出: -321
// 
//
// 示例 3: 
//
// 输入: 120
//输出: 21
// 
//
// 注意: 
//
// 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231, 231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。 
// Related Topics 数学 
// 👍 2123 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-08-25 00:21:21
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
    string reverse_str(string s){
        string new_s = s;
        for(int i =0;i<s.length();i++){
            new_s[new_s.length()-1-i] = s[i];
        }
        return new_s;
    }
    int solve(int x,bool isPositive){
        string x_str = to_string(x);
        x_str = reverse_str(x_str);
        long int record = stol(x_str);
        if(isPositive){
            if(record>INT32_MAX){
                return 0;
            }else{
                return int(record);
            }
        }else{
            if(-record<INT32_MIN){
                return 0;
            }else{
                return int(-record);
            }
        }

    }
    int reverse(int x) {
        bool isPositive = true;
        if(x==0){
            return 0;
        }else if(x<0){
            x = abs(x);
            isPositive = false;
        }
        return solve(x,isPositive);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    s.reverse(123);
    cout<<INT32_MAX<<endl;
    cout<<INT32_MIN<<endl;
    //s.method(params*);
    //cout<<s.method(params*);
    
}