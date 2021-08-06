#include <stdio.h>
int main(void)
{
	int H, W, n, i, R[100], C[100], check = 0, sum = 0, max = -1;
	scanf("%d %d", &H, &W);
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d %d", &R[i], &C[i]);
	for (i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			check = 0;
			if (C[i] + C[j] <= W)
				if ((R[i] <= H) && (R[j] <= H)) { sum = (R[i] * C[i] + R[j] * C[j]); check = 1; }
			if (C[i] + R[j] <= W)
				if ((R[i] <= H) && (C[j] <= H)) { sum = (R[i] * C[i] + R[j] * C[j]); check = 1; }
			if (R[i] + R[j] <= H)
				if ((C[i] <= W) && (C[j] <= W)) { sum = (R[i] * C[i] + R[j] * C[j]); check = 1; }
			if (R[i] + C[j] <= H)
				if ((C[i] <= W) && (R[j] <= W)) { sum = (R[i] * C[i] + R[j] * C[j]); check = 1; }
			if (R[i] + C[j] <= W)
				if ((C[i] <= H) && (R[j] <= H)) { sum = (R[i] * C[i] + R[j] * C[j]); check = 1; }
			if (R[i] + R[j] <= W)
				if ((C[i] <= H) && (C[j] <= H)) { sum = (R[i] * C[i] + R[j] * C[j]); check = 1; }
			if (C[i] + R[j] <= H)
				if ((R[i] <= W) && (C[j] <= W)) { sum = (R[i] * C[i] + R[j] * C[j]); check = 1; }
			if (C[i] + C[j] <= H)
				if ((R[i] <= W) && (R[j] <= W)) { sum = (R[i] * C[i] + R[j] * C[j]); check = 1; }
			if (check == 1)
				if (sum > max)max = sum;
		}
	}
	if (max == -1)max = 0;
	printf("%d", max);
}