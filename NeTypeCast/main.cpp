//
//  main.cpp
//  NeTypeCast
//
//  Created by 天涯路 on 2019/11/22.
//  Copyright © 2019年 天涯路. All rights reserved.
//

#include <iostream>
#include "Extends.hpp"

int main(int argc, const char * argv[]) {
    //-------------------const_cast----------------------------
    char x = 'x';
    const char *a = &x;
    char *b = const_cast<char*>(a);
    
    char* d = &x;
    const char *c = const_cast<const char*>(d);
    
    
    //静态多态->编译时已确定类型(Parent)
    Parent* child1 = new Child();
    child1->test(); //Parent
    
    //动态多态：虚函数->运行时对虚函数会检查类型（Child）
    //构造方法永远不要设为虚函数 -> 无法实例化子类
    //析构方法声明为虚函数 -> 释放子类内存
    Parent1* child2 = new Child();
    child2->test(); //Child
    
    //-------------------dynamic_cast----------------------------
    //动态转换要求在类中添加一个虚函数，随便一个都可以
    Child* child3 = dynamic_cast<Child*>(child1);
    if(child3) {
        child3->test(); //Child
    }
    
    //-------------------static_cast----------------------------
    //    Parent* parent = new Parent(); //失败
    Child* child4 = static_cast<Child*>(child1);
    child4->test(); //Child
    
    Child* child5 = static_cast<Child*>(child2);
    child5->test(); //Child
    
    //-------------------reinterpret_cast----------------------------
    float i = 10;
    //&i float指针，指向一个地址，转换为int类型，j就是这个地址
    long j = reinterpret_cast<long>(&i);
    cout << hex << &i <<endl; //0x7ffeefbff584
    cout << hex << j << endl; //7ffeefbff584
    
    cout << hex << i << endl; //输出十六进制数 10
    cout << oct << i << endl; //输出八进制数 10
    cout << dec << i << endl; //输出十进制数 10
    
    //-------------------char*与int转换----------------------------
    cout << "***********************" << endl;
    //char* 转 int float
    int e = atoi("1");
    float f = atof("1.1f");
    cout << e << endl; //1
    cout << f << endl; //1.1
    
    //int 转换为char*
    char c1[10];
    //10进制
//    itoa(100, c, 10); //mac下没有这个函数
//    cout << c << endl;
    
    //int 转 char*
    char c2[10];
    sprintf(c2, "%d", 100);
    cout << c2 << endl; //100
    
    return 0;
}
