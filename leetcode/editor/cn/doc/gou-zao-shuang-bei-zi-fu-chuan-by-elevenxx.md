- 假设 s 可由 子串 x 重复 n 次构成，即 s = nx
- 则有 s+s = 2nx
- 移除 s+s 开头和结尾的字符，变为 (s+s)[1:-1]，则破坏了开头和结尾的子串 x
- 此时只剩 2n-2 个子串
- 若 s 在 (s+s)[1:-1] 中，则有 2n-2 >= n，即 n >= 2
- 即 s 至少可由 x 重复 2 次构成
- 否则，n < 2，n 为整数，只能取 1，说明 s 不能由其子串重复多次构成

```python3 []
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        return s in (s+s)[1:-1]
```


参考：
[https://leetcode-cn.com/problems/repeated-substring-pattern/solution/guan-yu-gou-zao-ssjin-xing-pan-duan-de-zheng-ming-/]()