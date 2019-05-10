//
// Created by root on 19-4-23.
//

#include "cyclelist.h"


CycleList::CycleList(int size) {
    this->m_size = size;
    this->m_real_ptr = this->m_head_ptr = new Element_t;
    this->m_head_ptr->data = null;
    this->m_head_ptr->next = this->m_head_ptr;
}

CycleList::~CycleList() {
    this->destroyed();
}


bool CycleList::appendElement(void *ele) {
    this->m_real_ptr = this->m_real_ptr->next = new Element_t;
    if (!m_real_ptr) {
        return false;
    }

    m_real_ptr->next = m_head_ptr;
    m_real_ptr->data = malloc(this->m_size);
    memcpy(m_real_ptr->data, ele, m_size);

    return true;
}


void CycleList::travelList(func_t callback) {
    Element_t *temp_ptr = m_head_ptr->next;
    while (temp_ptr != m_head_ptr) {
        callback(temp_ptr->data);
        temp_ptr = temp_ptr->next;
    }
}

//自定义比较函数 判断是否为应该删除的结点
bool CycleList::deleteData(cmpFunc_t callback, void *destdata) {
    Element_t *temp_ptr = m_head_ptr->next;
    Element_t *prev = m_head_ptr;
    while (temp_ptr != m_head_ptr) {
        if (callback(temp_ptr->data, destdata)) {
            this->deleteElement(prev, prev->next);
            return true;
        }
        prev = temp_ptr;
        temp_ptr = temp_ptr->next;
    }

    return false;
}

void CycleList::destroyed() {
    Element_t *prev_ptr = this->getHead();
    Element_t *temp_ptr = this->getHead()->next;
    while (!this->isEmpty()) {
        this->deleteElement(prev_ptr, temp_ptr);
        prev_ptr = temp_ptr;
        temp_ptr = temp_ptr->next;
    }
}


bool CycleList::deleteElement(Element_t *prev, Element_t *element) {
    prev->next = element->next;
    free(element->data);
    free(element);
    return true;
}


bool CycleList::isEmpty() {
    Element_t *head = this->getHead();
    if (head->next == head) {
        return true;
    }
    return false;
}


Element *CycleList::getHead() {
    return this->m_head_ptr;
}

void CycleList::add_event(Ievent *event) {
    this->events.push_back(event);
}

void CycleList::doprocess(int value) {
    for(auto &event : this->events){
        event->doprocess(value);
    }
}
