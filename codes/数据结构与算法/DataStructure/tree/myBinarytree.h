#pragma once

#include <vector>

typedef _Node Node;

typedef struct _Node {
	int data;
	Node *parent;
	Node *lChild;
	Node *rChild;
}Node;


class myBinarytree
{
public:
	myBinarytree(std::vector<int> src);
	~myBinarytree();

	//���ʺ���
	void print(int data);

	/*˳��洢*/
	//�������
	void  PreOrder(int index);

	//�������
	void InOrder(int index);

	//��������
	void PostOrder(int index);

	//��α��������У�
	void LevelOrder1();

	//�ǵݹ����������ջ��
	void NRPreOrder();

	//�ǵݹ����������ջ��
	void NRPreOrder();

	//�ǵݹ���������ջ��
	void NRPreOrder();

	/***************************************************/

	/*��ʽ�洢*/
	//˳��洢ת��ʽ�洢
	Node *link(Node* parent, int index);
	Node* linkStorage();

	//�������
	void  PreOrder(Node *root);

	//�������
	void InOrder(Node *root);

	//��������
	void PostOrder(Node *root);

	//��α���
	void LevelOrder1();

	//�ǵݹ����������ջ��
	void NRPreOrder();

	//�ǵݹ����������ջ��
	void NRPreOrder();

	//�ǵݹ���������ջ��
	void NRPreOrder(Node *root);

	/***************************************/
	//����
	void Sort();


private:
	std::vector<int> m_srcData;  //Դ����
	Node* m_root;
};

