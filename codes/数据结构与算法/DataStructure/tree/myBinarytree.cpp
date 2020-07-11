#include "pch.h"
#include "myBinarytree.h"
#include <iostream>
#include <queue>
#include <stack>


myBinarytree::myBinarytree(std::vector<int> src):m_srcData(src)
{
	linkStorage();
}


myBinarytree::~myBinarytree()
{
}

//���ʺ���
void myBinarytree::print(int data) {
	std::cout << data << " ";
}

//�������
void  myBinarytree::PreOrder(int index) {
	if (index >= m_srcData.size()) {
		return;
	}

	print(m_srcData[index]);

	int lChild = 2 * index + 1;
	int rChild = 2 * index + 2;

	if (lChild < m_srcData.size()) {
		PreOrder(lChild);
	}
	if (rChild < m_srcData.size()) {
		PreOrder(rChild);
	}
}

//�������
void myBinarytree::InOrder(int index) {
	if (index >= m_srcData.size()) {
		return;
	}

	int lChild = 2 * index + 1;
	int rChild = 2 * index + 2;

	if (lChild < m_srcData.size()) {
		PreOrder(lChild);
	}
	print(m_srcData[index]);
	if (rChild < m_srcData.size()) {
		PreOrder(rChild);
	}
}

//��������
void myBinarytree::PostOrder(int index) {
	if (index >= m_srcData.size()) {
		return;
	}

	int lChild = 2 * index + 1;
	int rChild = 2 * index + 2;

	if (lChild < m_srcData.size()) {
		PreOrder(lChild);
	}

	if (rChild < m_srcData.size()) {
		PreOrder(rChild);
	}

	print(m_srcData[index]);
}

//��α���
void myBinarytree::LevelOrder1() {
	if (m_srcData.empty())
	{
		return;
	}

	std::queue<int> tmp;
	tmp.push(0);

	while (!tmp.empty()) {
		int index = tmp.front();
		tmp.pop();
		print(m_srcData[index]);

		int lIndex = 2 * index + 1;
		int rIndex = 2 * index + 2;
		if (lIndex < m_srcData.size()) {
			tmp.push(lIndex);
		}
		if (rIndex < m_srcData.size()) {
			tmp.push(rIndex);
		}
	}
}

//�ǵݹ����������ջ��
void myBinarytree::NRPreOrder(){
}

////�ǵݹ����������ջ��
//void myBinarytree::NRPreOrder() {
//	if (m_srcData.empty()) {
//		return;
//	}
//
//	std::stack<int> tmp;
//	tmp.push(0);
//	while (!tmp.empty()) {
//		int top = tmp.top();
//
//		int lIndex = 2 * top + 1;
//		int rIndex = 2 * top + 2;
//
//		if (lIndex < m_srcData.size()) {
//			
//		}
//
//
//	}
//
//
//
//}

//�ǵݹ���������ջ��
void myBinarytree::NRPreOrder() {

}



/*/**********************************************************/

//˳��洢ת��ʽ�洢
Node* myBinarytree::link(Node* parent, int index) {
	if (index >= m_srcData.size()) {
		return nullptr;
	}

	int lIndex = 2 * index + 1;
	int rIndex= 2 * index + 2;

	Node *node = new Node;
	node->data = m_srcData[index];
	node->parent = parent;

	if (lIndex < m_srcData.size()) {
		Node *lChild = link(node, lIndex);
		node->lChild = lChild;
	}
	if (rIndex < m_srcData.size()) {
		Node *rChild = link(node, rIndex);
		node->rChild = rChild;
	}
	return node;
}
Node* myBinarytree::linkStorage() {
	m_root=link(nullptr, 0);
	return m_root;
}

//�������
void  myBinarytree::PreOrder(Node *root) {
	if (!root) {
		return;
	}
	print(root->data);
	if (root->lChild) {
		PreOrder(root->lChild);
	}
	if (root->rChild) {
		PreOrder(root->rChild);
	}
}

//�������
void myBinarytree::InOrder(Node *root) {
	if (!root) {
		return;
	}

	if (root->lChild) {
		PreOrder(root->lChild);
	}
	print(root->data);
	if (root->rChild) {
		PreOrder(root->rChild);
	}
}

//��������
void myBinarytree::PostOrder(Node *root) {
	if (!root) {
		return;
	}

	if (root->lChild) {
		PreOrder(root->lChild);
	}
	print(root->data);
	if (root->rChild) {
		PreOrder(root->rChild);
	}
}

//��α���
void myBinarytree::LevelOrder1() {
	if (!m_root) {
		return;
	}

	std::queue<Node*> tmp;
	tmp.push(m_root);

	while (!tmp.empty()) {
		Node *node = tmp.front();
		tmp.pop();
		print(node->data);

		if (node->lChild) {
			tmp.push(node->lChild);
		}
		if (node->rChild) {
			tmp.push(node->rChild);
		}
	}

}
	//�ǵݹ����������ջ��
void myBinarytree::NRPreOrder() {
	if (!m_root) {
		return;
	}
	
	std::stack<Node*> stack;
	Node* p = m_root;
	while (p || !stack.empty()) {
		//ѭ���������е������������
		while (p) {
			print(p->data);
			stack.push(p);
			p = p->lChild;
		}
		//��߱�����ɣ�ȡ���һ�����ӣ������Һ���Ϊ���ظ���������
		if (!stack.empty()) {
			p = stack.top();
			stack.pop();
			p = p->rChild;  //���pΪ�գ���������������������ֱ��ȡջtop
		}
	}

}

	//�ǵݹ����������ջ��
void myBinarytree::NRPreOrder(Node *root) {
	if (!m_root) {
		return;
	}
	std::stack<Node*> stack;
	Node *p = m_root;

	while (p || !stack.empty()) {
		while (p) {
			stack.push(p);
			p = p->lChild;
		}

		if (!stack.empty()) {
			p = stack.top();
			print(p->data);
			p = p->rChild;
		}
	}


}

	//�ǵݹ���������ջ��
void myBinarytree::NRPreOrder(Node *root) {
	if (!m_root) {
		return;
	}
	std::stack<Node*> stack;
	Node *p = m_root;

	while (p || !stack.empty()) {
		while (p) {
			stack.push(p);
			p = p->lChild;

		}

		if (!stack.empty()) {
			p = stack.top();
			print(p->data);
			p = p->rChild;
		}
	}
}

