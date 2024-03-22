#include<iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFESIBLE -1
//#define OVERFLOW -2
#define MAXSIZE 100

typedef int Status;
typedef int ElemType;

typedef struct SqList{
	ElemType *elem;
	int length;
}SqList;


//���Ա�L�ĳ�ʼ��(����������)
Status InitList_Sq(SqList& L) {  	//����һ���յ�˳���L
	L.elem = new ElemType[MAXSIZE];	//Ϊ˳������ռ�	
	if (!L.elem) exit(OVERFLOW);	//�洢����ʧ��
	L.length = 0;
	return OK;
}

//�������Ա�L
void DestroyList(SqList& L) {
	if (L.elem) delete L.elem;	//�ͷŴ洢�ռ�
}

//������Ա�L
void ClearList(SqList& L) {
	L.length = 0;	//�����Ա�ĳ�����Ϊ0
}

//�����Ա�L�ĳ���
int GetLength(SqList L) {
	return (L.length);
}

//�ж����Ա�L�Ƿ�Ϊ��
int IsEmpty(SqList L) {
	if (L.length == 0) return 1;
	else return 0;
}

//�߼�λ��(a1,a2...,an)������λ��(0,1,...n-1)���1

//˳����ȡֵ(����λ��i��ȡ��Ӧλ������Ԫ�ص�����)
int GetElem(SqList L, int i, ElemType& e) {
	if (i<1 || i>L.length) return ERROR;//�ж�iֵ�Ƿ����
	e = L.elem[i - 1];	//��i-1����Ԫ�洢�ŵ�i������
	return OK;
}

//˳���Ĳ���
int LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++)
		if (L.elem[i] == e) return i + 1;	//���ҳɹ���������ţ������λ���1
	return 0;
}

//˳���Ĳ���
Status ListInsert_Sq(SqList& L, int i, ElemType e) {
	if (i<1 || i>L.length + 1) return ERROR;	//iֵ���Ϸ�
	if (L.length == MAXSIZE) return ERROR;	//��ǰ�洢�ռ�����
	for (int j = L.length - 1; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j];	//����λ�ü�֮���Ԫ�غ���
	L.elem[i - 1] = e;				//����Ԫ��e�����i��λ��
	L.length++;
	return OK;
}


//˳����ɾ��
Status ListDelete_Sq(SqList& L, int i) {
	if ((i < 1) || (i > L.length)) return ERROR;	//iֵ���Ϸ�
	for (int j = i; j <= L.length - 1; j++)
		L.elem[j - 1] = L.elem[j];	//��ɾ��Ԫ��֮���Ԫ��ǰ��
	L.length--;
	return OK;
}

/*
���Ա�ĺϲ�
*/
void union_list(SqList& La, SqList Lb) {
	int La_len, Lb_len;
	ElemType e;
	La_len = GetLength(La);
	Lb_len = GetLength(Lb);
	for (int i = 1; i <= Lb_len; i++) {
		GetElem(Lb, i, e);
		if (!LocateElem(La, e))
			ListInsert_Sq(La, ++La_len, e);
	}
}

/*
�����ĺϲ�����˳���ʵ��
*/
void MergeList_Sq(SqList LA, SqList LB, SqList LC) {
	ElemType *pa, *pb, * pc;
	pa = LA.elem;
	pb = LB.elem;
	LC.length = LA.length + LB.length;
	LC.elem = new ElemType[LC.length];
	pc = LC.elem;
	ElemType* pa_last, * pb_last;
	pa_last = LA.elem + LA.length - 1;
	pb_last = LB.elem + LB.length - 1;
}

int main() {
	SqList La;
	SqList Lb;
	InitList_Sq(La);
	InitList_Sq(Lb);
	ListInsert_Sq(La, 1, 1);
	ListInsert_Sq(La, 2, 2);
	ListInsert_Sq(La, 3, 5);
	//La = [1, 2, 5]
	ListInsert_Sq(Lb, 1, 1);
	ListInsert_Sq(Lb, 2, 3);
	ListInsert_Sq(Lb, 3, 5);
	//Lb = [1, 3, 5]
	union_list(La, Lb);
	//Lc=[1,2,3,5]
	//printf(La)
	return 0;
}