#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KEY_SIZE 10 // Ž�� Ű�� �ִ� ����
#define TABLE_SIZE 13 // �ؽ� ���̺��� ũ�� = �Ҽ�
#define empty(item) (strlen(item.key) == 0)
#define equal(item1, item2) (!strcmp(item1.key, item2.key))
#define _CRT_SECURE_NO_WARNINGS




//// ���� �����
//element hash_table[TABLE_SIZE];
//
//void init_table(element ht[]) {    // memset�� ����ص� ��
//	int i;
//	for (i = 0; i < TABLE_SIZE; i++) {
//		ht[i].key[0] = NULL;  // �ñ��� �� : �� 0 index���� �ʱ�ȭ�� �ϴ°�? 
//	}
//}
//
//// ���ڷ� �� Ű�� ���ڷ� ��ȯ
//int transform(char* key)
//{
//	int number = 0;
//	while (*key)
//		number = 31 * number + *key++;    /// ���� �����ΰ���..
//	return number;
//}
//
//typedef struct {
//	char key[KEY_SIZE];  // ���ڿ�
//	// �ٸ� �ʿ��� �ʵ��
//}element;
//



//// ���� �Լ��� ����� �ؽ� �Լ�
//
//int hash_function(char* key) {
//	// Ű�� �ڿ����� ��ȯ�� ���� ���̺��� ũ��� ������ �������� ��ȯ
//	return transform(key) % TABLE_SIZE;
//}
//
////���� ������� �̿��Ͽ� ���̺� Ű�� �����ϰ�,
//// ���̺��� ���� �� ���� ����
//
//void hash_lp_add(element item, element ht[]) {
//	int i, hash_value;
//	hash_value = i = hash_function(item.key);
//	//printf("hash_address = %d\n",i);
//	while (!empty(ht[i])) {
//		if (equal(item, ht[i])) {
//			fprintf(stderr, "Ž��Ű�� ����Ǿ����ϴ�.\n");  // i�� ã�� ���� �۾�
//			exit(1);
//		}
//		i = (i + 1) % TABLE_SIZE;
//		if (i == hash_value) {
//			fprintf(stderr, "���̺��� ����á���ϴ�\n");   // 1 cycle�� �� ����
//			exit(1);
//		}
//	}
//	ht[i] = item;
//}
//
//// ����������� �̿��Ͽ� ���̺� ����� Ű�� Ž��
//
//void hash_lp_search(element item, element ht[])
//{
//	int i, hash_value;
//	hash_value = i = hash_function(item.key);
//	while (!empty(ht[i]))
//	{
//		if (equal(item, ht[i])) {
//			fprintf(stderr, "Ž�� %s: ��ġ = %d\n", item.key, i);
//			return;
//		}
//		i = (i + 1) % TABLE_SIZE;
//		if (i == hash_value) {
//			fprintf(stderr, "ã�� ���� ���̺� ����\n"); // 1cycle�� �� ���Ұų�
//			return;
//		}
//	}
//	fprintf(stderr, "ã�� ���� ���̺� ����\n");  // �ؽ� ���̺��� i �ε��� ������ �ʰ��Ͽ� �ؽ� ���̺� ���� ���ų�
//}
//
//
//// �ؽ� ���̺��� ������ ���
//void hash_lp_print(element ht[])
//{
//	int i;
//	printf("\n===============================\n");
//	for (i = 0; i < TABLE_SIZE; i++)
//		printf("[%d] %s\n", i, ht[i].key);
//	printf("===============================\n\n");
//}
//// �ؽ� ���̺��� ����� ����
//int main(void)
//{
//	char* s[7] = { "do", "for", "if", "case", "else", "return", "function" };
//	element e;
//	for (int i = 0; i < 7; i++) {
//		strcpy_s(e.key, sizeof(e.key), s[i]);
//		hash_lp_add(e, hash_table);
//		hash_lp_print(hash_table);
//	}
//	for (int i = 0; i < 7; i++) {
//		strcpy_s(e.key, sizeof(e.key),s[i]);
//		hash_lp_search(e, hash_table);
//	}
//	return 0;
//}


// ü�̴� ��
#define SIZE 5

typedef struct {
	int key;
} element;

struct list {
	element item;
	struct list* link;
};

struct list* hash_table[TABLE_SIZE];

// ���� �Լ��� ����� �ؽ� �Լ�
int hash_function(int key)
{
	return key % TABLE_SIZE;
}
// ü�ι��� �̿��Ͽ� ���̺� Ű�� ����
void hash_chain_add(element item, struct list* ht[])
{
	int hash_value = hash_function(item.key);
	struct list* ptr;
	struct list* node_before = NULL, * node = ht[hash_value];
	for (; node; node_before = node, node = node->link) {
		if (node->item.key == item.key) {
			fprintf(stderr, "�̹� Ž��Ű�� ����Ǿ� ����\n");
			return;
		}
	}
	ptr = (struct list*)malloc(sizeof(struct list));
	ptr->item = item;
	ptr->link = NULL;
	if (node_before)
		node_before->link = ptr;
	else
		ht[hash_value] = ptr;
}

// ü�ι��� �̿��Ͽ� ���̺� ����� Ű�� Ž��
void hash_chain_search(element item, struct list* ht[])
{
	struct list* node;

	int hash_value = hash_function(item.key);
	for (node = ht[hash_value]; node; node = node->link) {
		if (node->item.key == item.key) {
			fprintf(stderr, "Ž�� %d ���� \n", item.key);
			return;
		}
	}
	printf("Ű�� ã�� ������\n");
}

// �ؽ� ���̺��� ������ ���

void hash_chain_print(struct list* ht[])
{
	struct list* node;
	int i;
	printf("\n===============================\n");
	for (i = 0; i < TABLE_SIZE; i++) {
		printf("[%d]->", i);
		for (node = ht[i]; node; node = node->link) {
			printf("%d->", node->item.key);
		}
		printf("\n");
	}
	printf("===============================\n");
}


// �ؽ� ���̺��� ����� ���� 
int main(void)
{
	int data[SIZE] = { 8, 1, 9, 6, 13 };
	element e;

	for (int i = 0; i < SIZE; i++) {
		e.key = data[i];
		hash_chain_add(e, hash_table);
		
	}
	for (int i = 0; i < SIZE; i++) {
		e.key = data[i];
		hash_chain_search(e, hash_table);
		hash_chain_print(hash_table);
	}
	return 0;
}
