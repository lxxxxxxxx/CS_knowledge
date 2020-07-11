#pragma once
#include <vector>

/*���������*/

typedef _Node Node;

typedef struct _Node {
	int data;
	Node *parent;
	Node *lChild;
	Node *rChild;
}Node;

class myBinTree
{
public:
	myBinTree(std::vector<int> src);
	~myBinTree();

	/*���ɶ��������*/
	void Init();

	/*����ڵ�*/
	void Insert(int data);

	/*���ҽڵ�*/
	Node* Search(int key);

	/*ɾ���ڵ�*/
	void Delete(int key);

private:
	std::vector<int> m_srcData;
	Node *m_root;
};

