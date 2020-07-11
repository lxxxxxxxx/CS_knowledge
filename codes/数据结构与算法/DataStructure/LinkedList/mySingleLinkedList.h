#pragma once

#include "define.h"

/**
  *  ������ģ���࣬�ṩģ��Ԫ�ص������������
  *  ����ElementType�����п������췽�����ع����==�����
**/

template<class ElementType>
struct Node {
	ElementType data;
	Node *next;
};

//��һ���汾������length�İ汾
template<class ElementType>
class MySingleLinkedList1
{
public:
	/*���캯��*/
	MySingleLinkedList1();

	/*���캯��*/
	MySingleLinkedList1(ElementType elems[], int size);

	/*��������*/
	~MySingleLinkedList1();

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



//�ڶ����汾����length��
//�ڴ�C����ʵ�ֵĵ������У�����ֻ��һ��ͷָ���ʾ����
//û�а취�ӳ���(��ʵҲ�ǿ��Ե�,�ýṹ���װһ������ˣ�
//��֪��Ϊʲô�̿����϶�û������˵������ʵ������ȷʵ�е���㣬����������ֳ���
//����������Խ�ԣ������汾�Ա�һ��

template<class ElementType>
class MySingleLinkedList2
{
public:
	/*���캯��*/
	MySingleLinkedList2();

	/*���캯��*/
	MySingleLinkedList2(ElementType elems[], int size);

	/*��������*/
	~MySingleLinkedList2();

	/*���*/
	Status Clear();

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

