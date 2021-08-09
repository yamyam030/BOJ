#include <stdio.h>
#include <stdlib.h>
int max = -1;
void comb(int *a, int *bucket, int n, int b, int k)
{
	int i, item, num = 0, len = 0;
	if (k == 0)
	{
		for (i = 0; i < n; i++)
		{
			num *= 10;
			num += (a[bucket[i]]);
		}
		for (i = num; i != 0; i /= 10)len++;
		if ((num < b) && (num > max) && (n == len))max = num;
		return;
	}
	item = (n - k);
	for (i = 0; i < n; i++)
	{
		if (bucket[i] == -1) 
		{
			bucket[i] = item; comb(a, bucket, n, b, k - 1); bucket[i] = -1; 
		}
	}
}
int main(void)
{
	int* a2, * bucket, a, b, c, i, len = 0;
	scanf("%d %d", &a, &b);
	for (i = a; i != 0; i /= 10)len++;
	a2 = (int*)malloc(sizeof(int) * len);
	bucket = (int*)malloc(sizeof(int) * len);
	for (i = 0; i < len; i++)bucket[i] = -1;
	for (i = len - 1; i >= 0; i--) { a2[i] = a % 10; a /= 10; }
	comb(a2, bucket, len, b, len);
	printf("%d", max);
}