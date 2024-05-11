#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Btree.h"
#include "Meun.h"
int Flag, Flag_1=0;
TreeNode* root1;
TreeNode* root2;
void Meun_Flag_1(void){
	Flag_1 = 1;
	printf("------------------------------------\n");
	printf("|       选择构造方式               |\n");
	printf("|       1.先序与中序               |\n");
	printf("|       2.中序与后序               |\n");
	printf("|       3.退出                     |\n");
	printf("|       请选择：                   |\n");
	printf("------------------------------------\n");
	scanf_s("%d", &Flag);
}


void Meun_Flag_2(int Flag) {
	Flag_1 = 2;
	switch (Flag)
	{
	case 1: {
		char preorder[100], inorder[100];
		printf("输入先序序列\n");
		unsigned int maxSize = 100;
		scanf_s("%s", preorder, maxSize);
		printf("输入中序序列\n");
		scanf_s("%s", inorder, maxSize);
		 root1 = buildTree(preorder, inorder, 0, strlen(inorder) - 1);
		Meun_Flag_3(Flag);
		break;
	}
	case 2: {
		char postorder[100], inorder2[100];
		printf("输入后序序列\n");
		unsigned int maxSize = 100;
		scanf_s("%s", postorder, maxSize);
		printf("输入中序序列\n");
		scanf_s("%s", inorder2, maxSize);
		int postIndex = strlen(postorder) - 1;
		root2 = buildTreeFromInorderPostorder(inorder2, postorder, 0, strlen(inorder2) - 1, &postIndex);
		Meun_Flag_3(Flag);
		break;
	}
	case 3: {
		exit(0);
		break;
	}
	default:
		break;
	
	}
}



void Meun_Flag_3(int Flag){
	Flag_1 = 3;
	printf("------------------------------------------------------------\n");
	printf("|       主菜单                                             |\n");
	printf("|       0. 括号表示法输出二叉树                            |\n");
	printf("|       1. 凹入表表示法输出二叉树                          |\n");
	printf("|       2. 中序遍历序列中第一个结点的值                    |\n");
	printf("|       3. 中序遍历序列中最后一个结点的值                  |\n");
	printf("|       4. 后序遍历序列中第一个结点的值                    |\n");
	printf("|       5. 前序遍历序列中最后一个结点的值                  |\n");
	printf("|       6. 后序遍历序列中第k个结点的值                     |\n");
	printf("|       7. 倒置形式显示的二叉树                            |\n");
	printf("|       8. 二叉树的高度                                    |\n");
	printf("|       9. 二叉树第n层的节点数                             |\n");
	printf("|       10.退出                                            |\n");
	printf("|       请选择：                                           |\n");
	printf("------------------------------------------------------------\n");
	scanf_s("%d", &Flag);
	Ex_List(Flag);
}

void Ex_List(int Flag)
{
		switch (Flag)
		{
		case 0: {
			// 第一个选项的子菜单
			if (root1) {
				printf("括号表示法输出二叉树: ");
				printTreeParenthesis(root1);
				printf("\n");
				break;
			}
			else {
				printf("括号表示法输出二叉树: ");
				printTreeParenthesis(root2);
				printf("\n");
				break;
			}
		}

		case 1: {
			// 第二个选项的子菜单
			if (root1) {
				printf("凹入表表示法输出二叉树:\n");
				printTreeIndentedWithStack(root1);
				break;
			}
			else {
				printf("凹入表表示法输出二叉树:\n");
				printTreeIndentedWithStack(root2);
				break;
			}
		}
		case 2: {
			if (root1) {
				printf("\n\n中序遍历序列中第一个结点的值: %c\n", firstNodeInorder(root1));
				break;
			}
			else {
				printf("\n\n中序遍历序列中第一个结点的值: %c\n", firstNodeInorder(root2));
				break;
			}
		}
		case 3: {
			if (root1) {
				printf("\n中序遍历序列中最后一个结点的值: %c\n", lastNodeInorder(root1));
				break;
			}
			else {
				printf("\n中序遍历序列中最后一个结点的值: %c\n", lastNodeInorder(root2));
				break;
			}
		}
		case 4: {
			if (root2) {
				printf("\n后序遍历序列中最后一个结点的值: %c\n", firstNodePostorder(root2));
				break;
			}
			else {
				printf("\n后序遍历序列中最后一个结点的值: %c\n", firstNodePostorder(root1));
				break;
			}
		}
		case 5: {
			if (root1) {
				printf("\n前序遍历序列中最后一个结点的值: %c\n", lastNodePreorder(root1));
				break;
			}
			else {
				printf("\n前序遍历序列中最后一个结点的值: %c\n", lastNodePreorder(root2));
				break;
			}
		}
		case 6: {
			if (root2)
			{
				int k;
				printf("输入k的值\n");
				scanf_s("%d", &k);
				char kthNode;
				int count = 0;
				kthNodePostorder(root2, k, &count, &kthNode);
				printf("\n后序遍历序列中第%d个结点的值: %c\n", k, kthNode);
				break;
			}
			else {
				int k;
				printf("输入k的值\n");
				scanf_s("%d", &k);
				char kthNode;
				int count = 0;
				kthNodePostorder(root1, k, &count, &kthNode);
				printf("\n后序遍历序列中第%d个结点的值: %c\n", k, kthNode);
				break;
			}
			break;
		}
		case 7: {
			if (root1) {
				printf("倒置形式显示的二叉树:\n");
				printTree(root1, 0);
				break;
			}
			else {
				printf("倒置形式显示的二叉树:\n");
				printTree(root2, 0);
				break;
			}
		}
		case 8: {
			if (root1) {
				int height = treeHeight(root1);
				printf("二叉树的高度为: %d\n", height);
				break;
			}
			else {
				int height = treeHeight(root2);
				printf("二叉树的高度为: %d\n", height);
				break;
			}
		}
		case 9: {
			if (root1) {
				int targetLevel;
				printf("输入层数\n");
				scanf_s("%d", &targetLevel);
				int nodesCount = nodesAtLevel(root1, targetLevel);
				printf("二叉树第%d层的节点数为: %d\n", targetLevel, nodesCount);
				break;
			}
			else {
				int targetLevel;
				printf("输入层数\n");
				scanf_s("%d", &targetLevel);
				int nodesCount = nodesAtLevel(root2, targetLevel);
				printf("二叉树第%d层的节点数为: %d\n", targetLevel, nodesCount);
				break;
			}
			}
		case 10: {
			void Meun_Flag_2();
			
			break;
		}
		}
		if (Flag == 10) {
			Flag_1 = 0;
		}
		else
		Flag_1 = 2;
}



void flushInputBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {
		// 读取并丢弃输入缓冲区中的字符，直到遇到换行符或文件结束符
	}
}