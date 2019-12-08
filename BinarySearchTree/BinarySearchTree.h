#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include<iostream>
#include"BinaryTree.h"

using namespace std;

template<typename T>
class BinarySearchTree:public BinaryTree<T>{
	private:
		void deleteFromTree(BTNode<T> *&p);
	public:
		BTNode<T>* search(T&);
		void insert(T&);
		void deleteBTNode(T&);
	
};

//---------------------------Public Declerations---------------------------//

template<typename T>
BTNode<T>* BinarySearchTree<T>::search(T &item){
	BTNode<T> *p;
	bool found=false;
	if(BinarySearchTree<T>::root==NULL){
		cerr<<"Empty Tree";
	}
	else{
		p=BinarySearchTree<T>::root;
		while(!found && p!=NULL){
			if(p->info==item){
				found=true;
			}
			else if(p->info>item){
				p=p->llink;
			}
			else{
				p=p->rlink;
			}
		}
	}
	return p;
}

template<typename T>
void BinarySearchTree<T>::insert(T &item){
	BTNode<T> *p,*q,*r;
	
	r=new BTNode<T>;
	r->info=item;
	r->llink=r->rlink=NULL;
	
	if(BinarySearchTree<T>::root==NULL){
		BinarySearchTree<T>::root=r;
	}
	else{
		p=BinarySearchTree<T>::root;
		while(p!=NULL){
			q=p;
			if(item>p->info){
				p=p->llink;
			}
			else{
				p=p->rlink;
			}
		}
		if(item<q->info){
			q->llink=r;
		}
		else{
			q->rlink=r;
		}
	}
	return;
}

//---------------------------Private Declerations---------------------------//
template<typename T>
void BinarySearchTree<T>::deleteFromTree(BTNode<T> *&p){
	BTNode<T> *c,*prev,*temp;
	
	if(p==NULL){
		cerr<<"No BTNode to delete!";
	}
	else if(p->llink==NULL && p->rlink==NULL){
		temp=p;
		p=NULL;
		delete temp;
	}
	else if(p->llink==NULL){
		temp=p;
		p=temp->rlink;
		delete temp;
	}
	else if(p->rlink==NULL){
		temp=p;
		p=temp->llink;
		delete temp;
	}
	else{
		c=p->llink;
		prev=NULL;
		while(c->rlink!=NULL){
			prev=c;
			c=c->rlink;
		}
		p->info=c->info;
		if(prev=NULL){
			p->llink=c->llink;
		}
		else{
			prev->rlink=c->llink;
		}
		delete c;
	}
	return;
}


#endif

