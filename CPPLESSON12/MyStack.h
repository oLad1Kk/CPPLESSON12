#pragma once
#include <iostream>
#include <string>;

using std::cout;
using std::endl;
using std::string;

namespace myStack {
	template <typename T>
	class Node {
	public:
		T info;
		Node* next;
		Node* prev;

		Node(T value) { info = value; next = prev = nullptr; }
	};


	template <typename U>
	class Stack {
		Node<U>* head;
		Node<U>* current;
	public:
		Stack() { head = current = nullptr; }
		~Stack() {
			while (!isEmpty()) {
				pop_back();
			}
		}

		bool isEmpty()const { return head == nullptr; }
		U top()const {
			if (isEmpty()) throw "Stack is empty\n";
			return current->info;
		}
		void push_back(U value) {
			Node<U>* el = new Node<U>(value);

			if (isEmpty()) head = current = el;
			else {
				el->prev = current;
				current->next = el;
				current = current->next;
			}
		}
		void pop_back() { 
			if (!isEmpty())
			{
				if (current != head)
				{
					current = current->prev;
					delete current->next;
					current->next = nullptr;
				}
				else
				{
					delete head;
					head = current = nullptr;
				}
			}
		}
		void showStack()const { 
			if (!isEmpty())
			{
				Node<U>* p = head;
				while (p != nullptr)
				{
					cout << p->info << " ";
					p = p->next;
				}
			}
			else
			{
				cout << "Stack is empty\n";
			}
		}
	};

	bool isBrackets(string line)
	{
		Stack<char> letter;
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == '(' || line[i] == '[' || line[i] == '{') {
				letter.push_back(line[i]);
			}
			else if (line[i] == ')' || line[i] == ']' || line[i] == '}')
			{
				if (letter.isEmpty())
					return false;

				else
				{
					if (letter.top() == '(' && line[i] != ')')
					{
						return false;
					}
					else if (letter.top() == '[' && line[i] != ']')
					{
						return false;
					}
					else if (letter.top() == '{' && line[i] != '}')
					{
						return false;
					}
					else
					{
						letter.pop_back();
					}
				}
			}
		}

		return letter.isEmpty();
	}

	
}


