#include <stdio.h>
int main(void)
{
	int H1, M1, H2, M2, check = 0;
	scanf("%d %d", &H1, &M1);
	if (M1 - 45 < 0)
	{
		M2 = 60 - (45 - M1); check = 1;
	}
	else M2 = M1 - 45;
	if (check == 1)
	{
		if (H1 - 1 < 0)H2 = 24 - 1;
		else H2 = H1 - 1;
	}
	else H2 = H1;
	printf("%d %d", H2, M2);
}