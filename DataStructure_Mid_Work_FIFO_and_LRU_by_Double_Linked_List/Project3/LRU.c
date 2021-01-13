//#ifdef _MSC_VER
//#define _CRT_SECURE_NO_WARNINGS
//#endif
//
//#include <stdio.h>
//#define   MAX_CACHE_SIZE      8192
//#define TRACE_FILE_NAME      "ref_stream.txt"
//
//typedef struct buffer {
//    int blkno;
//    struct buffer* next, * prev;
//}buffer;
//
//typedef struct pointer {
//    buffer* head;
//    buffer* tail;
//}pointer;
//
//buffer cache_buffer[MAX_CACHE_SIZE];
//
//void print_arr() {                                     // 시뮬레이션 테스트용 함수
//    for (int i = 0; i < 5; i++) {
//        printf("%d ", cache_buffer[i].blkno);
//    }
//    for (int i = 0; i < 5; i++) {
//        printf("%d ", cache_buffer[i+8187].blkno);
//    }
//    printf("\n");
//}
//
//
////탐색
//buffer* location;
//int search(pointer* list, int data) {
//    buffer* iter = list->head;
//    while (iter->next != NULL) {
//        if (iter->blkno == data) {
//            location = iter;
//            return 1;
//        }
//        iter = iter->next;
//    }
//    return 0;
//}
//
//
//void fifo(pointer* list, int data) {
//    buffer* new_tail = list->head;
//    buffer* new_head = list->head->next;
//    buffer* tail = list->tail;
//
//    list->head = new_head;
//    list->tail = new_tail;
//
//    new_tail->prev = tail;
//    tail->next = new_tail;
//
//    new_tail->next = NULL;
//    new_head->prev = NULL;
//
//    new_tail->blkno = data;
//}
//
//void lru(pointer* list, buffer* p) {
//    if (p == list->head) {
//        buffer* new_tail = list->head;
//        buffer* new_head = list->head->next;
//        buffer* tail = list->tail;
//
//        list->head = new_head;
//        list->tail = new_tail;
//
//        new_tail->prev = tail;
//        tail->next = new_tail;
//
//        new_tail->next = NULL;
//        new_head->prev = NULL;
//    }
//    else {
//        buffer* new_tail = p;
//        buffer* tail = list->tail;
//        list->tail = new_tail; // 노드를 맨 뒤로
//
//        new_tail->prev->next = new_tail->next; // 공백이 생긴 노드사이를 연결
//        new_tail->next->prev = new_tail->prev;
//
//        new_tail->prev = tail;  // (현) 맨 뒤 노드와 (전) 맨 뒤 노드를 연결
//        tail->next = new_tail;
//
//        new_tail->next = NULL; // (현) 맨 뒤 노드의 next
//    }
//}
//
//
//int main(int argc, char* argv[])
//{
//    int i = 0;
//    FILE* fp = NULL;
//    float a = 0.0, b = 0.0;
//    pointer list;
//    list.head = &cache_buffer[0];
//    list.tail = &cache_buffer[0];
//
//    if ((fp = fopen(TRACE_FILE_NAME, "r")) == NULL) {
//        printf("%s trace file open fail.\n", TRACE_FILE_NAME);
//        return 0;
//    }
//    printf("start simulation!\n");
//
//    while (1) {
//        int data;
//        fscanf(fp, "%d", &data);
//        if (i == 0) {
//            cache_buffer[i].blkno = data;
//            cache_buffer[i].next = NULL;
//            cache_buffer[i].prev = NULL;
//            i++;
//        }
//        else {
//            if (!search(&list, data)) {
//                buffer* temp = list.tail;
//                list.tail = &cache_buffer[i];
//                list.tail->blkno = data;
//                list.tail->next = NULL;
//                list.tail->prev = temp;
//                temp->next = list.tail;
//                if (i == MAX_CACHE_SIZE) break;
//                i++;
//            }
//            else {
//                lru(&list, location);
//                a++;
//            }
//        }
//        b++;
//    }
//
//    //LRU
//    while (1) {
//        int data;
//        fscanf(fp, "%d", &data);
//        if (data == 0) break;
//        if (!search(&list, data)) {
//            fifo(&list, data);
//        }
//        else {
//            lru(&list, location);
//            a++;
//        }
//        b++;
//        
//    }
//    printf("%f", (a/b)*100);
//    fclose(fp);
//
//    return 0;
//}