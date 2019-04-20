#pragma once
#define BinNodePosi BinNode<T>*
#define stature(p) ((p) ? (p)->height : -1) //节点高度


/******************************************************************************************
* BinNode状态与性质的判断
******************************************************************************************/
#define IsRoot(x) ( ! ( (x).parent ) )
#define IsLChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->lc ) )
#define IsRChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->rc ) )
#define HasParent(x) ( ! IsRoot(x) )
#define HasLChild(x) ( (x).lc )
#define HasRChild(x) ( (x).rc )
#define HasChild(x) ( HasLChild(x) || HasRChild(x) ) //至少拥有一个孩子
#define HasBothChild(x) ( HasLChild(x) && HasRChild(x) ) //同时拥有两个孩子
#define IsLeaf(x) ( ! HasChild(x) )

/******************************************************************************************
* 与BinNode具有特定关系的节点及指针
******************************************************************************************/
#define sibling(p) /*兄弟*/ \
   ( IsLChild( * (p) ) ? (p)->parent->rc : (p)->parent->lc )

#define uncle(x) /*叔叔*/ \
   ( IsLChild( * ( (x)->parent ) ) ? (x)->parent->parent->rc : (x)->parent->parent->lc )

#define FromParentTo(x) /*来自父亲的引用*/ \
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

	int size(); //统计当前节点后代总数，亦即以其为根的子树的规模
	BinNodePosi insertAsLC(T const&); //作为当前节点的左孩子插入新节点
	BinNodePosi insertAsRC(T const&); //作为当前节点的右孩子插入新节点
	BinNodePosi succ(); //取当前节点的直接后继

						// 比较器、判等器（各列其一，其余自行补充）
	bool operator< (BinNode const& bn) { return data < bn.data; } //小于
	bool operator== (BinNode const& bn) { return data == bn.data; } //等于
																	/*DSA*/
};

template <typename T> BinNodePosi BinNode<T>::insertAsLC(T const& e)
{
	return lc = new BinNode(e, this);
} //将e作为当前节点的左孩子插入二叉树

template <typename T> BinNodePosi BinNode<T>::insertAsRC(T const& e)
{
	return rc = new BinNode(e, this);
} //将e作为当前节点的右孩子插入二叉树

template <typename T> BinNodePosi BinNode<T>::succ() { //定位节点v的直接后继
	BinNodePosi s = this; //记录后继的临时变量
	if (rc) { //若有右孩子，则直接后继必在右子树中，具体地就是
		s = rc; //右子树中
		while (HasLChild(*s)) s = s->lc; //最靠左（最小）的节点
	}
	else { //否则，直接后继应是“将当前节点包含于其左子树中的最低祖先”，具体地就是
		while (IsRChild(*s)) s = s->parent; //逆向地沿右向分支，不断朝左上方移动
		s = s->parent; //最后再朝右上方移动一步，即抵达直接后继（如果存在）
	}
	return s;
}

template <typename T> int BinNode<T>::size() { //统计当前节点后代总数，即以其为根的子树规模
	int s = 1; //计入本身
	if (lc) s += lc->size(); //递归计入左子树规模
	if (rc) s += rc->size(); //递归计入右子树规模
	return s;
}


