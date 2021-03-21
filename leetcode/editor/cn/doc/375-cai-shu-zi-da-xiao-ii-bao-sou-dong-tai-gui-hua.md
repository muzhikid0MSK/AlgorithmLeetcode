题目：
我们正在玩一个猜数游戏，游戏规则如下：

我从 1 到 n 之间选择一个数字，你来猜我选了哪个数字。

每次你猜错了，我都会告诉你，我选的数字比你的大了或者小了。

然而，当你猜了数字 x 并且猜错了的时候，你需要支付金额为 x 的现金。直到你猜到我选的数字，你才算赢得了这个游戏。

**示例:**

    n = 10, 我选择了8.

    第一轮: 你猜我选择的数字是5，我会告诉你，我的数字更大一些，然后你需要支付5块。
    第二轮: 你猜是7，我告诉你，我的数字更大一些，你支付7块。
    第三轮: 你猜是9，我告诉你，我的数字更小一些，你支付9块。

    游戏结束。8 就是我选的数字。

    你最终要支付 5 + 7 + 9 = 21 块钱。
给定 n ≥ 1，计算你至少需要拥有多少现金才能确保你能赢得这个游戏。

1. 暴力解（TLE）  时间复杂度: O(N!) 空间复杂度： O(N)
我们首先在(1, n)中任意挑选一个数字i， 假设i是错误的（最坏情况）， 我们需要用最小代价去
猜到需要的数字。那么在一次尝试后，答案要么在i的左边， 要么在i的右边， 为了考虑最差的情况，我们
需要考虑两者的较大值。
cost(1,n) = i + max( cost(1, i - 1), cost(i + 1), n))
	

```
    public int cost(int l, int r){
        if(l >= r)  return 0;
        int min = Integer.MAX_VALUE;
        for(int i = l; i <= r; i++){
            int res = i + Math.max(cost(l, i - 1), cost(i + 1, r));
            min = Math.min(min, res);
        }
        return min;
    }

    public int getMoneyAmount(int n){
        return cost(1, n);
    }
```

2. Dp， 从暴力解可以看出， 大区间的猜数字的成本求解， 可以由小区间计算出来。
时间复杂度： O(N ^ 3), 空间复杂度O(N ^ 2)

![猜数字大小.png](https://pic.leetcode-cn.com/d914b275262a326c43892768e81acffdc97892192b40cd24345dbde739a402ff-%E7%8C%9C%E6%95%B0%E5%AD%97%E5%A4%A7%E5%B0%8F.png)
```
    public int getMoneyAmount(int n){
        int[][] dp = new int[n + 1][n + 1];
        for(int len = 2; len <= n; len ++){
            for(int i = 1; i + len - 1 <= n; i++){
                int j = i + len - 1;
                dp[i][j] = Integer.MAX_VALUE;
                for(int k = i; k <= j; k++){
                    dp[i][j] = Math.min(dp[i][j],
                            k + Math.max(k <= 1 ? 0 : dp[i][k - 1],
                                    k + 1 > j ? 0: dp[k + 1][j]));
                }
            }
        }
        return dp[1][n];
    }
```

