#include "RBTree.h"
#include <time.h>


void TestRBTree()
{
	RBTree<int> rb;
	srand(time(NULL));
	clock_t begin1 = clock();
	for (int i = 0; i < 1000000; i++)
	{
		int tmp = rand() + i;
		rb.Insert(tmp);
		if (!rb.Find(tmp))
			cout << "error" << endl;
	}
	clock_t end1 = clock();


	//rb.Insert(5);	
	//rb.Insert(7);
	//rb.Insert(9);
	//rb.Insert(-5);
	//rb.Insert(2);
	//rb.Insert(1);
	//rb.Insert(-1);
	//rb.Insert(0);

	cout << rb.IsValidRBTRee() << endl;
	//rb.InOrder();
	cout << "RBTree Insert : " << end1 - begin1 << endl;
	//cout << "AVLTree IsBalance : " << end2 - begin2 << endl;
}
int main()
{
	TestRBTree();
	return 0;
}