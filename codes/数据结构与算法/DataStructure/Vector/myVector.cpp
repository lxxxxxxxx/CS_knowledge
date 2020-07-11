#include "pch.h"
#include "myVector.h"


/*Ĭ�Ϲ��캯��*/
template<class ElementType>
MyVector<ElementType>::MyVector():capacity(DEFAULT_INIT_SIZE),length(0) {}

/*���캯��*/
template<class ElementType>
MyVector<ElementType>::MyVector(ElementType elems[], int size) {
	capacity = size / 2 * 3;//1.5��
	data = new ElementType[capacity];
	memcpy(data, elems, sizeof(ElementType)*size);
	length = size;
}

/*��������*/
template<class ElementType>
MyVector<ElementType>::~MyVector() {
	Clear();
}

/*��ʼ��*/
template<class ElementType>
Status MyVector<ElementType>::Init() {
	data = new ElementType[DEFAULT_INIT_SIZE];
	if (!data) {
		return My_Failed;
	}
	capacity = DEFAULT_INIT_SIZE;
	length = 0;
	return My_Success;
}

/*���vector*/
template<class ElementType>
Status MyVector<ElementType>::Clear() {
	if (data) {
		delete[]data;
		data = nullptr;
	}
	capacity = 0;
	length = 0;
	return My_Success;
}

/*�п�*/
template<class ElementType>
bool MyVector<ElementType>::Empty() {
	return length == 0;
}

/*��ַ����*/
template<class ElementType>
Status MyVector<ElementType>::At(int pos, ElementType &ret) {
	if (pos >= length) {
		return My_Range_Error;
	}
	ret = data[pos];
	return My_Success;
}

/*��ֵ����*/
template<class ElementType>
Status MyVector<ElementType>::Locate(const ElementType &elem,int &pos) {
	for (int i = 0; i < length; i++) {
		if (data[i] == elem) {
			pos = i;
			return My_Success;
		}
	}
	return My_Failed;
}

/*��elem���뵽posλ��*/
template<class ElementType>
Status MyVector<ElementType>::Insert(const ElementType &elem, int pos) {
	//����
	if (length == capacity-1) {
		capacity += DEFAULT_ADD_STEP;
		ElementType *tmp = new ElementType[capacity];
		if (!tmp) {
			return My_Failed;
		}
		memcpy(tmp, data, sizeof(ElementType)*length);
	}
	if (pos > length) {   
		return My_Range_Error;
	}
	else if (pos == length) {
		data[pos] = elem;
		length++;
		return My_Success;
	}
	else {
		for (int i = length; i != pos; i--) {
			data[i + 1] = data[i];
		}
		data[pos] = elem;
		length++;
		return My_Success;
	}
}

/*ɾ��posλ�õ�Ԫ��*/
template<class ElementType>
Status MyVector<ElementType>::Delete(int pos) {
	//��������
	if (capacity / length >= 3) {
		capacity -= DEFAULT_ADD_STEP;
		ElementType *tmp = new ElementType[capacity];
		if (!tmp) {
			return My_Failed;
		}
		memcpy(tmp, data, sizeof(ElementType)*length);
	}
	if (pos >= length) {
		return My_Range_Error;
	}
	else if (pos == length - 1) {
		length--;
		return  My_Success;
	}
	else {
		for (int i = pos; i < length-1; i++) {
			data[i] = data[i + 1];
			length--;
			return My_Success;
		}
	}
}

/*����posλ�õ�ǰ��������elem*/
template<class ElementType>
Status MyVector<ElementType>::Prior(int pos, ElementType &elem) {
	if (pos >= length || pos == 0) {
		return My_Range_Error;
	}
	else {
		elem = data[pos - 1];
		return My_Success;
	}
}

/*����posλ�õĺ�̣�����elem*/
template<class ElementType>
Status MyVector<ElementType>::next(int pos, ElementType &elem) {
	if (pos < 0 || pos >= length - 1) {
		return My_Range_Error;
	}
	else {
		elem = data[pos + 1];
		return My_Success;
	}
}

