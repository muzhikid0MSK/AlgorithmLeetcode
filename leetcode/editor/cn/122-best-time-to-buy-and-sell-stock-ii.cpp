//给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。 
//
// 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。 
//
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。 
//
// 
//
// 示例 1: 
//
// 输入: [7,1,5,3,6,4]
//输出: 7
//解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
//     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
// 
//
// 示例 2: 
//
// 输入: [1,2,3,4,5]
//输出: 4
//解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
//     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
//     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
// 
//
// 示例 3: 
//
// 输入: [7,6,4,3,1]
//输出: 0
//解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。 
//
// 
//
// 提示： 
//
// 
// 1 <= prices.length <= 3 * 10 ^ 4 
// 0 <= prices[i] <= 10 ^ 4 
// 
// Related Topics 贪心算法 数组 
// 👍 880 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-10-12 09:21:22
*   @FinishedTime:2020年11月23日18:48:18
*   @remarks:思路①试探一天，若跌则卖
 *           执行耗时:4 ms,击败了91.89% 的C++用户
			 内存消耗:7.6 MB,击败了24.26% 的C++用户
*
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
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int i=1,j;
        for(;i<prices.size();i++){
            if (prices[i]>prices[i-1]){
                i = i-1;
                break;
            }
        }
        if(i>=prices.size())
            return 0;
        j=i+1;
        int benefit = 0;
        while (i<prices.size() and j <prices.size()){
            if(prices[j]>=prices[j-1]){  //增加
              ;
            }else{
                benefit+=prices[j-1]-prices[i];
                i=j;
            }
            j++;
        }
        if(prices[j-1]>prices[i]){
            benefit+=(prices[j-1]-prices[i]);
        }
        return benefit;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    //s.method(params*);
    //cout<<s.method(params*);
    
}