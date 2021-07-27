#include <stdio.h>
long long A[1000000];
int main(void)
{
	long long  n, b, c, i, count = 0;
	scanf("%lld", &n);
	for (i = 0; i < n; i++)
		scanf("%lld", &A[i]);
	scanf("%lld %lld", &b, &c);
	for (i = 0; i < n; i++)
	{
		A[i] -= b; count++;
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		if (A[i] > 0)
		{
			if ((A[i] % c) != 0)
				count += (A[i] / c + 1);
			else
				count += (A[i] / c);
		}
	}
	printf("%lld", count);
}