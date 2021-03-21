```
public class Solution {
    public string GetHint (string secret, string guess) {
        int bulls = 0; // 公牛
        int cows = 0; // 母牛
        int[] num = new int[10]; // 存储出现数字的个数(数字为下标, 个数为值)
        for (int i = 0; i < secret.Length; i++) {
            if (secret[i] == guess[i]) bulls++; // 数字&&位置相等，公牛++
            else {
                // 更新数组
                // 如果不相等则每次将 答案 和 猜测 记录到数组中
                if (num[(int) (secret[i] - '0')]++ < 0) cows++; // 记录增加第i位数字的个数, 注:如果此时比0小则母牛++
                if (num[(int) (guess[i] - '0')]-- > 0) cows++; // 记录减少第i位数字的个数，注:如果此时比0大则母牛++
                // 数组中每个数字默认是0, 然后遍历时判断个数的变化记录母牛
            }
        }
        return bulls + "A" + cows + "B";
    }
}
```

