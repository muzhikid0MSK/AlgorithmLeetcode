//给你一个 无重叠的 ，按照区间起始端点排序的区间列表。 
//
// 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。 
//
// 
//
// 示例 1： 
//
// 
//输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
//输出：[[1,5],[6,9]]
// 
//
// 示例 2： 
//
// 
//输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
//输出：[[1,2],[3,10],[12,16]]
//解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。 
//
// 示例 3： 
//
// 
//输入：intervals = [], newInterval = [5,7]
//输出：[[5,7]]
// 
//
// 示例 4： 
//
// 
//输入：intervals = [[1,5]], newInterval = [2,3]
//输出：[[1,5]]
// 
//
// 示例 5： 
//
// 
//输入：intervals = [[1,5]], newInterval = [2,7]
//输出：[[1,7]]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= intervals.length <= 104 
// intervals[i].length == 2 
// 0 <= intervals[i][0] <= intervals[i][1] <= 105 
// intervals 根据 intervals[i][0] 按 升序 排列 
// newInterval.length == 2 
// 0 <= newInterval[0] <= newInterval[1] <= 105 
// 
// Related Topics 排序 数组 
// 👍 378 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2021-03-08 14:21:42
*   @FinishedTime: 2021年03月08日16:03:07
*   @Remarks:执行耗时:16 ms,击败了89.10% 的C++用户
			 内存消耗:16.7 MB,击败了47.83% 的C++用户
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
        int newBegin = newInterval[0];
        int newEnd = newInterval[1];
        short int isOutside = -1;
        int beginRecord = 0;
        for(int i =0;i<intervals.size();i++){
            int curBegin = intervals[i][0];
            int curEnd = intervals[i][1];
            beginRecord = i;
            if(newBegin<=curBegin){
                if(newEnd<curBegin){
                    intervals.insert(intervals.begin()+i,newInterval);
                    goto END;
                }else if(newEnd==curBegin or newEnd<=curEnd){
                    intervals[i]=vector<int>{newBegin,curEnd};
                    goto END;
                }else {
                    for(int j=i+1;j<intervals.size();j++){
                        int curBegin2 = intervals[j][0];
                        int curEnd2 = intervals[j][1];
                        if(newEnd<curBegin2){
                            // 在i位置替换元素k,并删除(k,j)
                            intervals[i]=newInterval;
                            intervals.erase(intervals.begin()+i+1,intervals.begin()+(j));
                            goto END;
                        }else if(newEnd == curBegin2 or newEnd<=curEnd2){
                            // 在i位置替换元素k,并删除(i,j]
                            intervals[i]=vector<int>{newBegin,curEnd2};
                            intervals.erase(intervals.begin()+i+1,intervals.begin()+j+1);
                            goto END;
                        }
                    }
                    isOutside = true;
                    break;
                }
            }else if(newBegin>curBegin and newBegin<=curEnd){
                if(newEnd<=curEnd){
                    goto END;
                }else{
                    for(int j=i+1;j<intervals.size();j++){
                        int curBegin2 = intervals[j][0];
                        int curEnd2 = intervals[j][1];
                        if(newEnd<curBegin2){
                            // 删除(i,j)
                            intervals.erase(intervals.begin()+i+1,intervals.begin()+(j));
                            intervals[i]=vector<int>{curBegin,newEnd};
                            goto END;
                        }else if(newEnd == curBegin2 or newEnd<=curEnd2){
                            // 删除(i,j]
                            intervals.erase(intervals.begin()+i+1,intervals.begin()+j+1);
                            intervals[i]=vector<int>{curBegin,curEnd2};
                            goto END;
                        }
                    }
                    isOutside = false;
                    break;
                }
            }
        }
        if(isOutside==1){
            cout<<"Right here"<<endl;
            intervals.erase(beginRecord+intervals.begin(),intervals.end());
            intervals.push_back(newInterval);
        }
        else if(isOutside==0){
            int numRecord = intervals[beginRecord][0];
            // cout<<"Right here";
            intervals.erase(beginRecord + 1 + intervals.begin(), intervals.end());
            intervals[beginRecord]=vector<int>{numRecord,newInterval[1]};
        }else{
            intervals.push_back(newInterval);
        }

        END:
        return intervals;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

void split(string str){
    
}
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