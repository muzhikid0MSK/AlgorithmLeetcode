### 解题思路

状态转移方程：
path(i,j) = min{path(i-1,j)+path(i-1,j-1)}+triangle(i,j);
注意控制边界
计算完成后，直接遍历path的最后一行，取最小值

### 代码

```java
class Solution {
    private int[][] path;

    public int minimumTotal(List<List<Integer>> triangle) {
        if (triangle.size() == 0) return 0;
        path = new int[triangle.size()][triangle.size()];
        path[0][0] = triangle.get(0).get(0);
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j <= i; j++) {
                int pre;//到上一级相邻节点的最小值
                if (j == 0) pre = path[i - 1][0];
                else if (j == i) pre = path[i - 1][j - 1];
                else pre = Math.min(path[i - 1][j], path[i - 1][j - 1]);
                path[i][j] = pre + triangle.get(i).get(j);
            }
        }
        //取path最后一行的最小值
        int i = triangle.size();
        int min = path[i - 1][0];
        for (int j = 1; j < i; j++) {
            min = Math.min(min, path[i - 1][j]);
        }
        return min;
    }
}
```