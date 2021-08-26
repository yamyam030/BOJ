#include <stdio.h>
int Rev(int n)
{
	int rslt = 0;
	while (n != 0)
	{
		rslt = rslt * 10 + n % 10;
		n /= 10;
	}
	return rslt;
}
int main(void)
{
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%d", Rev((Rev(x) + Rev(y))));
}