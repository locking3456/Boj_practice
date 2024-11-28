#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <vector>
using namespace std;
int alpha = 65;
//26개의 원소를 0으로 초기화
struct node {
	char left;
	char right;
};
vector<node> v(26);
void preOrder(char node) {
	if (node == '.'-alpha)
		return;

	printf("%c", node + alpha);
	preOrder(v[node].left);
	preOrder(v[node].right);
}
void inOrder(char node) {
	if (node == '.'-alpha)
		return;

	inOrder(v[node].left);
	printf("%c", node + alpha);
	inOrder(v[node].right);
}
void postOrder(char node) {
	if (node == '.'-alpha)
		return;

	postOrder(v[node].left);
	postOrder(v[node].right);
	printf("%c", node + alpha);
}
int main() {
	int N;
	scanf("%d", &N);
	getchar();
	char parent, leftchild, rightchild;
	for (int i = 0; i < N; i++) {
		scanf("%c %c %c", &parent , &leftchild , &rightchild);
		getchar();
		v[parent-alpha].left = leftchild-alpha;
		v[parent-alpha].right = rightchild-alpha;
	}

	preOrder('A'-alpha);
	printf("\n");
	inOrder('A'-alpha);
	printf("\n");
	postOrder('A'-alpha);
	return 0;
}