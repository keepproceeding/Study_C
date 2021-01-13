//#ifdef _MSC_VER
//#define _CRT_SECURE_NO_WARNINGS
//#endif
//
//#include <stdio.h>
//
//#define	MAX_CACHE_SIZE		8192
//
//// ������ ���� ��Ʈ���� ����� ���� 
//#define TRACE_FILE_NAME		"ref_stream.txt"
//
//
//// ���߿��Ḯ��Ʈ�� ��� Ÿ��
//typedef struct buffer {
//	unsigned long blkno;
//	struct buffer* next, * prev;
//}buffer;
//
//// �����͸� ������ ������ �� ���� �Ҵ� ����
//// ���� �߰����� �޸� �Ҵ��� ����
//// �Ҵ� ���� ������ �̿��Ͽ� LRU ����Ʈ �Ǵ� FIFO ����Ʈ�� �����ؾ� �� 
//buffer cache_buffer[MAX_CACHE_SIZE];
//
//
//// LRU �ùķ����� �� ��� lrulist �ƴϸ� fifolist�� �����ϱ� ���� ��� ��� ����
////#if 1
////struct buffer lrulist;
////#else
//buffer* fifolist;
////#endif
////�ʱ�ȭ
//void init(buffer* pfifolist) {
//	pfifolist->prev = pfifolist;
//	pfifolist->next = pfifolist;
//}
//// ���ο� ��� ����
//void dinsert(unsigned long blkno, int i) {
//	cache_buffer[i].blkno = blkno;
//	cache_buffer[i].next = NULL;
//	cache_buffer[i - 1].next = &cache_buffer[i];
//	cache_buffer[i].prev = &cache_buffer[i - 1];
//}
////fifolist �˰��� �Լ�
//void fifo(buffer* fifolist, int blkno) {
//	//��� ����� ������ ����
//	fifolist->next->blkno = blkno;
//	fifolist->prev->next = fifolist->next;  //(��)�� ������ ��尡 (��) �� ������ ��忡 next
//	fifolist->prev->next->next = fifolist; // �� ������ ����� next�� fifolist��
//	fifolist->next = fifolist->next->next; // fifolist�� next�� fifolist�� next next
//	fifolist->next->prev = fifolist; // (��)fifolist�� next�� prev�� fifolist��
//	fifolist->prev = fifolist->prev->next; // fifolist�� prev�� (��) ������ ��带
//}
//
////Ư�� ���� ������ �ִ� ��带 �˻��ؼ� �� ����� �����͸� ��ȯ�ϴ� �Լ� (��� Ž�� �����ε�)
//buffer* search(buffer* phead, unsigned long blkno) {
//	buffer* p;
//	for (p = phead->next; p != phead; p = p->next) {
//		if (p->blkno == blkno)
//			return p;
//		// while������ ������
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
