#include <stdio.h>
int ans = 0;
void comb(int a[15], int b[15], int n, int l, int r, int x, int k)
{
	int i, count = 0, sum = 0, min = 987654321, max = -1;
	if (k == n)
	{
		for (i = 0; i < n; i++)
			if (b[i] == 1)
			{
				count++; sum += a[i];
				if (a[i] > max)max = a[i];
				if (a[i] < min)min = a[i];
			}
		if (count >= 2)
			if ((sum >= l) && (sum <= r) && (max - min >= x))ans++;
		return;
	}
	for (i = 1; i >= 0; i--)
	{
		b[k] = i;
		comb(a, b, n, l, r, x, k + 1);
	}
}
int main(void)
{
	int a[15], b[15], n, l, r, x, i;
	scanf("%d %d %d %d", &n, &l, &r, &x);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	comb(a, b, n, l, r, x, 0);
	printf("%d", ans);
}