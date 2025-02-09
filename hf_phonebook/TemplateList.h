#ifndef TEMPLATELIST_H
#define TEMPLATELIST_H

#include "memtrace.h"
#include "cstddef"
/*Heterogen kollekcio megvalositasa*/
template <typename T>
/** \Node class
*/
struct Node {
	T data;
	Node* next;
	~Node() {
		delete data;
	};
};
/** \Lista class amely egy Node class tipusu elso elem, Head-et tarol
*/
template <typename T> class List {
	Node<T>* head;
public:
	List() : head(0) {};

	/**
	Hozzaad minden elemet egy masik listabol es meghivja a copy konstruktort minden elemre
	*/
	void addAll(const List<T>* l) {
		for (Node<T>* it = l->head; it != 0; it = it->next) {
			add(it->data);
		}
	}

	/** \Visszaadja a lista elso elemet
	*/
	Node<T>* get_head() {
		return head;
	}
	/** \Hozzafuz egy uj node-ot a listahoz
	* \param Typename T&
	*/
	void add(const T new_data) {
		Node<T>* n = new Node<T>();
		n->data = new_data;
		n->next = 0;

		if (head == 0) {
			head = n;
		}
		else {
			Node<T>* iterator = head;
			while (iterator->next != 0) {
				iterator = iterator->next;
			}
			iterator->next = n;
		}
	}
	/** \Visszaadja a lista meretet
	* \return size_t
	*/
	size_t get_size() {
		size_t size = 0;
		if (this->head == 0) {
			return size;
		}
		size++;
		Node<T>* iterator = head;
		while (iterator->next != 0) {
			size++;
			iterator = iterator->next;
		}
		return size;
	}
	/** \s-edik elemevel ter vissza a listanak
	* \param size_t
	* \return Typename T&
	*/
	T& get_data(const size_t s) {
		size_t it = 0;
		Node<T>* iterator = head;
		while (iterator->next != 0 && it < s) {
			it++;
			iterator = iterator->next;
		}
		return iterator->data;
	}
	/** \idx-edik elemevet eltavolitja a listabol
	* \param size_t
	*/
	void remove_from_list(const size_t idx) {
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
	/** \Lista destruktora, kitorli a Node-okat (Node-ok hivja meg a bennuk tarolt adatokra a destruktort)
	*/
	~List() {
		Node<T>* iterator = head;
		Node<T>* tmp;
		if (iterator != 0) {
			if (iterator->next == 0) {
				delete head;
			}
			else {
				while (iterator->next != 0) {
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
