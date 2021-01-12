#include <stdio.h>
#include <stdlib.h>

// ���� Ž��(sequential search)
int seq_search(int key, int low, int high) {
	int i;
	for (i = low; i <= high; i++) {
		if (list[i] == key) {
			return i;
		}
	}
	return -1;
}
// ������ ����Ž��
int seq_search2(int key, int low, int high) {
	int i;
	list[high + 1] = key; // Ű ���� ã���� ����
	for (i = low; list[i] != key; i++)
		;
	if (i == (high + 1)) return -1; // Ž�� ����
	else return i;
}
// ���� Ž��(binary search) ���ĵ� �迭�� ���

int search_binary2(int key, int low, int high)
{
	int middle;
	while (low <= high) { 				// ���� ���ڵ��� ���� ������
		middle = (low + high) / 2;
		if (key == list[middle]) return middle; 	// Ž�� ����
		else if (key > list[middle]) low = middle + 1; 	// ���� �κи���Ʈ Ž��
		else high = middle - 1; 			// ������ �κи���Ʈ Ž��
	}
	return -1; 					// Ž�� ����
}
