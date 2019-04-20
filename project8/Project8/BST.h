#pragma once
#include "BinTree.h" //����BinTree

using namespace std;

#define EQUAL(e, v)  (!(v) || (e) == (v)->data) //�ڵ�v��������ͨ���ڱ����Ĺؼ������e
template <typename T> //����vΪ���ģ�AVL��SPLAY��rbTree�ȣ�BST�����в��ҹؼ���e
static BinNodePosi & searchIn(BinNodePosi & v, const T& e, BinNodePosi & hot) {
	if (EQUAL(e, v)) return v; hot = v; //�˻���������������ڵ�v������
	while (1) { //һ��أ��������ϵ�
		BinNodePosi & c = (e < hot->data) ? hot->lc : hot->rc; //ȷ�����뷽��
		if (EQUAL(e, c)) return c; hot = c; //���з��أ���������һ��
	} //hotʼ��ָ�����һ��ʧ�ܽڵ�
} //����ʱ������ֵָ�����нڵ㣨������ͨ���ڱ�����hotָ���丸�ף��˻�ʱΪ��ʼֵNULL��

template <typename T>
static BinNodePosi removeAt(BinNodePosi & x, BinNodePosi & hot) {
	BinNodePosi w = x; //ʵ�ʱ�ժ���Ľڵ㣬��ֵͬx
	BinNodePosi succ = NULL; //ʵ�ʱ�ɾ���ڵ�Ľ�����
	if (!HasLChild(*x)) //��*x��������Ϊ�գ����
		succ = x = x->rc; //ֱ�ӽ�*x�滻Ϊ��������
	else if (!HasRChild(*x)) //��������Ϊ�գ����
		succ = x = x->lc; //�ԳƵش�����ע�⣺��ʱsucc != NULL
	else { //���������������ڣ���ѡ��x��ֱ�Ӻ����Ϊʵ�ʱ�ժ���ڵ㣬Ϊ����Ҫ
		w = w->succ(); //�����������У��ҵ�*x��ֱ�Ӻ��*w
		swap(x->data, w->data); //����*x��*w������Ԫ��
		BinNodePosi u = w->parent;
		((u == x) ? u->rc : u->lc) = succ = w->rc; //����ڵ�*w
	}
	hot = w->parent; //��¼ʵ�ʱ�ɾ���ڵ�ĸ���
	if (succ) succ->parent = hot; //������ɾ���ڵ�Ľ�������hot����
	delete w; 
	return succ; //�ͷű�ժ���ڵ㣬���ؽ�����
}


template <typename T> class BST : public BinTree<T> { //��BinTree����BSTģ����
protected:
	BinNodePosi _hot; //�����С��ڵ�ĸ���
public: //�����ӿڣ���virtual���Σ�ǿ��Ҫ�����������ࣨBST���֣����ݸ��ԵĹ��������д
	virtual BinNodePosi & search(const T& e); //����
	virtual BinNodePosi insert(const T& e); //����
	virtual bool remove(const T& e); //ɾ��
	void inDisplay(BinNodePosi const& x);
	void preDisplay(BinNodePosi const& x);
	void inOrder() { inDisplay(_root); };
	void preOrder() { preDisplay(_root); };
};


template <typename T> BinNodePosi & BST<T>::search(const T& e) //��BST�в��ҹؼ���e
{
	return searchIn(_root, e, _hot = NULL);
} //����Ŀ��ڵ�λ�õ����ã��Ա�������롢ɾ������


template <typename T> BinNodePosi BST<T>::insert(const T& e) { //���ؼ���e����BST����
	BinNodePosi & x = search(e); if (x) return x; //ȷ��Ŀ�겻���ڣ������_hot�����ã�
	x = new BinNode<T>(e, _hot); //�����½ڵ�x����eΪ�ؼ��룬��_hotΪ��
	_size++; //����ȫ����ģ
	updateHeightAbove(x); //����x�����������ȵĸ߶�
	return x; //�²���Ľڵ㣬��ΪҶ��
} //����e�Ƿ������ԭ���У�����ʱ����x->data == e


template <typename T> bool BST<T>::remove(const T& e) { //��BST����ɾ���ؼ���e
	BinNodePosi & x = search(e); if (!x) return false; //ȷ��Ŀ����ڣ�����_hot�����ã�
	removeAt(x, _hot); _size--; //ʵʩɾ��
	updateHeightAbove(_hot); //����_hot�����������ȵĸ߶�
	return true;
} //ɾ���ɹ�����ɷ���ֵָʾ

template <typename T> void BST<T>::inDisplay(BinNodePosi const& x) {
	if (x == NULL) return;
	inDisplay(x->lc);
	printf("%d ", x->data);
	inDisplay(x->rc);
}

template <typename T> void BST<T>::preDisplay(BinNodePosi const& x) {
	if (x == NULL) return;
	printf("%d ", x->data); 
	preDisplay(x->lc);
	preDisplay(x->rc);
}