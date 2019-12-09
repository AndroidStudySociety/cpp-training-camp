//
// Created by Jesson on 2019/10/31.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int a;
    short b[2];
} EX2;
typedef struct{
    int a;
    char b[2];
    EX2 c;
    struct EX *d;
} EX;

struct Person
{
    char* name;
    int age;
};

struct News {
    // 使用字符数组，在赋值的时候和字符指针略有不同
    char title[128];
    char* content;
};


struct Product {
    char* productName;
    char* productDesc;
}product , *productP;

struct {
    char * name;
    int age;
}person;
void useUnion();
int main(){
    EX2 x = {
            10,"wu",{5,{-1,33}},0
    };
    EX *px = &x;
    printf("%d\n",sizeof(px));
    printf("%p\n",px);
    //还记得我们之前讲过的指针++吗？
    printf("%d\n",(*px).a);
    printf("%d\n",x.a);
    printf("%d\n",px->a);
    int *pi = &px->a;
    printf("%d\n",*pi); //访问元素10
    printf("%p",&(px->c.a));

    //==========================
    struct Person person = { "jesson",21 };
    printf("输出：姓名 - %s ; 年龄 - %d\n", person.name, person.age);
    struct Person person2;
    person2.name = "非我";
    person2.age = 23;
    printf("\n输出：姓名 - %s ; 年龄 - %d\n", person2.name, person2.age);
    struct News news;
    //news.title 是字符数组 ， 不能直接 news.title = "xxx" ， 需要使用strcpy()函数
    strcpy(news.title, "我是新闻标题");
    news.content = " 我是新闻正文";
    printf("\n\n输出：\n标题 \n %s \n正文：\n  %s\n", news.title, news.content);


    //====================
    // 在声明结构体的时候定义结构变量 ， 操作方便 ， 不用再定义一遍
    product.productName = "全新X系列宝马X5";
    product.productDesc = "无刮痕全新X系列宝马享受驾驶愉悦就开宝马轿车";
    productP = &product;
    productP->productName = "全新奥迪A8";
    productP->productDesc = "==全新奥迪A8==";
    printf("产品信息：\n产品名称：%s\n产品描述：%s\n", productP->productName, productP->productDesc);
    printf("产品信息：\n产品名称：%s\n产品描述：%s\n", product.productName, product.productDesc);

    useUnion();
    return -1;
}


//演示结构体的嵌套

struct NewProduct {
    char* productName;
    char* productDesc;
};

struct GoodsBean {
    int total;
    int status;

    struct Goods {
        char *goodsName;
        char *goodsDesc;
    };
};

struct ProductBean
{
    int total;
    int status;

    struct NewProduct product;
};

void test(){
    // one
    printf("\n\n\n\n结构嵌套示例\n\n");
    // 使用字面量的形式赋值
    struct GoodsBean goodsBean = { 10,0,{ "全新Iphone6s","金色全新Iphone6s能与Android手机媲美的Iphone6s"}};
    //这里思考下怎么获取"全新Iphone6s"
    //printf("商品总数：%d\n商品状态：%d\n商品名称：%s\n商品描述：%s\n", goodsBean.total, goodsBean.status, goodsBean.goodsName, goodsBean.goodsDesc);

    // two
    printf("\n\n");
    struct ProductBean productBean;
    productBean.total = 100;
    productBean.status = 0;
    productBean.product.productName = "金色经典 ， 小米5 ， 你值得拥有";
    productBean.product.productDesc = "全新金色小米5 ， 刚买没几个月";

    printf("商品总数：%d\n商品状态：%d\n商品名称：%s\n商品描述：%s\n", productBean.total, productBean.status, productBean.product.productName, productBean.product.productDesc);
}


//结构体和函数指针
struct Dog {
    char* name;
    int age;
    void(*dogWow)(char* wow); //结构体中不能有函数实体所以在创建结构体时将函数名称赋值给函数指针即可。 ，
};

void dogWow(char* wow) {
    printf("狗是：%s 叫\n", wow);
}

void testFunc(){
    printf("\n\n\n\n");
    printf("结构体中函数没有实现，在创建结构体时将函数名称赋值给函数指针即可\n");
    struct Dog dog = { "小黄",3,dogWow };
    dog.dogWow("汪汪。。。");
}

//===/* 在来看 是不是很有感觉来
// * JNI invocation interface.
// */
//struct JNIInvokeInterface {
//    void*       reserved0;
//    void*       reserved1;
//    void*       reserved2;
//
//    jint        (*DestroyJavaVM)(JavaVM*);
//    jint        (*AttachCurrentThread)(JavaVM*, JNIEnv**, void*);
//    jint        (*DetachCurrentThread)(JavaVM*);
//    jint        (*GetEnv)(JavaVM*, void**, jint);
//    jint        (*AttachCurrentThreadAsDaemon)(JavaVM*, JNIEnv**, void*);
//};

union mValue
{
    int     i;
    short   s;
    long    l;
    float   f;
    char* ss;
};

/*联合体示例*/
void useUnion() {
    union mValue m;
    m.f = 23.4f;
    m.i = 100;  // 最后一次赋值有效
    printf("联合体：\n%f - %d\n", m.f, m.i);
    printf("联合体大小：%d", sizeof(m));
}