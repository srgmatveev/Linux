#include <iostream>
#include "list_reverse.hpp"


using namespace std;
template <class T>
List_Nodes<T>::List_Nodes(): head{nullptr} {

	std::cout << "Create List_Nodes" << std::endl;
}

template <class T>
List_Nodes<T>::~List_Nodes() {
	std::cout << "Delete List_Nodes" << std::endl;
	Node<T>* cur_node = head;

	while (cur_node) {
		Node<T> *tmp = cur_node;
		cur_node = cur_node->get_next_node();
		if (tmp) delete tmp;
	}
}
template <class T>
void List_Nodes<T>::add_node(Node<T>* node) {

	if (!head) {head = node; return;}

	Node<T>* cur_node = head;

	while (cur_node->get_next_node()) {

		cur_node = cur_node->get_next_node();
	}

	cur_node->set_next_node(node);
}

template <class T>
void List_Nodes<T>::print_nodes() {

	Node<T> * cur_node = head;
	while (cur_node) {
		cout << cur_node->get_node_value() << endl;
		cur_node = cur_node->get_next_node();
	}
}

template <class T>
void List_Nodes<T>::reverse_nodes() {
	if (!head || !head->get_next_node()) return;

	Node<T>* cur_node = head;
	Node<T>* prev_node = nullptr;
	Node<T>* next_node = nullptr;

	while (cur_node) {
		next_node = cur_node->get_next_node();
		cur_node->set_next_node(prev_node);
		prev_node = cur_node;
		cur_node = next_node;
	}

	head = prev_node;

}

int main(int argc, char const *argv[])
{
/*
	List_Nodes<std::string> *list = new List_Nodes<std::string>();

	Node<std::string> *my_node = new Node<std::string>("Первая нода");
	Node<std::string> *my_second_node = new Node<std::string>("Вторая нода");
	Node<std::string> *my_third_node = new Node<std::string>("Третья нода");
	list->add_node(my_node);
	list->add_node(my_second_node);
	list->add_node(my_third_node);
	list->print_nodes();
	list->reverse_nodes();
	cout << "========================\n";
	list->print_nodes();
	list->reverse_nodes();
	cout << "========================\n";
	list->print_nodes();
	cout << "========================\n";
	if (list) { delete list;}

	List_Nodes<int> *list1 = new List_Nodes<int>();

	Node<int> *my_node_int = new Node<int>(1);
	Node<int> *my_second_node_int = new Node<int>(2);
	Node<int> *my_third_node_int = new Node<int>(3);
	list1->add_node(my_node_int);
	list1->add_node(my_second_node_int);
	list1->add_node(my_third_node_int);
	list1->print_nodes();
	list1->reverse_nodes();
	cout << "========================\n";
	list1->print_nodes();
	list1->reverse_nodes();
	cout << "========================\n";
	list1->print_nodes();
	cout << "========================\n";
	if (list1) { delete list1;}
*/

	List_Nodes<int*> *list_int = new List_Nodes<int*>();

	int* one_p = new int(1);
	int* two_p = new int(2);
	int* third_p = new int(3);
	Node<int*> *my_node_int_p = new Node<int*>(one_p);
	Node<int*> *my_second_node_int_p = new Node<int*>(two_p);
	Node<int*> *my_third_node_int_p = new Node<int*>(third_p);
	list_int->add_node(my_node_int_p);
	list_int->add_node(my_second_node_int_p);
	list_int->add_node(my_third_node_int_p);
	list_int->print_nodes();
	list_int->reverse_nodes();
	cout << "========================\n";
	list_int->print_nodes();
	list_int->reverse_nodes();
	cout << "========================\n";
	list_int->print_nodes();
	cout << "========================\n";
	if (list_int)  delete list_int;
	if(one_p) delete one_p;
	if(two_p) delete two_p;
	if (third_p) delete third_p;
	return 0;
}