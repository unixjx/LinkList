#include "cyclelist.h"


typedef struct JosephData   //约瑟夫环每个结点的元素数据
{
    int id;
    int passwd;
} JosephData_t;

class Joseph : public CycleList {
public :
    Joseph(int size, int m); //m为初值
    void killAll(func_t callback);     //从开始直到全部人退出
protected:
    int deleteForm(int m, func_t callback);  //让第m个出列全,返回取出的密码
    void showProcess(int, func_t);

private :
    int m_m;
    Element_t *m_start;
    Element_t *m_prev;
};
