#ifndef TEMPLATELIST_H
#define TEMPLATELIST_H
#include "memtrace.h"
/*Heterogen kollekcio megvalositasa*/
template <typename T>
/*Node class
*/
struct Node {
	T data;
	Node* next;
	~Node() {
		delete data;
	};
};
/*Lista class amely egy Node class tipusu elso elem, Head-et tarol
*/
template <typename T> class List {
	Node<T>* head;
public:
	List() { head = NULL; };
	/*Visszaadja a lista elso elemet
	*/
	Node<T>* get_head() {
		return head;
	}
	/*Hozzafuz egy uj node-ot a listahoz
	*/
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
	/*Visszaadja a lista meretet
	*/
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
	/*s-edik elemevel ter vissza a listanak
	@param size_t s
	return Typename T&
	*/
	T& get_data(size_t s) {
		size_t it = 0;
		Node<T>* iterator = head;
		while (iterator->next != NULL && it < s) {
			it++;
			iterator = iterator->next;
		}
		return iterator->data;
	}
	/*idx-edik elemevet eltavolitja a listabol
	@param size_t
	*/
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
	/*Lista destruktora, kitorli a Node-okat (Node-ok hivja meg a bennuk tarolt adatokra a destruktort)
	*/
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
