#include <stdlib.h>
#include <printf.h>
#include <assert.h>

int mystrlen(char *s1);

void teststrcat();

char* mystrcat(char* dest, const char* str);

char* mystrstr(const char* dest, const char* str);

void testfindStr();

int main()
{
    char* s1 = "jesson";
    int ret = mystrlen(s1);
    printf("字符串长度为%d\n", ret);
    teststrcat();
    testfindStr();
    getchar();
    return 0;
}

void testfindStr() {
    const char* s1 = "abcdefgh";
    const char* s2 = "ab";
    char* ch = mystrstr(s1, s2);
    if (ch != NULL)
    {
        printf("%s\n", ch);
    }
    else
    {
        printf("not exist\n");
    }
}

void teststrcat() {
    char* s1 = "odkosd";  //
    char s2[] = {"isoo"};

    *(s2+2) = 's';


    char s1[20] = "abcde";
    const char* s2 = "fghil";
    printf("%s\n", mystrcat(s1, s2));
}

int mystrlen(char *s1) {
    int count = 0;
    while (*s1!='\0')
    {
        count++;
        *s1++;
    }
    return count;
}

//char* strcat(char* dest, const char* str)
char* mystrcat(char* dest, const char* str)
{
    assert(dest);
    assert(str);
    char *ret = dest;
    while (*dest)
    {
        dest++;
    }
    while (*dest++ = *str++)
    {
        ;
    }
    return ret;
}

//char* strstr(const char* dest, const char* str)
char* mystrstr(const char* dest, const char* str)
{
    char* ptr = dest;
    char* p1 = NULL;
    char* p2 = NULL;
    while (*dest)
    {
        p1 = ptr;
        p2 = str;
        while (*p1++ == *p2++)
        {
            p1++;
            p2++;
            if (*p2=='\0')
            {
                return ptr;
            }
        }
        ptr++;
    }
    return NULL;
}





