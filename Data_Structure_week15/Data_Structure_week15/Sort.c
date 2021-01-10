#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )  // ��ũ�� �Լ� ����ϴ� ���..?? �˾ƺ���
#define MAX_SIZE 20
#include <stdio.h>
#include <stdlib.h> //stdlib.h�� rand, srand�� ���� ��� �������� ����� ��
#include <time.h>

// �� Ƚ�� & �̵� Ƚ��

//// ���� ���� �ڵ�
//void selection_sort(int list[], int n)
//{
//	int i, j, least, temp;
//	for (i = 0; i < n - 1; i++) {
//		least = i;
//		for (j = i + 1; j < n; j++) 			// �ּڰ� Ž��
//			if (list[j] < list[least]) least = j;
//		SWAP(list[i], list[least], temp);
//	}
//}


// ��������
//void insertion_sort(int list[], int n)
//{
//	int i, j, key;
//	for (i = 1; i < n; i++) {
//		key = list[i];
//		for (j = i - 1; j >= 0 && list[j] > key; j--)
//			list[j + 1] = list[j]; 		// ���ڵ��� ������ �̵�
//		list[j + 1] = key;
//	}
//}

////��������
//void bubble_sort(int list[], int n)
//{
//	int i, j, temp;
//	for (i = n - 1; i > 0; i--) {
//		for (j = 0; j < i; j++) 	// �յ��� ���ڵ带 ���� �� ��ü
//			if (list[j] > list[j + 1])
//				SWAP(list[j], list[j + 1], temp);
//	}
//}


//// �� ����
//// gap ��ŭ ������ ��ҵ��� ���� ����
//// ������ ������ first���� last
//inc_insertion_sort(int list[], int first, int last, int gap)
//{
//	int i, j, key;
//	for (i = first + gap; i <= last; i = i + gap) {
//		key = list[i];
//		for (j = i - gap; j >= first && key < list[j]; j = j - gap)
//			list[j + gap] = list[j];
//		list[j + gap] = key;
//	}
//}
////
//void shell_sort(int list[], int n)   // n = size
//{
//	int i, gap;
//	for (gap = n / 2; gap > 0; gap = gap / 2) {
//		if ((gap % 2) == 0) gap++;
//		for (i = 0; i < gap; i++)		// �κ� ����Ʈ�� ������ gap
//			inc_insertion_sort(list, i, n - 1, gap);
//	}
//}

//
////�պ� ����
//int sorted[MAX_SIZE]; // �߰� ������ �ʿ�
//// i�� ���ĵ� ���ʸ���Ʈ�� ���� �ε���
//// j�� ���ĵ� �����ʸ���Ʈ�� ���� �ε���
//// k�� ���ĵ� ����Ʈ�� ���� �ε���
//
//void merge(int list[], int left, int mid, int right)
//{
//	int i, j, k, l;
//	i = left; j = mid + 1; k = left;
//	// ���� ���ĵ� list�� �պ�
//	while (i <= mid && j <= right) {
//		if (list[i] <= list[j]) sorted[k++] = list[i++];
//		else sorted[k++] = list[j++];
//	}
//	if (i > mid) 	// ���� �ִ� ���ڵ��� �ϰ� ����
//		for (l = j; l <= right; l++)
//			sorted[k++] = list[l];
//	else 	// ���� �ִ� ���ڵ��� �ϰ� ����
//		for (l = i; l <= mid; l++)
//			sorted[k++] = list[l];
//	// �迭 sorted[]�� ����Ʈ�� �迭 list[]�� ����
//	for (l = left; l <= right; l++)
//		list[l] = sorted[l];
//}
//
//void merge_sort(int list[], int left, int right)
//{
//	int mid;
//	if (left < right)
//	{
//		mid = (left + right) / 2;              // ����Ʈ�� �յ����
//		merge_sort(list, left, mid);     // �κи���Ʈ ����
//		merge_sort(list, mid + 1, right);//�κи���Ʈ ����
//		merge(list, left, mid, right);    // �պ�
//	}
//}



