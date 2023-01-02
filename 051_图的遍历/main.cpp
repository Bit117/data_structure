#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define MAX 100
#define isLetter(a)  ((((a)>='a')&&((a)<='z')) || (((a)>='A')&&((a)<='Z')))
#define LENGTH(a) (sizeof(a)/sizeof(a[0]))

// 邻接表中对应的链表顶点
typedef struct _ENode
{
	int ivex;
	struct _ENode* next_edge;
}ENode, *PENode;

// 邻接表中表的顶点
typedef struct _VNode
{
	char data;
	ENode* first_edge;
}VNode;

//邻接表
typedef	struct _LGraph
{
	int vexnum;
	int edgenum;
	VNode vexs[MAX];
}LGraph;

//返回ch在matrix矩阵中的位置
static int get_position(LGraph g, char ch)
{
	int i;
	for ( i = 0; i < g.vexnum; i++)
	{
		if (g.vexs[i].data==ch)
		{
			return i;
		}
	}
	return -1;
}

//读取一个输入字符
static char read_char()
{
	char ch;
	do
	{
		ch = getchar();
	} while (!isLetter(ch));

	return ch;
}

//将node链接到list的末尾
static void link_last(ENode* list, ENode* node)
{
	ENode* p = list;
	while (p->next_edge)
	{
		p = p->next_edge;
	}
	p->next_edge = node;
}

//创建邻接表对应的图（自己输入）
LGraph* create_lgraph()
{
	char c1, c2;
	int v, e;
	int i, p1, p2;
	ENode* node1, * node2;
	LGraph* pG;

	//输入 顶点数 和 边数
	printf("input vertex number:");
	scanf("%d", &v);
	printf("input edge number:");
	scanf("%d", &e);
	if (v<1||e<1||(e>(v*(v-1))))
	{
		printf("input error:invalid parameters!\n");
		return NULL;
	}
	if ((pG=(LGraph*)malloc(sizeof(LGraph))) ==NULL)
	{
		return NULL;
	}
	memset(pG, 0, sizeof(LGraph));

	// 初始化 顶点数 和 边数
	pG->vexnum = v;
	pG->edgenum = e;

	//初试化 邻接表的顶点
	for ( i = 0; i < pG->vexnum; i++)
	{
		printf("vertex(%d):", i);
		pG->vexs[i].data = read_char();
		pG->vexs[i].first_edge = NULL;
	}

	//初始化 邻接表的边
	for ( i = 0; i < pG->edgenum; i++)
	{
		//读取边的起始顶点和结束顶点
		printf("edge(%d):", i);
		c1 = read_char();
		c2 = read_char();

		p1 = get_position(*pG, c1);
		p2 = get_position(*pG, c2);

		//初始化node1
		node1 = (ENode*)calloc(1, sizeof(ENode));
		node1->ivex = p2;
		//将node1链接到“p1所在链接的末尾”
		if (pG->vexs[p1].first_edge == NULL)
		{
			pG->vexs[p1].first_edge = node1;
		}
		else
		{
			link_last(pG->vexs[p1].first_edge, node1);
		}
		//初始化node2
		node2 = (ENode*)calloc(1, sizeof(ENode));
		node2->ivex = p1;
		//将node2链接到“p2所在链表的末尾”
		if (pG->vexs[p2].first_edge ==NULL)
		{
			pG->vexs[p2].first_edge = node2;
		}
		else
		{
			link_last(pG->vexs[p2].first_edge, node2);
		}

	}
	return pG;
}

//创建邻接表对应的图(用已提供的数据)，无向图
LGraph* create_example_lgraph()
{
	char c1, c2;
	char vexs[] = { 'A','B','C','D','E','F','G' };
	char edges[][2] = {
		{'A', 'C'},
		{'A', 'D'},
		{'A', 'F'},
		{'B', 'C'},
		{'C', 'D'},
		{'E', 'G'},
		{'F', 'G'}
	};
	int vlen = LENGTH(vexs);
	int elen = LENGTH(edges);

	//上面类似于一个邻接矩阵
	int i, p1, p2;
	ENode* node1, * node2;
	LGraph* pG;

	if ((pG=(LGraph*)malloc(sizeof(LGraph))) ==NULL)
	{
		return NULL;
	}
	memset(pG, 0, sizeof(LGraph));

	//初始化 顶点数 和 边数
	pG->vexnum = vlen;
	pG->edgenum = elen;
	//初始化邻接表的顶点
	for ( i = 0; i < pG->vexnum; i++)
	{
		pG->vexs[i].data = vexs[i];
		pG->vexs[i].first_edge = NULL;
	}

	//初始化 邻接表 的边
	for ( i = 0; i < pG->edgenum; i++)
	{
		//读取边的起始顶点和结束顶点
		c1 = edges[i][0];
		c2 = edges[i][1];

		p1 = get_position(*pG, c1);//p1对应起始顶点的下标位置
		p2 = get_position(*pG, c2);//p2对应结束顶点的下标位置

		//初始化 node1
		node1 = (ENode*)calloc(1, sizeof(ENode));
		node1->ivex = p2;
		//将node1链接到“p1所在链表的末尾”
		if (pG->vexs[p1].first_edge ==NULL)
		{
			pG->vexs[p1].first_edge = node1;
		}
		else
		{
			link_last(pG->vexs[p1].first_edge, node1);
		}
		//初始化node2
		node2 = (ENode*)calloc(1, sizeof(ENode));
		node2->ivex = p1;
		//将node2链接到“p2所在链表的末尾”
		if (pG->vexs[p2].first_edge ==NULL)
		{
			pG->vexs[p2].first_edge = node2;
		}
		else
		{
			link_last(pG->vexs[p2].first_edge, node2);
		}
	}
	return pG;
}

