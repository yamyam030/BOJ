#include <stdio.h>
#define MAX_SIZE 100001
char stack[MAX_SIZE];
int top = -1;
int full()
{
	if (top >= MAX_SIZE)return 1;
	return 0;
}
int empty()
{
	if (top < 0)return 1;
	return 0;
}
void push(char c)
{
	if (full()) return;
	else { stack[++top % MAX_SIZE] = c; }
}
void pop()
{
	if (empty()) return;
	else { top--; }
}
char word[100][100001];
int main(void)
{
	int t, i, j, count = 0;
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		while (getchar() != '\n');
		scanf("%s", word[i]);
		top = -1;
		for (j = 0; word[i][j] != '\0'; j++)
		{
			if (word[i][j] != stack[top])push(word[i][j]);
			else pop();
		}
		if (empty())count++;
	}
	printf("%d", count);
}