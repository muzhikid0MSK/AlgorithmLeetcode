//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。 
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 
//
// 
//
// 示例: 
//
// 输入："23"
//输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// 
//
// 说明: 
//尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。 
// Related Topics 字符串 回溯算法 
// 👍 853 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-08-26 10:44:57
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
    string number[10];
    void init(){
        number[2]="abc";
        number[3]="def";
        number[4]="ghi";
        number[5]="jkl";
        number[6]="mno";
        number[7]="pqrs";
        number[8]="tuv";
        number[9]="wxyz";
    }
    vector<string>ansSet;
    void visit(int loc,string &temp,string digits){
        if(loc==digits.length()){
            ansSet.push_back(temp);
            return;
        }
        int curNum = digits[loc]-'0';
        for(int i =0;i<number[curNum].length();i++){
            string temp_i = temp;
            temp_i+=number[curNum][i];
            visit(loc+1,temp_i,digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return ansSet;
        init();
        string temp;
        visit(0,temp,digits);
        return ansSet;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    s.letterCombinations("23");
    //s.method(params*);
    //cout<<s.method(params*);
    
}