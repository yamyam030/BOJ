#include <stdio.h>
int main(void)
{
	int n, a[30000], i, index = 0, max = -1, cnt = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (i = 1; i < n ; i++)
	{
		if (a[index] > a[i])cnt++;
		else { cnt = 0; index = i; }
		if (cnt > max)max = cnt;
	}
	printf("%d", max);
}