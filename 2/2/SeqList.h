#pragma once

typedef struct {
	int array[100];
	int size;
}	SeqList;

void SeqListPushFront(SeqList *sl, int value) {
	assert(sl != NULL);
	assert(sl->size < 100);

	// Êý¾Ý°áÒÆ
	for (int i = sl->size; i > 0; i--) {
		sl->array[i] = sl->array[i - 1];
	}
	sl->array[0] = value;
	sl->size++;
}
