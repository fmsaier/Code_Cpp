#include <string>
#include "BinarySearchTree.h"

void TestBSTree()
{
	//BSTree<string, string> dict;
	//dict.Insert("insert", "插入");
	//dict.Insert("erase", "删除");
	//dict.Insert("left", "左边");
	//dict.Insert("string", "字符串");
	//string str;
	//while (cin >> str)
	//{
	//	auto ret = dict.Find(str);
	//	if (ret)
	//	{
	//		cout << str << ":" << ret->_value << endl;
	//	}
	//	else
	//	{
	//		cout << "单词拼写错误" << endl;
	//	}
	//}

	string strs[] = { "苹果", "西瓜", "苹果", "樱桃", "苹果", "樱桃", "苹果", "樱桃", "苹果" };
	// 统计水果出现的次
	BSTree<string, int> countTree;
	for (auto str : strs)
	{
		auto ret = countTree.Find(str);
		if (ret == NULL)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}
	countTree.Erase("西瓜");
	countTree.Erase("苹果");
	countTree.Erase("樱桃");
	countTree.InOrder();
}

void TestBSTree1()
{
	BSTree<int, int> t;
	srand(time(NULL));
	for (int i = 0; i < 10000; i++)
	{
		t.Insert(rand() + i, rand() - i);
	}
	for (int i = 0; i < 1000; i++)
	{
		t.Erase(rand() + i);
		if (!t.Find(rand() + i))
		{
			cout << "error" << endl;
			break;
		}
	}
	t.InOrder();
}

int main()
{
	TestBSTree1();
	return 0;
}
