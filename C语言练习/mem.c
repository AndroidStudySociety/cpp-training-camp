//
// Created by Jesson on 2019/10/30.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void testArray();

void fun(int *pInt);

void testMem();

int main() {
    //testArray();
    testMem();

    return 0;
}

void testMem() {
    char name[100];
    char *description;

    strcpy(name, "Jesson");
    /* 动态分配内存 */
    description = (char *)malloc( 200 * sizeof(char) );
    if( description == NULL ) {
        fprintf(stderr, "Error - unable to allocate required memory\n");
    }
    else {
        strcpy( description, "Jesson is a teacher");
    }
    printf("Name = %s\n", name );
    printf("Description: %s\n", description );

    description = (char *) realloc( description, 100 * sizeof(char) );
    if( description == NULL ) {
        fprintf(stderr, "Error - unable to allocate required memory\n");
    }
    else{
        strcat( description, "He is in class 10th");
    }
    printf("Description: %s\n", description );
    free(description);
}

void testArray() {
        int *p;
        //在堆区开辟一块内存，由p指向它
        p = (int*)malloc(sizeof(int)*10);
        if (p == NULL)
        {
            printf("分配失败\n");
        }
        *p = 20;
        printf("*p=%d\n",*p);
        printf("*p=%p\n",&p);

        //避免重复free发生错误，当分配空间成功时
        //p就不是NULL了，此时使用完成后将其free掉，并且设置
        //p为NULL，下次就不会走过来free了
        if (p != NULL)
        {
            free(p);
            p = NULL;
        }
        fun(p);
        printf("*p = %d\n",*p);  //bad exception
}
//在栈内存定义一个指针p后，并没有指定它的指向，所以他是一个野指针，通过fun方法将p传递进入，
// 此时，会在栈中再次定义一个指针temp,并在堆区开辟空间，由temp指向它，然后方法执行完毕，
// temp指针释放，但是堆区内存没有释放，内存泄漏。 这里应该在栈空间之外先开辟动态内存 或者返回指针
void fun(int *temp) {
    temp = (int*)malloc(sizeof(int));
    *temp = 100;
}
