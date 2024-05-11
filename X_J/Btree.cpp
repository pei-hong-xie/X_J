#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Btree.h"

// ��ʼ��ջ
void initStack(Stack* stack) {
	stack->top = -1;
}

// �ж�ջ�Ƿ�Ϊ��
int isEmpty(Stack* stack) {
	return stack->top == -1;
}

// ��ջ����
void push(Stack* stack, TreeNode* item) {
	if (stack->top == MAX_SIZE - 1) {
		printf("Stack Overflow\n");
		return;
	}
	stack->items[++stack->top] = item;
}

// ��ջ����
TreeNode* pop(Stack* stack) {
	if (isEmpty(stack)) {
		printf("Stack Underflow\n");
		exit(1);
	}
	return stack->items[stack->top--];
}

// �����������к��������й��������
TreeNode* buildTree(char* preorder, char* inorder, int inStart, int inEnd) {
	static int preIndex = 0;

	if (inStart > inEnd) {
		return NULL;
	}

	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	newNode->data = preorder[preIndex++];
	newNode->left = NULL;
	newNode->right = NULL;

	if (inStart == inEnd) {
		return newNode;
	}

	int inIndex;
	for (int i = inStart; i <= inEnd; i++) {
		if (inorder[i] == newNode->data) {
			inIndex = i;
			break;
		}
	}

	newNode->left = buildTree(preorder, inorder, inStart, inIndex - 1);
	newNode->right = buildTree(preorder, inorder, inIndex + 1, inEnd);

	return newNode;
}

// �����������кͺ������й��������
TreeNode* buildTreeFromInorderPostorder(char* inorder, char* postorder, int inStart, int inEnd, int* postIndex) {
	if (inStart > inEnd) {
		return NULL;
	}

	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	newNode->data = postorder[*postIndex];
	newNode->left = NULL;
	newNode->right = NULL;

	(*postIndex)--;

	if (inStart == inEnd) {
		return newNode;
	}

	int inIndex;
	for (int i = inStart; i <= inEnd; i++) {
		if (inorder[i] == newNode->data) {
			inIndex = i;
			break;
		}
	}

	newNode->right = buildTreeFromInorderPostorder(inorder, postorder, inIndex + 1, inEnd, postIndex);
	newNode->left = buildTreeFromInorderPostorder(inorder, postorder, inStart, inIndex - 1, postIndex);

	return newNode;
}

// �����ű�ʾ�����������
void printTreeParenthesis(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	printf("%c", root->data);

	if (root->left != NULL || root->right != NULL) {
		printf("(");
		printTreeParenthesis(root->left);
		if (root->right != NULL) {
			printf(",");
			printTreeParenthesis(root->right);
		}
		printf(")");
	}
}



// �������������������е�һ������ֵ
char firstNodeInorder(TreeNode* root) {
	// �����ڵ��Ƿ�Ϊ��
	if (root == NULL) {
		// ���Ϊ�գ��򷵻�һ��Ĭ��ֵ�������׳��쳣������ȡ�����������
		return '\0'; // ����һ�����ַ�
	}

	// ����������ֱ���ҵ�����ߵ�Ҷ�ӽڵ�
	while (root->left != NULL) {
		root = root->left;
	}
	return root->data;
}


// �����������������������һ������ֵ
char lastNodeInorder(TreeNode* root) {
	while (root->right != NULL) {
		root = root->right;
	}
	return root->data;
}

// �������������������е�һ������ֵ
char firstNodePostorder(TreeNode* root) {
	while (root->left != NULL || root->right != NULL) {
		if (root->left != NULL) {
			root = root->left;
		}
		else {
			root = root->right;
		}
	}
	return root->data;
}

// �������ǰ��������������һ������ֵ
char lastNodePreorder(TreeNode* root) {
	while (root->right != NULL) {
		root = root->right;
	}
	return root->data;
}

// �������������������е�k������ֵ
void kthNodePostorder(TreeNode* root, int k, int* count, char* result) {
	if (root == NULL || *count >= k) {
		return;
	}

	kthNodePostorder(root->left, k, count, result);
	kthNodePostorder(root->right, k, count, result);

	(*count)++;
	if (*count == k) {
		*result = root->data;
	}
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

// ����������ĸ߶�
int treeHeight(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	else {
		int leftHeight = treeHeight(root->left);
		int rightHeight = treeHeight(root->right);
		return 1 + max(leftHeight, rightHeight);
	}
}

// ���������ָ����εĽڵ���
int nodesAtLevel(TreeNode* root, int level) {
	if (root == NULL || level < 1) {
		return 0;
	}
	if (level == 1) {
		return 1;
	}
	else {
		return nodesAtLevel(root->left, level - 1) + nodesAtLevel(root->right, level - 1);
	}
}

// �Ե�����ʽ��ʾ������
void printTree(TreeNode* root, int space) {
    if (root == NULL) {
        return;
    }

    // ���Ӽ�࣬ʹ�����������ֱ�λ�ڸ��ڵ����������
    space += 5;

    // ����������
    printTree(root->right, space);

    // ��ӡ��ǰ�ڵ㣬ע��ո���
    printf("\n");
    for (int i = 0; i < space; i++) {
        printf(" ");
    }
    printf("%c\n", root->data);

    // ����������
    printTree(root->left, space);
}



// �԰�����ʾ�����������
void printTreeIndentedWithStack(TreeNode* root) {
	TreeNode* St[MaxSize], * p;
	int level[MaxSize][2], top = -1, n, i, width = 4;
	char type;
	if (root != NULL)
	{
		top++;
		St[top] = root;						//�������ջ
		level[top][0] = width;
		level[top][1] = 2;				//2��ʾ�Ǹ�
		while (top > -1)
		{
			p = St[top];					//��ջ��������ʾ�ý��ֵ
			n = level[top][0];
			switch (level[top][1])
			{
			case 0:type = 'L'; break;		//����֮�����(L)
			case 1:type = 'R'; break;		//�ҽ��֮�����(R)
			case 2:type = 'B'; break;		//�����֮��ǰ���(B)
			}
			for (i = 1; i <= n; i++)			//����nΪ��ʾ����,�ַ����Ҷ�����ʾ
				printf(" ");
			printf("%c(%c)", p->data, type);
			for (i = n + 1; i <= MaxWidth; i += 2)
				printf("--");
			printf("\n");
			top--;
			if (p->right != NULL)
			{							//���������������ջ
				top++;
				St[top] = p->right;
				level[top][0] = n + width;	//��ʾ������width
				level[top][1] = 1;		//1��ʾ��������
			}
			if (p->left != NULL)
			{							//���������������ջ
				top++;
				St[top] = p->left;
				level[top][0] = n + width;  //��ʾ������width
				level[top][1] = 0;        //0��ʾ��������
			}
		}
	}
}

