![![50\\]4\\]41YN3P(HAQB)F59HV.png\](https://pic.leetcode-cn.com/23da29ed35ea0536b8e787719ffb1050159d51a670f306415fc8ca431c16f086- ](./p__50_4_41YN3P_HAQB_F59HV.png__https:__pic.leetcode-cn.com_23da29ed35ea0536b8e787719ffb1050159d51a670f306415fc8ca431c16f086-_.png) 50%5D4%5D41YN3P\(HAQB\)F59HV.png)

### 解题思路
直接 模拟机器人的行走，使用m[4]保存东南西北方向上行走的距离
机器人最多走4次题中的规则，就能形成一个环，4次不能形成环，就再也不能形成环了
所以我们模拟这个行走的规则4次，然后我们分别比较 南北方向和东西方向的距离，如果都相等，则返回true
反正 返回false

### 代码

```cpp
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int m[4]={0};
        int flag=0;
        for(int i=0;i<4*instructions.size();i++){
            int n=i%instructions.size();
            if(instructions[n]=='G')
                m[flag]++;
            else if(instructions[n]=='L'){
                flag+=3;
            }
            else if(instructions[n]=='R')
                flag+=1;
            flag=flag%4;
        }
        if(m[0]==m[2]&&m[1]==m[3])
            return true;
        return false;
    }
};
```