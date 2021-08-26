#include <stdio.h>
int v[4000][4000], min = 987654321;
void f(int i, int j, int k, int n)
{
	int l, sum = 0;
	for (l = 0; l < n; l++)
	{
		if ((l == i) || (l == j) || (l == k))continue;
		if (v[i][l] == 1)sum++;
		if (v[j][l] == 1)sum++;
		if (v[k][l] == 1)sum++;
	}
	if (sum < min)min = sum;
}
int main(void)
{
	int n, m, i, j, k, a, b;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		v[a - 1][b - 1] = 1; v[b - 1][a - 1] = 1;
	}
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
		{
			if (v[i][j] == 1)
			{
				for (k = j + 1; k < n; k++)
				{
					if (v[i][k] == 1)
						if ((v[i][j] == 1) && (v[i][k] == 1) && (v[j][k] == 1))
							f(i, j, k, n);
				}
			}

		}
	if (min == 987654321)min = -1;
	printf("%d", min);
}