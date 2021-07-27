#include <stdio.h>
int rank[49];
void dungchi(int x[49], int y[49], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if ((x[i] < x[j]) && (y[i] < y[j]))rank[i] += 1;
}
int main(void)
{
	int n, i, x[49], y[49];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d %d", &x[i], &y[i]);
	dungchi(x, y, n);
	for (i = 0; i < n; i++)
		printf("%d ", rank[i] + 1);
}