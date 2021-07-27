#include <stdio.h>
int max = -1000000000, min = 1000000000;
void f(int N[11], int op[4], int b[10], int n, int k)
{
	int i;
	if (k == 0)
	{
		int sum = N[0];
		for (i = 0; i < n - 1; i++)
		{
			switch (b[i])
			{
			case 0:
				sum += N[i + 1];
				break;
			case 1:
				sum -= N[i + 1];
				break;
			case 2:
				sum *= N[i + 1];
				break;
			case 3:
				if (sum < 0)
				{
					sum = (((sum * -1) / N[i + 1]) * -1);
				}
				else sum /= N[i + 1];
				break;
			}
		}
		if (sum > max)max = sum;
		if (sum < min)min = sum;
		return;
	}
	for (i = 0; i < 4; i++)
	{
		if (op[i] > 0)
		{
			b[(n - 1) - k] = i;
			op[i]--;
			f(N, op, b, n, k - 1);
			op[i]++;
		}
	}
}
int main(void)
{
	int n, N[11], op[4], bucket[10], i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d", &N[i]);
	for (i = 0; i < 4; i++)scanf("%d", &op[i]);
	f(N, op, bucket, n, n - 1);
	printf("%d\n%d", max, min);
}