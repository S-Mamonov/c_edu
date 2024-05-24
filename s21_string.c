#include <stdio.h>
#include <string.h>

#define s21_size_t unsigned long
#define s21_NULL (void*)0

void* s21_memchr(const void* str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void* s21_memcpy(void* dest, const void* src, s21_size_t n);
void* s21_memset(void* str, int c, s21_size_t n);
char* s21_strncat(char* dest, const char* src, s21_size_t n);
char* s21_strchr(const char* str, int c);
int s21_strncmp(const char* str1, const char* str2, s21_size_t n);
char* s21_strncpy(char* dest, const char* src, s21_size_t n);
s21_size_t s21_strcspn(const char* str1, const char* str2);

s21_size_t s21_strlen(const char* str);
char* s21_strpbrk(const char* str1, const char* str2);
char* s21_strrchr(const char* str, int c);


int main()
{
    #ifdef __linux__
        puts("its a linux, baby!");
    #endif // __linux__

    char ar1[] = "123456";
    //char ar2[20] = "Grom3ozeka";

    printf("++%s++\n", s21_strrchr(ar1, 'z'));
    printf("--%s--\n", strrchr(ar1, 'z'));
//printf("--%s--\n", ar1 + 1);
    //strncat(ar1, ar2, 4);


    return 0;
}

void* s21_memchr(const void* str, int c, s21_size_t n){
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

int s21_memcmp(const void *str1, const void *str2, s21_size_t n){
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

char* s21_strncpy(char* dest, const char* src, s21_size_t n){
    s21_size_t i = 0;

    for (; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];

    if (src[i] == '\0'){
        for (; i < n; i++)
            dest[i] = '\0';
    }
    return dest;
}

s21_size_t s21_strcspn(const char* str1, const char* str2){
    int flag = 1;
    s21_size_t cnt = 0;

    for (; flag && cnt < s21_strlen(str1); cnt++)
        for (s21_size_t j = 0; j < s21_strlen(str2); j++)
            if (str1[cnt] == str2[j]){
                flag = 0;
                cnt--;
                break;
            }

    return cnt;
}

char* s21_strpbrk(const char* str1, const char* str2){
    char* res = s21_NULL;
    int flag = 1;

    for (s21_size_t i = 0; flag && i < s21_strlen(str1); i++)
        for (s21_size_t j = 0; j < s21_strlen(str2); j++)
            if (str1[i] == str2[j]){
                res = (char*)(str1 + i);
                flag = 0;
                break;
            }
    return res;
}

char* s21_strrchr(const char* str, int c){
    int len = s21_strlen(str);
    int flag = 0;

    while(len > -1){
        if (str[len] == c){
            flag = 1;
            break;
        }
        len--;
    }
    return flag ? (char*)(str + len) : s21_NULL;
}
