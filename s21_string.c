#include <stdio.h>
#include <string.h>

#define s21_size_t unsigned long long
#define s21_NULL (void*)0

void* s21_memchr(const void* str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);

int main()
{
    char ar1[] = "Negodyaj";
    char ar2[] = "Negozordec";

    printf("++%d++\n", s21_memcmp(ar1, ar2, 4));
    printf("--%d--\n", memcmp(ar1, ar2, 4));

    return 0;
}

void* s21_memchr(const void* str, int c, size_t n){
    void* res = s21_NULL;
    const char* ptr = str;

    for (s21_size_t i = 0; i < n; i++){
        if(ptr[i] == c){
            res = (void*)(ptr + i);
            break;
        }
    }
    return res;
}

int s21_memcmp(const void *str1, const void *str2, size_t n){
    int res = 0;
    const char* ptr1 = str1;
    const char* ptr2 = str2;

    for (s21_size_t i = 0; i < n; i++){
        if (ptr1[i] > ptr2[i]){
            res = 1;
            break;
        }
        else if(ptr1[i] < ptr2[i]){
            res = -1;
            break;
        }
    }
    return res;
}
