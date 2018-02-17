#ifndef LIST_REVERSE_HPP
#define LIST_REVERSE_HPP

#include <iostream>
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
	Node(T* node_value):  next_node{nullptr} {
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
		if (node_value) delete node_value;
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
	void reverse_nodes();
};

#endif