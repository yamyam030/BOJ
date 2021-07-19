#include <stdio.h>
int max = 0;
void function(int a[2][15], int list[15], int s, int n)
{
	int i;

	for (i = s; i < n; i++)
	{
		if ((i + a[0][i]) <= n)
		{
			list[i] = 1;
			function(a, list, i + a[0][i], n);
			list[i] = 0;
		}
	}
	if (i >= n)
	{
		int sum = 0;
		for (i = 0; i < n; i++)
		{
			if (list[i] == 1)
			{
				sum += a[1][i];
			}
		}
		if (sum > max) max = sum;
		return;
	}
}
int main(void)
{
	int i, n;
	int a[2][15], list[15];
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &a[0][i], &a[1][i]);
		list[i] = 0;
	}

	function(a, list, 0, n);
	printf("%d", max);
}