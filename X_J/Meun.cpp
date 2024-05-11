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
	printf("|       ѡ���췽ʽ               |\n");
	printf("|       1.����������               |\n");
	printf("|       2.���������               |\n");
	printf("|       3.�˳�                     |\n");
	printf("|       ��ѡ��                   |\n");
	printf("------------------------------------\n");
	scanf_s("%d", &Flag);
}


void Meun_Flag_2(int Flag) {
	Flag_1 = 2;
	switch (Flag)
	{
	case 1: {
		char preorder[100], inorder[100];
		printf("������������\n");
		unsigned int maxSize = 100;
		scanf_s("%s", preorder, maxSize);
		printf("������������\n");
		scanf_s("%s", inorder, maxSize);
		 root1 = buildTree(preorder, inorder, 0, strlen(inorder) - 1);
		Meun_Flag_3(Flag);
		break;
	}
	case 2: {
		char postorder[100], inorder2[100];
		printf("�����������\n");
		unsigned int maxSize = 100;
		scanf_s("%s", postorder, maxSize);
		printf("������������\n");
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
	printf("|       ���˵�                                             |\n");
	printf("|       0. ���ű�ʾ�����������                            |\n");
	printf("|       1. ������ʾ�����������                          |\n");
	printf("|       2. ������������е�һ������ֵ                    |\n");
	printf("|       3. ����������������һ������ֵ                  |\n");
	printf("|       4. ������������е�һ������ֵ                    |\n");
	printf("|       5. ǰ��������������һ������ֵ                  |\n");
	printf("|       6. ������������е�k������ֵ                     |\n");
	printf("|       7. ������ʽ��ʾ�Ķ�����                            |\n");
	printf("|       8. �������ĸ߶�                                    |\n");
	printf("|       9. ��������n��Ľڵ���                             |\n");
	printf("|       10.�˳�                                            |\n");
	printf("|       ��ѡ��                                           |\n");
	printf("------------------------------------------------------------\n");
	scanf_s("%d", &Flag);
	Ex_List(Flag);
}

void Ex_List(int Flag)
{
		switch (Flag)
		{
		case 0: {
			// ��һ��ѡ����Ӳ˵�
			if (root1) {
				printf("���ű�ʾ�����������: ");
				printTreeParenthesis(root1);
				printf("\n");
				break;
			}
			else {
				printf("���ű�ʾ�����������: ");
				printTreeParenthesis(root2);
				printf("\n");
				break;
			}
		}

		case 1: {
			// �ڶ���ѡ����Ӳ˵�
			if (root1) {
				printf("������ʾ�����������:\n");
				printTreeIndentedWithStack(root1);
				break;
			}
			else {
				printf("������ʾ�����������:\n");
				printTreeIndentedWithStack(root2);
				break;
			}
		}
		case 2: {
			if (root1) {
				printf("\n\n������������е�һ������ֵ: %c\n", firstNodeInorder(root1));
				break;
			}
			else {
				printf("\n\n������������е�һ������ֵ: %c\n", firstNodeInorder(root2));
				break;
			}
		}
		case 3: {
			if (root1) {
				printf("\n����������������һ������ֵ: %c\n", lastNodeInorder(root1));
				break;
			}
			else {
				printf("\n����������������һ������ֵ: %c\n", lastNodeInorder(root2));
				break;
			}
		}
		case 4: {
			if (root2) {
				printf("\n����������������һ������ֵ: %c\n", firstNodePostorder(root2));
				break;
			}
			else {
				printf("\n����������������һ������ֵ: %c\n", firstNodePostorder(root1));
				break;
			}
		}
		case 5: {
			if (root1) {
				printf("\nǰ��������������һ������ֵ: %c\n", lastNodePreorder(root1));
				break;
			}
			else {
				printf("\nǰ��������������һ������ֵ: %c\n", lastNodePreorder(root2));
				break;
			}
		}
		case 6: {
			if (root2)
			{
				int k;
				printf("����k��ֵ\n");
				scanf_s("%d", &k);
				char kthNode;
				int count = 0;
				kthNodePostorder(root2, k, &count, &kthNode);
				printf("\n������������е�%d������ֵ: %c\n", k, kthNode);
				break;
			}
			else {
				int k;
				printf("����k��ֵ\n");
				scanf_s("%d", &k);
				char kthNode;
				int count = 0;
				kthNodePostorder(root1, k, &count, &kthNode);
				printf("\n������������е�%d������ֵ: %c\n", k, kthNode);
				break;
			}
			break;
		}
		case 7: {
			if (root1) {
				printf("������ʽ��ʾ�Ķ�����:\n");
				printTree(root1, 0);
				break;
			}
			else {
				printf("������ʽ��ʾ�Ķ�����:\n");
				printTree(root2, 0);
				break;
			}
		}
		case 8: {
			if (root1) {
				int height = treeHeight(root1);
				printf("�������ĸ߶�Ϊ: %d\n", height);
				break;
			}
			else {
				int height = treeHeight(root2);
				printf("�������ĸ߶�Ϊ: %d\n", height);
				break;
			}
		}
		case 9: {
			if (root1) {
				int targetLevel;
				printf("�������\n");
				scanf_s("%d", &targetLevel);
				int nodesCount = nodesAtLevel(root1, targetLevel);
				printf("��������%d��Ľڵ���Ϊ: %d\n", targetLevel, nodesCount);
				break;
			}
			else {
				int targetLevel;
				printf("�������\n");
				scanf_s("%d", &targetLevel);
				int nodesCount = nodesAtLevel(root2, targetLevel);
				printf("��������%d��Ľڵ���Ϊ: %d\n", targetLevel, nodesCount);
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
		// ��ȡ���������뻺�����е��ַ���ֱ���������з����ļ�������
	}
}