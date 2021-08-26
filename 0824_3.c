#include <stdio.h>
int main(void)
{
	int n, temp, len = 0, sum = 0;
	scanf("%d", &n);
	temp = n;
	sum = (n / 10) + (n % 10);
	temp = (n % 10) * 10 + (sum % 10);
	len++;
	while (temp != n)
	{
		sum = (temp / 10) + (temp % 10);
		temp = (temp % 10) * 10 + (sum % 10);
		len++;
	}
	printf("%d", len);
}