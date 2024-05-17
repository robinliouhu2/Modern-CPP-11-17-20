// C++ output_input.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>


typedef struct _A
{
    int m_a;
}A;

std::istream& operator >> (std::istream& in, A& data)
{
    in >> data.m_a;
    return in;
}

std::ofstream& operator <<(std::ofstream& out, A& data)
{
    out << data.m_a;
    return out;
}

int main()
{
    A a = { 6 };
    std::ofstream outfile("my_bin_file.bin");
    if (outfile)
    {
        outfile << a;
        outfile.close();
    }

    int b = 0;
    std::ifstream infile("my_bin_file.bin");
    if (infile)
    {
        infile >> b;
        infile.close();
    }

    std::cout << " b value is " << b <<std::endl;
}

