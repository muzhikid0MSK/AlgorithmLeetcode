//在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。 
//
// 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。 
//
// 如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。 
//
// 说明: 
//
// 
// 如果题目有解，该答案即为唯一答案。 
// 输入数组均为非空数组，且长度相同。 
// 输入数组中的元素均为非负数。 
// 
//
// 示例 1: 
//
// 输入: 
//gas  = [1,2,3,4,5]
//cost = [3,4,5,1,2]
//
//输出: 3
//
//解释:
//从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
//开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
//开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
//开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
//开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
//开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
//因此，3 可为起始索引。 
//
// 示例 2: 
//
// 输入: 
//gas  = [2,3,4]
//cost = [3,4,3]
//
//输出: -1
//
//解释:
//你不能从 0 号或 1 号加油站出发，因为没有足够的汽油可以让你行驶到下一个加油站。
//我们从 2 号加油站出发，可以获得 4 升汽油。 此时油箱有 = 0 + 4 = 4 升汽油
//开往 0 号加油站，此时油箱有 4 - 3 + 2 = 3 升汽油
//开往 1 号加油站，此时油箱有 3 - 3 + 3 = 3 升汽油
//你无法返回 2 号加油站，因为返程需要消耗 4 升汽油，但是你的油箱只有 3 升汽油。
//因此，无论怎样，你都不可能绕环路行驶一周。 
// Related Topics 贪心算法 
// 👍 417 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-10-15 10:28:25
*   @FinishedTime:2020年11月23日19:31:53
*   @remarks: 思路① 计算总和，若sum cost > sum gas 则return -1；否则找gas_i-cost_i最大者。
*               对思路①的补充：或许不需要计算总和，只需要找 gas_i-cost_i最大者，遇见赤字则表明不可以走完。
*               对思路①的补充：有错误。			测试用例:[5,8,2,8]
			                                            [6,5,6,6]
			                                            测试结果:-1
			                                            期望结果:3
			 思路② 计算所有结余记为remain 。遍历remain对所有remain[i]>0 开始向后遍历计算sum remain_(i to j) 如果小于0则从当前开始重新向后遍历。

            执行耗时:12 ms,击败了61.15% 的C++用户
			内存消耗:9.9 MB,击败了34.18% 的C++用户

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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int>remain(gas.size()+1,0);  //增加最后一位哨兵
        for(int i =0;i<gas.size();i++){
            remain[i]=gas[i]-cost[i];
            remain[gas.size()]+=(remain[i]);
        }
        int nowBegin = 0;
        int tempSum = 0;

        int cnt = 0;
        if(remain[gas.size()]<0){
            return -1;
        }else{
            remain.pop_back();
            while (cnt<remain.size()){
                tempSum+=(remain[(nowBegin+cnt)%(int(remain.size()))]);
                if(tempSum<0){
                    nowBegin=(nowBegin+cnt+1)%(int(remain.size()));
                    cnt=-1;
                    tempSum=0;
                }
                cnt= (cnt+1);
            }
        }
        return nowBegin;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
void input(vector<int>&a,vector<int>&b){
    string s;
    while (cin>>s and s!="#"){
        a.push_back(stoi(s));
    }
    while (cin>>s and s!="#"){
        b.push_back(stoi(s));
    }
}
int main(){
    Solution s;
    vector<int>a,b;
    input(a,b);
    int ans =s.canCompleteCircuit(a,b);
    cout<<ans<<endl;
    //s.method(params*);
    //cout<<s.method(params*);
    
}