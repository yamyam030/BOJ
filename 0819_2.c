#include <stdio.h>
#include <stdlib.h>
int l[6][3], min = 987654321, v[6];
void calculate(int** a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < m; j++)
			sum += a[i][j];
		if (min > sum)min = sum;
	}
}
void spin(int** a, int** copy, int r, int c, int s)
{
	int i, j, k, sR, sC, eR, eC;
	for (k = 0; k < s; k++)
	{
		sR = r - s + k; sC = c - s + k; eR = r + s - k; eC = c + s - k;
		for (j = sC; j < eC; j++)
			copy[sR][j + 1] = a[sR][j];
		for (i = sR; i < eR; i++)
			copy[i + 1][eC] = a[i][eC];
		for (j = eC; j > sC; j--)
			copy[eR][j - 1] = a[eR][j];
		for (i = eR; i > sR; i--)
			copy[i - 1][sC] = a[i][sC];
	}
}
void copyList(int** a, int** copy, int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			copy[i][j] = a[i][j];
}
void comb(int** copy, int** copy2, int b[6], int n, int m, int k, int c, int** a)
{
	int i, lastIndex, item;
	if (c == 0)
	{
		for (i = 0; i < k; i++)
		{
			spin(copy, copy2, l[b[i]][0], l[b[i]][1], l[b[i]][2]);
			copyList(copy2, copy, n, m);
		}
		calculate(copy, n, m);
		copyList(a, copy, n, m);
		copyList(a, copy2, n, m);
		return;
	}
	lastIndex = k - c - 1;
	for (i = 0; i < k; i++)
	{
		if (v[i] != 1)
		{
			v[i] = 1;
			b[lastIndex + 1] = i;
			comb(copy, copy2, b, n, m, k, c - 1, a);
			v[i] = 0;
		}
	}
}
int main(void)
{
	int n, m, k, ** a, ** copy, ** copy2, i, j, b[6];
	scanf("%d %d %d", &n, &m, &k);
	a = (int**)malloc(sizeof(int*) * n);
	copy = (int**)malloc(sizeof(int*) * n);
	copy2 = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
	{
		a[i] = (int*)malloc(sizeof(int) * m);
		copy[i] = (int*)malloc(sizeof(int) * m);
		copy2[i] = (int*)malloc(sizeof(int) * m);
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	copyList(a, copy, n, m);
	copyList(a, copy2, n, m);
	for (i = 0; i < k; i++)
	{
		scanf("%d %d %d", &l[i][0], &l[i][1], &l[i][2]);
		l[i][0]--; l[i][1]--;
	}
	comb(copy, copy2, b, n, m, k, k, a);
	printf("%d", min);
}