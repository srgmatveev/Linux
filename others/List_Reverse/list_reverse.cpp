#include <iostream>
#include <string>
#include "list_reverse.hpp"

using namespace std;

List_Nodes::List_Nodes(): head{nullptr} {

	std::cout << "Create List_Nodes" << std::endl;
}

List_Nodes::~List_Nodes() {
	std::cout << "Delete List_Nodes" << std::endl;
	Node* cur_node = head;

	while (cur_node) {
		Node *tmp = cur_node;
		cur_node = cur_node->get_next_node();
		if (tmp) delete tmp;
	}
}

void List_Nodes::add_node(Node* node) {

	if (!head) {head = node; return;}

	Node* cur_node = head;

	while (cur_node->get_next_node()) {

		cur_node = cur_node->get_next_node();
	}

	cur_node->set_next_node(node);
}

void List_Nodes::print_nodes() {

	Node * cur_node = head;
	while (cur_node) {
		cout << cur_node->get_node_value() << endl;
		cur_node = cur_node->get_next_node();
	}
}


void List_Nodes::reverse_nodes() {
	if (!head || !head->get_next_node()) return;

	Node* cur_node = head;
	Node* prev_node = nullptr;
	Node* next_node = nullptr;

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

	List_Nodes *list = new List_Nodes();

	Node *my_node = new Node("Первая нода");
	Node *my_second_node = new Node("Вторая нода");
	Node *my_third_node = new Node("Третья нода");
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
	return 0;
}