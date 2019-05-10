//
// Created by root on 19-4-24.
//

#ifndef CLION_KMP_H
#define CLION_KMP_H

#endif //CLION_KMP_H

#include <iostream>
#include <string.h>

using namespace std;

bool cmp_str(char *source, char *dest, int num);

void compute_indexValue(int *first, int index);

void compute_next(int *next, int length);

/*
 * source_string:
 * dest_string:
 * */
int kmp(char *source_string, char *dest_string);
