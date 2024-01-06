#include<iostream>
#include<algorithm>


/**
 * [外部变量访问方式说明符] (参数表) -> 返回值类型
{
   语句块
}

 * 外部变量访问方式说明符灵活用法
 * 
 * [=, &x, &y]表示外部变量 x、y 的值可以被修改，其余外部变量不能被修改；
 * [&, x, y]表示除 x、y 以外的外部变量，值都可以被修改。
 * 
 * 
*/
void test1() {
    int length = 5;
    int a[length] = {11,62,3,44,2};
    std::cout << "a lenth : " << sizeof(a) << std::endl;
    // [=] "="的作用表示，定义在{}外面的变量在{}中不允许改变，[&] "&"表示允许
    std::sort(a, a+length,[=](int x, int y)->bool{ return x/10 < y/10;});
    std::for_each(a, a+length, [=](int x){std::cout<<x<<" ";});

}

void test2() {
    int length = 5;
    int a[length] = {1,2,33,4,5};
    int total = 0;
    std::for_each(a, a + length, [&](int& x) {total += x; x *= 2;});
    std::for_each(a, a + length, [=](int x){std::cout << x << " ";});
}

void test3() {
    int length = 5;
    int a[length] = {1,2,3,4,5};

    std::for_each(a, a + length, [](int x){std::cout << "Hello." << std::endl;});
}

int main() {

    test3();

    return 0;
}