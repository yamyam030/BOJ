#include <stdio.h>
int main(void)
{
	int a, b, c, x, y, sum = 0, big;
	scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
	big = (x > y) ? x : y;
	if (2 * c < a + b)
	{
		if (x > y) { sum += (2 * c * y); x -= y; y = 0; }
		else { sum += (2 * c * x); y -= x; x = 0; }
	}
	if (x > 0) sum += (a * x);
	if (y > 0) sum += (b * y);
	if ((2 * c * big) < sum)sum = (2 * c * big);
	printf("%d", sum);
}