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
////Å½»ö
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
//
//int main(int argc, char* argv[])
//{
//    FILE* fp = NULL;
//    float a = 0.0, b = 0.0;
//    pointer list;
//    list.head = &cache_buffer[0];
//    list.tail = &cache_buffer[MAX_CACHE_SIZE - 1];
//
//
//    if ((fp = fopen(TRACE_FILE_NAME, "r")) == NULL) {
//        printf("%s trace file open fail.\n", TRACE_FILE_NAME);
//        return 0;
//    }
//    printf("start simulation!\n");
//
//    for (int i = 0; i < MAX_CACHE_SIZE; i++) {
//        int data;
//        fscanf(fp, "%d", &data);
//        if (i == 0) {
//            cache_buffer[i].blkno = data;
//            cache_buffer[i].next = NULL;
//            cache_buffer[i].prev = NULL;
//        }
//        else {
//            cache_buffer[i].blkno = data;
//            cache_buffer[i].next = NULL;
//            cache_buffer[i - 1].next = &cache_buffer[i];
//            cache_buffer[i].prev = &cache_buffer[i - 1];
//        }
//    }
//
//    //FIFO
//    while (1) {
//        int data;
//        fscanf(fp, "%d", &data);
//        if (data == 0) break;
//        if (!search(&list, data)) {
//            fifo(&list, data);
//        }
//        else {
//            a++;
//        }
//        b++;
//    }
//    printf("%f", (a / b) * 100.0);
//    fclose(fp);
//
//    return 0;
//}