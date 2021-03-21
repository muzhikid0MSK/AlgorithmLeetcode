### 解题思路
![屏幕快照 2020-08-26 19.30.52.png](https://pic.leetcode-cn.com/1598441463-GbYOgb-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-08-26%2019.30.52.png)
思路很简单
考虑长度为n的字符串，共有f(n)种，拿掉第一个数字，剩余长度n-1的字符串共有f(n-1)种。

按照这个思路，我们具体分情况讨论：
**当首位是0时，** 因为合法的编码不能从0开始，所以直接返回0。
**当首位是1时，** 此时考察下一位
- 下一位如果大于0，则此时f(n)=f(n-1)+f(n-2)
- 下一位如果等于0，这个0一定是跟随前一个的，所以此时f(n)=f(n-2)。

剩下就是等于2、大于3的情况，就不做具体分析了，可以直接看代码注释
另外注意控制一下越界的情况
同时加个备忘录，避免重复搜索

### 代码

```java
class Solution {
   private Integer[] mem;

    //A-1 B-2...Z-26
    public int numDecodings(String s) {
        if ("0".equals(s)) return 0;
        if (s.length() == 1) return 1;
        mem = new Integer[s.length()];
        return f(s, 0);
    }

    public int f(String s, int index) {
        //越界
        if (index >= s.length()) return 1;
        char c = s.charAt(index);
        //0开头，直接返回0
        if (c == '0') return 0;
        //就一个数字，直接返回1
        if (index == s.length() - 1) return 1;
        //优先从备忘录中找，找到则直接返回
        if (mem[index] != null) return mem[index];
        //大于等于3，因为最大26，3一定不会和下一位组成一个合法的编码f(n) = f(n-1)，
        if (c >= '3') {
            return f(s, index + 1);
        }
        //c=1或2
        char next = s.charAt(index + 1);
        //下一位等于0，0一定是和1或2一起的
        if (next == '0') {
            mem[index] = f(s, index + 2);
            return mem[index];
        }
        //下一位大于0且小于等于6，则有可能是单独的，也有可能和1或2一起
        if (next <= '6') {
            mem[index] = f(s, index + 1) + f(s, index + 2);
            return mem[index];
        }
        //c=1或2，但next>=7
        if (c == '1') {
            mem[index] = f(s, index + 1) + f(s, index + 2);
            return mem[index];
        }
        //c=2,next>7
        mem[index] = f(s, index + 1);
        return mem[index];

    }
}
```