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


//线性表L的初始化(参数用引用)
Status InitList_Sq(SqList& L) {  	//构造一个空的顺序表L
	L.elem = new ElemType[MAXSIZE];	//为顺序表分配空间	
	if (!L.elem) exit(OVERFLOW);	//存储分配失败
	L.length = 0;
	return OK;
}

//销毁线性表L
void DestroyList(SqList& L) {
	if (L.elem) delete L.elem;	//释放存储空间
}

//清空线性表L
void ClearList(SqList& L) {
	L.length = 0;	//将线性表的长度置为0
}

//求线性表L的长度
int GetLength(SqList L) {
	return (L.length);
}

//判断线性表L是否为空
int IsEmpty(SqList L) {
	if (L.length == 0) return 1;
	else return 0;
}

//逻辑位序(a1,a2...,an)和物理位序(0,1,...n-1)相差1

//顺序表的取值(根据位置i获取相应位置数据元素的内容)
int GetElem(SqList L, int i, ElemType& e) {
	if (i<1 || i>L.length) return ERROR;//判断i值是否合理
	e = L.elem[i - 1];	//第i-1个单元存储着第i个数据
	return OK;
}

//顺序表的查找
int LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++)
		if (L.elem[i] == e) return i + 1;	//查找成功，返回序号，序号与位序差1
	return 0;
}

//顺序表的插入
Status ListInsert_Sq(SqList& L, int i, ElemType e) {
	if (i<1 || i>L.length + 1) return ERROR;	//i值不合法
	if (L.length == MAXSIZE) return ERROR;	//当前存储空间已满
	for (int j = L.length - 1; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j];	//插入位置及之后的元素后移
	L.elem[i - 1] = e;				//将新元素e放入第i个位置
	L.length++;
	return OK;
}


//顺序表的删除
Status ListDelete_Sq(SqList& L, int i) {
	if ((i < 1) || (i > L.length)) return ERROR;	//i值不合法
	for (int j = i; j <= L.length - 1; j++)
		L.elem[j - 1] = L.elem[j];	//被删除元素之后的元素前移
	L.length--;
	return OK;
}

/*
线性表的合并
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
有序表的合并——顺序表实现
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