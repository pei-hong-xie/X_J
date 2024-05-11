#ifndef __Btree_H
#define __Btree_H


#define MaxWidth 40
#define MaxSize 100
#define MAX_SIZE 100

// 定义二叉树节点结构
typedef struct TreeNode {
	char data;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

// 定义栈结构
typedef struct Stack {
	int top;
	TreeNode* items[MAX_SIZE];
} Stack;

void initStack(Stack* stack);
int isEmpty(Stack* stack);
void push(Stack* stack, TreeNode* item);
TreeNode* pop(Stack* stack);
TreeNode* buildTree(char* preorder, char* inorder, int inStart, int inEnd);
TreeNode* buildTreeFromInorderPostorder(char* inorder, char* postorder, int inStart, int inEnd, int* postIndex);
void printTreeParenthesis(TreeNode* root);
char firstNodeInorder(TreeNode* root);
char lastNodeInorder(TreeNode* root);
char firstNodePostorder(TreeNode* root);
char lastNodePreorder(TreeNode* root);
void kthNodePostorder(TreeNode* root, int k, int* count, char* result);
int treeHeight(TreeNode* root);
int nodesAtLevel(TreeNode* root, int level);
void printTree(TreeNode* root, int space);
void printTreeIndentedWithStack(TreeNode* root);
#endif // !__Btree_H
