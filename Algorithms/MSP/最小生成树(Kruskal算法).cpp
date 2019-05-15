#include<stdio.h>
#include<stdlib.h>
#define M 20
#define MAX 20
typedef struct
{
    int begin;
    int end;
    int weight;
} edge;
typedef struct
{
    int adj;
    int weight;
} AdjMatrix[MAX][MAX];
typedef struct
{
    AdjMatrix arc;
    int vexnum, arcnum;
} MGraph;
//��������
void CreatGraph(MGraph *);
void sort(edge* ,MGraph *);
void MiniSpanTree(MGraph *);
int Find(int *, int );
void Swapn(edge *, int, int);

void CreatGraph(MGraph *G)//����ͼ
{
    int i, j,n, m;
    char n1,m1;
    printf("���������������:");
    scanf("%d %d",&G->vexnum,&G->arcnum);
    for (i = 1; i <= G->vexnum; i++)//��ʼ��ͼ
    {
        for ( j = 1; j <= G->vexnum; j++)
        {
            G->arc[i][j].adj = G->arc[j][i].adj = 0;
        }
    }
    printf("��������·��ͨ��2���㼰����֮���Ȩֵ:\n");
    for ( i = 1; i <= G->arcnum; i++)
    {
        getchar();
        scanf("%c %c",&n1,&m1);
        n=n1-'a'+1;
        m=m1-'a'+1;
        G->arc[n][m].adj = G->arc[m][n].adj = 1;
        scanf(" %d",&G->arc[n][m].weight);
    }
    printf("�ڽӾ���Ϊ:\n");
    for ( i = 1; i <= G->vexnum; i++)
    {
        for ( j = 1; j <= G->vexnum; j++)
        {
            if(G->arc[i][j].adj==1)
                printf("%d ",G->arc[i][j].weight);
            else
                printf("%d ",G->arc[i][j].adj);
            G->arc[j][i].weight=G->arc[i][j].weight;
        }
        printf("\n");
    }
}

void sort(edge edges[],MGraph *G)//��Ȩֵ��������
{
    int i, j;
    for ( i = 1; i < G->arcnum; i++)
    {
        for ( j = i + 1; j <= G->arcnum; j++)
        {
            if (edges[i].weight > edges[j].weight)
            {
                Swapn(edges, i, j);
            }
        }
    }
}

void Swapn(edge *edges,int i, int j)
{
    int temp;
    temp = edges[i].begin;
    edges[i].begin = edges[j].begin;
    edges[j].begin = temp;
    temp = edges[i].end;
    edges[i].end = edges[j].end;
    edges[j].end = temp;
    temp = edges[i].weight;
    edges[i].weight = edges[j].weight;
    edges[j].weight = temp;
}

void MiniSpanTree(MGraph *G)//������С������
{
    int i, j, n, m,Mincost=0;
    int k = 1;
    int parent[M];
    edge edges[M];
    for ( i = 1; i < G->vexnum; i++)
    {
        for (j = i + 1; j <= G->vexnum; j++)
        {
            if (G->arc[i][j].adj == 1)
            {
                edges[k].begin = i;
                edges[k].end = j;
                edges[k].weight = G->arc[i][j].weight;
                k++;
            }
        }
    }
    sort(edges, G);
    for (i = 1; i <= G->arcnum; i++)
    {
        parent[i] = 0;
    }
    printf("��С������Ϊ:\n");
    for (i = 1; i <= G->arcnum; i++)//���Ĳ���
    {
        n = Find(parent, edges[i].begin);
        m = Find(parent, edges[i].end);
        if (n != m)
        {
            parent[n] = m;
            printf("< %c, %c > %d\n", edges[i].begin+'a'-1, edges[i].end+'a'-1, edges[i].weight);
            Mincost+=edges[i].weight;
        }
    }
    printf("��С������Ȩֵ��Ϊ��Mincost=%d\n",Mincost);
}

int Find(int *parent, int f)
{
    while ( parent[f] > 0)
    {
        f = parent[f];
    }
    return f;
}

int main()//������
{
    MGraph *G;
    G = (MGraph*)malloc(sizeof(MGraph));
    CreatGraph(G);
    MiniSpanTree(G);
}
