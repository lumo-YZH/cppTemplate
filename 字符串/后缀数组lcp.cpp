#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
 
#define MAX_N 10005
#define max(a, b) (a > b ? a : b)
 
char strA[MAX_N], strB[MAX_N], strC[MAX_N*2 + 5];
int sufArr[MAX_N], lcp[MAX_N], rank[MAX_N], temp[MAX_N];
int n, k;
 
bool compareSufArr(int i, int j) {
	int ri, rj;	
	
	if (rank[i] != rank[j]) {
		return rank[i] < rank[j];
	} else {
		ri = i + k <= n ? rank[i + k] : -1;
		rj = j + k <= n ? rank[j + k] : -1;
		return ri < rj;
	}
}
 
void constructSufArr(char* str, int* sa, int len) {
	int i;
	int n;
	n = len;
	for (i = 0; i <= n; i++) {
		sa[i] = i;
		rank[i] = i < n ? str[i] : -1;
	}
 
	for (k = 1; k <= n; k *= 2) {
		sort(sa, sa + n + 1, compareSufArr);
 
		temp[sa[0]] = 0;
		for (i = 1; i <= n; i++) {
			temp[sa[i]] = temp[sa[i - 1]] + (compareSufArr(sa[i - 1], sa[i]) ? 1 : 0);
		}
 
		for (i = 0; i <= n; i++) {
			rank[i] = temp[i];
		}
	}
}
 
// 构造后缀数组的lcp
void constructLcp(char* str, int* sa, int* cp, int len) {
	int i, j;
	int h;
 
	for (i = 0; i <= len; i++) {
		rank[sa[i]] = i;
	}
 
	h = 0;
	cp[0] = 0;
	for (i = 0; i < len; i++) {
		j = sa[rank[i] - 1];
 
		if (h > 0) {
			--h;
		}
 
		while (i + h < n && j + h < n && str[i + h] == str[j + h]) {
			++h;
		}
 
		cp[rank[i] - 1] = h;
	}
} // O(n)
 
 
// 求一个字符串中出现过的最长重复子串
int lrs(char* str) {
	int len;
	int res;
	int i;
	
	len = strlen(str);
	constructSufArr(str, sufArr, len);
	constructLcp(str, sufArr, lcp, len);
	
	res = 0;
	for (i = 0; i < len; i++) {
		res = max(res, lcp[i]);
	}
	
	return res;
}
 
// 求两个字符串的最长公共连续子串
int lcs(char* ms, char* ss) {
	int ml, sl, len;
	int res;
	int i;
 
	ml = strlen(ms), sl = strlen(ss);
 
	// strC = ms + '\0' + ss
	strcpy(strC, ms);
	strC[ml + 1] = '\0';
	strcpy(strC + ml + 2, ss);
 
	// 对strC求后缀数组和lcp
	len = ml + sl + 2;
	constructSufArr(strC, sufArr, len);
	constructLcp(strC, sufArr, lcp, len);
 
	//
	res = 0;
	for (i = 0; i < len; i++) {
		// 需要分属不同的字符串，否则就变成了在同一个字符串中求最长公共连续子串的长度
		if ((sufArr[i] < ml) != (sufArr[i + 1] < ml)) {
			res = max(res, lcp[i]);
		}
	}
 
	return res;
}
 
int main() {
 
	while (scanf("%s%s", strA, strB) != EOF) {
		printf("%d %d\n", lrs(strA), lrs(strB));
 
		printf("%d\n", lcs(strA, strB));
	}
 
	return 0;
}