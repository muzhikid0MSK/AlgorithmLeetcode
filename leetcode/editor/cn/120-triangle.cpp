//给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。 
//
// 相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。 
//
// 
//
// 例如，给定三角形： 
//
// [
//     [2],
//    [3,4],
//   [6,5,7],
//  [4,1,8,3]
//]
// 
//
// 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。 
//
// 
//
// 说明： 
//
// 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。 
// Related Topics 数组 动态规划 
// 👍 582 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-09-06 12:01:33
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

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int>dp;
        dp.resize(triangle.size());
        vector<int>temp;
        dp[0] = triangle[0][0];
        for(int i =1 ;i<triangle.size();i++){
             temp = dp;
            for(int j = 0;j<=i;j++){
                if(j==0){
                    dp[j] = temp[j]+triangle[i][j];
                }else if(j == i){
                    dp[j]= temp[j-1]+triangle[i][j];
                }else{
                    dp[j]=min(temp[j-1],temp[j])+triangle[i][j];
                }
            }
        }
        int ans = *min_element(dp.begin(),dp.end());
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    vector<int>tempTest;
    vector<vector<int> >test;
    tempTest.push_back(2);
    test.push_back(tempTest);
    tempTest = {3,4};
    test.push_back(tempTest);
    tempTest={6,5,7};
    test.push_back(tempTest);
    tempTest = {4,1,8,3};
    test.push_back(tempTest);
    cout<<s.minimumTotal(test);
    //s.method(params*);
    //cout<<s.method(params*);

}