//在无限的平面上，机器人最初位于 (0, 0) 处，面朝北方。机器人可以接受下列三条指令之一： 
//
// 
// "G"：直走 1 个单位 
// "L"：左转 90 度 
// "R"：右转 90 度 
// 
//
// 机器人按顺序执行指令 instructions，并一直重复它们。 
//
// 只有在平面中存在环使得机器人永远无法离开时，返回 true。否则，返回 false。 
//
// 
//
// 示例 1： 
//
// 输入："GGLLGG"
//输出：true
//解释：
//机器人从 (0,0) 移动到 (0,2)，转 180 度，然后回到 (0,0)。
//重复这些指令，机器人将保持在以原点为中心，2 为半径的环中进行移动。
// 
//
// 示例 2： 
//
// 输入："GG"
//输出：false
//解释：
//机器人无限向北移动。
// 
//
// 示例 3： 
//
// 输入："GL"
//输出：true
//解释：
//机器人按 (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ... 进行移动。 
//
// 
//
// 提示： 
//
// 
// 1 <= instructions.length <= 100 
// instructions[i] 在 {'G', 'L', 'R'} 中 
// 
// Related Topics 数学 
// 👍 41 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-10-06 22:06:37
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
    enum ee{N=0,E,S,W};
    int getDirection(int cur,char change){
        if(change=='L')
                return  (cur-1)>=0?cur-1:W;
        else
                return (cur+1)%4;
    }
    bool isRobotBounded(string instructions) {
        int curDirection=N;
        int dirs[4]{0,0,0,0};
       // cout<<"Where are you ?"<<endl;
        for(int c = 0;c<4;c++){
            for(int i =0;i<instructions.size();i++){
                if(instructions[i]=='G'){
                    dirs[curDirection]++;
                }else{
                    curDirection=getDirection(curDirection,instructions[i]);
                }
            }}
       // cout<<"Where are you ?"<<endl;
        return dirs[0]==dirs[2] and dirs[1]==dirs[3];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    s.isRobotBounded("GGLLGG");
    //s.method(params*);
    //cout<<s.method(params*);
    
}