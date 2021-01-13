//#ifdef _msc_ver
//#define _crt_secure_no_warnings
//#endif
//
//#include <stdio.h>
//
//#define	max_cache_size	8192
//
//// 데이터 참조 스트림이 저장된 파일 
//#define trace_file_name	"ref_stream.txt"
//
//
//// 이중연결리스트의 노드 타입
//typedef struct buffer {
//	unsigned long blkno;
//	struct buffer* next, * prev;
//} buffer;
//
//buffer* cache_buffer[max_cache_size];
//
//
////struct buffer lrulist;
//
//buffer* fifolist;
////초기화
//void init(buffer* fifolist) {
//	fifolist->prev = fifolist;
//	fifolist->next = fifolist;
//}
////void init(linkedqueuetype* q) {
////	q->front = q->rear = 0;
////}
//
//
//// 맨처음 8192개의 새로운 노드 삽입
////void dinsert(buffer* before, unsigned long blkno,int i) {
////	buffer* newnode;
////	newnode = cache_buffer[i];
////	// 4개의 포인터 조작
////	// 1. 새로 삽입될 (new node)노드의 두 포인터 변경
////	newnode->blkno = blkno;
////	newnode->prev = before;
////	newnode->next = before->next;
////
////	//2. 새로 삽입되는 노드를 가리키는 두 개의 포인터 변경
////	before->next->prev = newnode;
////	before->next = newnode;
////}
////
////// 특정 노드 삭제
////void ddelete(buffer*fifolist) {
////	if (removed == phead)  // 헤드노드를 삭제하는 경우 == 삭제할 노드가 없다는 의미와 유사할 수도..?
////		return;
////
////	//삭제될 노드를 가리키고 있던 두 개의 포인터를 변경
////	removed->llink->rlink = removed->rlink;
////	removed->rlink->llink = removed->llink;
////
////	free(removed);
////}
//
////fifolist 알고리즘 함수
////void dinsert(buffer* before, unsigned long blkno) {
////	before->next->blkno = blkno;
////	before->prev = before->next;
////	before->next = before->next->next;
////}
//
//
//
//
//int main(int argc, char* argv[])
//{
//
//	int	ret = 0;
//	float count = 0;
//	unsigned long blkno;
//	file* fp = null;
//	cache_buffer[0]->prev = fifolist;
//
//	if ((fp = fopen(trace_file_name, "r")) == null) {
//		printf("%s trace file open fail.\n", trace_file_name);
//
//		return 0;
//	}
//	else {
//		printf("start simulation!\n");
//	}
//	buffer* fifolist;
//	fifolist = cache_buffer[0];
//	init(fifolist);
//
//	for (int i = 0; i < max_cache_size; i++) {
//		fscanf(fp, "%lu", &cache_buffer[i]->blkno);
//	}
//	printf("%lu", cache_buffer[100]->blkno);
//
//	fclose(fp);
//
//	return 0;
//}
//
