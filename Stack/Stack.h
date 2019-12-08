#ifndef STACK_H
#define STACK_H

#include<iostream>
#include<cassert>
using namespace std;

template<typename T>
class Stack{
	protected:
		T *arr;
		int top,size;
		
	public:
		Stack(int=100);
		bool isEmpty();
		bool isFull();
		void destroy();
		T pop();
		T sTop();
		void push(T&);
		~Stack();
		
};

template<typename T>
Stack<T>::Stack(int stackSize){
	size=stackSize;
	arr=new T[size];
	top=0;
}

template<typename T>
Stack<T>::~Stack(){
	delete []arr;
}

template<typename T>
bool Stack<T>::isEmpty(){
	return top==0;
}

template<typename T>
bool Stack<T>::isFull(){
	return top==size;
}

template<typename T>
void Stack<T>::destroy(){
	top=0;
}

template<typename T>
void Stack<T>::push(T &item){
	if(!isFull()){
		arr[top++]=item;
	}
	else{
		cerr<<"No more space!"<<endl;
	}
}

template<typename T>
T Stack<T>::pop(){
	assert(!isEmpty());
	return arr[--top];
}

template<typename T>
T Stack<T>::sTop(){
	assert(!isEmpty());
	return arr[top-1];
}

#endif

