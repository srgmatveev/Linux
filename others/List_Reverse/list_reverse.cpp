#include <iostream>
#include "list_reverse.hpp"
#include <locale>


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
void List_Nodes<T>::print_unicode_nodes() {

	Node<T> * cur_node = head;
	while (cur_node) {
		wcout << cur_node->get_node_value() << endl;
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

template <class T>
Node<T>* List_Nodes<T>::get_head() {
	return this->head;
}

template <class T>
void List_Nodes<T>::set_head(Node<T>* head) {
	if (head) this->head = head;
}

template <class T>
void List_Nodes<T>::reverse_nodes_recursively(Node<T>* first, Node<T>* prev) {
	if (!first) return;

	if (!first->get_next_node()) {
		head = first;
		first->set_next_node(prev);
		return;
	}

	
	Node<T>* next = first->get_next_node();
	first->set_next_node(prev);

	reverse_nodes_recursively(next, first);

}

int main(int argc, char const *argv[])
{
	std::locale current_locale("");
	std::locale::global(current_locale);
	std::ios::sync_with_stdio(false);


	List_Nodes<std::string> *list = new List_Nodes<std::string>();

	Node<std::string> *my_node = new Node<std::string>("Первая нода");
	//Node<std::string> *my_second_node = new Node<std::string>("Вторая нода");
	//Node<std::string> *my_third_node = new Node<std::string>("Третья нода");
	//Node<std::string> *my_fourth_node = new Node<std::string>("Четвертая нода");
	list->add_node(my_node);
	//list->add_node(my_second_node);
	//list->add_node(my_third_node);
	//list->add_node(my_fourth_node);
	cout << "=========reverse_beg=========\n";
	list->reverse_nodes_recursively(list->get_head());
	cout << "=========reverse_end=========\n";
	//cout<<list->get_head()->get_node_value()<<endl;
	//list->print_nodes();
	/*
	list->reverse_nodes();
	cout << "========================\n";
	list->print_nodes();
	list->reverse_nodes();
	cout << "========================\n";
	list->print_nodes();
	cout << "========================\n";
	*/
	if (list) { delete list;}
	/*
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




		List_Nodes<char*> *list_chars = new List_Nodes<char*>();
		char s1[] = "first";
		char s2[] = "second";
		char s3[] = "Thirs stringers";
		Node<char*> *my_node_char = new Node<char*>(s1);
		Node<char*> *my_second_node_char = new Node<char*>(s2);
		Node<char*> *my_third_node_char = new Node<char*>(s3);
		list_chars->add_node(my_node_char);
		list_chars->add_node(my_second_node_char);
		list_chars->add_node(my_third_node_char);
		list_chars->print_nodes();
		cout << "========================\n";
		list_chars->reverse_nodes();
		list_chars->print_nodes();
		if (list_chars) delete list_chars;
		cout << "========================\n";


		List_Nodes<wchar_t*> *list_wchars = new List_Nodes<wchar_t*>();

		wchar_t w_s1[] = L"Первая";
		wchar_t w_s2[] = L"Вторая строка";
		wchar_t w_s3[] = L"Третья строчка";

		Node<wchar_t*> *my_node_wchar = new Node<wchar_t*>(w_s1);
		Node<wchar_t*> *my_second_node_wchar = new Node<wchar_t*>(w_s2);
		Node<wchar_t*> *my_third_node_wchar = new Node<wchar_t*>(w_s3);

		list_wchars->add_node(my_node_wchar);
		list_wchars->add_node(my_second_node_wchar);
		list_wchars->add_node(my_third_node_wchar);
		wcout << L"^========================^\n";
		list_wchars->print_unicode_nodes();
		wcout << L"^========================^\n";
		list_wchars->reverse_nodes();
		list_wchars->print_unicode_nodes();
		if (list_wchars) delete list_wchars;
	*/
	return 0;
}