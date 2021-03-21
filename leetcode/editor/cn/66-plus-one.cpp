//给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。 
//
// 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。 
//
// 你可以假设除了整数 0 之外，这个整数不会以零开头。 
//
// 示例 1: 
//
// 输入: [1,2,3]
//输出: [1,2,4]
//解释: 输入数组表示数字 123。
// 
//
// 示例 2: 
//
// 输入: [4,3,2,1]
//输出: [4,3,2,2]
//解释: 输入数组表示数字 4321。
// 
// Related Topics 数组 
// 👍 529 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-08-27 23:50:20
*/
#include <iostream>
//#include <cstdlib>
//#include <map>
//#include <stack>
//#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int>ans;
    //stack<int>ansStack;

    vector<int> plusOne(vector<int>& digits) {
        if(digits.empty())
            return ans;
        string num;
        int carry = 1;
        ans.resize(digits.size());
        for(int i = int(digits.size()-1);i>=0;i--){
            ans[i]=(digits[i]+carry)%10;
            if(digits[i]+carry>=10){
                carry = 1;
            }else{
                carry = 0;
            }
        }
        if(carry){
            ans[0]=0;
            ans.insert(ans.begin(),1);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    vector<int>test;
    test.push_back(9);
    //test.push_back(2);
    test.push_back(9);
    s.plusOne(test);
    //s.method(params*);
    //cout<<s.method(params*);
    
}