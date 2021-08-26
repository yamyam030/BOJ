#include <stdio.h>
int main(void)
{
	long long int i, n, f[1000], size, cnt = 0;
	scanf("%lld", &n);
	for (i = 0; i < n; i++)
		scanf("%lld", &f[i]);
	scanf("%lld", &size);
	for (i = 0; i < n; i++)
	{
		cnt += (f[i] / size);
		if ((f[i] % size) != 0)cnt += 1;
	}
	printf("%lld", (size * cnt));
}