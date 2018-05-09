#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <queue>
#include <stdio.h> 
using namespace std;

struct BinaryTreeNode
{
    int                    m_nValue;
    BinaryTreeNode*        m_pLeft;
    BinaryTreeNode*        m_pRight;
    BinaryTreeNode(){
    	m_pLeft = NULL;
    	m_pRight = NULL;
	}
};

char str[1002];
BinaryTreeNode* pNode1 = NULL;
BinaryTreeNode* pNode2 = NULL;

std::queue<BinaryTreeNode*> queueTreeNode;

//��������
bool ReadStream(int& index, int& number)
{
    if(str[index]=='\0')
        return false;

    char buffer[32];
    buffer[0] = '\0';

    char ch = str[index];
    int i = 0;
    while(str[index++]!='\0' && ch != ' ')
    {
        buffer[i++] = ch;
        ch = str[index];
    }

    bool isNumeric = false;
    if(i > 0 && buffer[0] != '#')
    {
        number = atoi(buffer);
        isNumeric = true;
    }

    //printf("number %d %d\n",index,number);

    return isNumeric;
}


//��������
bool ReadStream2(int& index, int& number)
{
    if(str[index]=='\0'||str[index]=='#')
        return false;

    char buffer[32];
    buffer[0] = '\0';

    char ch = str[index];
    int i = 0;
    while(str[index++]!='\0' && ch != ' ')
    {
        buffer[i++] = ch;
        ch = str[index];
    }

    bool isNumeric = false;
    if(i > 0)
    {
        number = atoi(buffer);
        isNumeric = true;
    }

    //printf("number %d %d\n",index,number);

    return isNumeric;
}
//ǰ����
void DFS_Deserialize(BinaryTreeNode*& pRoot,int& index)
{
    int number;
    if(ReadStream(index, number))
    {
        pRoot = new BinaryTreeNode();
        pRoot->m_nValue = number;
        pRoot->m_pLeft = NULL;
        pRoot->m_pRight = NULL;

        if(number == 4)
        {
            pNode1 = pRoot;
            printf("pNode1 is set %d\n", pNode1->m_nValue);
        }
        else if(number == 12)
        {
            pNode2 = pRoot;
            printf("pNode2 is set %d\n", pNode2->m_nValue);
        }

        DFS_Deserialize(pRoot->m_pLeft, index);
        DFS_Deserialize(pRoot->m_pRight, index);
    }  
}
//������
//            10
//        5      12
//      4  7
//10 5 12 4 7 # # # # # #
void BFS_Deserialize(BinaryTreeNode* pRoot)
{
    int index = 0;
    int number;

    while(!queueTreeNode.empty()){
        queueTreeNode.pop();
    }
    queueTreeNode.push(pRoot);
    int id = 0;
    while(ReadStream2(index, number) && !queueTreeNode.empty())
    {
        BinaryTreeNode* currentNode = queueTreeNode.front();

        //printf("%d %d %d",queueTreeNode.size(),id++,number);
        currentNode->m_nValue = number;
        BinaryTreeNode* leftNode = new BinaryTreeNode();
        BinaryTreeNode* rightNode = new BinaryTreeNode();
        currentNode->m_pLeft = leftNode;
        currentNode->m_pRight = rightNode;
        queueTreeNode.pop();
        queueTreeNode.push(currentNode->m_pLeft);
        queueTreeNode.push(currentNode->m_pRight);
    }
    //printf("%d %d\n",queueTreeNode.size(),pRoot->m_nValue);
    while(!queueTreeNode.empty())
    {
        BinaryTreeNode* currentNode = queueTreeNode.front();
        currentNode->m_nValue = -1;
        queueTreeNode.pop();
    }
}

//�������к�Ϊĳһֵ��·��
void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int currentSum)
{
    currentSum += pRoot->m_nValue;
    path.push_back(pRoot->m_nValue);

    //�����Ҷ���,����·���Ͻ��ĺ͵��������ֵ,��ӡ������·��
    bool isLeaf = pRoot->m_pLeft == NULL && pRoot->m_pRight == NULL;
    if(currentSum == expectedSum && isLeaf)
    {
        printf("A path is found: ");
        std::vector<int>::iterator iter = path.begin();
        for(; iter != path.end(); iter++)
            printf("%d ", *iter);

        printf("\n");
    }

    //�������Ҷ���,����������ӽ��
    if(pRoot->m_pLeft != NULL)
        FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
    if(pRoot->m_pRight != NULL)
        FindPath(pRoot->m_pRight, expectedSum, path, currentSum);

    //�ڷ��ظ����֮ǰ,��·����ɾ����ǰ���
    currentSum -= pRoot->m_nValue;
    path.pop_back();
}
void FindPath(BinaryTreeNode* pRoot, int expectedSum)
{
    if(pRoot == NULL)
        return;

    std::vector<int> path;
    int currentSum = 0;
    FindPath(pRoot, expectedSum, path, currentSum);
}

