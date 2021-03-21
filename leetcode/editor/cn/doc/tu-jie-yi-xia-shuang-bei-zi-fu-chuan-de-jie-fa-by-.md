> 看到 "大力王" 大佬的双倍字符串解法，把我下巴都惊掉了，真的太强了！

****
开局贴代码，剩下全靠图~
```
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s+s).find(s, 1) != s.size();
    }
};
```

### 当 s 没有循环节时：
如果 s 中没有循环节，那么 ss 中必然有且只有两个 s，此时从 ss[1] 处开始寻找 s ，必然只能找到**第二个**，所以此时返回值为 s.size()。
 ![image.png](https://pic.leetcode-cn.com/1598227887-eIftIu-image.png)

### 当 s 有循环节时：
当 s 中有循环节时，设循环节为 r，其长度为 l，那么 ss 中必然有 s.size()/l + 1 个 s。
因为去掉了第一个 S 的第一个字符 (代码中，(s+s).find(s, 1)， 是从 ss[1] 处开始 find )
所以此时必回找到第二个 s 的起点。

![image.png](https://pic.leetcode-cn.com/1598228553-dXojLo-image.png)


****

## 如果感觉有点意思，那就关注一下【[我的公众号](https://blog.csdn.net/Time_Limit/article/details/108179387)】吧~