#pragma once

/**
  *  ˫������ģ���࣬�ṩģ��Ԫ�ص������������
  *  ����ElementType�����п������췽�����ع����==�����
**/

template<class ElementType>
struct Node {
	ElementType data;
	Node *prior;
	Node *next;
};

template<class ElementType>
class myDoubleLinkedList
{
public:
	myDoubleLinkedList();

	/*���캯��*/
	myDoubleLinkedList(ElementType elems[], int size);

	/*��������*/
	~myDoubleLinkedList();

	/*���*/
	Status Clear();

	/*��ȡ����*/
	int Size();

	/*��λ������pos�Ľڵ�*/
	Status Locate(Node<ElementType>** ptr, int pos);

	/*��ַ����*/
	Status At(int pos, ElementType &elem);

	/*��ֵ����*/
	Status Locate(const ElementType &elem, int &pos);

	/*����*/
	Status Insert(const ElementType &elem, int pos);

	/*ɾ��*/
	Status Delete(int pos);

	/*����ǰ��*/
	Status Prior(int pos, ElementType &elem);

	/*���Һ��*/
	Status Next(int pos, ElementType &elem);

private:
	Node *head;
};

