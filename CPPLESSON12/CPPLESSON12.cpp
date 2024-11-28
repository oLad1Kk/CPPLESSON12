#include "MyStack.h"
#include <iostream>
#include <string>
#include "MyStack.h"
#include <stack>
using std::string;
using namespace myStack;

string PolishRecord(string line) // 1 + 2 * 3
{
	string postf = "";
	std::stack<char> operations;
	for (int i = 0; i < line.size(); i++)
	{
		if (isdigit(line[i]))
		{
			postf += line[i];
		}
		else if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/')
		{
			if (operations.empty())
			{
				operations.push(line[i]);
			}
			else
			{
				if ((operations.top() == '*' || operations.top() == '/') && (line[i] == '+' || line[i] == '-'))
				{
					postf += operations.top();
					operations.pop();
					operations.push(line[i]);
				}
				else
				{
					operations.push(line[i]);
				}
			}
		}
	}
	while (!operations.empty())
	{
		postf += operations.top();
		operations.pop();
	}
	return postf;
}

int main()
{
	//myStack::Stack<std::string> p34;
	//p34.push_back("Students");
	//p34.push_back("of");
	//p34.push_back("the");
	//p34.push_back("group");
	//p34.push_back("P34");
	//p34.showStack();
	//cout << endl;

	//p34.pop_back();
	//p34.showStack();

	//cout << "-------------------------------------------\n\n";
	//while (!p34.isEmpty())
	//{
	//	if (p34.top().size() == 2) cout << p34.top() << " ";
	//	p34.pop_back();
	//}
	//cout << endl;
	//p34.showStack();

	//string str;
	//std::cout << "Enter string: "; std::cin >> str;

	//Stack<char>letter;
	//for (int i = 0; i < str.size(); i++)
	//{
	//	letter.push_back(str[i]);
	//}
	//bool isPolly = true;
	//for (int i = 0; i < str.size(); i++)
	//{
	//	if (letter.isEmpty()) {
	//		isPolly = false;
	//		break;
	//	}
	//	else
	//	{
	//		if (str[i] != letter.top())
	//		{
	//			isPolly = false;
	//			break;
	//		}
	//		letter.pop_back();
	//	}
	//}

	//if (isPolly)
	//{
	//	cout << "The word is palindrome\n";
	//}
	//else
	//{
	//	cout << "The word is not palindrome\n";
	//}

	//cout << "[()]{}: " << isBrackets("[()]{}") << endl;
	//cout << "[()]{}): " << isBrackets("[()]{})");

	cout << PolishRecord("1+2*3") << endl;
	cout << PolishRecord("1*2+3") << endl;




}
