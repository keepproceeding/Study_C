//#ifdef _msc_ver
//#define _crt_secure_no_warnings
//#endif
//
//#include <stdio.h>
//
//#define	max_cache_size	8192
//
//// ������ ���� ��Ʈ���� ����� ���� 
//#define trace_file_name	"ref_stream.txt"
//
//
//// ���߿��Ḯ��Ʈ�� ��� Ÿ��
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
////�ʱ�ȭ
//void init(buffer* fifolist) {
//	fifolist->prev = fifolist;
//	fifolist->next = fifolist;
//}
////void init(linkedqueuetype* q) {
////	q->front = q->rear = 0;
////}
//
//
//// ��ó�� 8192���� ���ο� ��� ����
////void dinsert(buffer* before, unsigned long blkno,int i) {
////	buffer* newnode;
////	newnode = cache_buffer[i];
////	// 4���� ������ ����
////	// 1. ���� ���Ե� (new node)����� �� ������ ����
////	newnode->blkno = blkno;
////	newnode->prev = before;
////	newnode->next = before->next;
////
////	//2. ���� ���ԵǴ� ��带 ����Ű�� �� ���� ������ ����
////	before->next->prev = newnode;
////	before->next = newnode;
////}
////
////// Ư�� ��� ����
////void ddelete(buffer*fifolist) {
////	if (removed == phead)  // ����带 �����ϴ� ��� == ������ ��尡 ���ٴ� �ǹ̿� ������ ����..?
////		return;
////
////	//������ ��带 ����Ű�� �ִ� �� ���� �����͸� ����
////	removed->llink->rlink = removed->rlink;
////	removed->rlink->llink = removed->llink;
////
////	free(removed);
////}
//
////fifolist �˰��� �Լ�
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
