#ifndef BINARYTREE_H
#define BINARYTREE_H

#include<iostream>

using namespace std;

template<typename T>
struct BTNode{
	T info;
	BTNode<T> *llink,*rlink;
};

template<typename T>
class BinaryTree{
	protected:
		BTNode<T> *root;
	private:
		void destroy(BTNode<T> *&);
		void inorderT(BTNode<T> *);
		void preorderT(BTNode<T> *);
		void postorderT(BTNode<T> *);
		int height(BTNode<T> *);
		int max(int,int);
		int BTNodeCount(BTNode<T> *);
		int leavesCount(BTNode<T> *);
	public:
		BinaryTree();
		~BinaryTree();
		bool isEmpty();
		void inorder();
		void preorder();
		void postorder();
		int treeHeight();
		int count();
		int leaves();
};

//---------------------------Public Declerations---------------------------//

template<typename T>
BinaryTree<T>::BinaryTree(){
	this->root=NULL;
}

template<typename T>
BinaryTree<T>::~BinaryTree(){
	BinaryTree::destroy(this->root);
}

template<typename T>
bool BinaryTree<T>::isEmpty(){
	return this->root==NULL;
}

template<typename T>
void BinaryTree<T>::inorder(){
	BinaryTree::inorderT(this->root);
}

template<typename T>
void BinaryTree<T>::preorder(){
	BinaryTree::preorderT(this->root);
}

template<typename T>
void BinaryTree<T>::postorder(){
	BinaryTree::postorderT(this->root);
}

template<typename T>
int BinaryTree<T>::treeHeight(){
	return height(this->root);
}

template<typename T>
int BinaryTree<T>::count(){
	return BTNodeCount(this->root);
}

template<typename T>
int BinaryTree<T>::leaves(){
	return leavesCount(this->root);
}

//---------------------------Private Declerations---------------------------//

template<typename T>
void BinaryTree<T>::inorderT(BTNode<T> *p){
	if(p!=NULL){
		inorderT(p->llink);
		cout<<p->info;
		inorderT(p->rlink);
	}
}

template<typename T>
void BinaryTree<T>::preorderT(BTNode<T> *p){
	if(p!=NULL){
		cout<<p->info;
		inorderT(p->llink);
		inorderT(p->rlink);
	}
}

template<typename T>
void BinaryTree<T>::postorderT(BTNode<T> *p){
	if(p!=NULL){
		inorderT(p->llink);
		inorderT(p->rlink);
		cout<<p->info;
	}
}

template<typename T>
int BinaryTree<T>::BTNodeCount(BTNode<T> *p){
	if(p==NULL){
		return 0;
	}
	else{
		return 1+BTNodeCount(p->llink)+BTNodeCount(p->rlink);
	}
}

template<typename T>
int BinaryTree<T>::leavesCount(BTNode<T> *p){
	if(p==NULL){
		return 0;
	}
	else if(p->llink==NULL && p->rlink==NULL){
		return 1;
	}
	else{
		return leavesCount(p->llink)+leavesCount(p->rlink);
	}
}

template<typename T>
int BinaryTree<T>::max(int x, int y){
	if(x>=y){
		return x;
	}
	else{
		return y;
	}

}

template<typename T>
int BinaryTree<T>::height(BTNode<T> *p){
	if(p==NULL){
		return 0;
	}
	else{
		return 1+max(height(p->llink),height(p->rlink));
	}
}

template<typename T>
void BinaryTree<T>::destroy(BTNode<T> *&p){
	if(p!=NULL){
		destroy(p->llink);
		destroy(p->rlink);
		destroy(p);
		p=NULL;
	}
}


#endif

