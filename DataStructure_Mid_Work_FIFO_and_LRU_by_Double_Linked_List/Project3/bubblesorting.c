#include <stdio.h>
//int main(void) {
//	int i = 1;
//	int array[5] = { 0 };
//
//	for (i = 1; i <= 5; i++) {
//		printf("�������� %d�� ° ���� �Է��ϼ���.\n", i);
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
//		printf("%d��° �� �Է� :", i + 1);
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
//// ���� ����
//void insertion_sort(int list[], int n) {
//    int i, j, key;
//
//    // ���ؽ� 0�� �̹� ���ĵ� ������ �� �� �ִ�.
//    for (i = 1; i < n; i++) {
//        key = list[i]; // ���� ���Ե� ������ i��° ������ key ������ ����
//
//        // ���� ���ĵ� �迭�� i-1�����̹Ƿ� i-1��°���� �������� �����Ѵ�.
//        // j ���� ������ �ƴϾ�� �ǰ�
//        // key ������ ���ĵ� �迭�� �ִ� ���� ũ�� j��°�� j+1��°�� �̵�
//        for (j = i - 1; j >= 0 && list[j] > key; j--) {
//            list[j + 1] = list[j]; // ���ڵ��� ���������� �̵�
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
//    // ���� ���� ����
//    insertion_sort(list, n);
//
//    // ���� ��� ���
//    for (i = 0; i < n; i++) {
//        printf("%d\n", list[i]);
//    }
//}