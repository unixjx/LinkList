#include "kmp.h"

#define CORRECT

bool cmp_str(const char *source, const char *dest, int num) {
    for (int i = 0; i < num; i++) {
        if (source[i] != dest[i]) {
            return false;
        }
    }
    return true;
}

#ifdef CORRECT

void compute_indexValue(const char *dest_string, int *first, int index) {
    int prefix_end = index - 2; //--
    int suffix_start = 1;   //++
    for (; prefix_end >= 0; prefix_end--, suffix_start++) {
        int num = prefix_end + 1;  // 代表前后缀的长度
        if (cmp_str(dest_string, dest_string + suffix_start, num)) {
            first[index] = num;
            return;
        }
    }
    first[index] = 0;
}

#else
void compute_indexValue(const char * dest_string, int * first, int index)
{
    int length = index + 1;
    int mid_index = length/2;
    int i = 0;
    int j = 0;
    int value = 0;
    //mid_index=3 index=5 i=2 j=0
    for(i = mid_index, j = 0; i < index; i++)
    {
        if (dest_string[i] == dest_string[j])   {
            value++;
        }else {
        value = 0;
        j = 0;
        continue;
        }
        j++;
    }

    first[index] = value;
}
#endif


/*
		0	1	2	3	4	5	6
		A	B	C	D	A	B	D
		-1	0	0	0	0	1	2
*/
void compute_next(char *dest_string, int *next, int length) {
    int i = 0;
    next[0] = -1;
    next[1] = 0;
    for (i = 2; i < length; i++) {
        compute_indexValue(dest_string, next, i);
    }
    for (int i = 0; i < length; i++) {
        cout << next[i] << " ";
    }
}


/*
 * 返回索引
 * */
int kmp(char *source_string, char *dest_string) {
    int souce_len = strlen(source_string);
    int dest_len = strlen(dest_string);
    int *next = new int[dest_len];  //匹配表
    int i, j;
    compute_next(dest_string, next, dest_len);

    // 如果模式串大于源串
    if (dest_len > souce_len) {
        return -1;
    }

    for (j = i = 0; i < souce_len && j < dest_len;) {
        // 如果待cmp的源串小于模式串直接退出
        if (souce_len - i < dest_len - j) {
            return -1;
        }

        if (source_string[i] != dest_string[j]) {
            if (next[j] != -1) {
                j = next[j];            //ABC ABCDAB ABCDABCDABDE   aaaacbb
                // TODO
            } else {
                j = 0;                  //ABCDABD   baaac
                i++;
                continue;
            }
            //i保持原位不动
            continue;
        }
        i++;
        j++;
    }

//    cout<<i<<" "<<j<<endl;
    if ((source_string[i - 1] == dest_string[j - 1]) && (j - dest_len == 0)) {
        return i - dest_len;
    }
    return -1;
}
