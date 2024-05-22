#include <stdio.h>
#include <string.h>

#define s21_size_t unsigned long long
#define s21_NULL (void*)0

void* s21_memchr(const void* str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void* s21_memcpy(void* dest, const void* src, s21_size_t n);
void* s21_memset(void* str, int c, s21_size_t n);
char* s21_strncat(char* dest, const char* src, s21_size_t n);
char* s21_strchr(const char* str, int c);
int s21_strncmp(const char* str1, const char* str2, s21_size_t n);


s21_size_t s21_strlen(const char* str);

int main()
{
    char ar1[20] = "Gromozeka";
    char ar2[20] = "Gronego";

    //printf("++%s++\n", s21_memcmp(ar1, ar2, 50));
    //strncat(ar1, ar2, 4);
    printf("--%d--\n", s21_strncmp(ar1, ar2, 3));

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
    const char* ptr1 = str1;
    const char* ptr2 = str2;

    for (s21_size_t i = 0; i < n && *ptr1 && *ptr2 && *ptr1 == *ptr2; i++){
        ptr1++;
        ptr2++;
    }
    return *ptr1 - *ptr2;
}

void* s21_memcpy(void* dest, const void* src, s21_size_t n){
    char* ptr_dst = dest;
    const char* ptr_src = src;

    for(s21_size_t i = 0; i < n; i++){
        ptr_dst[i] = ptr_src[i];
    }
    return dest;
}

void* s21_memset(void* str, int c, s21_size_t n){
    char* ptr = str;

    for (s21_size_t i = 0; i < n; i++)
        ptr[i] = c;

    return str;
}

char* s21_strncat(char* dest, const char* src, s21_size_t n){
    char* ptr = s21_strchr(dest, '\0');
    s21_size_t cnt = 0;

    while(cnt < n && src[cnt]){
        ptr[cnt] = src[cnt];
        cnt++;
    }
    ptr[cnt] = '\0';

    return dest;
}

char* s21_strchr(const char* str, int c){
    s21_size_t len = s21_strlen(str);
    s21_size_t cnt = 0;
    int flag = 0;

    while(cnt < len + 1){
        if (str[cnt] == c){
            flag = 1;
            break;
        }
        cnt++;
    }
    return flag ? (char*)(str + cnt) : s21_NULL;
}

s21_size_t s21_strlen(const char* str){
    const char* ptr = str;
    s21_size_t cnt = 0;

    while(*ptr){
        cnt++;
        ptr++;
    }
    return cnt;
}

int s21_strncmp(const char* str1, const char* str2, s21_size_t n){
    s21_size_t cnt = 0;

    while(*str1 && *str1 == *str2 && cnt < n){
        str1++;
        str2++;
        cnt++;
    }
    return *str1 - *str2;
}
