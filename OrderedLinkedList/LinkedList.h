#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template<typename T>
struct node{
	T info;
	node<T> *link;
};

template<typename T>
class LinkedList
{
	protected:
		node<T> *head,*last;
		int count;
	
	public:
		LinkedList();
		~LinkedList();
		bool emptyList();
		int length();
		T back();
		T front();
		void destroyList();
		node<T>* search(const T&);
		void insertFirst(const T&);
		void insertLast(const T&);
		void deleteNode(const T&);
		
		template<typename S>
		friend ostream& operator<<(ostream&, LinkedList<S>&);
		
};

template<typename T>
LinkedList<T>::LinkedList(){
	head=last=NULL;
	count=0;
}

template<typename T>
LinkedList<T>::~LinkedList(){
	LinkedList<T>::destroyList();
}

template<typename T>
bool LinkedList<T>::emptyList(){
	return head==NULL;
}

template<typename T>
int LinkedList<T>::length(){
	return count;
}

template<typename T>
T LinkedList<T>::back(){
	if(last!=NULL)
		return last->info;
}

template<typename T>
T LinkedList<T>::front(){
	if(head!=NULL)
		return head->info;
}

template<typename T>
void LinkedList<T>::destroyList(){
	node<T> *p;
	while(head!=NULL){
		p=head;
		head=head->link;
		delete p;
	}		
	last=NULL;
	count=0;
}

template<typename T>
node<T>* LinkedList<T>::search(const T &item){
	bool found=false;
	node<T> *p=head;
	
	while(p!=NULL && !found){
		if(p->info==item){
			found=true;
		}
		else{
			p=p->link;
		}
	}
	return p;
}

template<typename T>
void LinkedList<T>::insertFirst(const T &item){
	node<T> *p=new node<T>;
	p->info=item;
	p->link=head;
	head=p;
	if(last==NULL){
		last=head;
	}
	count++;
}

template<typename T>
void LinkedList<T>::insertLast(const T &item){
	node<T> *p=new node<T>;
	p->info=item;
	p->link=NULL;
	if(last!=NULL){
		last->link=p;
		last=p;
	}
	else{
		head=last=p;
	}
	count++;
}

template<typename T>
void LinkedList<T>::deleteNode(const T &item){
	node<T> *p, *q;
	bool found=false;
	if(head==NULL){
		cerr<<"List is empty"<<endl;
	}
	else{
		if(head->info==item){
			p=head;
			head=head->link;
			delete p;
			count--;
			if(head==NULL){
				last=NULL;
			}
		}
		else{
			p=head;
			q=p->head;
			while(q!=NULL && !found){
				if(q->info==item){
					found=true;
				}
				else{
					p=q;
					q=q->link;
				}
			}
			if(found){
				p->link=q->link;
				count--;
				if(last==q){
					last=p;
				}
				delete q;
			}
		}
	}
}

template<typename T>
ostream& operator<<(ostream &os, LinkedList<T> &list){
	node<T> *p=list.head;
	while(p!=NULL){
		os<<p->info;
		p=p->link;
	}
	return os;
}



#endif
