//给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, 
//ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。 
//
// 说明：你不能倾斜容器，且 n 的值至少为 2。 
//
// 
//
// 
//
// 图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。 
//
// 
//
// 示例： 
//
// 输入：[1,8,6,2,5,4,8,3,7]
//输出：49 
// Related Topics 数组 双指针 
// 👍 1779 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-08-29 16:48:59
*   @FinishedTime:
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
    int myMin(int a,int b){
        return a>b?b:a;
    }
    int maxArea(vector<int>& height) {
       int l,r ;
       l = 0;
       r = height.size()-1;
       int curMax = 0;

       while (l<r){
           int capacity = 0;
           capacity = (r-l)*myMin(height[l],height[r]);
           if(height[l]<height[r]){
               l++;
           }else{
               r--;
           }
           if(capacity>curMax){
               curMax = capacity;
           }
       }
        return curMax;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    Solution s;
    vector<int>a;
    a.push_back(1);
    a.push_back(8);
    a.push_back(6);
    a.push_back(2);
    a.push_back(5);
    a.push_back(4);
    a.push_back(8);
    a.push_back(3);
    a.push_back(7);
    s.maxArea(a);
    //s.method(params*);
    //cout<<s.method(params*);
    
}