#include <stdio.h>
int time = 0;
void move(int array[200], int n)
{
	int i, temp = array[2 * n - 1];
	for (i = (2 * n - 2); i >= 0; i--)
		array[i + 1] = array[i];
	array[0] = temp;
	return;
}
void f(int N[200], int R[200], int n, int k)
{
	int i, count = 0;
	while (1)
	{
		time++;
		move(N, n); move(R, n);
		if (R[n - 1] == 1)R[n - 1] = 0;
		for (i = (n - 2); i >= 0 ; i--)
		{
			if ((R[i] == 1) && (N[i + 1] > 0) && (R[i + 1] == 0))
			{
				R[i + 1] = 1;
				R[i] = 0;
				N[i + 1] -= 1;
			}
		}
		if (R[n - 1] == 1)R[n - 1] = 0;
		if ((N[0] > 0) && (R[0] == 0)) { R[0] = 1; N[0] -= 1; }
		count = 0;
		for (i = 0; i < (2 * n); i++)
		{
			if (N[i] == 0)count++;
		}
		if (count >= k)return;
	}
}
int main(void)
{
	int n, k, i, N[200], R[200];
	scanf("%d %d", &n, &k);
	for (i = 0; i < (2 * n); i++)
	{
		scanf("%d", &N[i]);
		R[i] = 0;
	}
	f(N, R, n, k);
	printf("%d", time);
}//0718