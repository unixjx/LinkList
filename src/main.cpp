#include "joseph.h"
#include "kmp.h"

//遍历循环链表的回调函数
void callback(void *data) {
    cout << "" << *(int *) data << " ";
}

//测试约瑟夫环
void test_Joseph() {
    Joseph loop(sizeof(JosephData_t), 20);
    JosephData_t array[7] = {
            [0] = {1, 3}, //测试数据
            [1] = {2, 1},
            [2] = {3, 7},
            [3] = {4, 2},
            [4] = {5, 4},
            [5] = {6, 8},
            [6] = {7, 4}};

    for (int i = 0; i <= 6; i++) {
        if (!loop.appendElement(array + i)) {
            cout << "error in appendElement\n";
        }
    }
    loop.killAll(callback);

}

// 测试kmp
void test_kmp() {
    char source[] = "aaaacbb";  //PARTICIPATE IN PARACHUTE
    char dest[] = "aaac";   //-1 0 1 1

    int index = kmp(source, dest);
    cout << endl << "index: " << index << endl;
}

int main(int argc, char **argv) {
    test_kmp();
    return 0;
}
