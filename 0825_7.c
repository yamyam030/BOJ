#include <stdio.h>
int main(void)
{
	int n, k, i, sum = 0, a[10], cnt = 0;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (i = n - 1; i >= 0; i--)
		if ((k / a[i]) > 0) 
		{
			cnt += k / a[i]; k -= (k / a[i]) * a[i];
		}
	printf("%d", cnt);
}