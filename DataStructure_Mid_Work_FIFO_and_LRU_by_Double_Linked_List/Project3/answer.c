#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <time.h>
#define	MAX_CACHE_SIZE		8192

// ������ ���� ��Ʈ���� ����� ���� 
#define TRACE_FILE_NAME		"ref_stream.txt"

// ���߿��Ḯ��Ʈ�� ��� Ÿ��

struct buffer {
	unsigned long blkno;
	struct buffer* next, * prev;
};

// �����͸� ������ ������ �� ���� �Ҵ� ����
// ���� �߰����� �޸� �Ҵ��� ����
// �Ҵ� ���� ������ �̿��Ͽ� LRU ����Ʈ �Ǵ� FIFO ����Ʈ�� �����ؾ� �� 
struct buffer cache_buffer[MAX_CACHE_SIZE];


// LRU �ùķ����� �� ��� lrulist �ƴϸ� fifolist�� �����ϱ� ���� ��� ��� ����
#if 1
struct buffer lrulist;
#else
struct buffer fifolist;
#endif

unsigned long curtime, hit, miss;

void lruin(struct buffer* bp) {
	struct buffer* dp = &lrulist;
	bp->next = dp->next;
	bp->prev = dp;
	(dp->next)->prev = bp;
	dp->next = bp;
}

struct buffer* lruout() {
	struct buffer* bp;
	bp = lrulist.prev;
	(bp->prev)->next = bp->next;
	(bp->next)->prev = bp->prev;

	return bp;
}


void reorder(struct buffer* bp) {
	(bp->prev)->next = bp->next;
	(bp->next)->prev = bp->prev;

	lruin(bp);
}

void init() {
	int i;
	lrulist.next = lrulist.prev = &lrulist;
	for (i = 0; i < MAX_CACHE_SIZE; i++) {
		cache_buffer[i].blkno = ~0;  // ���δ� -1������ ä�����
		cache_buffer[i].next = cache_buffer[i].prev = NULL;

		lruin(&cache_buffer[i]);

	}
	return;
}

struct buffer* findblk(unsigned long blkno) {
	struct buffer* dp, * bp;
	dp = &lrulist;
	for (bp = dp->next; bp != dp; bp = bp->next) {
		if (bp->blkno == blkno)
			return bp;
	}
	return NULL;
}

void pgref(unsigned long blkno) {
	struct buffer* bufp;
	// search blkno in lrulist
	bufp = findblk(blkno);
	if (bufp) {
		hit++;
		reorder(bufp);  //FIFO�� reorder�� �Ⱦ��� ��.
	}
	else {
		miss++;
		bufp = lruout();
		bufp->blkno = blkno;
		lruin(bufp);
	}
}

int main(int argc, char* argv[])
{
	int	ret;
	time_t t1, t2;
	unsigned long blkno;
	FILE* fp = NULL;
	init();
	curtime = miss = hit = 0;
	if ((fp = fopen(TRACE_FILE_NAME, "r")) == NULL) {
		printf("%s trace file open fail.\n", TRACE_FILE_NAME);
		return 0;
	}
	else {
		printf("start simulation!\n");
	}
	t1 = time(NULL);
	////////////////////////////////////////////////
	// �ùķ��̼� ���� �� ��� ����� ���� �ڵ�
	////////////////////////////////////////////////

	while ((ret = fscanf(fp, "%lu\n", &blkno)) != EOF) {
		curtime++;
		pgref(blkno);
	}
	t2 = time(NULL);

	fclose(fp);
	printf("total access = %lu, hit = %lu, miss = %lu\n", curtime, hit, miss);
	printf("hit ratio = %f, miss ratio = %f\n", (float)hit / (float)curtime, (float)miss / (float)curtime);
	printf("time : %d", t2-t1);
	return 0;
}

