**解题思路**
动态规划的主要思路和官方题解类似，不再赘述；
本解法主要是将空间复杂度降至O(n)，仅使用一个一维数组维护当前最短路径:
- 当i == 0 && j == 0时（即遍历第一个数时），cur[j] = grid[i][j];
- 当i == 0 && j >= 1时（即遍历第一行数时），cur[j] =cur[j - 1] + grid[i][j];
- 当i >= 1 && j == 0时（即遍历第一列数时），cur[j] =cur[j] + grid[i][j];
- 当i >= 1 && j >= 0时（其余大部分情况时），cur[j] = Math.min(cur[j - 1], cur[j]) + grid[i][j];
类比于官方题解中的dp方程：dp[i][j]=min(dp[i−1][j],dp[i][j−1])+grid[i][j], 
cur[j - 1]就相当于dp[i][j−1],cur[j]就相当于dp[i−1][j];
最后的结果就是cur[cur.length - 1]

**复杂度分析**
时间复杂度：O(mn)
空间复杂度：O(n)
```
class Solution {
    public int minPathSum(int[][] grid) {
        if(grid.length == 0){
            return -1;
        }
        int[] cur = new int[grid[0].length];
        for(int i = 0; i < grid.length; ++i){
            for(int j = 0; j < cur.length; ++j){
                if(i == 0 && j >= 1){
                    cur[j] =cur[j - 1] + grid[i][j];
                }else if(i == 0 && j == 0){
                    cur[j] = grid[i][j];
                }else if(i >= 1 && j == 0){
                    cur[j] =cur[j] + grid[i][j];
                }else{
                    cur[j] = Math.min(cur[j - 1], cur[j]) + grid[i][j];
                }
            }
        }
        return cur[cur.length - 1];
    }           
}
```
