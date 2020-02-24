#include "A7.h"

using namespace std;

bool TreeNode::operator< (TreeNode A){
    if(marks0 > A.marks0){return 1;}
    else if(marks1 > A.marks1){return 1;}
    else if(marks2 > A.marks2){return 1;}
    else if(marks3 > A.marks3){return 1;}
    else if(marks4 > A.marks4){return 1;}
    else{ return 0;}
}
bool TreeNode::operator> (TreeNode A){
    return !(*this < A);
}
TreeNode::TreeNode(DataType id, DataType m0,DataType m1,DataType m2,DataType m3,DataType m4,DataType sk) {
	this->ID = id;
    this->marks0 = m0;
    this->marks1 = m1;
    this->marks2 = m2;
    this->marks3 = m3;
    this->marks4 = m4;
    this->skill = sk;
	this->left = this->right = NULL;
	this->height = 0;
}
PtrToNode TreeNode::taller() {
	if (left == NULL) return right;
	if (right == NULL) return left;
	if (left->height > right->height) return left;
	return right;
}
int TreeNode::updateHeight(int hleft, int hright) {
	height = 1 + std::max(hleft, hright);	// changes height of this node.
	return height;
}
int TreeNode::updateHeight() {
	int hleft = (left ? left->getHeight() : -1);
	int hright = (right ? right->getHeight() : -1);
	return updateHeight(hleft, hright);
}
bool TreeNode::imbalanced() {
	int hleft = (left ? left->getHeight() : -1);
	int hright = (right ? right->getHeight() : -1);
	return (abs(hleft - hright) == 2);
}
void TreeNode::addChild(PtrToNode child) {
	// assume child != NULL.
	if (*child < *this) left = child;
	else right = child;
}
void TreeNode::print() {
	cout<<ID<<' '<<marks0<<' '<<marks1<<' '<<marks2<<' '<<marks3<<' '<<marks4<<' '<<skill<<endl;
}

PtrToNode Tree::rotateLeft(PtrToNode k2) {
	std::cout << "left rotate at " << k2->data << std::endl;
	PtrToNode k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;

	k2->updateHeight();
	if (k1->right) k1->updateHeight(k1->right->height, k2->height);
	else k1->updateHeight(-1, k2->height);
	return k1;
}
PtrToNode Tree::rotateRight(PtrToNode k2) {
	PtrToNode k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;

	k2->updateHeight();
	if (k1->left) k1->updateHeight(k1->left->height, k2->height);
	else k1->updateHeight(-1, k2->height);

	return k1;
}
PtrToNode Tree::rotateLeftRight(PtrToNode k1) {
	k1->left = rotateLeft(k1->left);
	return rotateRight(k1);
}
PtrToNode Tree::rotateRightLeft(PtrToNode k1) {
	k1->right = rotateRight(k1->right);
	return rotateLeft(k1);
}
PtrToNode Tree::insert(PtrToNode ptr, PtrToNode rr) {
	// assumes unique keys.
	if (rr == NULL) return ptr;
	if (*ptr < *rr) {
		rr->left = insert(ptr, rr->left);
		if (rr->imbalanced()) {
			if (*ptr < *(rr->left))
				rr = rotateRight(rr);
			else
				rr = rotateLeftRight(rr);
		}
	} else {
		rr->right = insert(ptr, rr->right);
		//std::cout << "Debug: ptr->data = " << ptr->data << ", rr->right->data = " << rr->right->data << std::endl;
		if (rr->imbalanced()) {
			if (*ptr > *(rr->right))
				rr = rotateLeft(rr);
			else
				rr = rotateRightLeft(rr);
		}
	}
	rr->updateHeight();
	return rr;
}
PtrToNode Tree::insert(DataType id, DataType m0,DataType m1,DataType m2,DataType m3,DataType m4,DataType sk) {
	std::cout << "inserting " << data << std::endl;
	PtrToNode ptr = new TreeNode(data);
	root = insert(ptr, root);
	return ptr;
}
void Tree::inorder(PtrToNode rr) {
	if (rr) {
		inorder(rr->left);
		rr->print();
		inorder(rr->right);
	}
}
void Tree::inorder() {
	inorder(root);
	std::cout << std::endl;
}
void Tree::print() {
	inorder();
}
bool Tree::search(DataType data, PtrToNode rr) {
	if (rr == NULL) return false;
	if (data == rr->data) return true;
	if (data < rr->data) return search(data, rr->left);
	return search(data, rr->right);
}
bool Tree::search(DataType data) {
	bool present = search(data, root);
	if (present)
		std::cout << data << " present." << std::endl;
	else
		std::cout << data << " NOT present." << std::endl;
	return present;
}
void Tree::printGraphviz(PtrToNode rr) {
	if (rr) {
		if (rr->left) {
			std::cout << '"' << rr->data << '"';
			std::cout << " -> ";
			std::cout << '"' << rr->left->data << '"';
			std::cout << std::endl;
			printGraphviz(rr->left);
		}
		if (rr->right) {
			std::cout << '"' << rr->data << '"';
			std::cout << " -> ";
			std::cout << '"' << rr->right->data << '"';
			std::cout << std::endl;
			printGraphviz(rr->right);
		}
	}
}
PtrToNode Tree::remove(DataType data, PtrToNode rr) {
	if (rr == NULL)
		std::cout << "Element " << data << " NOT found.\n";
	else if (data < rr->data)
		rr->left = remove(data, rr->left);
	else if (rr->data < data)
		rr->right = remove(data, rr->right);
	else {	// the element is present in BST at rr.
		if (rr->left && rr->right) {	// scratch your head.
			PtrToNode minptr = findminptr(rr->right);
			rr->data = minptr->data;
			rr->right = remove(minptr->data, rr->right);
		} else {			// zero or one children.
			PtrToNode toberemoved = rr;
			if (rr->left == NULL)
				rr = rr->right;
			else
				rr = rr->left;
			delete toberemoved;	// free memory.
		}
	}
	if (rr && rr->imbalanced()) {	// need to be repeated for all the ancestors.
		PtrToNode rrchild = rr->taller();
		PtrToNode rrgrandchild = rrchild->taller();	// rr->imbalanced() should guarantee this and below dereferences safe.
		std::cout << rr->data << " is imbalanced (child=" << rrchild->data << ", grandchild=" << rrgrandchild->data << ").\n";

		if (rr->data < rrchild->data)
			if (rrchild->data < rrgrandchild->data)	// right-right
				rr = rotateLeft(rr);
			else 					// right-left
				rr = rotateRightLeft(rr);
		else
			if (rrchild->data > rrgrandchild->data)	// left-left
				rr = rotateRight(rr);
			else 					// left-right
				rr = rotateLeftRight(rr);
	}
	if (rr) rr->updateHeight();
	
	return rr;
}
PtrToNode Tree::remove(DataType data) {
	std::cout << "removing " << data << std::endl;
	return (root = remove(data, root));
}
void Tree::printGraphviz() {
	std::cout << "-----------------\n";
	std::cout << "digraph G {\n";
	printGraphviz(root);
	std::cout << "}\n";
	std::cout << "-----------------\n";
}

int main(){
    Tree T;
    T.add(1,28,15,72,79,53,880704511);
    T.add(2,9,27,78,89,81,133736473);
    T.print();
}