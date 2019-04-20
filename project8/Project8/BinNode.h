#pragma once
#define BinNodePosi BinNode<T>*
#define stature(p) ((p) ? (p)->height : -1) //�ڵ�߶�


/******************************************************************************************
* BinNode״̬�����ʵ��ж�
******************************************************************************************/
#define IsRoot(x) ( ! ( (x).parent ) )
#define IsLChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->lc ) )
#define IsRChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->rc ) )
#define HasParent(x) ( ! IsRoot(x) )
#define HasLChild(x) ( (x).lc )
#define HasRChild(x) ( (x).rc )
#define HasChild(x) ( HasLChild(x) || HasRChild(x) ) //����ӵ��һ������
#define HasBothChild(x) ( HasLChild(x) && HasRChild(x) ) //ͬʱӵ����������
#define IsLeaf(x) ( ! HasChild(x) )

/******************************************************************************************
* ��BinNode�����ض���ϵ�Ľڵ㼰ָ��
******************************************************************************************/
#define sibling(p) /*�ֵ�*/ \
   ( IsLChild( * (p) ) ? (p)->parent->rc : (p)->parent->lc )

#define uncle(x) /*����*/ \
   ( IsLChild( * ( (x)->parent ) ) ? (x)->parent->parent->rc : (x)->parent->parent->lc )

#define FromParentTo(x) /*���Ը��׵�����*/ \
   ( IsRoot(x) ? _root : ( IsLChild(x) ? (x).parent->lc : (x).parent->rc ) )



template <typename T> struct BinNode {
	T data; 
	BinNodePosi parent; BinNodePosi lc; BinNodePosi rc; 
	int height; 

	BinNode() { parent = NULL; lc = NULL; rc = NULL; height = 0; }
	BinNode(T e, BinNodePosi p = NULL, BinNodePosi lc_ = NULL, BinNodePosi rc_ = NULL,
		int h = 0) {
		data = e; parent = p; lc = lc_; rc = rc_; height = h;
	}

	int size(); //ͳ�Ƶ�ǰ�ڵ����������༴����Ϊ���������Ĺ�ģ
	BinNodePosi insertAsLC(T const&); //��Ϊ��ǰ�ڵ�����Ӳ����½ڵ�
	BinNodePosi insertAsRC(T const&); //��Ϊ��ǰ�ڵ���Һ��Ӳ����½ڵ�
	BinNodePosi succ(); //ȡ��ǰ�ڵ��ֱ�Ӻ��

						// �Ƚ������е�����������һ���������в��䣩
	bool operator< (BinNode const& bn) { return data < bn.data; } //С��
	bool operator== (BinNode const& bn) { return data == bn.data; } //����
																	/*DSA*/
};

template <typename T> BinNodePosi BinNode<T>::insertAsLC(T const& e)
{
	return lc = new BinNode(e, this);
} //��e��Ϊ��ǰ�ڵ�����Ӳ��������

template <typename T> BinNodePosi BinNode<T>::insertAsRC(T const& e)
{
	return rc = new BinNode(e, this);
} //��e��Ϊ��ǰ�ڵ���Һ��Ӳ��������

template <typename T> BinNodePosi BinNode<T>::succ() { //��λ�ڵ�v��ֱ�Ӻ��
	BinNodePosi s = this; //��¼��̵���ʱ����
	if (rc) { //�����Һ��ӣ���ֱ�Ӻ�̱����������У�����ؾ���
		s = rc; //��������
		while (HasLChild(*s)) s = s->lc; //�����С���Ľڵ�
	}
	else { //����ֱ�Ӻ��Ӧ�ǡ�����ǰ�ڵ���������������е�������ȡ�������ؾ���
		while (IsRChild(*s)) s = s->parent; //������������֧�����ϳ����Ϸ��ƶ�
		s = s->parent; //����ٳ����Ϸ��ƶ�һ�������ִ�ֱ�Ӻ�̣�������ڣ�
	}
	return s;
}

template <typename T> int BinNode<T>::size() { //ͳ�Ƶ�ǰ�ڵ���������������Ϊ����������ģ
	int s = 1; //���뱾��
	if (lc) s += lc->size(); //�ݹ������������ģ
	if (rc) s += rc->size(); //�ݹ������������ģ
	return s;
}


