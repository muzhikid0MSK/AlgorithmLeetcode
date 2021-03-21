//实现一个基本的计算器来计算一个简单的字符串表达式的值。 
//
// 字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格 。 整数除法仅保留整数部分。 
//
// 示例 1: 
//
// 输入: "3+2*2"
//输出: 7
// 
//
// 示例 2: 
//
// 输入: " 3/2 "
//输出: 1 
//
// 示例 3: 
//
// 输入: " 3+5 / 2 "
//输出: 5
// 
//
// 说明： 
//
// 
// 你可以假设所给定的表达式都是有效的。 
// 请不要使用内置的库函数 eval。 
// 
// Related Topics 字符串 
// 👍 175 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-09-05 19:12:23
*   @FinishedTime:
*   @remarks: ①两个栈记录operator,operand;若新的operator优先级大于栈顶元素,则压入;否则弹出栈顶operator,并弹出两个operand计算结果后压入
 *              operand栈,再压入新operator.
 *             执行耗时:36 ms,击败了11.73% 的C++用户
			   内存消耗:9.9 MB,击败了9.69% 的C++用户
*/
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    map<char,int>priority;
    void init(){
        priority['/']=2;
        priority['*']=2;
        priority['+']=1;
        priority['-']=1;
    }
    bool isInferior(char a,char b){
        return priority[a]<priority[b];
    }
    void split(vector<char>&operators ,vector<int>&nums,string s){
        int lastPos  = -1;
        s +='#';
        for(int i =0;i<s.length();i++){
            if(s[i]=='*' or s[i] == '/' or s[i] == '+' or s[i] == '-' or s[i]=='#'){
                    operators.emplace_back(s[i]);
                    if(lastPos==-1){
                        nums.emplace_back(stoi(s.substr(0,i)));
                        lastPos = i;
                    }else{
                        nums.emplace_back(stoi(s.substr(lastPos+1,(i-lastPos-1))));
                        lastPos = i;
                    }


            }

        }
    }
    void cal(stack<int>&numStack,stack<char>&operatorsStack){
        char topOperator = operatorsStack.top();
        operatorsStack.pop();
        int num2 = numStack.top();
        numStack.pop();
        int num1 = numStack.top();
        numStack.pop();
        int curAns ;
        switch (topOperator) {
            case '+':
                curAns = num1+num2;
                break;
            case '-':
                curAns = num1-num2;
                break;
            case '*':
                curAns = num1*num2;
                break;
            case '/':
                curAns = num1/num2;
                break;
            default:
                break;
        }
        numStack.push(curAns);
    }
    int calculate(string s) {
        init();
        vector<int>nums;
        vector<char>operators;
        split(operators,nums,s);
        if(nums.size()==1)
            return nums[0];
        stack<int>numStack;
        stack<char>operatorsStack;
        bool isNum = true;
        int i =0,j=0;
        nums.push_back(-1);

        while(i<nums.size()){
            if(isNum){
                if(nums[i]==-1){
                    cal(numStack,operatorsStack);
                    goto END;
                }
                numStack.push(nums[i]);
                i++;
            }else{
                if(operators[j]!='#' and(operatorsStack.empty() or isInferior(operatorsStack.top(),operators[j]))){
                    operatorsStack.push(operators[j]);
                }else{
                    CAL:
                    cal(numStack,operatorsStack);
                    if(operatorsStack.empty() or isInferior(operatorsStack.top(),operators[j]) ){
                        if(operators[j]=='#')
                            break;
                        operatorsStack.push(operators[j]);

                    }else{
                        goto CAL;
                    }

                }
                j++;
            }
            isNum = !isNum;
        }
        END:

        return numStack.top();
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    cout<<s.calculate("0");
    //s.method(params*);
    //cout<<s.method(params*);
    
}