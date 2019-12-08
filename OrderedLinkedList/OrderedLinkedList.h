#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H

#include "LinkedList.h"

template<typename T>
class OrderedLinkedList : public LinkedList<T>{
	public:
		node<T> *search(const T&);
		void insert(const T&);
		void deleteNode(const T&);
};

template<typename T>
node<T>* OrderedLinkedList<T>::search(const T &item){
	
	node<T> *p=OrderedLinkedList<T>::head;
	
	while(p!=NULL){
		if(item==p->info){
			return p;
		}
		else if(item>p->info){
			p=p->link;
		}
		else{
			return NULL;
		}
	}
}

template<typename T>
void OrderedLinkedList<T>::insert(const T &item){
		
	node<T> *p,*q=NULL,*n;	
	
	n=new node<T>;
	n->info=item;
	n->link=NULL;
		
	if(OrderedLinkedList<T>::emptyList()){
		OrderedLinkedList<T>::head=OrderedLinkedList<T>::last=n;
		cout<<"First node"<<endl;
	}
	else{
		for(p=OrderedLinkedList<T>::head; (p!=NULL && item>p->info) ;q=p,p=p->link);
		
//		cout<<p->info<<", "<<q->info<<endl;
		
		if(p==OrderedLinkedList<T>::head){
			n->link=OrderedLinkedList<T>::head;
			OrderedLinkedList<T>::head=n;
			cout<<"Front"<<endl;
		}
		else if(p==NULL && q==OrderedLinkedList<T>::last){
			OrderedLinkedList<T>::last->link=n;
			OrderedLinkedList<T>::last=n;
			cout<<"Last"<<endl;
		} 
		else{
			n->link=p;
			q->link=n;
			cout<<"Middle"<<endl;
		}
		
	}
	
//	node<T> *p,*q=NULL,*n;
//	
//	for(p=OrderedLinkedList<T>::head; (p!=NULL && item>p->info) ;q=p,p=p->link);
//	
//	n=new node<T>;
//	n->info=item;
//	
//	if(p!=NULL){
//		if(p!=OrderedLinkedList<T>::head){
//			cout<<"Test1";
//			n->link=q->link;
//			q->link=n;
//		}
//		else{
//			cout<<"Test2";
//			n->link=OrderedLinkedList<T>::head;
//			OrderedLinkedList<T>::head=n;
//		}
//	}
//	else{
////		if(OrderedLinkedList<T>::last==NULL){
////			cout<<"Test3";
////			OrderedLinkedList<T>::head=n;
////			n->link=NULL;
////			OrderedLinkedList<T>::last=n;
////		}
////		else{
////			cout<<"Test4";
////			if(q==OrderedLinkedList<T>::last){
////				cout<<"Test5";
////				OrderedLinkedList<T>::last->link=n;
////				n->link=NULL;
////				OrderedLinkedList<T>::last=n;
////			}	
////			else{
////				cout<<"Test6";
////			}
////				
////			
////		}
//		OrderedLinkedList<T>::head=OrderedLinkedList<T>::last=n;
//		n->link=NULL;
//
//		
//		
//	}
	OrderedLinkedList<T>::count++;
	return;
}

template<typename T>
void OrderedLinkedList<T>::deleteNode(const T &item){
	if(OrderedLinkedList<T>::last->info < item){
		return;
	}
	else{
		LinkedList<T>::deleteNode(item);
	}
	return;
}

#endif