//�ж�ƽ�������
bool IsBalanced(BinaryTreeNode* pRoot, int* pDepth)
{
    if(pRoot == NULL)
    {
        *pDepth = 0;
        return true;
    }

    int left, right;
    if(IsBalanced(pRoot->m_pLeft, &left) && IsBalanced(pRoot->m_pRight, &right))
    {
        int diff = left - right;
        if(diff <= 1 && diff >= -1)
        {
            *pDepth = 1 +(left > right ? left : right);
            return true;
        }
    }

    return false;
}
bool IsBalanced_Solution(BinaryTreeNode* pRoot)
{
    int depth = 0;
    return IsBalanced(pRoot, &depth);
}

//��͹�������
bool GetNodePath(BinaryTreeNode* pRoot, BinaryTreeNode* pNode, list<BinaryTreeNode*>& path)
{
	path.push_back(pRoot);
    if(pRoot == pNode)
    {
        return true;
    }

    bool found = false;

    if(pRoot->m_pLeft)
        found = GetNodePath(pRoot->m_pLeft, pNode, path);
    if(!found && pRoot->m_pRight)
        found = GetNodePath(pRoot->m_pRight, pNode, path);

    if(!found)
        path.pop_back();

    return found;
}
BinaryTreeNode* GetLastCommonNode(const list<BinaryTreeNode*>& path1, const list<BinaryTreeNode*>& path2)
{
    list<BinaryTreeNode*>::const_iterator iter1 = path1.begin();
    list<BinaryTreeNode*>::const_iterator iter2 = path2.begin();

    BinaryTreeNode* pLast = NULL;

    while(iter1 != path1.end() && iter2 != path2.end())
    {
        if(*iter1 == *iter2)
            pLast = *iter1;
        else
            break;

        iter1++;
        iter2++;
    }

    return pLast;
}
BinaryTreeNode* GetLastCommonParent(BinaryTreeNode* pRoot, BinaryTreeNode* pNode1, BinaryTreeNode* pNode2)
{
    if(pRoot == NULL || pNode1 == NULL || pNode2 == NULL)
    {
        printf("BinaryTreeNode is NULL.");
        return NULL;
    }

    list<BinaryTreeNode*> path1;
    GetNodePath(pRoot, pNode1, path1);

    list<BinaryTreeNode*> path2;
    GetNodePath(pRoot, pNode2, path2);

    return GetLastCommonNode(path1, path2);
}



void PrintfTree(BinaryTreeNode* pRoot)
{
    if(pRoot == NULL || pRoot->m_nValue == -1){
        printf("# ");
        return;
    }

    printf("%d ",pRoot->m_nValue);
	if(pRoot->m_pLeft)
    	PrintfTree(pRoot->m_pLeft);
	if(pRoot->m_pRight)
    	PrintfTree(pRoot->m_pRight);
}
void DestroyTree(BinaryTreeNode* pRoot)
{
    if(pRoot != NULL )
    {
        BinaryTreeNode* pLeft = pRoot->m_pLeft;
        BinaryTreeNode* pRight = pRoot->m_pRight;

        delete pRoot;
        pRoot = NULL;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}

//            10
//        5      12
//      4  7
int main() {
    //ǰ�������뽨��
    strcpy(str,"10 5 4 # # 7 # # 12 # # ");
    BinaryTreeNode* pRoot = NULL;
    int index = 0;
    DFS_Deserialize(pRoot,index);
    PrintfTree(pRoot);
    printf("\n\n");
    //���������뽨��
    strcpy(str,"10 5 12 4 7 # # # # # # ");
    BinaryTreeNode* pRoot2 = new BinaryTreeNode();;
    BFS_Deserialize(pRoot2);
    PrintfTree(pRoot2);
    printf("\n\n");

    //�������к�Ϊĳһֵ��·��
    int expectedSum = 22;
    FindPath(pRoot, expectedSum);
    printf("\n");

    //�ж�ƽ�������
    if(IsBalanced_Solution(pRoot) == true)
        printf("IsBalanced.\n");
    else
        printf("Not IsBalanced.\n");
    printf("\n");

    //��͹�������
    BinaryTreeNode* lastCommonParent = GetLastCommonParent(pRoot, pNode1, pNode2);
    if(lastCommonParent)
        printf("Last Common Parent is %d.\n", lastCommonParent->m_nValue);

    //�ͷſռ�
    DestroyTree(pRoot);
    DestroyTree(pRoot2);

    return 0;
}

