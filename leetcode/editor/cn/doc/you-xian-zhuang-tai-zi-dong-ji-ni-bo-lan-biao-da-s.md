两个提示：1.注意本题int装不下！！！需要用long
2.switch break过不去换continue

```
#include<bits/stdc++.h>
class Solution {
public:
    void compute(std::stack<long> &number_stack,std::stack<char> &operation_stack){
        if(number_stack.size()<2) return;
        long num2 = number_stack.top();
        number_stack.pop();
        long num1 = number_stack.top();
        number_stack.pop();
        if(operation_stack.top()=='+') number_stack.push(num1+num2);
        if(operation_stack.top()=='-') number_stack.push(num1-num2);
        operation_stack.pop();
    }
    int calculate(std::string s) {
        static const int STATE_BEGIN = 0;
        static const int NUMBER_STATE = 1;
        static const int OPERATION_STATE = 2;
        std::stack<long> number_stack;
        std::stack<char> operation_stack;
        long number = 0;
        int STATE = STATE_BEGIN;
        int compuate_flag = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' ') continue;
            switch(STATE){
                case STATE_BEGIN:
                    if(s[i]>='0'&&s[i]<='9') STATE = NUMBER_STATE;
                    else STATE = OPERATION_STATE;
                    i--;
                    continue;
                case NUMBER_STATE:
                    if(s[i]>='0'&&s[i]<='9') number=number*10+s[i]-'0';
                    else{
                        number_stack.push(number);
                        if(compuate_flag==1) compute(number_stack,operation_stack);
                        number=0;
                        i--;
                        STATE=OPERATION_STATE;
                    }
                    continue;
                case OPERATION_STATE:
                    if(s[i]=='+'||s[i]=='-'){
                        operation_stack.push(s[i]);
                        compuate_flag=1;
                    }
                    else if(s[i]=='('){
                        STATE =NUMBER_STATE;
                        compuate_flag=0;
                    }
                    else if(s[i]>='0'&&s[i]<='9'){
                        STATE = NUMBER_STATE;
                        i--;
                    }
                    else if(s[i]==')'){
                        compute(number_stack,operation_stack);
                    }
                    continue;
            }
        }
                    if(number!=0){
                number_stack.push(number);
                compute(number_stack,operation_stack);
            }
            if(number==0 && number_stack.empty()) return 0;
        return number_stack.top();
    }
};
```
