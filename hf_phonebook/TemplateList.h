#ifndef TEMPLATELIST_H
#define TEMPLATELIST_H
#include "memtrace.h"
template <typename T>
struct Node {
	T data;
	Node* next;
	~Node() {
		delete data;
	};
};
template <typename T> class List {
	Node<T>* head;
public:
	List() { head = NULL; };
	Node<T>* get_head() {
		return head;
	}
	void add(T new_data) {
		Node<T>* n = new Node<T>();
		n->data = new_data;
		n->next = NULL;

		if (head == NULL) {
			head = n;
		}
		else {
			Node<T>* iterator = head;
			while (iterator->next != NULL) {
				iterator = iterator->next;
			}
			iterator->next = n;
		}
	}
	size_t get_size() {
		size_t size = 0;
		if (head == NULL) {
			return size;
		}
		size++;
		Node<T>* iterator = head;
		while (iterator->next != NULL) {
			size++;
			iterator = iterator->next;
		}
		return size;
	}
	T& get_data(size_t s) {
		size_t it = 0;
		Node<T>* iterator = head;
		while (iterator->next != NULL && it < s) {
			it++;
			iterator = iterator->next;
		}
		return iterator->data;
	}
	void remove_from_list(size_t idx) {
		Node<T>* it = head;

		// Ha a headet toroljuk
		if (idx == 0) {
			head = head->next;
			delete(it);
			return;
		}

		// Ha a mereten tul torlunk
		if (idx >= get_size()) {
			throw "Index out of range";
		}

		for (size_t i = 0; i < idx; i++, it = it->next)
		{
			// Ha megvan az elozo elem
			if (i == idx - 1) {
				Node<T>* temp = it->next;
				it->next = it->next->next;
				delete(temp);
				return;
			}
		}
	};
	~List() {
		Node<T>* iterator = head;
		Node<T>* tmp;
		if (iterator != NULL) {
			if (iterator->next == NULL) {
				delete head;
			}
			else {
				while (iterator->next != NULL) {
					tmp = iterator;
					iterator = iterator->next;
					delete tmp;
				}
				delete iterator;
			}
		}
	}
};
#endif // !TEMPLATELIST_H
