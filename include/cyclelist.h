//
// Created by root on 19-4-23.
//

#ifndef CLION_CYCLELIST_H
#define CLION_CYCLELIST_H

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <list>

using namespace std;
#define  null NULL

typedef void (*func_t)(void *);

typedef bool (*cmpFunc_t)(void *, void *);

typedef struct Element {
    struct Element *next;
    void *data; //指向存储数据首地址 实现数据万能型 不使用c++模板
} Element_t;

/**********/

class Ievent {
public:
    virtual void doprocess(int) = 0;

    virtual ~Ievent(){}
};

/**********/

class CycleList: Ievent{
public :
    CycleList(int size);

    virtual ~CycleList();
    void virtual doprocess(int);

    void travelList(func_t callback);   //遍历单循环链表
    bool appendElement(void *element);

    bool deleteData(cmpFunc_t callback, void *destdata); //指定某个数据删除，由回调函数决定
    void add_event(Ievent *);

protected:
    bool deleteElement(Element *prev, Element_t *element);

    void destroyed();

    bool isEmpty();

    Element *getHead();


private :
    int m_size; //struct size
    Element_t *m_head_ptr; //
    Element_t *m_real_ptr; //
    list<Ievent* > events;
};


#endif //CLION_CYCLELIST_H
