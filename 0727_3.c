#include <stdio.h>
int main(void)
{
	int a[4], i, n, count = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		int temp = i, lastIndex = 0;
		while (temp != 0)
		{
			a[lastIndex++] = (temp % 10);
			temp /= 10;
		}
		int gap = a[0] - a[1], j = 1, rslt = 1;
		while ((j + 1) < lastIndex)
		{
			if ((a[j] - a[j + 1]) != gap) { rslt = -1; break; }
			j++;
		}
		if (rslt == 1)count++;
	}
	printf("%d", count);
}/