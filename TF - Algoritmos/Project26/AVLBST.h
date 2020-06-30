#pragma once
#include <functional>
#include <msclr\marshal_cppstd.h>
#include <sstream>
#include <string>
#include <string.h>
#define	max(a,b) (a > b ? a : b)
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

template<typename T, typename R>
class AVLBST
{
	struct Node {
		T       element;
		Node*   left;
		Node*   right;
		int     height;

		Node(T element) : element(element), height(0), left(nullptr), right(nullptr) {}
	};
	Node *root;
	function<R(T, short)> key;
	int len;
public:
	AVLBST(function<R(T, short)> k) : key(k), root(nullptr), len(0) {}
	~AVLBST() {}
	int height() { return height(root); }
	int size() { return len; }
	void clear() { clear(root); len = 0; }
	void add(T elem, short pos) { add(root, elem, pos); }
	T find(R val) { return find(root, val); }
	void greaterThan(R val, ListView ^l, vector<char> orden, short pos) { greaterThan(root, val, l, orden, pos); }
	void lowerThan(R val, ListView ^l, vector<char> orden, short pos) { lowerThan(root, val, l, orden, pos); }
	void inOrder(ListView ^l, vector<char> orden) { inOrder(root, l, orden); }
	void startsWith(string s, ListView ^l, vector<char> orden, short pos) { startsWith(root, s, l, orden, pos); }
	void startsWith_2(string s, ListView ^l, vector<char> orden, short pos) { startsWith_2(root, s, l, orden, pos); }
	void startsWith_3(char s, ListView ^l, vector<char> orden, short pos) { startsWith_3(root, s, l, orden, pos); }
	void finishWith(string s, ListView ^l, vector<char> orden, short pos) { finishWith(root, s, l, orden, pos); }
	void finishWith_2(string s, ListView ^l, vector<char> orden, short pos) { finishWith_2(root, s, l, orden, pos); }
	void containedIn(string s, ListView ^l, vector<char> orden, short pos) { containedIn(root, s, l, orden, pos); }
	void notContainedIn(string s, ListView ^l, vector<char> orden, short pos) { notContainedIn(root, s, l, orden, pos); }
private:
	void clear(Node*& node)
	{
		if (node != nullptr) {
			clear(node->left);
			clear(node->right);
			delete node;
			node = nullptr;
		}
	}
	int height(Node* node)
	{
		return node == nullptr ? -1 : node->height;
	}
	void add(Node*& node, T elem, short pos)
	{
		if (node == nullptr) {
			node = new Node(elem);
			++len;
		}
		else
		{
			if (key(elem, pos) < key(node->element, pos))
				add(node->left, elem, pos);
			else
				add(node->right, elem, pos);

			balance(node);
		}
	}
	void updateHeight(Node *node)
	{
		if (node != nullptr)
		{
			int hl = height(node->left);
			int hr = height(node->right);

			node->height = max(hl, hr) + 1;
		}
	}
	void rotateLeft(Node *&node)
	{
		Node* aux = node->right;
		node->right = aux->left;
		updateHeight(node);
		aux->left = node;
		updateHeight(aux);
		node = aux;
	}
	void rotateRight(Node *&node)
	{
		Node* aux = node->left;
		node->left = aux->right;
		updateHeight(node);
		aux->right = node;
		updateHeight(aux);
		node = aux;
	}
	void balance(Node *&node)
	{
		int hl = height(node->left);
		int hr = height(node->right);

		if (hr - hl < -1) {
			hl = height(node->left->left);
			hr = height(node->left->right);
			if (hr > hl) {
				rotateLeft(node->left);
			}
			rotateRight(node);
		}
		else if (hr - hl > 1) {
			hl = height(node->right->left);
			hr = height(node->right->right);
			if (hl > hr) {
				rotateRight(node->right);
			}
			rotateLeft(node);
		}
		else {
			updateHeight(node);
		}
	}
	T find(Node* node, R val, short pos)
	{
		if (node == nullptr) {
			return nullptr;
		}
		else if (val == key(node->element, pos)) {
			return node->element;
		}
		else if (val < key(node->element, pos)) {
			return find(node->left, val, pos);
		}
		else {
			return find(node->right, val, pos);
		}
	}
	void inOrder(Node *&node, ListView ^l, vector<char> orden)
	{
		if (node != nullptr) {
			inOrder(node->left, l, orden);
			////////////////////////////
			print(node, l, orden);
			///////////////////////////
			inOrder(node->right, l, orden);
		}
	}
	void greaterThan(Node *&node, R val, ListView ^l, vector<char> orden, short pos)
	{
		if (node != nullptr)
		{
			if (val < key(node->element, pos))
			{
				print(node, l, orden);
				greaterThan(node->right, val, l, orden, pos);
				greaterThan(node->left, val, l, orden, pos);
			}
			else
				greaterThan(node->right, val, l, orden, pos);
		}
	}
	void lowerThan(Node *&node, R val, ListView ^l, vector<char> orden, short pos)
	{
		if (node != nullptr)
		{
			if (val > key(node->element, pos))
			{
				print(node, l, orden);
				lowerThan(node->right, val, l, orden, pos);
				lowerThan(node->left, val, l, orden, pos);
			}
			else
				lowerThan(node->left, val, l, orden, pos);
		}
	}
	void startsWith(Node *&node, std::string s, ListView ^l, vector<char> orden, short pos)
	{
		if (node != nullptr) 
		{
				if (s.at(0) == key(node->element, pos).at(0))
				{
					if (s.size() <= key(node->element, pos).size())
					{
						bool comp = false;
						for (short i = 0; i < s.size(); ++i)
						{
							if (s.at(i) == key(node->element, pos).at(i))
								comp = true;
							else
							{
								comp = false; break;
							}
						}
						if (comp)
							print(node, l, orden);
					}
				}
				startsWith(node->right, s, l, orden, pos);
				startsWith(node->left, s, l, orden, pos);
		}
	}
	void startsWith_2(Node *&node, string s, ListView ^l, vector<char> orden, short pos) // int y float
	{
		if (node != nullptr)
		{
			stringstream ss; string val;
			ss << key(node->element, pos); val = ss.str();
			if (s.at(0) == val.at(0))
			{
				if (s.size() <= val.size())
				{
					bool comp = false;
					for (short i = 0; i < s.size(); ++i)
					{
						if (s.at(i) == val.at(i))
							comp = true;
						else
						{
							comp = false; break;
						}
					}
					if (comp)
						print(node, l, orden);
				}
			}
			startsWith_2(node->left, s, l, orden, pos);
			startsWith_2(node->right, s, l, orden, pos);
		}
	}
	void startsWith_3(Node *&node, char s, ListView ^l, vector<char> orden, short pos) // int y float
	{
		if (node != nullptr)
		{
			if (s == key(node->element, pos))
				print(node, l, orden);
			startsWith_3(node->left, s, l, orden, pos);
			startsWith_3(node->right, s, l, orden, pos);
		}
	}
	void finishWith(Node *&node, std::string s, ListView ^l, vector<char> orden, short pos)
	{
		if (node != nullptr)
		{
			if (s.at(s.size() - 1) == key(node->element, pos).at(key(node->element, pos).size() - 1))
			{
				if (s.size() <= key(node->element, pos).size())
				{
					bool comp = false;
					for (short i = 0; i < s.size(); ++i)
					{
						if (s.at(s.size() - 1 - i) == key(node->element, pos).at(key(node->element, pos).size()-1-i))
							comp = true;
						else
						{
							comp = false; break;
						}
					}
					if (comp)
						print(node, l, orden);
				}
			}
			finishWith(node->right, s, l, orden, pos);
			finishWith(node->left, s, l, orden, pos);
		}
	}
	void finishWith_2(Node *&node, string s, ListView ^l, vector<char> orden, short pos) {
		if (node != nullptr)
		{
			stringstream ss; string val;
			ss << key(node->element, pos); val = ss.str();
			if (s.at(s.size()-1) == val.at(val.size()-1))
			{
				if (s.size() <= val.size())
				{
					bool comp = false;
					for (short i = 0; i < s.size(); ++i) 
					{
						if (s.at(s.size() - 1 - i) == val.at(val.size() - 1 - i)) {
							comp = true;
						}
						else
						{
							comp = false; break;
						}
					}
					if (comp)
						print(node, l, orden);
				}
			}
			finishWith_2(node->left, s, l, orden, pos);
			finishWith_2(node->right, s, l, orden, pos);
		}
	}
	void containedIn(Node *&node, string s, ListView ^l, vector<char> orden, short pos)
	{
		if (node != nullptr)
		{
			if (key(node->element, pos).find(s) <= key(node->element, pos).size() - 1)
				print(node, l, orden);
			containedIn(node->right, s, l, orden, pos);
			containedIn(node->left, s, l, orden, pos);
		}
	}
	void notContainedIn(Node *&node, string s, ListView ^l, vector<char> orden, short pos)
	{
		if (node != nullptr)
		{
			if (key(node->element, pos).find(s) > key(node->element, pos).size() - 1)
				print(node, l, orden);
			notContainedIn(node->right, s, l, orden, pos);
			notContainedIn(node->left, s, l, orden, pos);
		}
	}
	void print(Node *&node, ListView ^l, vector<char> orden)
	{
		int a = 0, b = 0, c = 0, d = 0;
		ListViewItem ^item;
		if (orden.at(0) == 'I' && node->element->ints.at(0).p == 0)
		{
			item = gcnew ListViewItem(Convert::ToString(node->element->ints.at(0).x));
			a++;
		}
		else if (orden.at(0) == 'C'&& node->element->chars.at(0).p == 0)
		{
			String ^s; s += (wchar_t)node->element->chars.at(0).x;
			item = gcnew ListViewItem(s);
			b++;
		}
		else if (orden.at(0) == 'F'&& node->element->floats.at(0).p == 0)
		{
			item = gcnew ListViewItem(Convert::ToString(node->element->floats.at(0).x));
			c++;
		}
		else if (orden.at(0) == 'S'&& node->element->strings.at(0).p == 0)
		{
			item = gcnew ListViewItem(msclr::interop::marshal_as<System::String^>(node->element->strings.at(0).x));
			d++;
		}
		l->Items->Add(item);
		for (int i = 1; i < orden.size(); ++i)
		{
			if (orden.at(i) == 'I'&&node->element->ints.at(a).p == i)
			{
				item->SubItems->Add(Convert::ToString(node->element->ints.at(a).x));
				a++;
			}
			else if (orden.at(i) == 'C'&&node->element->chars.at(b).p == i)
			{
				String ^s; s += (wchar_t)node->element->chars.at(b).x;
				item->SubItems->Add(s);
				b++;
			}
			else if (orden.at(i) == 'F'&&node->element->floats.at(c).p == i)
			{
				item->SubItems->Add(Convert::ToString(node->element->floats.at(c).x));
				c++;
			}
			else if (orden.at(i) == 'S'&&node->element->strings.at(d).p == i)
			{
				item->SubItems->Add(msclr::interop::marshal_as<System::String^>(node->element->strings.at(d).x));
				d++;
			}
		}
	}

};