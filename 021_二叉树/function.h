#include <stdio.h>
#include <stdlib.h>
//���� ����ѵ��Ӫ ����
typedef char BiElemType; //�� char ��

//Binary tree �������� BiTNode �������ڵ�
typedef struct BiTNode {
	BiElemType c;//c�����鼮�ϵ�data���������
	struct BiTNode* lchild; //������
	struct BiTNode* rchild; //������
}BiTNode, * BiTree;

//Ҫ�������еĶ��У���ν����ĸ�������
typedef struct tag {
	BiTree p;//����ĳһ�����ĵ�ֵַ
	struct tag* pnext;//��phead��ptail�������
}tag_t, * ptag_t;
