#ifndef LIST_REVERSE_HPP
#define LIST_REVERSE_HPP

#include <iostream>
#include <cstring>
#include <cwchar>

using namespace std;

template <class T>
class Node {
private:
	T node_value;
	Node* next_node;
public:

	Node(): node_value{}, next_node{nullptr} {}
	Node(const T& node_value): node_value{node_value}, next_node{nullptr} {}
	const T& get_node_value() {
		return node_value;
	}


	Node* get_next_node() {
		return this->next_node;
	}

	void set_next_node(Node *node) {
		if (this != node) next_node = node;
	}

	virtual ~Node() {
		cout << "Delete:" << node_value << endl;
	}


};


template <class T>
class Node<T*> {
private:
	T* node_value;
	Node* next_node;
public:

	Node(): node_value{}, next_node{nullptr} {}
	Node(const T* node_value):  next_node{nullptr} {
		this->node_value = new T;
		*this->node_value = *node_value;

	}
	const T& get_node_value() {
		return *node_value;
	}


	Node* get_next_node() {
		return this->next_node;
	}

	void set_next_node(Node *node) {
		if (this != node) next_node = node;
	}

	virtual ~Node() {
		cout << "Delete *:" <<  *node_value << endl;
		if (node_value) delete[] node_value;
	}


};

template <>
class Node<char*> {
private:
	char* node_value;
	Node* next_node;
public:

	Node(): node_value{nullptr}, next_node{nullptr} {}
	Node(const char* node_value):  next_node{nullptr} {
		this->node_value = new char[std::strlen(node_value) + 1];
		std::strcpy(this->node_value, node_value);
		cout << this->node_value << " " << std::strlen(this->node_value) << endl;
	}
	const char* get_node_value() {
		return node_value;
	}


	Node* get_next_node() {
		return this->next_node;
	}

	void set_next_node(Node *node) {
		if (this != node) next_node = node;
	}

	virtual ~Node() {
		cout << "Delete *:" <<  this->node_value << endl;

		if (node_value) delete[] node_value;
	}


};


template <>
class Node<wchar_t*> {
private:
	wchar_t* node_value;
	Node* next_node;
public:

	Node(): node_value{nullptr}, next_node{nullptr} {}
	Node(const wchar_t* node_value):  next_node{nullptr} {

		this->node_value = new wchar_t[std::wcslen(node_value) + 1];
		std::wcscpy(this->node_value, node_value);

	}

	const wchar_t* get_node_value() {

		return node_value;
	}


	Node* get_next_node() {
		return this->next_node;
	}

	void set_next_node(Node *node) {
		if (this != node) next_node = node;
	}

	virtual ~Node() {
		wcout << L"Delete *:" <<  this->node_value << endl;

		if (node_value) delete[] node_value;
	}


};


template <class T>
class List_Nodes {
private:
	Node<T>* head;
public:
	List_Nodes();
	void add_node(Node<T>*);
	virtual ~List_Nodes();
	void print_nodes();
	void print_unicode_nodes();
	void reverse_nodes();
	void reverse_nodes_recursively(Node<T>*, Node<T>* = NULL);
	Node<T>* get_head();
	void set_head(Node<T>*); 
};

#endif