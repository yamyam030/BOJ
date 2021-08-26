#include <stdio.h>
int v[200][200], ans = 0;
void f(int b[3], int n, int r, int k) 
{
	int item, lastIndex, smallest;
	if (k == 0)
	{
		if ((v[b[0]][b[1]] != 1) && (v[b[0]][b[2]] != 1) && (v[b[1]][b[2]] != 1))
			ans++;
		return;
	}
	lastIndex = r - k - 1;
	if (r == k)
		smallest = 0;
	else
		smallest = b[lastIndex] + 1;
	for (item = smallest; item < n; item++) 
	{
		b[lastIndex + 1] = item;
		f(b, n, r, k - 1);
	}
}
int main(void)
{
	int n, m, i, a, b, bucket[3];
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		v[a - 1][b - 1] = 1; v[b - 1][a - 1] = 1;
	}
	f(bucket, n, 3, 3);
	printf("%d", ans);
}