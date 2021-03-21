### 解题思路
分析下标的规律吧。。别的没啥

### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) return s;
        StringBuilder builder = new StringBuilder();
        int maxStep = (numRows - 1) * 2;
        for (int level = 1; level <= numRows; level++) {
            //非首行和末行，step1不为空，要多追加一个
            int step1 = (numRows - level) * 2;
            int currLvlStartIndex = level - 1;

            while (currLvlStartIndex < s.length()) {
                builder.append(s.charAt(currLvlStartIndex));
                if (step1 < maxStep && step1 > 0 && step1 + currLvlStartIndex < s.length()) {
                    builder.append(s.charAt(step1 + currLvlStartIndex));
                }
                currLvlStartIndex += maxStep;
            }
        }
        return builder.toString();
    }
}
```