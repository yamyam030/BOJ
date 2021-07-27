#include <stdio.h>
int min = 1000;
int comb2(int a[20][20], int b[20], int bSize, int c[2], int s, int k)
{
	int i, sum = 0;
	if (k == 0)
		return (a[c[0]][c[1]] + a[c[1]][c[0]]);
	for (i = s; i < bSize; i++)
	{
		c[2 - k] = b[i];
		sum += comb2(a, b, bSize, c, i + 1, k - 1);
	}
	return sum;
}
void comb1(int a[20][20], int n, int b1[20], int bSize, int s, int k)
{
	int i, j, index = 0, find, b2[20];
	if (k == 0)
	{
		for (i = 0; i < n; i++)
		{
			find = 0;
			for (j = 0; j < bSize; j++)
			{
				if (b1[j] == i)
				{
					find = 1; break;
				}
			}
			if (find == 0)
				b2[index++] = i;
		}
		int c[2];
		int num1 = comb2(a, b1, bSize, c, 0, 2);
		int num2 = comb2(a, b2, bSize, c, 0, 2);
		int rslt = num1 - num2;
		if (rslt < 0)rslt *= -1;
		min = (min > rslt) ? rslt : min;
		return;
	}

	for (i = s; i < n; i++)
	{
		b1[bSize - k] = i;
		comb1(a, n, b1, bSize, i + 1, k - 1);
	}
}
int main(void)
{
	int a[20][20], bucket[20];
	int i, j, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	comb1(a, n, bucket, n / 2, 0, n / 2);
	printf("%d", min);
}