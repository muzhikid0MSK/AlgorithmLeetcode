//实现一个基本的计算器来计算一个简单的字符串表达式的值。 
//
// 字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格 。 
//
// 示例 1: 
//
// 输入: "1 + 1"
//输出: 2
// 
//
// 示例 2: 
//
// 输入: " 2-1 + 2 "
//输出: 3 
//
// 示例 3: 
//
// 输入: "(1+(4+5+2)-3)+(6+8)"
//输出: 23 
//
// 说明： 
//
// 
// 你可以假设所给定的表达式都是有效的。 
// 请不要使用内置的库函数 eval。 
// 
// Related Topics 栈 数学 
// 👍 253 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-09-05 17:11:56
*/
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
enum {LEFT_BRACKET_INDEXES = INT32_MIN,ADD,SUBTRACTION};
class Solution {
public:
    int ans=0;
    int calculate(string s) {
        stack<int >record;
        int numIndex = -1;
        s.insert(s.end(),'&');  //用于结束
        for(int i =0;i<s.length();i++){
            if(s[i]==' ')
                continue;
            if(numIndex != - 1 and !isdigit(s[i])){
                record.push(stoi(s.substr(numIndex,i-numIndex)));
                numIndex = -1;
            }
            if(s[i]=='('){
                record.push(LEFT_BRACKET_INDEXES);
            }else if(s[i]==')' or s[i]=='&'){
                //cal
                deque<int>temp;
                while (!record.empty() and record.top()!=LEFT_BRACKET_INDEXES){
                    temp.push_front(record.top());
                    record.pop();
                }
                if(!record.empty())
                    record.pop();

                bool hasGetOpe = false;
                int curOpe = 0;
                int num1 = 0;
                int num2 =0;
                while (temp.size()!=1 or hasGetOpe){
                    if(temp.front()!=ADD and temp.front()!=SUBTRACTION){
                        if(!hasGetOpe){
                            num1 = temp.front();
                            temp.pop_front();
                        }else{
                            num2 = temp.front();
                            temp.pop_front();
                            if(curOpe == ADD){
                                temp.push_front(num1+num2);
                            }else{
                                temp.push_front(num1-num2);
                            }
                            hasGetOpe = false;
                        }
                    }else{
                        curOpe = temp.front();
                        temp.pop_front();
                        hasGetOpe = true;
                    }
                }
                record.push(temp.front());
            }else if(s[i]=='+'){
                record.push(ADD);
            }else if(s[i]=='-'){
                record.push(SUBTRACTION);
            }else{
                if(numIndex==-1 ){
                    numIndex = i;
                }
            }

        }
        return record.top();
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    cout<<s.calculate("5   + ((1+3) - (9-8-9))-(1-0)");
    //s.method(params*);
    //cout<<s.method(params*);
    
}