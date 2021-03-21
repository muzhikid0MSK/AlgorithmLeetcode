//以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返
//回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。 
//
// 
//
// 示例 1： 
//
// 
//输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
//输出：[[1,6],[8,10],[15,18]]
//解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 
//
// 示例 2： 
//
// 
//输入：intervals = [[1,4],[4,5]]
//输出：[[1,5]]
//解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。 
//
// 
//
// 提示： 
//
// 
// 1 <= intervals.length <= 104 
// intervals[i].length == 2 
// 0 <= starti <= endi <= 104 
// 
// Related Topics 排序 数组 
// 👍 827 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2021-03-10 08:03:39
*   @FinishedTime:2021年03月10日08:50:13
*   @Remarks:			执行耗时:16 ms,击败了98.23% 的C++用户
			            内存消耗:14.5 MB,击败了21.16% 的C++用户
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
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int> >ans;
        for(int i =0;i<intervals.size();i++){
            int curStart = intervals[i][0];
            int curEnd = intervals[i][1];
            if(ans.empty()){
                ans.push_back(intervals[i]);
            }else{
                vector<int>last = ans.back();
                if(curStart<=last[1] and curEnd>last[1]){
                    ans[ans.size()-1] = vector<int>{last[0],curEnd};
                }else if (curStart>last[1]){
                    ans.push_back(intervals[i]);
                }
            }
        }

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