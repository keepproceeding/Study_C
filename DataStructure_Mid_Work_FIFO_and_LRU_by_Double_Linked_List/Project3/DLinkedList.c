//# include <stdio.h>
//# include <stdlib.h>
//
//typedef int element;
//
//// ����ü ����
//typedef struct DListNode {
//	element data;
//	struct DListNode* llink;
//	struct DListNode* rlink;
//}DListNode;
//
//// �Ű����� �κп��� ���������� �� head�� �ƴ϶� phead�� �ϴ� ������ ������ Ÿ���̶�� ���� ����ϱ� ���� �Ϻη� phead��� �ϴ� ����
//// ���� �ʱ�ȭ �ܰ�
//void init(DListNode* phead) {
//	phead->llink = phead;
//	phead->rlink = phead;
//}
//// ���ο� ��� ����
//void dinsert(DListNode* before, element data) {
//	DListNode* newnode;
//
//	newnode = (DListNode*)malloc(sizeof(DListNode));
//	// 4���� ������ ����
//	// 1. ���� ���Ե� (new node)����� �� ������ ����
//	newnode->data = data;
//	newnode->llink = before;
//	newnode->rlink = before->rlink;
//
//	//2. ���� ���ԵǴ� ��带 ����Ű�� �� ���� ������ ����
//	before->rlink->llink = newnode;
//	before->rlink = newnode;
//}
//
//// Ư�� ��� ����
//void ddelete(DListNode* phead, DListNode * removed) {
//	if (removed == phead)  // ����带 �����ϴ� ��� == ������ ��尡 ���ٴ� �ǹ̿� ������ ����..?
//		return;
//
//	//������ ��带 ����Ű�� �ִ� �� ���� �����͸� ����
//	removed->llink->rlink = removed->rlink;
//	removed->rlink->llink = removed->llink;
//
//	free(removed);
//}
//
////Ư�� ���� ������ �ִ� ��带 �˻��ؼ� �� ����� �����͸� ��ȯ�ϴ� �Լ� (��� Ž�� �����ε�)
//DListNode* search(DListNode* phead, element data) {
//	DListNode* p;
//	for (p = phead->rlink; p != phead; p = p->rlink) {
//		printf("<-|%d|->", p->data);
//		if (p->data == data)
//			return p;
//		// while������ ������
//		// while(p!=phead){
//		//printf("<-|%d|->",p->data);
//		//p = p->rlink;
//		//}
//	}
//	return NULL;
//}
//
////��� ��带 ����ϴ� �Լ�
//void print_dlist(DListNode* phead) {
//
//	DListNode* p;
//
//	for (p = phead->rlink; p != phead; p = p->rlink) {
//		printf("<-|%d|->", p->data);
//		// while������ ������
//		// while(p!=phead){
//		//printf("<-|%d|->",p->data);
//		//p = p->rlink;
//		//}
//	}
//
//}
//
//int main() {
//
//	DListNode* head;
//	element data;
//	head = (DListNode*)malloc(sizeof(DListNode));
//	init(head);
//
//	dinsert(head, 1);
//	dinsert(head, 2);
//	dinsert(head, 3);
//	print_dlist(head);
//
//	printf("�˻� ��: ");
//	scanf_s("%d", &data);
//	
//	if (search(head, data) != NULL) {
//		printf("%d is in list\n",data);
//	}
//	else {
//		printf("%d is not in list\n", data);
//	}
//
//	return 0;
//}