#include <stdio.h>
int x[4] = { -1,0,1,0 }, y[4] = { 0,1,0,-1 }, max = -1;
void swap(char a[50][50], int i, int j, int n1, int n2)
{
	char t = a[i][j];
	a[i][j] = a[n1][n2];
	a[n1][n2] = t;
}
int check(char a[50][50], int r, int c, int i, int j, int n, int l)
{
	int count = 0;
	while ((r >= 0) && (r < n) && (c >= 0) && (c < n))
	{
		if (a[r][c] != a[i][j])break;
		r += x[l]; c += y[l];
		count++;
	}
	return count;
}
void search(char a[50][50], int n, int i, int j, int k)
{
	int r, c, l, count = 1;
	swap(a, i, j, i + x[k], j + y[k]);
	for (l = 0; l < 2; l++)
	{
		count = 1;
		r = i + x[l]; c = j + y[l];
		count += check(a, r, c, i, j, n, l);
		r = i + x[l + 2]; c = j + y[l + 2];
		count += check(a, r, c, i, j, n, l + 2);
		if (count > max)max = count;
	}
	for (l = 0; l < 2; l++)
	{
		count = 1;
		r = i + x[l]; c = j + y[l];
		count += check(a, r, c, i, j, n, l);
		r = i + x[l + 2]; c = j + y[l + 2];
		count += check(a, r, c, i, j, n, l + 2);
		if (count > max)max = count;
	}
	swap(a, i + x[k], j + y[k], i, j);
}
int main(void)
{
	char a[50][50];
	int i, j, k, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s", a[i]);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			for (k = 0; k < 4; k++)
				if ((i + x[k] >= 0) && (i + x[k] < n) && (j + y[k] >= 0) && (j + y[k] < n))
					search(a, n, i, j, k);
	printf("%d", max);
}