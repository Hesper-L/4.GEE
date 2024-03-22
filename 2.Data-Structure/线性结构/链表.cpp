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
//typedef struct LNode {  //�����������ͺ�ָ�������������
//	ElemType  data;     //����������
//	struct LNode* next;//����ָ����
//}LNode, * LinkList; //LinkListΪָ��ṹ��LNode��ָ�����͡�LNodeΪ���
//
////=========================������====================
///*
//* ��ʼ��������
//*/
//Status InitList_L(LinkList& L) {
//	L = new LNode;    //L=(LinkList)malloc(sizeof(LNode))
//	L->next = NULL;
//	return OK;
//}
//
///*
//�жϵ������Ƿ�Ϊ��
//*/
//int ListEmpty(LinkList L) {
//	if (L->next)
//		return 0;
//	else
//		return 1;
//}
//
///*
// *���ٵ�����L
// *������������ͷ�
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
// *��յ�����L
// *�����ͷ����н�㣬����ͷ���ָ��������Ϊ��
// **/
//Status ClearList(LinkList& L) {	//��L����Ϊ�ձ�
//	LNode* p, * q;
//	p = L->next;
//	while (p) {
//		q = p->next;
//		delete p;
//		p = q;
//	}
//	L->next = NULL;	//ͷָ����Ϊ��
//	return OK;
//}
//
///*
//������L�ı�
//*/
//int ListLength_L(LinkList L) {
//	LinkList p;
//	p = L->next;	//pָ���һ�����
//	int i = 0;
//	while (p) {	//����������ͳ�ƽ����
//		i++;
//		p = p->next;
//	}
//}
///*
// *��ȡ���Ա�L�е�ĳ������Ԫ�����ݣ�ͨ������e����
// **/
//Status GetElem_L(LinkList L, int i, ElemType & e) {
//	LinkList p;
//	p = L->next;
//	int j = 1;
//	while (p && j < i) {	//���ɨ�裬ֱ��pָ���i��Ԫ�ػ�pΪ��
//		p = p->next;
//		++j;
//	}
//	if (!p || j > i)	//��i��Ԫ�ز�����
//		return ERROR;
//	e = p->data;
//	return OK;
//}
//
///*
// *����Ԫ�ص�ַ
// *�����Ա�L�в���ֵΪe������Ԫ��
// *�ҵ�����e������Ԫ�ص�ַ���Ҳ�������NULL
// **/
//LNode* LocateElem_L_1(LinkList L, ElemType  e) {
//	LinkList p;
//	p = L->next;
//	while (p && p->data != e)
//		p = p->next;
//	return p;
//}
///*
// *����Ԫ��λ��
// *�����Ա�L�в���ֵΪe������Ԫ��
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
// *����Ԫ��e
// *��L�е�i��Ԫ��֮ǰ��������Ԫ��e
// **/
//Status ListInsert_L(LinkList& L, int i, ElemType  e) {
//	LinkList p,s;
//	p = L;
//	int j = 0;
//	while (p && j < i - 1) {	//Ѱ�ҵ�i-1����㣬pָ��i-1���
//		p = p->next;
//		++j;
//	}
//	if (!p || j > i - 1)		//i���ڱ�+1��С��1������λ�÷Ƿ�
//		return ERROR;
//	s = new LNode;
//	s->data = e;			//�����½��s�������s����������Ϊe
//	s->next = p->next;	//�����s����L��
//	p->next = s;
//}
//
///*
// *ɾ��Ԫ��e
// *��L�е�i������Ԫ��ɾ��
// **/
//Status ListDelete_L(LinkList& L, int i, ElemType & e) {
//	LinkList p,q;
//	p = L;
//	int j = 0;
//	while (p->next && j < i - 1) {	//Ѱ�ҵ�i����㣬����pָ����ǰ��
//		p = p->next;
//		++j;
//	}
//	if (!(p->next) || j > i - 1) return ERROR;	//ɾ��λ�ò�����
//	q = p->next;		//��ʱ���汻ɾ���ĵ�ַ�Ա��ͷ�
//	p->next = q->next; //�ı�ɾ�����ǰ������ָ����
//	//p->next = p->next->next;
//	e = q->data;		//����ɾ������������
//	delete q;		//�ͷ�ɾ�����Ŀռ�
//	return OK;
//}
//
//
///*
// *ͷ�巨
// **/
//void CreateList_H(LinkList& L, int n) {
//	L = new LNode;
//	L->next = NULL; //�Ƚ���һ����ͷ���ĵ�����
//	for (int i = n; i > 0; --i) {
//		LinkList p = new LNode; //C��p=(LNode*)malloc(sizeof(LNode));
//		cin >> p->data;	//scanf(&p->data);
//		p->next = L->next;
//		L->next = p;
//	}
//}
//
///*
// *β�巨
// **/
//void CreateList_R(LinkList& L, int n) {
//	L = new LNode;
//	L->next = NULL; //�Ƚ���һ����ͷ���ĵ�����
//	LinkList r,p;
//	r = L;	//βָ��rָ��ͷ���
//	for (int i = 0; i < n; ++i) {
//		p = new LNode; //C��p=(LNode*)malloc(sizeof(LNode));
//		cin >> p->data;	//scanf(&p->data);
//		p->next = NULL;
//		r->next = p;	//�����β
//		r = p;	//rָ���µ�Ϊ���
//	}
//}
//
//
////=========================ѭ������====================
//LinkList Connect(LinkList Ta, LinkList Tb) {
//	LNode *p;
//	p = Ta->next;
//	Ta->next = Tb->next->next;
//	delete Tb->next;
//	Tb->next = p;
//	return Tb;
//}//��βָ���ѭ������
//
//
////=========================˫������====================
//typedef struct DuLNode {
//	ElemType  data;
//	struct DuLNode* prior, * next;
//}DuLNode,*DuLinkList;
//
//Status GetElemP_DuL(DuLinkList L, int i,ElemType & e) {
//	DuLinkList p;
//	p = L->next;
//	int j = 1;
//	while (p && j < i) {	//���ɨ�裬ֱ��pָ���i��Ԫ�ػ�pΪ��
//		p = p->next;
//		++j;
//	}
//	if (!p || j > i)	//��i��Ԫ�ز�����
//		return ERROR;
//	e = p->data;
//	return OK;
//}
//
////˫������Ĳ���
//Status ListInsert_DuL(DuLinkList& L, int i, ElemType  e) {
//	DuLNode* p,*s;
//	if (!( GetElemP_DuL(L, i,e))) return ERROR;
//	p = L;
//	s = new DuLNode;	s->data = e;
//	s->next = p;		p->prior = s;
//	return OK;
//}
//
////˫�������ɾ��
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
//�����ĺϲ���������ʵ��
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
//	pc = Lc = La;	//��La��ͷ�����ΪLc��ͷ���
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