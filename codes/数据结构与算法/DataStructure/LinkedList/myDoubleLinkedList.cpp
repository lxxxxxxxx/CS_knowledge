#include "pch.h"
#include "myDoubleLinkedList.h"

template<class ElementType>
myDoubleLinkedList<ElementType>::myDoubleLinkedList():head(nullptr) {}

/*���캯��*/
template<class ElementType>
myDoubleLinkedList<ElementType>::myDoubleLinkedList(ElementType elems[], int size) {
	for (int i = 0; i < size; i++) {
		Insert(elems[i], i);
	}
}

/*��������*/
template<class ElementType>
myDoubleLinkedList<ElementType>::~myDoubleLinkedList() {
	Clear();
}

/*���*/
template<class ElementType>
Status myDoubleLinkedList<ElementType>::Clear() {
	Node<ElementType> *p = head;
	while (head) {
		p = head->next;
		delete head;
		head = p;
	}
}

/*��ȡ����*/
template<class ElementType>
int myDoubleLinkedList<ElementType>::Size() {
	Node<ElementType> *p = head;
	int i = 0;
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}

/*��λ������pos�Ľڵ�*/
template<class ElementType>
Status myDoubleLinkedList<ElementType>::Locate(Node<ElementType>** ptr, int pos) {
	Node<ElementType> *p = head;
	int i = 0;
	while (p && i < pos) {
		i++;
		p = p->next;
	}
	if (i == pos){
		*ptr = p;
		return My_Success;
	}
	return My_Range_Error;
}

/*��ַ����*/
template<class ElementType>
Status myDoubleLinkedList<ElementType>::At(int pos, ElementType &elem) {
	Node<ElementType> *p = nullptr;
	Status status = Locate(&p, pos);
	if (status == My_Success) {
		elem = p->data;
	}
	return status;
}

/*��ֵ����*/
template<class ElementType>
Status myDoubleLinkedList<ElementType>::Locate(const ElementType &elem, int &pos) {
	Node<ElementType> *p = head;
	int i = 0;
	while (p) {
		if (p->data == elem) {
			pos = i;
			return My_Success;
		}
		i++;
	}
	return My_Range_Error;
}

/*����*/
template<class ElementType>
Status myDoubleLinkedList<ElementType>::Insert(const ElementType &elem, int pos) {
	Node<ElementType> *tmp = new Node<ElementType>;
	tmp->data = elem;

	Node<ElementType> *p = nullptr;
	Status status = Locate(&p, pos - 1);
	if (status == My_Success) {
		tmp->next = p->next;
		tmp->prior = p;
		p->next = tmp;
		if (p->next) {
			p->next->prior = tmp;
		}
	}
	else if (pos == 0) {
		tmp->next = head ? head->next : nullptr;
		tmp->prior = nullptr;
		head = tmp;
		if (head->next) {
			head->next->prior = tmp;
		}
	}
}

/*ɾ��*/
template<class ElementType>
Status myDoubleLinkedList<ElementType>::Delete(int pos) {
	Node<ElementType> *p = nullptr;
	Status status = Locate(p, pos - 1);

	if (status == My_Success) {
		if (p->next) {
			Node<ElementType> *tmp = p->next ? p->next->next : nullptr;
			delete p->next;
			p->next = tmp;
			tmp->prior = p;
		}
		return My_Success;
	}
	else if (pos == 0) {
		if (head) {
			Node<ElementType> *tmp = head->next;
			delete head;
			head = tmp;
			return My_Success;
		}
		return My_Range_Error;
	}
}

/*����ǰ��*/
template<class ElementType>
Status myDoubleLinkedList<ElementType>::Prior(int pos, ElementType &elem) {
	Node<ElementType> *tmp = nullptr;
	Status status = Locate(tmp, pos - 1);
	if (status == My_Success) {
		elem = tmp->data;
	}
	return status;
}

/*���Һ��*/
template<class ElementType>
Status myDoubleLinkedList<ElementType>::Next(int pos, ElementType &elem) {
	Node<ElementType> *tmp = nullptr;
	Status status = Locate(&tmp, pos + 1);
	if (status == My_Success) {
		elem = tmp->data;
	}
	return status;
}