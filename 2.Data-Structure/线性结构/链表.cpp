//#include<iostream>
//using namespace std;
//
//#define TRUE 1
//#define FALSE 0
//#define OK 1
//#define ERROR 0
//#define INFESIBLE -1
//#define OVERFLOW -2
//
//typedef int Status;
//typedef char ElemType ;
//
//typedef struct LNode {  //声明结点的类型和指向结点的数据类型
//	ElemType  data;     //结点的数据域
//	struct LNode* next;//结点的指针域
//}LNode, * LinkList; //LinkList为指向结构体LNode的指针类型、LNode为结点
//
////=========================单链表====================
///*
//* 初始化单链表
//*/
//Status InitList_L(LinkList& L) {
//	L = new LNode;    //L=(LinkList)malloc(sizeof(LNode))
//	L->next = NULL;
//	return OK;
//}
//
///*
//判断单链表是否为空
//*/
//int ListEmpty(LinkList L) {
//	if (L->next)
//		return 0;
//	else
//		return 1;
//}
//
///*
// *销毁单链表L
// *各个结点依次释放
// **/
//Status DestoryList_L(LinkList& L) {
//	LNode* p;
//	while (L) {
//		p = L;
//		L = L->next;
//		delete p;
//	}
//}
//
///*
// *清空单链表L
// *依次释放所有结点，并将头结点指针域设置为空
// **/
//Status ClearList(LinkList& L) {	//将L重置为空表
//	LNode* p, * q;
//	p = L->next;
//	while (p) {
//		q = p->next;
//		delete p;
//		p = q;
//	}
//	L->next = NULL;	//头指针域为空
//	return OK;
//}
//
///*
//求单链表L的表长
//*/
//int ListLength_L(LinkList L) {
//	LinkList p;
//	p = L->next;	//p指向第一个结点
//	int i = 0;
//	while (p) {	//遍历单链表，统计结点数
//		i++;
//		p = p->next;
//	}
//}
///*
// *获取线性表L中的某个数据元素内容，通过变量e返回
// **/
//Status GetElem_L(LinkList L, int i, ElemType & e) {
//	LinkList p;
//	p = L->next;
//	int j = 1;
//	while (p && j < i) {	//向后扫描，直到p指向第i个元素或p为空
//		p = p->next;
//		++j;
//	}
//	if (!p || j > i)	//第i个元素不存在
//		return ERROR;
//	e = p->data;
//	return OK;
//}
//
///*
// *查找元素地址
// *在线性表L中查找值为e的数据元素
// *找到返回e的数据元素地址；找不到返回NULL
// **/
//LNode* LocateElem_L_1(LinkList L, ElemType  e) {
//	LinkList p;
//	p = L->next;
//	while (p && p->data != e)
//		p = p->next;
//	return p;
//}
///*
// *查找元素位置
// *在线性表L中查找值为e的数据元素
// **/
//int LocateElem_L_2(LinkList L, ElemType  e) {
//	LinkList p;
//	p = L->next;
//	int j = 1;
//	while (p && p->data != e) {
//		p = p->next;
//		j++;
//	}
//	if (p) return j;
//	else return 0;
//}
//
///*
// *插入元素e
// *在L中第i个元素之前插入数据元素e
// **/
//Status ListInsert_L(LinkList& L, int i, ElemType  e) {
//	LinkList p,s;
//	p = L;
//	int j = 0;
//	while (p && j < i - 1) {	//寻找第i-1个结点，p指向i-1结点
//		p = p->next;
//		++j;
//	}
//	if (!p || j > i - 1)		//i大于表长+1或小于1，插入位置非法
//		return ERROR;
//	s = new LNode;
//	s->data = e;			//生成新结点s，将结点s的数据域置为e
//	s->next = p->next;	//将结点s插入L中
//	p->next = s;
//}
//
///*
// *删除元素e
// *将L中第i个数据元素删除
// **/
//Status ListDelete_L(LinkList& L, int i, ElemType & e) {
//	LinkList p,q;
//	p = L;
//	int j = 0;
//	while (p->next && j < i - 1) {	//寻找第i个结点，并令p指向其前驱
//		p = p->next;
//		++j;
//	}
//	if (!(p->next) || j > i - 1) return ERROR;	//删除位置不合理
//	q = p->next;		//临时保存被删结点的地址以备释放
//	p->next = q->next; //改变删除结点前驱结点的指针域
//	//p->next = p->next->next;
//	e = q->data;		//保存删除结点的数据域
//	delete q;		//释放删除结点的空间
//	return OK;
//}
//
//
///*
// *头插法
// **/
//void CreateList_H(LinkList& L, int n) {
//	L = new LNode;
//	L->next = NULL; //先建立一个带头结点的单链表
//	for (int i = n; i > 0; --i) {
//		LinkList p = new LNode; //C：p=(LNode*)malloc(sizeof(LNode));
//		cin >> p->data;	//scanf(&p->data);
//		p->next = L->next;
//		L->next = p;
//	}
//}
//
///*
// *尾插法
// **/
//void CreateList_R(LinkList& L, int n) {
//	L = new LNode;
//	L->next = NULL; //先建立一个带头结点的单链表
//	LinkList r,p;
//	r = L;	//尾指针r指向头结点
//	for (int i = 0; i < n; ++i) {
//		p = new LNode; //C：p=(LNode*)malloc(sizeof(LNode));
//		cin >> p->data;	//scanf(&p->data);
//		p->next = NULL;
//		r->next = p;	//插入表尾
//		r = p;	//r指向新的为结点
//	}
//}
//
//
////=========================循环链表====================
//LinkList Connect(LinkList Ta, LinkList Tb) {
//	LNode *p;
//	p = Ta->next;
//	Ta->next = Tb->next->next;
//	delete Tb->next;
//	Tb->next = p;
//	return Tb;
//}//带尾指针的循环链表
//
//
////=========================双向链表====================
//typedef struct DuLNode {
//	ElemType  data;
//	struct DuLNode* prior, * next;
//}DuLNode,*DuLinkList;
//
//Status GetElemP_DuL(DuLinkList L, int i,ElemType & e) {
//	DuLinkList p;
//	p = L->next;
//	int j = 1;
//	while (p && j < i) {	//向后扫描，直到p指向第i个元素或p为空
//		p = p->next;
//		++j;
//	}
//	if (!p || j > i)	//第i个元素不存在
//		return ERROR;
//	e = p->data;
//	return OK;
//}
//
////双向链表的插入
//Status ListInsert_DuL(DuLinkList& L, int i, ElemType  e) {
//	DuLNode* p,*s;
//	if (!( GetElemP_DuL(L, i,e))) return ERROR;
//	p = L;
//	s = new DuLNode;	s->data = e;
//	s->next = p;		p->prior = s;
//	return OK;
//}
//
////双向链表的删除
//Status ListDelete_DuL(DuLinkList& L, int i, ElemType & e) {
//	DuLNode* p;
//	if (!GetElemP_DuL(L, i,e)) return ERROR;
//	p = L;
//	e = p->data;
//	p->prior->next = p->next;
//	p->next->prior = p->prior;
//	free(p);
//	return OK;
//}
//
///*
//有序表的合并——链表实现
//*/
//typedef struct LNode {
//	ElemType  data;
//	LNode* next;
//}LNode, * LinkList;
//
//void MergeList_L(LinkList& La, LinkList& Lb, LinkList& Lc) {
//	LNode* pa, * pb, * pc;
//	pa = La->next;
//	pb = Lb->next;
//	pc = Lc = La;	//用La的头结点作为Lc的头结点
//	while (pa && pb) {
//		if (pa->data <= pb->data) {
//			pc->next = pa; pc = pa; pa = pa->next;
//		}
//		else {
//			pc->next = pb; pc = pb; pb = pb->next;
//		}
//	}
//	pc->next = pa ? pa : pb;
//}