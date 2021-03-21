### 解题思路
![image.png](https://pic.leetcode-cn.com/fcbad7eb94659a3ed466847f0b9a43968b8b6c78f83d5047e90eb7bad66b4677-image.png)

方法简单 但是一开始我用的是4个变量 然后switch语句 耗时20ms
然后，实践证明这样写速度更快了，也没有付出太多的内存代价。
内存消耗从8.1MB提高到8.2MB，用时从20ms降到8ms。


### 代码

```cpp
class Solution {
public:
    bool judgeCircle(string moves) {
        int count[86] = { 0 };
		for (int i = 0; i < moves.length(); ++i)
			++count[moves[i]];
		return count['L'] == count['R'] && count['U'] == count['D'];
    }
};
```