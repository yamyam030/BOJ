#include <stdio.h>
int main(void)
{
	float sum = 0, ave = 0, max = -1;
	int i, n, a[1000];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] > max)max = a[i];
	}
	for (i = 0; i < n; i++)
		sum += ((double)a[i] / max * 100);
	printf("%g", (sum / (double)n));
}