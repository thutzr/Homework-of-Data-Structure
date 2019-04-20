#pragma once
#include "ListNode.h"


template <typename T> class List {

private:
	ListNodePosi header;
	ListNodePosi tailer;
	int _size;

protected:
	void init();
	void clear();

public:
	Rank size() const { return _size; };
	bool empty() const { return _size<=0; };

	List() { init(); };
	~List() { clear(); delete header; delete tailer; }
	
	ListNodePosi first() { return header->succ; };
	ListNodePosi last() { return tailer->pred; };
	ListNodePosi insertAsFirst(T const& e);
	ListNodePosi insertAsLast(T const& e);
	ListNodePosi insertA(ListNodePosi p, T const& e);
	ListNodePosi insertB(ListNodePosi p, T const& e);
	ListNodePosi find(T const& e, Rank r, ListNodePosi p);
	ListNodePosi search(T const& e, Rank r, ListNodePosi p);

	void insertSort(ListNodePosi p, int n);
	void insertSort() { insertSort(header->succ, _size); };
	void selectSort(ListNodePosi p, int n);
	void selectSort() { selectSort(header->succ, _size); };
	ListNodePosi selectMax(ListNodePosi p, int n);

	T remove(ListNodePosi p);
	
	int deduplicate();
	int uniquify();

	template<typename VST> void traverse(VST& visit);

};
template <typename T>
ListNodePosi List<T>::selectMax(ListNodePosi p, int n) {
	T maxvalue = p->data;
	ListNodePosi max = p;
	for (int i = 1; i < n; i++) {
		p = p->succ;
		if (p->data >= maxvalue) {
			maxvalue = p->data;
			max = p;
		}
	}
	return max;
}

template <typename T>
void List<T>::selectSort(ListNodePosi p, int n) {
	ListNodePosi head = p->pred;
	ListNodePosi tail = p;
	for (int i = 0; i < n; i++) {
		tail = tail->succ;
	}
	while (n > 1) {
		ListNodePosi max = selectMax(head->succ, n);
		insertB(tail, remove(max));
		tail = tail->pred;
		n--;
	}
}

template <typename T>
void List<T>::insertSort(ListNodePosi p, int n) {
	for (int r = 0; r < n; r++) {
		insertA(search(p->data, r, p), p->data);
		p = p->succ;
		remove(p->pred);
	}
}


template <typename T>
ListNodePosi List<T>::find(T const& e, Rank n, ListNodePosi p) { 
	while (0 < n--) {
		if (e == ((p = p->pred)->data)) return p;
	}
	return NULL;
}

template <typename T>
ListNodePosi List<T>::search(T const& e, Rank n, ListNodePosi p) {
	while (0 <= n--) {
		if (((p = p->pred)->data) <= e) break;
	}
	return p;
}

template <typename T> 
int List<T>::deduplicate() {
	if (_size < 2)	return 0;
	int oldSize = _size;
	Rank r = 0;
	ListNodePosi p = header;
	while (tailer!=(p=p->succ)) {
		ListNodePosi q = find(p->data, r, p);
		q ? remove(q) : r++;
	}
	return oldSize - _size;
}

template <typename T>
int List<T>::uniquify() {
	if (_size < 2)	return 0;
	int oldSize = _size;
	Rank r = 0;
	ListNodePosi p = header->succ;
	while (tailer != (q = p->succ)) {
		if (q->data == p->data) remove(q);
		else p = q;
	}
	return oldSize - _size;
}

template <typename T> template<typename VST> 
void List<T>::traverse(VST& visit) {
	for (ListNodePosi p = header->succ; p != tailer; p = p->succ) {
		visit(p->data);
	}
}

template <typename T>
T List<T>::remove(ListNodePosi p) {
	T e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	_size--;
	return e;
}


template <typename T>
ListNodePosi List<T>::insertA(ListNodePosi p, T const& e) {
	_size++;
	return p->InsertAsSucc(e);
}

template <typename T>
ListNodePosi List<T>::insertB(ListNodePosi p, T const& e) {
	_size++;
	return p->InsertAsPred(e);
}

template <typename T>
ListNodePosi List<T>::insertAsFirst(T const& e) {
	_size++;
	return header->InsertAsSucc(e);
}

template <typename T>
ListNodePosi List<T>::insertAsLast(T const& e) {
	_size++;
	return tailer->InsertAsPred(e);
}

template <typename T>
void List<T>::init() {
	header = new ListNode<T>;
	tailer = new ListNode<T>;
	header->succ = tailer; header->pred = NULL;
	tailer->pred = header; tailer->succ = NULL;
	_size = 0;
}

template <typename T>
void List<T>::clear() {
	while (tailer->pred != header) {
		remove(tailer->pred);
	}
}

/*
template <typename T>
int List<T>::deduplicate() {
for (ListNodePosi p = trailer->pred; p != header; p = p->pred) {
if (ListNodePosi q = find(p->data, _size-1, p)) remove(q);
}
}
*/