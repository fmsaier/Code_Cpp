#include <iostream>
#include "unordered_map.h"

using namespace std;
using namespace fmsaier;

int main()
{
	//HashBucket<int> hash;
	////srand(time(NULL));
	////clock_t begin = clock();
	////for (size_t i = 0; i < 100000; i++)
	////{
	////	int x = rand() + i;
	////	hash.Insert(x);
	////}
	////clock_t end = clock();

	////cout << end - begin << endl;

	//hash.Insert(1);
	//hash.Insert(2);
	//hash.Insert(3);
	//hash.Insert(4);
	//hash.Insert(5);
	//hash.Insert(6);

	//hash.Erase(6);
	//hash.Erase(5);
	//hash.Erase(5);
	//hash.Erase(4);

	unordered_map<int, int> hash;
	hash.insert(make_pair(1, 1));

	return 0;
}