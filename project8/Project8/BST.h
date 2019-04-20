#pragma once
#include "BinTree.h" //引入BinTree

using namespace std;

#define EQUAL(e, v)  (!(v) || (e) == (v)->data) //节点v（或假想的通配哨兵）的关键码等于e
template <typename T> //在以v为根的（AVL、SPLAY、rbTree等）BST子树中查找关键码e
static BinNodePosi & searchIn(BinNodePosi & v, const T& e, BinNodePosi & hot) {
	if (EQUAL(e, v)) return v; hot = v; //退化情况：在子树根节点v处命中
	while (1) { //一般地，反复不断地
		BinNodePosi & c = (e < hot->data) ? hot->lc : hot->rc; //确定深入方向
		if (EQUAL(e, c)) return c; hot = c; //命中返回，或者深入一层
	} //hot始终指向最后一个失败节点
} //返回时，返回值指向命中节点（或假想的通配哨兵），hot指向其父亲（退化时为初始值NULL）

template <typename T>
static BinNodePosi removeAt(BinNodePosi & x, BinNodePosi & hot) {
	BinNodePosi w = x; //实际被摘除的节点，初值同x
	BinNodePosi succ = NULL; //实际被删除节点的接替者
	if (!HasLChild(*x)) //若*x的左子树为空，则可
		succ = x = x->rc; //直接将*x替换为其右子树
	else if (!HasRChild(*x)) //若右子树为空，则可
		succ = x = x->lc; //对称地处理——注意：此时succ != NULL
	else { //若左右子树均存在，则选择x的直接后继作为实际被摘除节点，为此需要
		w = w->succ(); //（在右子树中）找到*x的直接后继*w
		swap(x->data, w->data); //交换*x和*w的数据元素
		BinNodePosi u = w->parent;
		((u == x) ? u->rc : u->lc) = succ = w->rc; //隔离节点*w
	}
	hot = w->parent; //记录实际被删除节点的父亲
	if (succ) succ->parent = hot; //并将被删除节点的接替者与hot相联
	delete w; 
	return succ; //释放被摘除节点，返回接替者
}


template <typename T> class BST : public BinTree<T> { //由BinTree派生BST模板类
protected:
	BinNodePosi _hot; //“命中”节点的父亲
public: //基本接口：以virtual修饰，强制要求所有派生类（BST变种）根据各自的规则对其重写
	virtual BinNodePosi & search(const T& e); //查找
	virtual BinNodePosi insert(const T& e); //插入
	virtual bool remove(const T& e); //删除
	void inDisplay(BinNodePosi const& x);
	void preDisplay(BinNodePosi const& x);
	void inOrder() { inDisplay(_root); };
	void preOrder() { preDisplay(_root); };
};


template <typename T> BinNodePosi & BST<T>::search(const T& e) //在BST中查找关键码e
{
	return searchIn(_root, e, _hot = NULL);
} //返回目标节点位置的引用，以便后续插入、删除操作


template <typename T> BinNodePosi BST<T>::insert(const T& e) { //将关键码e插入BST树中
	BinNodePosi & x = search(e); if (x) return x; //确认目标不存在（留意对_hot的设置）
	x = new BinNode<T>(e, _hot); //创建新节点x：以e为关键码，以_hot为父
	_size++; //更新全树规模
	updateHeightAbove(x); //更新x及其历代祖先的高度
	return x; //新插入的节点，必为叶子
} //无论e是否存在于原树中，返回时总有x->data == e


template <typename T> bool BST<T>::remove(const T& e) { //从BST树中删除关键码e
	BinNodePosi & x = search(e); if (!x) return false; //确认目标存在（留意_hot的设置）
	removeAt(x, _hot); _size--; //实施删除
	updateHeightAbove(_hot); //更新_hot及其历代祖先的高度
	return true;
} //删除成功与否，由返回值指示

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