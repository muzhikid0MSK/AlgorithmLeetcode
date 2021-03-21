//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：["((()))","(()())","(())()","()(())","()()()"]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：["()"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 8 
// 
// Related Topics 字符串 回溯算法 
// 👍 1591 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2021-03-01 22:52:31
*   @FinishedTime: 2021年03月01日23:09:54
*   @Remarks:执行耗时:8 ms,击败了37.59% 的C++用户
			 内存消耗:13.6 MB,击败了42.77% 的C++用户
*/
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <fstream>


using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int N;
    vector<string>ans;
    void arrange(string temp,int cntLeft,int cntRight){
        if(cntLeft>cntRight){
            if(cntLeft<N){
                arrange(temp+"(",cntLeft+1,cntRight);
                arrange(temp+")",cntLeft,cntRight+1);
            }else{
                arrange(temp+")",cntLeft,cntRight+1);
            }
        }else{
            if(cntRight == N){
                ans.push_back(temp);
            }else{
                arrange(temp+"(",cntLeft+1,cntRight);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        N = n;
        arrange("",0,0);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


//input
void input(){
    string path="";
    ifstream f;
    
    if(f.is_open()){
        //TODO
        
    }else{
        cerr<<"File opened fail"<<endl;
    }
    
}
int main(){
    Solution s;
    //s.method(params*);
    //cout<<s.method(params*);
    
}