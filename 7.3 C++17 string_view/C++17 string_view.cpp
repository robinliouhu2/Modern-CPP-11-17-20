#include <iostream>
#include <string_view>

/*
std::string_view 是一种轻量级(无需复制)的字符串数据访问方式，可以理解为字符串的只读视图。

易错点： 如果string_viwe 所指向的内存（string/常量字符串等）失效，string_view也会一起失效。
*/


#include <iostream>
#include <string_view>

int main() {
    const char* c_str = "Hello, world!";

    std::string      str     = c_str; // str会重新分配内存
    std::string_view strView = c_str; //strView 不会重新分配内存

    std::string sub_str = str.substr(0, 2); // sub_str会重新分配内存
    std::string_view subStrView = strView.substr(0, 2); //subStrView 不会重新分配内存

    // 打印子串
    std::cout << std::hex << (uint64_t)c_str << std::endl;
    std::cout << "string-view data address: " << std::hex << (uint64_t)&strView[0]
        << " substri " << (uint64_t)&subStrView[0] << std::endl;

    std::cout << "string      data address: " << std::hex << (uint64_t)&str[0] 
        << " substri " << (uint64_t)&sub_str[0] << std::endl;

    return 0;
}