//打印链接表图
void print_lgraph(LGraph G)
{
	int i;
	ENode* node;

	printf("List Graph:\n");
	for ( i = 0; i < G.vexnum; i++)
	{
		printf("%d(%c):", i, G.vexs[i].data);
		node = G.vexs[i].first_edge;
		while (node != NULL)//把每个顶点周围的节点都输出一下
		{
			printf("%d(%c):", node->ivex, G.vexs[node->ivex].data);
			node = node->next_edge;
		}
		printf("\n");
	}
}

//深度优先搜索遍历图的递归实现
static void DFS(LGraph G, int i, int* visited)
{
	ENode* node;
	visited[i] = 1;//要访问当前节点了，所以进行打印
	printf("%c ", G.vexs[i].data);
	node = G.vexs[i].first_edge;//拿当前顶点后面的一个顶点
	while (node!= NULL)
	{
		if (!visited[node->ivex])
		{
			DFS(G, node->ivex, visited);//只要对应的顶点没有访问过，深入到下一个顶点进行访问
		}
		node = node->next_edge;//某个顶点的下一条边，例如B节点的下一条边
	}
}

//深度优先搜索遍历图
void DFSTraverse(LGraph G)
{
	int i;
	int visited[MAX]; //顶点访问标记

	//初始化所有顶点都没有被访问
	for ( i = 0; i < G.vexnum; i++)
	{
		visited[i] = 0;
	}

	printf("DFS:");
	//从A开始深度优先遍历
	for ( i = 0; i < G.vexnum; i++)
	{
		if (!visited[i])
		{
			DFS(G, i, visited);
		}
	}
	printf("\n");

}

//广度优先遍历（类似于树的层次遍历）
void BFS(LGraph G)
{
	int head = 0;
	int rear = 0;
	int queue[MAX];//辅助队列
	int visited[MAX];//顶点访问标记
	int i, j, k;
	ENode* node;

	//每个顶点未被访问
	for ( i = 0; i < G.vexnum; i++)
	{
		visited[i] = 0;
	}

	//从零号顶点开始遍历
	printf("BFS:");
	for ( i = 0; i < G.vexnum; i++)//对每个连同分量均调用一个BFS
	{
		if (!visited[i])
		{
			visited[i] = 1;//标记已经访问过
			printf("%c ", G.vexs[i].data);
			queue[rear++] = i;//入队列
		}
		while (head != rear)
		{
			j = queue[head++];//出队列
			node = G.vexs[j].first_edge;
			while (node!=NULL)
			{
				k = node->ivex;
				if (!visited[k])
				{
					visited[k] = 1;
					printf("%c ", G.vexs[k].data);
					queue[rear++] = k;//类似树的层次遍历，遍历到的同时入队
				}
				node = node->next_edge;
			}
		}
	}

	printf("\n");
}

LGraph* create_example_lgraph_directed()
{
	char c1, c2;
	char vexs[] = { 'A','B','C','D','E','F','G' };
	char edges[][2] = {
		{'A', 'B'},
		{'B', 'C'},
		{'B', 'E'},
		{'B', 'F'},
		{'C', 'E'},
		{'D', 'C'},
		{'E', 'B'},
		{'E', 'D'},
		{'F', 'G'}
	};

	int vlen = LENGTH(vexs);
	int elen = LENGTH(edges);
	int i, p1, p2;
	ENode* node1;
	LGraph* pG;

	if ((pG=(LGraph*)malloc(sizeof(LGraph))) ==NULL)
	{
		return NULL;
	}
	memset(pG, 0, sizeof(LGraph));

	//初始化顶点数和边数
	pG->vexnum = vlen;
	pG->edgenum = elen;

	//初始化邻接表的顶点
	for ( i = 0; i < pG->vexnum; i++)
	{
		pG->vexs[i].data = vexs[i];
		pG->vexs[i].first_edge = NULL;
	}

	//初始化邻接表的边
	for ( i = 0; i < pG->edgenum; i++)
	{
		c1 = edges[i][0];
		c2 = edges[i][1];

		p1 = get_position(*pG, c1);
		p2 = get_position(*pG, c2);

		//初始化node1
		node1 = (ENode*)calloc(1, sizeof(ENode));
		node1->ivex = p2;

		//将node1链接到 p1所在链表的末尾
		if (pG->vexs[p1].first_edge==NULL)
		{
			pG->vexs[p1].first_edge = node1;
		}
		else
		{
			link_last(pG->vexs[p1].first_edge, node1);
		}

	}
	return pG;
}

int main()
{
	LGraph* pG;
	// 无向图自定义"图"(自己输入数据，输入的方法可以参考create_example_lgraph初始化好的数据)
	//pG = create_lgraph();
	
	// 无向图的创建，采用已有的"图"
	//pG = create_example_lgraph();

	//有向图的创建
	pG = create_example_lgraph_directed();

	//打印图
	print_lgraph(*pG);
	DFSTraverse(*pG);
	BFS(*pG);


	return 0;
}
