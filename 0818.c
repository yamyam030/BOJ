#include <stdio.h>
int main(void)
{
	long long int n, i, k;
	scanf("%lld", &n);
	for (k = 2; k <= n; k *= 2);
	while (k > 1)
	{
		k /= 2;
		printf("%lld", n / k);
		n %= k;
	}
}