#include "joseph.h"


Joseph::Joseph(int size, int m) : CycleList(size) {
    this->m_m = m;
    this->m_prev = this->m_start = null;
}


int Joseph::deleteForm(int m, func_t callback) {
    Element *prev = this->m_prev;
    Element *temp_ptr = this->m_start;
    for (int i = 2; i <= m; i++) {
        if (temp_ptr->next == this->getHead()) {
            prev = temp_ptr;
            temp_ptr = temp_ptr->next;
        }
        prev = temp_ptr;
        temp_ptr = temp_ptr->next;
    }
    int passwd = ((JosephData_t *) (temp_ptr->data))->passwd;
    int deleteId = ((JosephData_t *) (temp_ptr->data))->id;

    this->m_prev = prev;    //保存出列那个人的上一个人地址
    this->m_start = temp_ptr->next; //保存下个人
    if (m_start == this->getHead()) {
        m_start = m_start->next;
    }

    this->deleteElement(prev, temp_ptr);
    //显示过程
    this->showProcess(deleteId, callback);
    return passwd;
}


void Joseph::killAll(func_t callback) {
    int passwd = this->m_m;
    this->m_prev = this->getHead();
    this->m_start = m_prev->next;
    while (!this->isEmpty()) {
        passwd = this->deleteForm(passwd, callback);
    }
}

void Joseph::showProcess(int deleteId, func_t callback) {
    cout << "出列 ： " << deleteId << " ,剩下 ：";
    //遍历打印剩下的元素
    this->travelList(callback);
    cout << endl;
}



