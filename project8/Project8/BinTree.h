#pragma once

#include "Queue.h" //引入二叉树节点类
#include "BinNode.h" //引入二叉树节点类

template <typename T> class BinTree { //二叉树模板类
protected:
	int _size; BinNodePosi _root; //规模、根节点
	virtual int updateHeight(BinNodePosi x); //更新节点x的高度
	void updateHeightAbove(BinNodePosi x); //更新节点x及其祖先的高度
public:
	BinTree() { _size = 0; _root = NULL; } //构造函数
	~BinTree() { if (0 < _size) remove(_root); } //析构函数
	int size() const { return _size; } //规模
	bool empty() const { return !_root; } //判空
	BinNodePosi root() const { return _root; } //树根
	BinNodePosi insertAsRoot(T const& e); //插入根节点
	BinNodePosi insertAsLC(BinNodePosi x, T const& e); //e作为x的左孩子（原无）插入
	BinNodePosi insertAsRC(BinNodePosi x, T const& e); //e作为x的右孩子（原无）插入
	BinNodePosi attachAsLC(BinNodePosi x, BinTree<T>* &T); //T作为x左子树接入
	BinNodePosi attachAsRC(BinNodePosi x, BinTree<T>* &T); //T作为x右子树接入
	int remove(BinNodePosi x); //删除以位置x处节点为根的子树，返回该子树原先的规模
	BinTree<T>* secede(BinNodePosi x); //将子树x从当前树中摘除，并将其转换为一棵独立子树
	
	template <typename VST> //操作器
	void travLevel(VST& visit) { if (_root) travLevel(_root, visit); } //层次遍历
	template <typename VST> //操作器
	void travLevel(BinNodePosi x, VST& visit);  //层次遍历

	template <typename VST> //操作器
	void travPre(VST& visit) { if (_root) travPre(_root,visit); } //先序遍历
	template <typename VST> //操作器
	void travPre(BinNodePosi x, VST& visit);

	template <typename VST> //操作器
	void travIn(VST& visit) { if (_root) travIn(_root,visit); } //中序遍历
	template <typename VST> //操作器
	void travIn(BinNodePosi x, VST& visit);

	template <typename VST> //操作器
	void travPost(VST& visit) { if (_root) travPost(_root, visit); } //中序遍历
	template <typename VST> //操作器
	void travPost(BinNodePosi x, VST& visit);

	bool operator< (BinTree<T> const& t) //比较器（其余自行补充）
	{
		return _root && t._root && lt(_root, t._root);
	}
	bool operator== (BinTree<T> const& t) //判等器
	{
		return _root && t._root && (_root == t._root);
	}
}; //BinTree


template <typename T> template <typename VST> //元素类型、操作器
void BinTree<T>::travIn(BinNodePosi x, VST& visit) { //二叉树中序遍历算法（递归版）
	if (!x) return;
	travIn(x->lc, visit);
	visit(x->data);
	travIn(x->rc, visit);
}


template <typename T> template <typename VST> //元素类型、操作器
void BinTree<T>::travPre(BinNodePosi x, VST& visit) { //二叉树中序遍历算法（递归版）
	if (!x) return;
	visit(x->data);
	travPre(x->lc, visit);
	travPre(x->rc, visit);
}

template <typename T> template <typename VST> //元素类型、操作器
void BinTree<T>::travPost(BinNodePosi x, VST& visit) { //二叉树中序遍历算法（递归版）
	if (!x) return;
	travPost(x->lc, visit);
	travPost(x->rc, visit);
	visit(x->data);
}

template <typename T> template <typename VST> //元素类型、操作器
void BinTree<T>::travLevel(BinNodePosi x, VST& visit) { //二叉树层次遍历算法
	Queue<BinNodePosi> Q; //辅助队列
	Q.enqueue(x); //根节点入队
	while (!Q.empty()) { //在队列再次变空之前，反复迭代
		BinNodePosi p = Q.dequeue(); visit(p->data); //取出队首节点并访问之
		if (HasLChild(*p)) Q.enqueue(p->lc); //左孩子入队
		if (HasRChild(*p)) Q.enqueue(p->rc); //右孩子入队
	}
}

template <typename T> BinNodePosi BinTree<T>::insertAsRoot(T const& e)
{
	_size = 1; return _root = new BinNode<T>(e);
};

template <typename T> BinNodePosi BinTree<T>::insertAsLC(BinNodePosi x, T const& e)
{
	_size++; x->insertAsLC(e); updateHeightAbove(x); return x->lc;
};

template <typename T> BinNodePosi BinTree<T>::insertAsRC(BinNodePosi x, T const& e)
{
	_size++; x->insertAsRC(e); updateHeightAbove(x); return x->rc;
};

template <typename T> //二叉树子树接入算法：将S当作节点x的左子树接入，S本身置空
BinNodePosi BinTree<T>::attachAsLC(BinNodePosi x, BinTree<T>* &S) { //x->lc == NULL
	if (x->lc = S->_root) x->lc->parent = x; //接入
	_size += S->_size; updateHeightAbove(x); //更新全树规模与x所有祖先的高度
	S->_root = NULL; S->_size = 0; release(S); S = NULL; return x; //释放原树，返回接入位置
};

template <typename T> //二叉树子树接入算法：将S当作节点x的右子树接入，S本身置空
BinNodePosi BinTree<T>::attachAsRC(BinNodePosi x, BinTree<T>* &S) { //x->rc == NULL
	if (x->rc = S->_root) x->rc->parent = x; //接入
	_size += S->_size; updateHeightAbove(x); //更新全树规模与x所有祖先的高度
	S->_root = NULL; S->_size = 0; release(S); S = NULL; return x; //释放原树，返回接入位置
};


template <typename T> int BinTree<T>::updateHeight(BinNodePosi x) //更新节点x高度
{
	int a = stature(x->lc);
	int b = stature(x->rc);
	if (a < b) a = b;
	return x->height = 1 + a;
	//return x->height = 1 + max ( stature ( x->lc ), stature ( x->rc ) ); 
};
template <typename T> void BinTree<T>::updateHeightAbove(BinNodePosi x) //更新高度
{
	while (x) { updateHeight(x); x = x->parent; }
};

template <typename T> //二叉树子树分离算法：将子树x从当前树中摘除，将其封装为一棵独立子树返回
BinTree<T>* BinTree<T>::secede(BinNodePosi x) { //assert: x为二叉树中的合法位置
	FromParentTo(*x) = NULL; //切断来自父节点的指针
	updateHeightAbove(x->parent); //更新原树中所有祖先的高度
	BinTree<T>* S = new BinTree<T>; S->_root = x; x->parent = NULL; //新树以x为根
	S->_size = x->size(); _size -= S->_size; return S; //更新规模，返回分离出来的子树
}

template <typename T> //删除二叉树中位置x处的节点及其后代，返回被删除节点的数值
int BinTree<T>::remove(BinNodePosi x) { //assert: x为二叉树中的合法位置
	FromParentTo(*x) = NULL; //切断来自父节点的指针
	updateHeightAbove(x->parent); //更新祖先高度
	int n = removeAt(x); _size -= n; return n; //删除子树x，更新规模，返回删除节点总数
}
template <typename T> //删除二叉树中位置x处的节点及其后代，返回被删除节点的数值
static int removeAt(BinNodePosi x) { //assert: x为二叉树中的合法位置
	if (!x) return 0; //递归基：空树
	int n = 1 + removeAt(x->lc) + removeAt(x->rc); //递归释放左、右子树
	delete(x); 
	return n; //释放被摘除节点，并返回删除节点总数
}