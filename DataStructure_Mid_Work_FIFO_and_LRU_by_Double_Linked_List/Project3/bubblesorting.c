#include <stdio.h>
//int main(void) {
//	int i = 1;
//	int array[5] = { 0 };
//
//	for (i = 1; i <= 5; i++) {
//		printf("데이터의 %d번 째 값을 입력하세요.\n", i);
//		scanf("%d", &array[i - 1]);
//	}
//	printf("\narray[5]=");
//	for (i = 1; i <= 5; i++) printf("%d", array[i - 1]);
//	bubblesort(array, sizeof(array) / sizeof(int));
//
//	for (int i = 0; i < 5; i++) {
//		printf("\n%d", array[i]);
//	}
//
//}
//void bubblesort(int data[], int num) {
//	int temp;
//	for (int i = 0; i < num; i++) {
//		for (int j = 0; j < num - 1; j++) {
//			if (data[j] > data[j + 1]) {
//				temp = data[j];
//				data[j] = data[j + 1];
//				data[j + 1] = temp;
//			}
//		}
//	}
////}
//
//
//int main(void) {
//	int num[5] = { 0 };
//	int i, j;
//	int key;
//
//	for (i = 0; i < 5; i++) {
//		printf("%d번째 수 입력 :", i + 1);
//		scanf_s("%d", &num[i]);
//	}
//	for (i = 0; i < 4; i++) {
//		key = num[i + 1];
//		for (j = i; j > -1; j--) {
//			if (num[j] > key) {
//				num[j + 1] = num[j];
//			}
//			else
//				break;
//		}
//		num[j + 1] = key;
//	}
//	for (i = 0; i < 5; i++) printf("%d", num[i]);
//}



//
//# include <stdio.h>
//# define MAX_SIZE 5
//
//// 삽입 정렬
//void insertion_sort(int list[], int n) {
//    int i, j, key;
//
//    // 인텍스 0은 이미 정렬된 것으로 볼 수 있다.
//    for (i = 1; i < n; i++) {
//        key = list[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사
//
//        // 현재 정렬된 배열은 i-1까지이므로 i-1번째부터 역순으로 조사한다.
//        // j 값은 음수가 아니어야 되고
//        // key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+1번째로 이동
//        for (j = i - 1; j >= 0 && list[j] > key; j--) {
//            list[j + 1] = list[j]; // 레코드의 오른쪽으로 이동
//        }
//
//        list[j + 1] = key;
//    }
//}
//
//void main() {
//    int i;
//    int n = MAX_SIZE;
//    int list[5] = { 8, 5, 6, 2, 4 };
//
//    // 삽입 정렬 수행
//    insertion_sort(list, n);
//
//    // 정렬 결과 출력
//    for (i = 0; i < n; i++) {
//        printf("%d\n", list[i]);
//    }
//}