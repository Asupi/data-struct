#pragma once

typedef struct Node {
	int value;
	struct Node *next;
}	Node;

typedef struct SList {
	Node *first;
}	SList;

// 尾删
// 关键是找到倒数第二个结点
// 更改倒数第二个结点的 next = NULL
void SListPopBack(SList *list) {
	assert(list->first != NULL);	// 不支持链表中没有结点的删除
	if (list->first->next == NULL) {
		// 链表中只有一个结点
		free(list->first);
		list->first = NULL;
		return;
	}
	/* 找倒数第二个结点（链表中至少有两个结点） */
	Node *cur = list->first;
	while (cur->next->next != NULL) {
		cur = cur->next;
	}
	// cur 就是倒数第二个结点

	// 不要忘记释放内存
	free(cur->next);
	cur->next = NULL;
}

// 链表逆置
// 三个指针
Node * Reverse_1(Node *head) {
	if (head == NULL) {
		return NULL;
	}
	Node *p1 = NULL;
	Node *p2 = head;
	Node *p3 = head->next;
	// p1 p2(head) p3

	// 循环要保证每个结点都被处理
	while (p2 != NULL) {
		// 变更 p2 的 next
		p2->next = p1;

		// 变更 3 个指针
		p1 = p2;
		p2 = p3;
		if (p3 != NULL) {
			p3 = p3->next;
		}
	}

	// p2 肯定是 NULL，否则循环不会结束
	// p3 在 p2 后边，一定也是 NULL
	return p1;
}

// 逆置
// 头删 + 头插
// 为啥不用 尾删 + 尾插
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
		return NULL;	// 空树里一定找不到
	}

	if (root->value == v) {
		// 根就是要找的结点
		return root;
	}

	// 根里没找到
	// 去左子树里找
	TreeNode *found = Find(root->left, v);
	// found 如果找到了，就是找到的结点地址
	// 如果没找到，就是 NULL
	if (found != NULL) {
		// 左子树里找到了
		return found;
	}

	// 左子树里没找到
	found = Find(root->right, v);
	if (found != NULL) {
		return found;
	}
	else {
		return NULL;
	}
}


// 层序遍历
#include <queue>

void Levelorder(TreeNode *root)
{
	if (root == NULL) {
		return;
	}
	std::queue<TreeNode *>	q;	// 命名空间 + 模板
	q.push(root);

	while (q.size() > 0) {			// q.函数名		对象.函数名
		TreeNode *n = q.front();	// 队列的首元素取出
		q.pop();					// 把队列的首元素弹出
		printf("%d", n->value);
		// 带左右孩子进来
		if (n->left != NULL) {
			q.push(n->left);
		}
		if (n->right != NULL) {
			q.push(n->right);
		}
	}
}
bool IsComplete(TreeNode *root);	// 判断是否是完全二叉树


void AdjustDown(int array[], int size, int root) {
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	if (left >= size) {
		// 越界了，没有左孩子，就没有右孩子
		// root 是叶子
		return;
	}

	// 确定谁是大的孩子
	int max = left;
	if (right < size /* 有右孩子 */ && array[right] > array[left]) {
		max = right;
	}

	// 如果根比最大的孩子大
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

// 堆排序
// N * logN
// 不稳定
void HeapSort(int array[], int size) {
	CreateHeap(array, size);

	for (int i = 0; i < size; i++) {
		// 最大的数一定在 array[0]
		// 把最大的数交换到最后去
		int t = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = t;

		// 前面部分，只有 array[0] 不满足堆的性质
		AdjustDown(array, size - 1 - i, 0);
	}
}
