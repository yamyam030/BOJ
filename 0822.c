#include <stdio.h>
int main(void)
{
	int n, i, j, dp[1001], p[1001], max;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	dp[1] = p[1];
	for (i = 2; i <= n; i++)
	{
		max = -1;
		for (j = 1; j < i; j++)
		{
			max = (dp[i - j] + dp[j] > max) ? dp[i - j] + dp[j] : max;
		}
		dp[i] = (p[i] > max) ? p[i] : max;
	}
	printf("%d", dp[n]);
}