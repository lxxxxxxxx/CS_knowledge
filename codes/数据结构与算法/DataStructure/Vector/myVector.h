#pragma once
#include "define.h"

/**
  *  ��������ģ���࣬�ṩģ��Ԫ�ص������������
  *  ����ElementType�����п������췽�����ع����==�����
**/

#define DEFAULT_INIT_SIZE 20
#define DEFAULT_ADD_STEP 5

template<class ElementType>
class MyVector
{
public:
	/*Ĭ�Ϲ��캯��*/
	MyVector();

	/*���캯��*/
	MyVector(ElementType elems[], int size);

	/*��������*/
	~MyVector();

	/*��ʼ��*/
	Status Init();

	/*���vector*/
	Status Clear(); 

	/*�п�*/
	bool Empty();

	/*��ַ����*/
	Status At(int pos, ElementType &ret);

	/*��ֵ����*/
	Status Locate(const ElementType &elem,int &pos);

	/*��elem���뵽posλ��*/
	Status Insert(const ElementType &elem, int pos);

	/*ɾ��posλ�õ�Ԫ��*/
	Status Delete(int pos);

	/*����posλ�õ�ǰ��������elem*/
	Status Prior(int pos, ElementType &elem);

	/*����posλ�õĺ�̣�����elem*/
	Status next(int pos, ElementType &elem);

private:
	ElementType *data;
	uint32_t length;
	uint32_t capacity;
};

