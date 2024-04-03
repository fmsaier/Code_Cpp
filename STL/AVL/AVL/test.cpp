#include "AVLTree.h"
#include <time.h>


void TestAVLTree()
{
	AVLTree<int> avl;
	srand(time(NULL));
	clock_t begin1 = clock();
	for (int i = 0; i < 100000; i++)
	{
		avl.Insert(rand() + i);
	}
	clock_t end1 = clock();
	clock_t begin2 = clock();
	cout << avl.IsAVLTree() << endl;
	clock_t end2 = clock();
	//avl.Insert(2);
	//avl.Insert(0);
	//avl.Insert(1);
	////avl.Insert(2);
	////avl.Insert(1);
	////avl.Insert(0);
	//avl.InOrder();

	cout << "AVLTree Insert : " << end1 - begin1 << endl;
	cout << "AVLTree IsBalance : " << end2 - begin2 << endl;
}

int main()
{
	TestAVLTree();
	
	return 0;
}