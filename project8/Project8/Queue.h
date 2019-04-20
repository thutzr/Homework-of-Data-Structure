#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <iostream>
#include <windows.h>
#include "List.h"


template <typename T> class Queue : public List<T> { //����������/ĩ����Ϊջ��/��
public: //size()��empty()�Լ��������Žӿڣ�����ֱ������
	void enqueue(T const& e) { insertAsLast(e); } //��ջ����Ч�ڽ���Ԫ����Ϊ������ĩԪ�ز���
	T dequeue() { return remove(first()); } //��ջ����Ч��ɾ����������Ԫ��
	T& front() { return first()->data; } //ȡ����ֱ�ӷ���������ĩԪ��
};
