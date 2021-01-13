//#ifdef _MSC_VER
//#define _CRT_SECURE_NO_WARNINGS
//#endif
//
//#include <stdio.h>
//
//#define	MAX_CACHE_SIZE		8192
//
//// 데이터 참조 스트림이 저장된 파일 
//#define TRACE_FILE_NAME		"ref_stream.txt"
//
//
//// 이중연결리스트의 노드 타입
//typedef struct buffer {
//	unsigned long blkno;
//	struct buffer* next, * prev;
//}buffer;
//
//// 데이터를 저장할 공간을 한 번에 할당 받음
//// 이후 추가적인 메모리 할당은 없음
//// 할당 받은 노드들을 이용하여 LRU 리스트 또는 FIFO 리스트를 유지해야 함 
//buffer cache_buffer[MAX_CACHE_SIZE];
//
//
//// LRU 시뮬레이터 인 경우 lrulist 아니면 fifolist를 유지하기 위한 헤드 노드 선언
////#if 1
////struct buffer lrulist;
////#else
//buffer* fifolist;
////#endif
////초기화
//void init(buffer* pfifolist) {
//	pfifolist->prev = pfifolist;
//	pfifolist->next = pfifolist;
//}
//// 새로운 노드 삽입
//void dinsert(unsigned long blkno, int i) {
//	cache_buffer[i].blkno = blkno;
//	cache_buffer[i].next = NULL;
//	cache_buffer[i - 1].next = &cache_buffer[i];
//	cache_buffer[i].prev = &cache_buffer[i - 1];
//}
////fifolist 알고리즘 함수
//void fifo(buffer* fifolist, int blkno) {
//	//헤더 노드의 포인터 수정
//	fifolist->next->blkno = blkno;
//	fifolist->prev->next = fifolist->next;  //(전)맨 마지막 노드가 (현) 맨 마지막 노드에 next
//	fifolist->prev->next->next = fifolist; // 맨 마지막 노드의 next에 fifolist가
//	fifolist->next = fifolist->next->next; // fifolist의 next에 fifolist의 next next
//	fifolist->next->prev = fifolist; // (현)fifolist의 next의 prev에 fifolist를
//	fifolist->prev = fifolist->prev->next; // fifolist의 prev에 (현) 마지막 노드를
//}
//
////특정 값을 가지고 있는 노드를 검색해서 그 노드의 포인터를 반환하는 함수 (노드 탐색 느낌인듯)
//buffer* search(buffer* phead, unsigned long blkno) {
//	buffer* p;
//	for (p = phead->next; p != phead; p = p->next) {
//		if (p->blkno == blkno)
//			return p;
//		// while문으로 쓰려면
//		// while(p!=phead){
//		//printf("<-|%d|->",p->data);
//		//p = p->rlink;
//		//}
//	}
//	return NULL;
//}
//void print_arr() {
//	for (int i = 0; i < 10; i++) {
//		printf("%lu ", cache_buffer[i].blkno);
//	}
//	printf("\n");
//}
//
//int main(int argc, char* argv[])
//{
//	float a=0.0, b=0.0;
//	int	ret;
//	unsigned long blkno = 0;
//	FILE* fp = NULL;
//	buffer* fifolist;
//	fifolist = cache_buffer;
//	init(fifolist);
//
//	if ((fp = fopen(TRACE_FILE_NAME, "r")) == NULL) {
//		printf("%s trace file open fail.\n", TRACE_FILE_NAME);
//
//		return 0;
//	}
//	else {
//		printf("start simulation!\n");
//	}
//	for (int i = 0; i < MAX_CACHE_SIZE; i++) {
//		fscanf(fp, "%lu", &blkno);
//		if (i == 0) {
//			cache_buffer[i].blkno = blkno;
//			cache_buffer[i].next = NULL;
//			cache_buffer[i].prev = NULL;
//		}
//		else {
//			dinsert(blkno, i);
//		}
//	}
//	for (ret = 0;; ret++) {
//		fscanf(fp, "%u", &blkno);
//
//		if (search(fifolist,blkno) != NULL) {
//
//			a++;
//		}
//		else {
//			b++;
//			if (blkno == 0) break;
//		}
//		
//	}
//	printf("%p", cache_buffer[4].prev);
//	fclose(fp);
//
//	return 0;
//}
//
