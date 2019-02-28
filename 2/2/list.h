#pragma once

typedef struct Node {
	int value;
	struct Node *next;
}	Node;

typedef struct SList {
	Node *first;
}	SList;

// βɾ
// �ؼ����ҵ������ڶ������
// ���ĵ����ڶ������� next = NULL
void SListPopBack(SList *list) {
	assert(list->first != NULL);	// ��֧��������û�н���ɾ��
	if (list->first->next == NULL) {
		// ������ֻ��һ�����
		free(list->first);
		list->first = NULL;
		return;
	}
	/* �ҵ����ڶ�����㣨������������������㣩 */
	Node *cur = list->first;
	while (cur->next->next != NULL) {
		cur = cur->next;
	}
	// cur ���ǵ����ڶ������

	// ��Ҫ�����ͷ��ڴ�
	free(cur->next);
	cur->next = NULL;
}

// ��������
// ����ָ��
Node * Reverse_1(Node *head) {
	if (head == NULL) {
		return NULL;
	}
	Node *p1 = NULL;
	Node *p2 = head;
	Node *p3 = head->next;
	// p1 p2(head) p3

	// ѭ��Ҫ��֤ÿ����㶼������
	while (p2 != NULL) {
		// ��� p2 �� next
		p2->next = p1;

		// ��� 3 ��ָ��
		p1 = p2;
		p2 = p3;
		if (p3 != NULL) {
			p3 = p3->next;
		}
	}

	// p2 �϶��� NULL������ѭ���������
	// p3 �� p2 ��ߣ�һ��Ҳ�� NULL
	return p1;
}

// ����
// ͷɾ + ͷ��
// Ϊɶ���� βɾ + β��
Node * Reverse_2(Node *head) {
	Node *newHead = NULL;
	Node *cur = head;

	while (cur != NULL) {
		Node *next = cur->next;

		cur->next = newHead;
		newHead = cur;

		cur = next;
	}

	return newHead;
}

typedef struct TreeNode {
	struct TreeNode *left;
	struct TreeNode *right;
	int value;
}	TreeNode;

TreeNode * Find(TreeNode *root, int v) {
	if (root == NULL) {
		return NULL;	// ������һ���Ҳ���
	}

	if (root->value == v) {
		// ������Ҫ�ҵĽ��
		return root;
	}

	// ����û�ҵ�
	// ȥ����������
	TreeNode *found = Find(root->left, v);
	// found ����ҵ��ˣ������ҵ��Ľ���ַ
	// ���û�ҵ������� NULL
	if (found != NULL) {
		// ���������ҵ���
		return found;
	}

	// ��������û�ҵ�
	found = Find(root->right, v);
	if (found != NULL) {
		return found;
	}
	else {
		return NULL;
	}
}


// �������
#include <queue>

void Levelorder(TreeNode *root)
{
	if (root == NULL) {
		return;
	}
	std::queue<TreeNode *>	q;	// �����ռ� + ģ��
	q.push(root);

	while (q.size() > 0) {			// q.������		����.������
		TreeNode *n = q.front();	// ���е���Ԫ��ȡ��
		q.pop();					// �Ѷ��е���Ԫ�ص���
		printf("%d", n->value);
		// �����Һ��ӽ���
		if (n->left != NULL) {
			q.push(n->left);
		}
		if (n->right != NULL) {
			q.push(n->right);
		}
	}
}
bool IsComplete(TreeNode *root);	// �ж��Ƿ�����ȫ������


void AdjustDown(int array[], int size, int root) {
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	if (left >= size) {
		// Խ���ˣ�û�����ӣ���û���Һ���
		// root ��Ҷ��
		return;
	}

	// ȷ��˭�Ǵ�ĺ���
	int max = left;
	if (right < size /* ���Һ��� */ && array[right] > array[left]) {
		max = right;
	}

	// ����������ĺ��Ӵ�
	if (array[root] > array[max]) {
		return;
	}

	int t = array[root];
	array[root] = array[max];
	array[max] = t;

	AdjustDown(array, size, max);
}

void CreateHeap(int array[], int size) {
	for (int i = (size - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(array, size, i);
	}
}

// ������
// N * logN
// ���ȶ�
void HeapSort(int array[], int size) {
	CreateHeap(array, size);

	for (int i = 0; i < size; i++) {
		// ������һ���� array[0]
		// �����������������ȥ
		int t = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = t;

		// ǰ�沿�֣�ֻ�� array[0] ������ѵ�����
		AdjustDown(array, size - 1 - i, 0);
	}
}
