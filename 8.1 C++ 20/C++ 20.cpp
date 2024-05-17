/*
C++20 现状及展望
概念、协程、模块
*/

// 1.Concepts
/*
概念是一种类型约束，用于限制模板参数的类型。
它可以提供更好的错误提示和文档，以及更清晰的代码结构
*/
#include <iostream>
#include <type_traits>
template<typename T>
concept Integral = std::is_integral<T>::value;

void foo(Integral auto x) {
    // 函数模板参数必须为整数类型
}



// 2.协程
/*
协程是一种轻量级的"线程"，可以在函数内部进行暂停和恢复，而不是依赖于函数的调用和返回。
C++20引入了std::coroutine和相关的语法和库，以支持协程的使用
*/
#include <iostream>
#include <coroutine>
struct Task {
    struct promise_type {
        int value;
        auto initial_suspend() { return std::suspend_never{}; }
        auto final_suspend() { return std::suspend_never{}; }
        auto get_return_object() { return Task{}; }
        void return_void() {}
        void unhandled_exception() {}
    };
};
Task foo() {
    co_return;
}
int main() {
    foo();
    std::cout << "Coroutine started." << std::endl;
    return 0;
}

// 3.模块
/*
module.h
模块是一种新的组织和管理C++代码的方式，模块取代了传统的头文件包含方式，
可以极大的提高编译速度及依赖管理。
*/
export module module;
export void hello();

// module.cpp
module;
#include <iostream>
void hello() {
    std::cout << "Hello, world!" << std::endl;
}

// main.cpp
import module;
int main() {
    hello();
    return 0;
}

