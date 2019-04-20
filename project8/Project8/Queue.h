#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <iostream>
#include <windows.h>
#include "List.h"


template <typename T> class Queue : public List<T> { //将向量的首/末端作为栈底/顶
public: //size()、empty()以及其它开放接口，均可直接沿用
	void enqueue(T const& e) { insertAsLast(e); } //入栈：等效于将新元素作为向量的末元素插入
	T dequeue() { return remove(first()); } //出栈：等效于删除向量的首元素
	T& front() { return first()->data; } //取顶：直接返回向量的末元素
};
