#include<bits/stdc++.h>
typedef struct TreeNode *PtrToNode;
typedef int DataType;

using namespace std;

struct TreeNode {
	DataType ID, marks0, marks1, marks2, marks3, marks4, skill;
	PtrToNode left, right;
	int height;
	TreeNode::TreeNode(DataType id, DataType m0,DataType m1,DataType m2,DataType m3,DataType m4,DataType sk);
	void addChild(PtrToNode);
	int getHeight() { return height; }
	int updateHeight();
	int updateHeight(int, int);
	bool imbalanced();
	PtrToNode taller();
	void print();
    bool operator< (TreeNode A);
    bool operator> (TreeNode A);
};

class Tree {
	PtrToNode root;
public:
	Tree():root(NULL) { }
	void print();
	void inorder();
	void inorder(PtrToNode);
	PtrToNode insert();
	PtrToNode insert(PtrToNode, PtrToNode);
	PtrToNode rotateLeft(PtrToNode);
	PtrToNode rotateRight(PtrToNode);
	PtrToNode rotateLeftRight(PtrToNode);
	PtrToNode rotateRightLeft(PtrToNode);
	bool search(DataType data, PtrToNode rr);
	bool search(DataType data);
	PtrToNode remove(DataType);
	PtrToNode remove(DataType, PtrToNode);
	void printGraphviz();
	void printGraphviz(PtrToNode rr);
    DataType Update();
};

	