#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Btree.h"

// 初始化栈
void initStack(Stack* stack) {
	stack->top = -1;
}

// 判断栈是否为空
int isEmpty(Stack* stack) {
	return stack->top == -1;
}

// 入栈操作
void push(Stack* stack, TreeNode* item) {
	if (stack->top == MAX_SIZE - 1) {
		printf("Stack Overflow\n");
		return;
	}
	stack->items[++stack->top] = item;
}

// 出栈操作
TreeNode* pop(Stack* stack) {
	if (isEmpty(stack)) {
		printf("Stack Underflow\n");
		exit(1);
	}
	return stack->items[stack->top--];
}

// 根据先序序列和中序序列构造二叉树
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

// 根据中序序列和后序序列构造二叉树
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

// 以括号表示法输出二叉树
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



// 求二叉树中序遍历序列中第一个结点的值
char firstNodeInorder(TreeNode* root) {
	// 检查根节点是否为空
	if (root == NULL) {
		// 如果为空，则返回一个默认值，或者抛出异常，具体取决于你的需求
		return '\0'; // 返回一个空字符
	}

	// 遍历左子树直到找到最左边的叶子节点
	while (root->left != NULL) {
		root = root->left;
	}
	return root->data;
}


// 求二叉树中序遍历序列中最后一个结点的值
char lastNodeInorder(TreeNode* root) {
	while (root->right != NULL) {
		root = root->right;
	}
	return root->data;
}

// 求二叉树后序遍历序列中第一个结点的值
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

// 求二叉树前序遍历序列中最后一个结点的值
char lastNodePreorder(TreeNode* root) {
	while (root->right != NULL) {
		root = root->right;
	}
	return root->data;
}

// 求二叉树后序遍历序列中第k个结点的值
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

// 计算二叉树的高度
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

// 计算二叉树指定层次的节点数
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

// 以倒置形式显示二叉树
void printTree(TreeNode* root, int space) {
    if (root == NULL) {
        return;
    }

    // 增加间距，使得左右子树分别位于根节点的左右两侧
    space += 5;

    // 遍历右子树
    printTree(root->right, space);

    // 打印当前节点，注意空格数
    printf("\n");
    for (int i = 0; i < space; i++) {
        printf(" ");
    }
    printf("%c\n", root->data);

    // 遍历左子树
    printTree(root->left, space);
}



// 以凹入表表示法输出二叉树
void printTreeIndentedWithStack(TreeNode* root) {
	TreeNode* St[MaxSize], * p;
	int level[MaxSize][2], top = -1, n, i, width = 4;
	char type;
	if (root != NULL)
	{
		top++;
		St[top] = root;						//根结点入栈
		level[top][0] = width;
		level[top][1] = 2;				//2表示是根
		while (top > -1)
		{
			p = St[top];					//退栈并凹入显示该结点值
			n = level[top][0];
			switch (level[top][1])
			{
			case 0:type = 'L'; break;		//左结点之后输出(L)
			case 1:type = 'R'; break;		//右结点之后输出(R)
			case 2:type = 'B'; break;		//根结点之后前输出(B)
			}
			for (i = 1; i <= n; i++)			//其中n为显示场宽,字符以右对齐显示
				printf(" ");
			printf("%c(%c)", p->data, type);
			for (i = n + 1; i <= MaxWidth; i += 2)
				printf("--");
			printf("\n");
			top--;
			if (p->right != NULL)
			{							//将右子树根结点入栈
				top++;
				St[top] = p->right;
				level[top][0] = n + width;	//显示场宽增width
				level[top][1] = 1;		//1表示是右子树
			}
			if (p->left != NULL)
			{							//将左子树根结点入栈
				top++;
				St[top] = p->left;
				level[top][0] = n + width;  //显示场宽增width
				level[top][1] = 0;        //0表示是左子树
			}
		}
	}
}

