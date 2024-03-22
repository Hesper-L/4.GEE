#include<iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFESIBLE -1
#define OVERFLOW -2

typedef int Status;

typedef struct PNode {
	float coef;
	int expn;
	PNode* next;
}PNode,*Polynomial;

//多项式创建
void CreatePolyn(Polynomial& P, int n) {
	P = new PNode;
	P->next = NULL;
	for (int i = 1; i <= n; i++) {
		PNode *s, *pre, *q;
		s = new PNode;
		cin >> s->coef >> s->expn;
		pre = P;
		q = P->next;
		while (q && q->expn < s->expn) {
			pre = q;
			q = q->next;
		}
		s->next=q;
		pre->next = s;
	}
}

//多项式相加
