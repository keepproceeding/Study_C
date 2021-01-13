#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <time.h>
#define	MAX_CACHE_SIZE		8192

// 데이터 참조 스트림이 저장된 파일 
#define TRACE_FILE_NAME		"ref_stream.txt"

// 이중연결리스트의 노드 타입

struct buffer {
	unsigned long blkno;
	struct buffer* next, * prev;
};

// 데이터를 저장할 공간을 한 번에 할당 받음
// 이후 추가적인 메모리 할당은 없음
// 할당 받은 노드들을 이용하여 LRU 리스트 또는 FIFO 리스트를 유지해야 함 
struct buffer cache_buffer[MAX_CACHE_SIZE];


// LRU 시뮬레이터 인 경우 lrulist 아니면 fifolist를 유지하기 위한 헤드 노드 선언
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
		cache_buffer[i].blkno = ~0;  // 전부다 -1값으로 채운것임
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
		reorder(bufp);  //FIFO는 reorder을 안쓰면 됨.
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
	// 시뮬레이션 시작 및 결과 출력을 위한 코드
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

