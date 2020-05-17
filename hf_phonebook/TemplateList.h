#ifndef TEMPLATELIST_H
#define TEMPLATELIST_H
template <typename T>
struct Node {
	T data;
	Node* next;
};
template <typename T> class List {
	Node<T>* head;
public:
	List() { head = NULL; };
	void add(T new_data) {

		Node<T>* n = new Node<T>();
		n->data = new_data;
		n->next = NULL;

		if (head == NULL) {
			head = n;
		}else{
			Node<T>* iterator = head;
			while (iterator->next != NULL) {
				iterator = iterator->next;
			}
			iterator->next = n;
		}
		
	}
	size_t get_size() const{
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
	T& get_data(size_t s) const {
		size_t it = 0;
		Node<T>* iterator = head;
		while (iterator->next != NULL && it < s) {
			it++;
			iterator = iterator->next;
		}
		return iterator->data;
	}
	T* get_for_edit(size_t s) {  //ut�na k�ne j�rni sz�ks�ges-e
		size_t it = 0;
		Node<T>* iterator = head;
		while (iterator->next != NULL && it < s) {
			it++;
			iterator = iterator->next;
		}
		return iterator->data;
	};
	Node<T>* get_data_and_remove_from_list(size_t s) {
		size_t it = 0;
		Node<T>* iterator = head;
		Node<T>* tmp;
		if (s == 0) {
			tmp = head;
			head = iterator->next;
			return tmp;
		}
		else {
			while (iterator->next != NULL && it < (s-1)) {
				it++;
				iterator = iterator->next;
			}
			tmp = iterator->next;
			iterator->next = tmp->next;
			return tmp;
		}
	
	};
};
#endif // !TEMPLATELIST_H
