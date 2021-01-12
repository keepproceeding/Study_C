#include <stdio.h>
#include <stdlib.h>

// 순차 탐색(sequential search)
int seq_search(int key, int low, int high) {
	int i;
	for (i = low; i <= high; i++) {
		if (list[i] == key) {
			return i;
		}
	}
	return -1;
}
// 개선된 순차탐색
int seq_search2(int key, int low, int high) {
	int i;
	list[high + 1] = key; // 키 값을 찾으면 종료
	for (i = low; list[i] != key; i++)
		;
	if (i == (high + 1)) return -1; // 탐색 실패
	else return i;
}
// 이진 탐색(binary search) 정렬된 배열에 사용

int search_binary2(int key, int low, int high)
{
	int middle;
	while (low <= high) { 				// 아직 숫자들이 남아 있으면
		middle = (low + high) / 2;
		if (key == list[middle]) return middle; 	// 탐색 성공
		else if (key > list[middle]) low = middle + 1; 	// 왼쪽 부분리스트 탐색
		else high = middle - 1; 			// 오른쪽 부분리스트 탐색
	}
	return -1; 					// 탐색 실패
}
