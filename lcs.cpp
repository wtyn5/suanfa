
#include "pch.h"
#include<iostream>
using namespace std;

int lcs[100][100]; //
char track[100][100]; //
char S[100], T[100];


void LCS(int slen, int tlen) {
	int i, j;

	//初始化矩阵
	for (i = 0; i <= slen; i++) lcs[i][0] = 0;
	for (i = 0; i <= tlen; i++) lcs[0][i] = 0;


	for (i = 1; i <= slen; i++)
		for (j = 1; j <= tlen; j++) {
			if (S[i] == T[j]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
				track[i][j] = 'Q';  // 左上
			}

			if (S[i] != T[j]) {
				if (lcs[i - 1][j] >= lcs[i][j - 1]) {
					lcs[i][j] = lcs[i - 1][j];
					track[i][j] = 'W'; // 上
				}
				else {
					lcs[i][j] = lcs[i][j - 1];
					track[i][j] = 'A'; // 左
				}
			}
		}
}

void printLcs(int slen, int tlen) {
	int i, j;
	char q[100]; //存储LCS串的栈
	int top = 0; //栈顶
	i = slen;
	j = tlen;
	cout << "length:" << lcs[i][j] << endl;
	cout << "LCS:";
	while (i != 0 && j != 0) {
		if (track[i][j] == 'Q') {
			q[++top] = T[j];
			i--;
			j--;
		}
		else if (track[i][j] == 'A') {
			j--;
		}
		else {
			i--;
		}
	}
	while (top != 0)
		cout << q[top--];
}
	int main() {
		int n, m, i;
		cin >> n >> m;
		for (i = 1; i <= n; i++)cin >> S[i];
		for (i = 1; i <= m; i++)cin >> T[i];

		LCS(n, m);
		printLcs(n, m);
		return 0;
	}
