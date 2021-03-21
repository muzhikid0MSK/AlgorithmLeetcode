//给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。 
//
// 如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。 
//
// 注意：你不能在买入股票前卖出股票。 
//
// 
//
// 示例 1: 
//
// 输入: [7,1,5,3,6,4]
//输出: 5
//解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
//     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
// 
//
// 示例 2: 
//
// 输入: [7,6,4,3,1]
//输出: 0
//解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
// 
// Related Topics 数组 动态规划 
// 👍 1237 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-10-11 22:19:15
*/
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //单调栈解法
        //维护一个单调增的栈
        //当栈为空或元素大于栈顶，入栈
        //若栈顶大于元素，则弹出直到栈顶小于元素为止；每次弹出时将它和栈底元素作差（模拟卖），维护一个最大值
        //边界：当扫描完最后一个元素时，将当前栈顶和栈底作差，维护最大值。
        if(prices.empty()){
            return 0;
        }
        int optimal = 0;
        int myStack[prices.size()];
        int top=-1;
        for(int i =0;i<prices.size();i++){
            if(top == -1 or  myStack[top]<prices[i]){
                top++;
                myStack[top] = prices[i];
            }else{
                while (top>=0 and myStack[top]>prices[i]){
                    optimal = max(optimal,myStack[top]-myStack[0]);
                    top--;
                }
                top++;
                myStack[top]=prices[i];
            }
//            cout<<"i:"<<i<<endl;
//            for(int j=bottom;j<=top;j++){
//                cout<<myStack[j]<<' ';
//            }
//            cout<<endl;
        }
        optimal = max(optimal,myStack[top]-myStack[0]);
        return optimal;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    //s.method(params*);
    //cout<<s.method(params*);
    
}