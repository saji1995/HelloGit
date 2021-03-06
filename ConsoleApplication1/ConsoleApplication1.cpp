// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <stack>
using namespace std;

//1.
void foo_01()
{
	int n = 11;
	unsigned int tmp = n - ((n >> 1) & 033333333333) - ((n >> 2) & 011111111111);
	cout << ((tmp + (tmp >> 3)) & 030707070707) % 63 << endl;
}

//2.
bool Find(int target, vector<vector<int>> array)
{
	if (!array.empty())
	{
		int rowCount = array.size();
		int nLength = 0;
		while (rowCount > 0 && nLength < array[0].size())
		{
			if (target < array[rowCount - 1][nLength])
			{
				rowCount--;
			}
			else if(target > array[rowCount-1][nLength])
			{
				nLength++;
			}
			else
			{
				return true;
			}
		}
	}
	else
	{
		return false;
	}
	return false;
}

//3.
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		int top = 0;
		if (stack1.size() > 1)
		{
			while (stack1.size() > 1)
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
			top = stack1.top();
			stack1.pop();
			while (stack2.size() > 0)
			{
				stack1.push(stack2.top());
				stack2.pop();
			}
		}
		else if (stack1.size() == 1)
		{
			top = stack1.top();
			stack1.pop();
		}
		return top;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main()
{
	//TODO
	vector<vector<int>> tmp{ {0,1,2,3,4},{5,6,7,8,9},{10,11,12,13,14} };
	cout << Find(4, tmp);

	cout << endl;
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
