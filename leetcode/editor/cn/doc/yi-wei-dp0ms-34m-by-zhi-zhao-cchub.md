dp[i][j] 表示以[i][j]为右下端点的正方形的边长
if matrix[i][j] == 0; dp[i][j] = 0
if matrix[i][j] == 1; dp[i][j] = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1])+1
```
func maximalSquare(matrix [][]byte) int {
	if len(matrix) == 0 {
		return 0
	}
	m, n, maxside := len(matrix), len(matrix[0]), 0
	dp := make([]int, n)

	for i := 0; i < m; i++ {
		northwest := 0
		for j := 0; j < n; j++ {
			if i == 0 || j == 0 {
				dp[j] = int(matrix[i][j] - '0')
			} else if matrix[i][j] == '1' {
				dp[j], northwest = min(dp[j-1], min(dp[j], northwest))+1, dp[j]
			} else {
				dp[j], northwest = 0, dp[j]
			}
			if dp[j] > maxside {
				maxside = dp[j]
			}
		}
	}
	return maxside * maxside
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
```
