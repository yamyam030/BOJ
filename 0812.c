#include <stdio.h>
#include <math.h>
int min = 987654321;
void pick(int index, int a[50][50], int c[13][2], int bucket[13], int bucketSize, int k, int n, int m) {
	int i, j, l, lastIndex, smallest, item, sum = 0, compare, temp;
	if (k == 0) {
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (a[i][j] == 1)
				{
					compare = 987654321;
					for (l = 0; l < bucketSize; l++)
					{
						temp = abs(i - c[bucket[l]][0]) + abs(j - c[bucket[l]][1]);
						compare = (temp < compare) ? temp : compare;
					}
					sum += compare;
				}
			}
		}
		if (sum != 0)
			min = (sum < min) ? sum : min;
		return;
	}
	lastIndex = bucketSize - k - 1;
	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;
	for (item = smallest; item < index; item++) {
		bucket[lastIndex + 1] = item;
		pick(index, a, c, bucket, bucketSize, k - 1, n, m);
	}
}
int main(void)
{
	int n, m, i, j, a[50][50], sum = 0, chicken[13][2], index = 0, b[13];
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
			if (a[i][j] == 2) { chicken[index][0] = i; chicken[index][1] = j; b[index] = 0; index++; }
		}
	pick(index, a, chicken, b, m, m, n, m);
	printf("%d", min);
}