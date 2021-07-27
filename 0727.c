#include <stdio.h>
int a[10001];
void f()
{
	int i, temp, sum;
	for (i = 1; i <= 10000; i++)
	{
		temp = i; sum = i;
		while (temp != 0)
		{
			sum += (temp % 10);
			temp /= 10;
		}
		if (sum != i)a[sum] += 1;
	}
	return;
}
int main(void)
{
	int i;
	for (i = 1; i <= 10000; i++)
		a[i] = 0;
	f();
	for (i = 1; i <= 10000; i++)
		if (a[i] == 0)
			printf("%d\n", i);
}