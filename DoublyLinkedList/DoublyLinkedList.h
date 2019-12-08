#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include<iostream>
#include<cassert>

using namespace std;

template<typename T>
struct DNode{
	DNode *left,*right;
	T info;
};

template <typename T>
class DoublyLinkedList{
	protected:
		DNode<T> *first,*last;
		int count;
	public:
		DoublyLinkedList();
		~DoublyLinkedList();
		bool emptyList();
		int length();
		T back();
		T front();
		void destroyList();
		DNode<T>* search(const T&);
		void insertFirst(const T&);
		void insertLast(const T&);
		void deleteNode(const T&);
		void reverse();
		
		template<typename S>
		friend ostream& operator<<(ostream&, DoublyLinkedList<S>&);
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(){
	first=last=NULL;
	count=0;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
	destroyList();
}

template<typename T>
bool DoublyLinkedList<T>::emptyList(){
	return first==NULL;
}

template<typename T>
int DoublyLinkedList<T>::length(){
	return count;
}

template<typename T>
T DoublyLinkedList<T>::back(){
	return last->info;
}

template<typename T>
T DoublyLinkedList<T>::front(){
	return first->info;
}

template<typename T>
void DoublyLinkedList<T>::destroyList(){
	
	for(DNode<T> *p;!emptyList();p=first,first=first.right,delete p);
	count=0;
	first=last=NULL;
	
}

template<typename T>
DNode<T>* DoublyLinkedList<T>::search(const T&){
	
	
	
}

#endif