////�� ����
//int partition(int list[], int left, int right) //�ǹ� ���� ��ȯ��
//{
//	int pivot, temp;
//	int low, high;
//
//	low = left;
//	high = right + 1;
//	pivot = list[left];
//	do {
//		do
//			low++;
//		while (low <= right && list[low] < pivot);
//		do
//			high--;
//		while (high >= left && list[high] > pivot);
//		if (low < high) SWAP(list[low], list[high], temp);
//	} while (low < high);
//
//	SWAP(list[left], list[high], temp);
//	return high;
//}
//void quick_sort(int list[], int left, int right)
//{
//	if (left < right) {
//		int q = partition(list, left, right);  // �ǹ��� �������� ����, Ȥ�� ū ������ �迭�� �� �����ϱ� ����
//		quick_sort(list, left, q - 1);
//		quick_sort(list, q + 1, right);
//	}
//}


//
////�������
//// 6���� ť �ҽ��� ���⿡...
//
//#define BUCKETS 10
//#define DIGITS 4  // '������ �ڸ��� : 4 '  --> ������Ŀ����� �ٽ� ��� , ���� �� ���ÿ����� ������ 0~99�̹Ƿ� DIGITS�� 2�� �ص� �����ϴ�.
//#define MAX 10
//typedef int element;
//typedef struct { // ť Ÿ��
//	element data[MAX];
//	int front, rear;
//} QueueType;
//// ���� �Լ�
//void error(char* message)
//{
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//void init_queue(QueueType* q)
//{
//	q->rear = -1;
//	q->front = -1;
//}
//// ���� ���� ���� �Լ�
//int is_empty(QueueType* q)
//{
//	if (q->front == q->rear)
//		return 1;
//	else
//		return 0;
//}
//
//// ��ȭ ���� ���� �Լ�
//int is_full(QueueType* q)
//{
//	if (q->rear == MAX - 1)
//		return 1;
//	else
//		return 0;
//}
//
//// ���� �Լ�
//void enqueue(QueueType* q, int item)
//{
//	if (is_full(q)) {
//		return;
//	}
//	q->data[++(q->rear)] = item;
//}
//
//// ���� �Լ�
//int dequeue(QueueType* q)
//{
//	if (is_empty(q)) {
//		return -1;
//	}
//	int item = q->data[++(q->front)];
//	return item;
//}
//
//void radix_sort(int list[], int n)
//{
//	int i, b, d, factor = 1;
//	QueueType queues[BUCKETS];
//
//	for (b = 0; b < BUCKETS; b++) init_queue(&queues[b]);	// ť���� �ʱ�ȭ
//
//	for (d = 0; d < DIGITS; d++) {
//		for (i = 0; i < n; i++)				// �����͵��� �ڸ����� ���� ť�� �Է�
//			enqueue(&queues[(list[i] / factor) % 10], list[i]);
//
//		for (b = i = 0; b < BUCKETS; b++)			// ���Ͽ��� ������ list�� ��ģ��.
//			while (!is_empty(&queues[b]))
//				list[i++] = dequeue(&queues[b]);
//		factor *= 10;				// �� ���� �ڸ����� ����.
//	}
//}

//int main(void)
//{
//	int i;
//	int n = MAX_SIZE;
//	int list[MAX_SIZE] = { 0, };
//	srand(time(NULL));
//	for (i = 0; i < n; i++)      	// ���� ���� �� ��� 
//		list[i] = rand() % 100; // ���� �߻� ���� 0~99
//
//	//shell_sort(list, n);  // ������ ȣ�� // gap�� ������ n/2���� ����!
//	//selection_sort(list, n); // �������� ȣ�� 
//	//insertion_sort(list, n);  // �������� ȣ��
//	//merge_sort(list, 0, MAX_SIZE - 1); �պ����� ȣ��
//	//quick_sort(list, 0, n - 1); // ������ ȣ�� 
//	//radix_sort(list, MAX_SIZE); // ������� ȣ�� 
//	for (i = 0; i < n; i++)
//		printf("%d ", list[i]);
//	printf("\n");
//	return 0;
//}


