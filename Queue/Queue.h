#ifndef QUEUE_H
#define QUEUE_H

#include <cassert>

template<typename T>
struct node{
	T info;
	node<T> *link;
};

template<typename T>
class Queue{
	private:
		node<T> *front,*rear;
	public:
		Queue();
		~Queue();
		bool isEmpty();
		T Qfront();
		T Qrear();
		T deleteQ();
		void insert(T&);
		void destroyQ();
};

template<typename T>
Queue<T>::Queue(){
	front=rear=NULL;
}

template<typename T>
Queue<T>::~Queue(){
	destroyQ();
}

template<typename T>
bool Queue<T>::isEmpty(){
	return front==NULL;
}

template<typename T>
T Queue<T>::Qfront(){
	assert(!isEmpty());
	return front->info;
}

template<typename T>
T Queue<T>::Qrear(){
	assert(!isEmpty());
	return rear->info;
}

template<typename T>
T Queue<T>::deleteQ(){
	assert(!isEmpty());
	T x=front->info;
	node<T> *p=front;
	front=front->link;
	delete p;
	return x;
}

template<typename T>
void Queue<T>::insert(T &item){
	node<T> *p=new node<T>;
	p->info=item;
	p->link=NULL;
	if(!isEmpty()){
		rear->link=p;
		rear=p;
	}
	else{
		front=rear=p;
	}
}

template<typename T>
void Queue<T>::destroyQ(){
	node<T> *p;
	while(front!=NULL){
		p=front;
		front=front->link;
		delete p;
	}
	rear=NULL;
}
#endif

