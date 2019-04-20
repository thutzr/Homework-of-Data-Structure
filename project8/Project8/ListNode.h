#pragma once
typedef int Rank;
#define ListNodePosi ListNode<T>*

template <typename T> struct ListNode {
	T data;
	ListNodePosi succ;
	ListNodePosi pred;

	ListNode() {};
	ListNode(T e, ListNodePosi p = NULL, ListNodePosi s = NULL) {
		data = e; pred = p; succ = s;
	};

	ListNodePosi InsertAsPred(T const& e);
	ListNodePosi InsertAsSucc(T const& e);

};


template <typename T> 
ListNodePosi ListNode<T>::InsertAsPred(T const& e) {
	ListNodePosi x = new ListNode(e, pred, this);
	pred->succ = x; pred = x;
	return x;
}

template <typename T>
ListNodePosi ListNode<T>::InsertAsSucc(T const& e) {
	ListNodePosi x = new ListNode(e, this, succ);
	succ->pred = x; succ = x;
	return x;
}