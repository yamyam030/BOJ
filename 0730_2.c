#include <stdio.h>
long long int f(long long int x, long long int y)
{
	long long int count = 0, i, k = 1;
	for (k = 1; ; k++)
	{
		x += k; count++;
		if (x >= y) { break; }
		y -= k; count++;
		if (x >= y) { break; }
	}
	return count;
}
int main(void)
{
	long long int t, x, y, i;
	scanf("%lld", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%lld %lld", &x, &y);
		printf("%lld\n", f(x, y));
	}
}