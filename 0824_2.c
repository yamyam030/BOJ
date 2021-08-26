#include <stdio.h>
#define MAX 100000
int top = -1, stack[MAX];
int empty()
{
	if (top <= -1) return 1;
	return 0;
}
int full()
{
	if (top >= MAX)return 1;
	return 0;
}
void push(int n)
{
	if (!full())stack[++top] = n;
}
void pop()
{
	if (!empty()) stack[top--];
}
int main(void)
{
	int n, i, a, sum = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (a == 0)pop();
		else push(a);
	}
	for (i = 0; i <= top; i++)sum += stack[i];
	printf("%d", sum);
}