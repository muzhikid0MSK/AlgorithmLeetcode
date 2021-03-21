### 解题思路
一开始只想到了O(n^2)的方法，实际上还是对这个问题理解不够深刻。为什么可以使用贪婪？因为我们可以知道当前第n步最远能够走多远，不断递推，而这恰恰是这道题的另一个思考思路，题目的思考思路是到达终点最少多少步，这和n步最远能够走多远实际上是一致的。

我们维护一个变量`max_ind`代表第`cnt`步最远能够走多远，那么下一个`max_ind`的求法就是从当前位置`ind`到当前`max_ind`求一个能够走到的最远位置即为下一个`max_ind`，值得注意的是循环条件是`max_ind < len(nums) - 1`而不是`max_ind < len(nums)`这是因为如果退出循环则说明当前能够走到了`len(nums) - 1`或者更远的位置，也就是刚好能够抵达终点或者走到更远的位置，这是满足题意的。

### 代码

```python3
class Solution:
    def jump(self, nums: List[int]) -> int:
        if not nums:
            return 0
        cnt = 0
        max_ind = 0
        ind = 0
        while max_ind < len(nums) - 1:
            temp = []
            while ind <= max_ind:
                temp.append(ind + nums[ind])
                ind += 1
            max_ind = max(temp)
            cnt += 1
        return cnt
```