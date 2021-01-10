#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )  // 매크로 함수 사용하는 방법..?? 알아보자
#define MAX_SIZE 20
#include <stdio.h>
#include <stdlib.h> //stdlib.h는 rand, srand를 위한 헤더 파일임을 기억할 것
#include <time.h>

// 비교 횟수 & 이동 횟수

//// 선택 정렬 코드
//void selection_sort(int list[], int n)
//{
//	int i, j, least, temp;
//	for (i = 0; i < n - 1; i++) {
//		least = i;
//		for (j = i + 1; j < n; j++) 			// 최솟값 탐색
//			if (list[j] < list[least]) least = j;
//		SWAP(list[i], list[least], temp);
//	}
//}


// 삽입정렬
//void insertion_sort(int list[], int n)
//{
//	int i, j, key;
//	for (i = 1; i < n; i++) {
//		key = list[i];
//		for (j = i - 1; j >= 0 && list[j] > key; j--)
//			list[j + 1] = list[j]; 		// 레코드의 오른쪽 이동
//		list[j + 1] = key;
//	}
//}

////버블정렬
//void bubble_sort(int list[], int n)
//{
//	int i, j, temp;
//	for (i = n - 1; i > 0; i--) {
//		for (j = 0; j < i; j++) 	// 앞뒤의 레코드를 비교한 후 교체
//			if (list[j] > list[j + 1])
//				SWAP(list[j], list[j + 1], temp);
//	}
//}


//// 셸 정렬
//// gap 만큼 떨어진 요소들을 삽입 정렬
//// 정렬의 범위는 first에서 last
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
//		for (i = 0; i < gap; i++)		// 부분 리스트의 개수는 gap
//			inc_insertion_sort(list, i, n - 1, gap);
//	}
//}

//
////합병 정렬
//int sorted[MAX_SIZE]; // 추가 공간이 필요
//// i는 정렬된 왼쪽리스트에 대한 인덱스
//// j는 정렬된 오른쪽리스트에 대한 인덱스
//// k는 정렬될 리스트에 대한 인덱스
//
//void merge(int list[], int left, int mid, int right)
//{
//	int i, j, k, l;
//	i = left; j = mid + 1; k = left;
//	// 분할 정렬된 list의 합병
//	while (i <= mid && j <= right) {
//		if (list[i] <= list[j]) sorted[k++] = list[i++];
//		else sorted[k++] = list[j++];
//	}
//	if (i > mid) 	// 남아 있는 레코드의 일괄 복사
//		for (l = j; l <= right; l++)
//			sorted[k++] = list[l];
//	else 	// 남아 있는 레코드의 일괄 복사
//		for (l = i; l <= mid; l++)
//			sorted[k++] = list[l];
//	// 배열 sorted[]의 리스트를 배열 list[]로 복사
//	for (l = left; l <= right; l++)
//		list[l] = sorted[l];
//}
//
//void merge_sort(int list[], int left, int right)
//{
//	int mid;
//	if (left < right)
//	{
//		mid = (left + right) / 2;              // 리스트의 균등분할
//		merge_sort(list, left, mid);     // 부분리스트 정렬
//		merge_sort(list, mid + 1, right);//부분리스트 정렬
//		merge(list, left, mid, right);    // 합병
//	}
//}



////퀵 정렬
//int partition(int list[], int left, int right) //피벗 값을 반환함
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
//		int q = partition(list, left, right);  // 피벗을 기준으로 작은, 혹은 큰 값들의 배열을 퀵 정렬하기 위함
//		quick_sort(list, left, q - 1);
//		quick_sort(list, q + 1, right);
//	}
//}


//
////기수정렬
//// 6장의 큐 소스를 여기에...
//
//#define BUCKETS 10
//#define DIGITS 4  // '숫자의 자릿수 : 4 '  --> 기수정렬에서의 핵심 요소 , 물론 이 예시에서는 난수가 0~99이므로 DIGITS를 2로 해도 무방하다.
//#define MAX 10
//typedef int element;
//typedef struct { // 큐 타입
//	element data[MAX];
//	int front, rear;
//} QueueType;
//// 오류 함수
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
//// 공백 상태 검출 함수
//int is_empty(QueueType* q)
//{
//	if (q->front == q->rear)
//		return 1;
//	else
//		return 0;
//}
//
//// 포화 상태 검출 함수
//int is_full(QueueType* q)
//{
//	if (q->rear == MAX - 1)
//		return 1;
//	else
//		return 0;
//}
//
//// 삽입 함수
//void enqueue(QueueType* q, int item)
//{
//	if (is_full(q)) {
//		return;
//	}
//	q->data[++(q->rear)] = item;
//}
//
//// 삭제 함수
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
//	for (b = 0; b < BUCKETS; b++) init_queue(&queues[b]);	// 큐들의 초기화
//
//	for (d = 0; d < DIGITS; d++) {
//		for (i = 0; i < n; i++)				// 데이터들을 자리수에 따라 큐에 입력
//			enqueue(&queues[(list[i] / factor) % 10], list[i]);
//
//		for (b = i = 0; b < BUCKETS; b++)			// 버켓에서 꺼내어 list로 합친다.
//			while (!is_empty(&queues[b]))
//				list[i++] = dequeue(&queues[b]);
//		factor *= 10;				// 그 다음 자리수로 간다.
//	}
//}

//int main(void)
//{
//	int i;
//	int n = MAX_SIZE;
//	int list[MAX_SIZE] = { 0, };
//	srand(time(NULL));
//	for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
//		list[i] = rand() % 100; // 난수 발생 범위 0~99
//
//	//shell_sort(list, n);  // 셸정렬 호출 // gap의 범위는 n/2부터 시작!
//	//selection_sort(list, n); // 선택정렬 호출 
//	//insertion_sort(list, n);  // 삽입정렬 호출
//	//merge_sort(list, 0, MAX_SIZE - 1); 합병정렬 호출
//	//quick_sort(list, 0, n - 1); // 퀵정렬 호출 
//	//radix_sort(list, MAX_SIZE); // 기수정렬 호출 
//	for (i = 0; i < n; i++)
//		printf("%d ", list[i]);
//	printf("\n");
//	return 0;
//}


