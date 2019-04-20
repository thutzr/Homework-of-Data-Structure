#pragma once

#include "Queue.h" //����������ڵ���
#include "BinNode.h" //����������ڵ���

template <typename T> class BinTree { //������ģ����
protected:
	int _size; BinNodePosi _root; //��ģ�����ڵ�
	virtual int updateHeight(BinNodePosi x); //���½ڵ�x�ĸ߶�
	void updateHeightAbove(BinNodePosi x); //���½ڵ�x�������ȵĸ߶�
public:
	BinTree() { _size = 0; _root = NULL; } //���캯��
	~BinTree() { if (0 < _size) remove(_root); } //��������
	int size() const { return _size; } //��ģ
	bool empty() const { return !_root; } //�п�
	BinNodePosi root() const { return _root; } //����
	BinNodePosi insertAsRoot(T const& e); //������ڵ�
	BinNodePosi insertAsLC(BinNodePosi x, T const& e); //e��Ϊx�����ӣ�ԭ�ޣ�����
	BinNodePosi insertAsRC(BinNodePosi x, T const& e); //e��Ϊx���Һ��ӣ�ԭ�ޣ�����
	BinNodePosi attachAsLC(BinNodePosi x, BinTree<T>* &T); //T��Ϊx����������
	BinNodePosi attachAsRC(BinNodePosi x, BinTree<T>* &T); //T��Ϊx����������
	int remove(BinNodePosi x); //ɾ����λ��x���ڵ�Ϊ�������������ظ�����ԭ�ȵĹ�ģ
	BinTree<T>* secede(BinNodePosi x); //������x�ӵ�ǰ����ժ����������ת��Ϊһ�ö�������
	
	template <typename VST> //������
	void travLevel(VST& visit) { if (_root) travLevel(_root, visit); } //��α���
	template <typename VST> //������
	void travLevel(BinNodePosi x, VST& visit);  //��α���

	template <typename VST> //������
	void travPre(VST& visit) { if (_root) travPre(_root,visit); } //�������
	template <typename VST> //������
	void travPre(BinNodePosi x, VST& visit);

	template <typename VST> //������
	void travIn(VST& visit) { if (_root) travIn(_root,visit); } //�������
	template <typename VST> //������
	void travIn(BinNodePosi x, VST& visit);

	template <typename VST> //������
	void travPost(VST& visit) { if (_root) travPost(_root, visit); } //�������
	template <typename VST> //������
	void travPost(BinNodePosi x, VST& visit);

	bool operator< (BinTree<T> const& t) //�Ƚ������������в��䣩
	{
		return _root && t._root && lt(_root, t._root);
	}
	bool operator== (BinTree<T> const& t) //�е���
	{
		return _root && t._root && (_root == t._root);
	}
}; //BinTree


template <typename T> template <typename VST> //Ԫ�����͡�������
void BinTree<T>::travIn(BinNodePosi x, VST& visit) { //��������������㷨���ݹ�棩
	if (!x) return;
	travIn(x->lc, visit);
	visit(x->data);
	travIn(x->rc, visit);
}


template <typename T> template <typename VST> //Ԫ�����͡�������
void BinTree<T>::travPre(BinNodePosi x, VST& visit) { //��������������㷨���ݹ�棩
	if (!x) return;
	visit(x->data);
	travPre(x->lc, visit);
	travPre(x->rc, visit);
}

template <typename T> template <typename VST> //Ԫ�����͡�������
void BinTree<T>::travPost(BinNodePosi x, VST& visit) { //��������������㷨���ݹ�棩
	if (!x) return;
	travPost(x->lc, visit);
	travPost(x->rc, visit);
	visit(x->data);
}

template <typename T> template <typename VST> //Ԫ�����͡�������
void BinTree<T>::travLevel(BinNodePosi x, VST& visit) { //��������α����㷨
	Queue<BinNodePosi> Q; //��������
	Q.enqueue(x); //���ڵ����
	while (!Q.empty()) { //�ڶ����ٴα��֮ǰ����������
		BinNodePosi p = Q.dequeue(); visit(p->data); //ȡ�����׽ڵ㲢����֮
		if (HasLChild(*p)) Q.enqueue(p->lc); //�������
		if (HasRChild(*p)) Q.enqueue(p->rc); //�Һ������
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

template <typename T> //���������������㷨����S�����ڵ�x�����������룬S�����ÿ�
BinNodePosi BinTree<T>::attachAsLC(BinNodePosi x, BinTree<T>* &S) { //x->lc == NULL
	if (x->lc = S->_root) x->lc->parent = x; //����
	_size += S->_size; updateHeightAbove(x); //����ȫ����ģ��x�������ȵĸ߶�
	S->_root = NULL; S->_size = 0; release(S); S = NULL; return x; //�ͷ�ԭ�������ؽ���λ��
};

template <typename T> //���������������㷨����S�����ڵ�x�����������룬S�����ÿ�
BinNodePosi BinTree<T>::attachAsRC(BinNodePosi x, BinTree<T>* &S) { //x->rc == NULL
	if (x->rc = S->_root) x->rc->parent = x; //����
	_size += S->_size; updateHeightAbove(x); //����ȫ����ģ��x�������ȵĸ߶�
	S->_root = NULL; S->_size = 0; release(S); S = NULL; return x; //�ͷ�ԭ�������ؽ���λ��
};


template <typename T> int BinTree<T>::updateHeight(BinNodePosi x) //���½ڵ�x�߶�
{
	int a = stature(x->lc);
	int b = stature(x->rc);
	if (a < b) a = b;
	return x->height = 1 + a;
	//return x->height = 1 + max ( stature ( x->lc ), stature ( x->rc ) ); 
};
template <typename T> void BinTree<T>::updateHeightAbove(BinNodePosi x) //���¸߶�
{
	while (x) { updateHeight(x); x = x->parent; }
};

template <typename T> //���������������㷨��������x�ӵ�ǰ����ժ���������װΪһ�ö�����������
BinTree<T>* BinTree<T>::secede(BinNodePosi x) { //assert: xΪ�������еĺϷ�λ��
	FromParentTo(*x) = NULL; //�ж����Ը��ڵ��ָ��
	updateHeightAbove(x->parent); //����ԭ�����������ȵĸ߶�
	BinTree<T>* S = new BinTree<T>; S->_root = x; x->parent = NULL; //������xΪ��
	S->_size = x->size(); _size -= S->_size; return S; //���¹�ģ�����ط������������
}

template <typename T> //ɾ����������λ��x���Ľڵ㼰���������ر�ɾ���ڵ����ֵ
int BinTree<T>::remove(BinNodePosi x) { //assert: xΪ�������еĺϷ�λ��
	FromParentTo(*x) = NULL; //�ж����Ը��ڵ��ָ��
	updateHeightAbove(x->parent); //�������ȸ߶�
	int n = removeAt(x); _size -= n; return n; //ɾ������x�����¹�ģ������ɾ���ڵ�����
}
template <typename T> //ɾ����������λ��x���Ľڵ㼰���������ر�ɾ���ڵ����ֵ
static int removeAt(BinNodePosi x) { //assert: xΪ�������еĺϷ�λ��
	if (!x) return 0; //�ݹ��������
	int n = 1 + removeAt(x->lc) + removeAt(x->rc); //�ݹ��ͷ���������
	delete(x); 
	return n; //�ͷű�ժ���ڵ㣬������ɾ���ڵ�����
}