//# include <stdio.h>
//# include <stdlib.h>
//
//typedef int element;
//
//// 구조체 선언
//typedef struct DListNode {
//	element data;
//	struct DListNode* llink;
//	struct DListNode* rlink;
//}DListNode;
//
//// 매개변수 부분에서 변수선언할 때 head가 아니라 phead로 하는 이유는 포인터 타입이라는 것을 명시하기 위해 일부러 phead라고 하는 것임
//// 변수 초기화 단계
//void init(DListNode* phead) {
//	phead->llink = phead;
//	phead->rlink = phead;
//}
//// 새로운 노드 삽입
//void dinsert(DListNode* before, element data) {
//	DListNode* newnode;
//
//	newnode = (DListNode*)malloc(sizeof(DListNode));
//	// 4개의 포인터 조작
//	// 1. 새로 삽입될 (new node)노드의 두 포인터 변경
//	newnode->data = data;
//	newnode->llink = before;
//	newnode->rlink = before->rlink;
//
//	//2. 새로 삽입되는 노드를 가리키는 두 개의 포인터 변경
//	before->rlink->llink = newnode;
//	before->rlink = newnode;
//}
//
//// 특정 노드 삭제
//void ddelete(DListNode* phead, DListNode * removed) {
//	if (removed == phead)  // 헤드노드를 삭제하는 경우 == 삭제할 노드가 없다는 의미와 유사할 수도..?
//		return;
//
//	//삭제될 노드를 가리키고 있던 두 개의 포인터를 변경
//	removed->llink->rlink = removed->rlink;
//	removed->rlink->llink = removed->llink;
//
//	free(removed);
//}
//
////특정 값을 가지고 있는 노드를 검색해서 그 노드의 포인터를 반환하는 함수 (노드 탐색 느낌인듯)
//DListNode* search(DListNode* phead, element data) {
//	DListNode* p;
//	for (p = phead->rlink; p != phead; p = p->rlink) {
//		printf("<-|%d|->", p->data);
//		if (p->data == data)
//			return p;
//		// while문으로 쓰려면
//		// while(p!=phead){
//		//printf("<-|%d|->",p->data);
//		//p = p->rlink;
//		//}
//	}
//	return NULL;
//}
//
////모든 노드를 출력하는 함수
//void print_dlist(DListNode* phead) {
//
//	DListNode* p;
//
//	for (p = phead->rlink; p != phead; p = p->rlink) {
//		printf("<-|%d|->", p->data);
//		// while문으로 쓰려면
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
//	printf("검색 값: ");
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