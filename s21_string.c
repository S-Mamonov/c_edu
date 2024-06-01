#include <stdio.h>
#include <string.h>

#define s21_NULL (void*)0

typedef unsigned long s21_size_t;

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
char* s21_strstr(const char* haystack, const char* needle);
char* s21_strtok(char* str, const char* delim);

void* s21_insert(const char* src, const char* str, s21_size_t start_index);

int main()
{
    #ifdef __linux__
        puts("it's a linux, baby!");
    #endif // __linux__

    char str[100] = {0};
    char* s1 = "0123";
    char s2[] = "ad";
    char s3[] = "third";
    char* res = s21_insert(s1, s2, 2);
    printf("---%s---", res);
//    char str[] = "abc1xyz";
//    char str2[] = "abc1xyz";
//    char* sep = "1y";
//
//    printf ("+++%s+++\n", strtok(str, sep));
//    printf ("---%s---\n", s21_strtok(str2, sep));
//    printf ("+++%s+++\n", strtok(NULL, sep));
//    printf ("---%s---\n", s21_strtok(s21_NULL, sep));
//    printf ("+++%s+++\n", strtok(NULL, sep));
//    printf ("---%s---\n", s21_strtok(s21_NULL, sep));
//    printf ("+++%s+++\n", strtok(NULL, sep));
//    printf ("---%s---\n", s21_strtok(s21_NULL, sep));
//
//    puts(str);
//    puts(str2);

//    for(int i = 0; i < 150; i ++)
//        printf("%3d - %s\n", i, strerror(i));

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
    int res = 0;

    for (s21_size_t i = 0; i < n; i++){
        if(ptr1[i] != ptr2[i]){
            res = ptr1[i] - ptr2[i];
            break;
        }
    }
    return res;
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
    char* res = s21_NULL;
    s21_size_t cnt = 0;
    s21_size_t len = s21_strlen(str) + 1;

    while(cnt < len){
        if (str[cnt] == c){
            res = (char*)(str + cnt);
            break;
        }
        cnt++;
    }
    return res;
}

s21_size_t s21_strlen(const char* str){
    s21_size_t cnt;

    for (cnt = 0; str[cnt]; cnt++);

    return cnt;
}

int s21_strncmp(const char* str1, const char* str2, s21_size_t n){
    n = (s21_strlen(str1) < s21_strlen(str2) ? s21_strlen(str1) : s21_strlen(str1)) + 1;
    return s21_memcmp(str1, str2, n);
}

char* s21_strncpy(char* dest, const char* src, s21_size_t n){
    s21_size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];

    if (src[i] == '\0'){
        for (; i < n; i++)
            dest[i] = '\0';
    }
    return dest;
}

s21_size_t s21_strcspn(const char* str1, const char* str2) {
  s21_size_t res;

  for (res = 0; res < s21_strlen(str1); res++)
    if (s21_strchr(str2, str1[res]))
        break;

  return res;
}

char* s21_strpbrk(const char* str1, const char* str2){
    char* res = s21_NULL;

    for (s21_size_t i = 0; i < s21_strlen(str1); i++)
        if(s21_strchr(str2, str1[i])){
            res = (char*)(str1 + i);
            break;
        }
    return res;
}

char* s21_strrchr(const char* str, int c){
    int len = s21_strlen(str);
    char* res = s21_NULL;

    while(len > -1){
        if (str[len] == c){
            res = (char*)(str + len);
            break;
        }
        len--;
    }
    return res;
}

char* s21_strstr(const char* haystack, const char* needle){
    char* res = s21_NULL;
    char* ptr;
    int flag = 1;

    if (s21_strlen(needle) == 0)
        flag = 0;

    while(flag && (ptr = s21_strchr(haystack, *needle)) != s21_NULL){
        if (s21_strncmp(ptr, needle, s21_strlen(needle)) == 0){
            res = ptr;
            break;
        }
        haystack++;
    }
    return flag ? res : (char*)haystack;
}

char* s21_strtok(char* str, const char* delim){
    static char* last;

    if (str)
        last = str;

    if ((last == 0) || (*last == 0))
        return 0;

    char* c = last;

    while(strchr(delim, *c)) c++;

    if (*c == 0) return 0;

    char* start = c;

    while(*c && (strchr(delim, *c) == 0)) c++;

    if (*c == 0)
    {
        last = c;
        return start;
    }

    *c = 0;
    last = c+1;

    return start;
}

//char* s21_strtok(char* str, const char* delim){
//    static char* final;
//    char ch;
//
//    if (str == s21_NULL)
//        str = final;
//
//    do{
//        if ((ch = *str++) == '\0')
//            return s21_NULL;
//    }while(s21_strchr(delim, ch));
//    str--;
//
//    final = str + s21_strcspn(str, delim);
//
//    if (*final != 0)
//        *final++ = '\0';
//
//    return str;
//}

void* s21_insert(const char* src, const char* str, s21_size_t start_index){
    if (src == s21_NULL || str == s21_NULL) return s21_NULL;
    s21_size_t len_src = s21_strlen(src);
    s21_size_t len_str = s21_strlen(str);
    start_index = start_index < len_src ? start_index : len_src;

    char* res = malloc(len_src + len_str + 1);

    s21_memcpy(res, src, start_index);
    res[start_index] = '\0';
    s21_strncat(res, str, len_str + 1);
    s21_strncat(res, src + start_index, len_src - start_index + 1);


    return res;
}
