#include <stdio.h>
struct activity {
	int start;
	int end;
	int time;
}A[130];
void sort(activity A[], int n) {
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 1; j < n - i; j++)
		{
			if (A[j - 1].end > A[j].end)
			{
				int temp = A[j - 1].end;
				A[j - 1].end = A[j].end;
				A[j].end = temp;
				temp = A[j - 1].start;
				A[j - 1].start = A[j].start;
				A[j].start = temp;
				temp = A[j - 1].time;
				A[j - 1].time = A[j].time;
				A[j].time = temp;
			}
		}
	}
}
int f(activity A[], int n) {
	int k = 1;
	int lastend = A[0].end;
	for (int i = 1; i < n; i++)
	{
		if (A[i].start > lastend)
		{
			k++;
			lastend = A[i].end;
		}
	}
	return k;
}
int main() {
	int l, i;
	printf("输入活动数:\n");
	scanf("%d", &l);
	printf("输入活动开始和结束时间:\n");
	for (i = 0; i < l; i++) {
		scanf("%d", &A[i].start);
		scanf("%d", &A[i].end);
		A[i].time = A[i].end - A[i].start;
	}
	sort(A, l);
	printf("最多能安排的活动数量为:\n");
	printf("%d", f(A, l));
}