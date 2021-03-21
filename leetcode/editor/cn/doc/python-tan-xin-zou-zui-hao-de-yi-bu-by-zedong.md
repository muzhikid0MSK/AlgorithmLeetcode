### 解题思路
如果有一步不这么走, 那下一步的可能考虑要走的元素就可能会少.
关键是这一行, 给每元素一个价值. `nums[cur+i]+i>=nums[cur+best_off]+best_off`
### 代码

```python3
class Solution:
    def jump(self, nums: List[int]) -> int:
        def nextBest(nums, cur, step) -> int:
            if cur == len(nums)-1:  # 终点或者止步不前.
                return step
            elif cur+nums[cur]>=len(nums)-1: 
                return nextBest(nums,len(nums)-1, step+1)
            else:
                best_off = 1
                for i in range(1,nums[cur]+1):
                    if nums[cur+i]+i>=nums[cur+best_off]+best_off:
                        best_off = i
                return nextBest(nums,cur+best_off,step+1)

        return nextBest(nums,0,0)
```