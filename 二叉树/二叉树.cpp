#include<iostream>
#include<string>
#include<stack>

using namespace std;

struct BTree
{
	int Nodedata = 0;
	struct BTree *pleft = nullptr;
	struct BTree *pright = nullptr;
};

void zhong_stack(struct BTree *pRoot ) {
	if (pRoot == nullptr) {
		return;
	}
	else
	{
		struct BTree* pcurrent = pRoot;
		stack< BTree*> mystack;
		while (!mystack.empty() || pcurrent != nullptr)
		{
			while (pcurrent != nullptr)
			{
				mystack.push(pcurrent);
				pcurrent = pcurrent->pleft;
			}
			if (!mystack.empty()) {
				pcurrent = mystack.top();
				cout << "" << pcurrent->Nodedata << endl;
				mystack.pop();
				pcurrent = pcurrent->pright;
			}
		}

	}


}


void show(struct BTree *pRoot, int n) {
	if (pRoot == nullptr)
	{
		return;
	}
	else
	{
		
		show(pRoot->pleft, n + 1);
		
		for (int i = 0; i < n; i++)
		{
			cout << "   ";
		}
		cout << pRoot->Nodedata << endl;
		show(pRoot->pright, n + 1);

	}
}


void main() {

	struct BTree *pRoot;
	struct BTree tree1;
	struct BTree tree2;
	struct BTree tree3;
	struct BTree tree4;
	struct BTree tree5;
	struct BTree tree6;
	struct BTree tree7;
	struct BTree tree8;
	tree1.Nodedata = 1;
	tree2.Nodedata = 2;
	tree3.Nodedata = 3;
	tree4.Nodedata = 4;
	tree5.Nodedata = 5;
	tree6.Nodedata = 6;
	tree7.Nodedata = 7;
	tree8.Nodedata = 8;
	pRoot = &tree1;

	tree1.pleft = &tree2;
	tree1.pright = &tree3;

	tree2.pleft = &tree4;
	tree2.pright = &tree5;

	tree3.pleft = &tree6;
	tree3.pright = &tree7;

	tree4.pleft = &tree8;


	show(pRoot, 1);
	zhong_stack(pRoot);
	cin.get();
}
