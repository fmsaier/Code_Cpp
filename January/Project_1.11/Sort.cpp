#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> tmp;
public:
	void ShellSort(vector<int>& arr)
	{
		int gap = arr.size();
		while (gap > 1)
		{
			gap = gap / 3 + 1;
			for (int i = 0; i < arr.size() - gap; i += gap)
			{
				int end = i;
				int cur = arr[end + gap];
				while (end >= 0)
				{
					if (cur < arr[end])
					{
						arr[end + gap] = arr[end];
						end -= gap;
					}
					else
						break;
				}
				arr[end + gap] = cur;
			}
		}
	}

	void InsertSort(vector<int>& arr)
	{
		for (int i = 0; i < arr.size() - 1; i++)
		{
			int end = i;
			int cur = arr[end + 1];
			while (end >= 0)
			{
				if (cur < arr[end])
				{
					arr[end + 1] = arr[end];
					end--;
				}
				else
					break;
			}
			arr[end + 1] = cur;
		}
	}

	void BubbleSort(vector<int>& arr)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			int exchange = 0;
			for (int j = 0; j < arr.size() - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					swap(arr[j], arr[j + 1]);
					exchange = 1;
				}
			}
			if (!exchange)
				break;
		}
	}

	//整成闭区间
	void QuickSort(vector<int>& arr, int l, int r)
	{
		if (l >= r) return;
		int left = l - 1;
		int right = r + 1;
		int key = arr[(r - l) / 2 + l];
		int i = l;
		while (i < right)
		{
			if (arr[i] < key)
				swap(arr[i++], arr[++left]);
			else if (arr[i] > key)
				swap(arr[i], arr[--right]);
			else
				i++;
		}
		QuickSort(arr, l, left);
		QuickSort(arr, right, r);
	}

	void MergeSort(vector<int>& arr, int left, int right)
	{
		if (left >= right) return;
		int mid = (right - left) / 2 + left;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		int i = left, j = mid + 1, k = 0;
		while (i <= mid && j <= right) tmp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
		while (i <= mid) tmp[k++] = arr[i++];
		while (j <= right) tmp[k++] = arr[j++];

		for (int i = left; i <= right; i++)
			arr[i] = tmp[i - left];
	}

	void SelectSort(vector<int>& arr)
	{
		int left = 0;
		int right = arr.size() - 1;
		while (left < right)
		{
			int max = left;
			int min = right;
			for (int i = left; i <= right; i++)
			{
				if (arr[i] > arr[max])
					max = i;
				if (arr[i] < arr[min])
					min = i;
			}
			swap(arr[max], arr[right]);
			if (right == min)
				min = max;
			swap(arr[min], arr[left]);
			left++;
			right--;
		}
	}

	void AdjustDown(vector<int>& arr, int n, int parent)
	{
		int child = parent * 2 + 1;
		while (child < n)
		{
			if (child + 1 < n && arr[child + 1] > arr[child])
				child++;
			if (arr[parent] < arr[child])
				swap(arr[parent], arr[child]);
			else
				break;
			parent = child;
			child = parent * 2 + 1;
		}
	}

	void HeapSort(vector<int>& arr)
	{
		//建堆
		for (int i = (arr.size() - 2) / 2; i >= 0; i--)
		{
			AdjustDown(arr, arr.size(), i);
		}

		for (int i = 1; i < arr.size(); i++)
		{
			swap(arr[0], arr[arr.size() - i]);
			AdjustDown(arr, arr.size() - i, 0);
		}
	}

	void CountSort(vector<int>& arr)
	{
		int max = arr[0];
		int min = arr[0];
		for (int i = 0; i < arr.size(); i++)
		{
			if (max < arr[i])
				max = arr[i];
			if (min > arr[i])
				min = arr[i];
		}
		vector<int> count(max - min + 1, 0);
		for (int i : arr)
		{
			count[i - min]++;
		}
		int k = 0;
		for (int i = 0; i < count.size(); i++)
		{
			while (count[i]--)
			{
				arr[k++] = i + min;
			}
		}
	}
};

int main()
{
	vector<int> arr = { 4,6,9,2,45,18,61,4,8412,5,464,31,15 };
	Solution s;
	s.tmp.resize(arr.size(), 0);
	s.CountSort(arr);
	for (auto i : arr)
	{
		cout << i << " ";
	}

	cout << sizeof(nullptr) << endl;

	return 0;
}