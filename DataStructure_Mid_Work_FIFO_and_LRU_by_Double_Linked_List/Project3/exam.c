//# include <stdio.h>
//#include<stdlib.h>
//#define _CRT_SECURE_NO_WARNIGNS
//
//
//
//// 단순 연결 리스트 구현
//
//typedef int element;
//typedef struct list_node {
//	element data;
//	struct list_node* link;
//} ListNode;
//
//
//
//	void error(char* message)
//	{
//		printf("%s\n", message);
//		exit(1);
//	}
//	ListNode *insert_first(ListNode* head, element value)
//	{
//		ListNode* p = (ListNode * )malloc(sizeof(ListNode));
//		p->data = value;
//		p->link = head;
//		head = p;
//
//		return head;
//	}
//	ListNode* insert(ListNode* head, ListNode* pre,element value)
//	{
//		ListNode* p = (ListNode*)malloc(sizeof(ListNode));
//		p->data = value;
//		p->link = pre->link;
//		pre->link = p;
//		return head;
//	 }
//	// insert sorted 공부할 것!!
//	ListNode* insert_sorted(ListNode* head, element value)
//	{
//		ListNode* p = (ListNode*)malloc(sizeof(ListNode));
//		ListNode* cur;
//
//		p->data = value;
//		p->link = NULL;
//
//		if (head == NULL) {
//			head = p;
//			return 0;
//		}
//
//		cur = head;
//		while (cur->link != NULL && cur-> link ->data <p->data) {
//			cur = cur->link;
//		}
//		p->link = cur->link;
//		cur->link = p;
//
//		return head;
//	}
//
//	ListNode* delete_first(ListNode* head)
//	{
//		ListNode* to_be_removed;
//		to_be_removed = head;
//		head = to_be_removed->link;
//		free(to_be_removed);
//
//		return head;
//	}
//	ListNode* delete(ListNode* head, ListNode* pre)
//	{
//		ListNode* to_be_removed;
//		to_be_removed = pre->link;
//		pre->link = to_be_removed->link;
//		free(to_be_removed);
//	}
//	void print_list(ListNode* head)
//	{
//		ListNode* p;
//		for (p = head; p != NULL; p = p->link) {
//			printf("%d->", p->data);
//		}
//		printf("NULL\n");
//	}
//	int main() {
//		ListNode* head = NULL;
//		for (int i = 0; i < 5; i++) {
//			head = insert_first(head, i);
//			print_list(head);
//		}
//		head = insert_sorted(head, 8);
//		print_list(head);
//		head = insert_sorted(head, 7);
//		print_list(head);
//		head = insert_sorted(head, 6);
//		print_list(head);
//
//		for (int i = 0; i < 5; i++) {
//			head = delete_first(head);
//			print_list(head);
//		}
//
//		return 0;
//	}



	/*int ch, sum,i, a = 0;
	char num1[22] = { 0 }, num2[22] = { 0 }, result[23] = {' '};

	while (1) {
		if ((ch = getchar()) == '+') {
			while (1) {
				if ((ch = getchar()) == '\n') {
					break;
				}
				else
					for (i = sizeof(num2) - 1; i >=0; i--) {
						num2[i] = (int)ch - 48;
					}
			}
			break;
		}
		else
			for (i = sizeof(num1)-1; i >=0 ; i--) {
				num1[i] = (int)ch - 48;
			}

		for (i = sizeof(num1) - 1; i >= 0; i--) {
			sum = num1[i] + num2[i] + a;
			a = sum / 10;
			sum = sum % 10;
			result[i + 1] = sum;
		}
		result[0] = a;
	}
	for (i = 0; result[i] == 0; i++);
	printf("%s\n", result+i);*/


//	char ch;
//	long long num = 0;
//	while (1) {
//		if ((ch = getchar()) == '/')
//			break;
//		else
//			num = num * 10 + (int)ch - 48;
//	}
//	printf("%lld", num);
//}



	//char ch;
	//int num1=0, num2 = 0;
	//while (1) {
	//	if ((ch = getchar()) == '+') {
	//		while (1){
	//			if ((ch = getchar()) == '\n') {
	//				break;
	//			}
	//			else
	//				num2 = num2 * 10 + (int)ch - 48;
	//		}
	//		break;
	//	}
	//	else
	//		num1 =num1*10+ (int)ch - 48;
	//}
	//printf("%d", num1+num2);

