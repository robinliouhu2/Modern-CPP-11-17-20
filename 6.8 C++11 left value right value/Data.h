#pragma once
#include <iostream>

class Data
{
private:
    int* m_pArray;
    uint32_t m_size;
public:
    Data()
    {
        m_size = 100;
        m_pArray = new int[100];
        std::cout << "constructed " << std::hex << this << std::endl;
    }

    ~Data()
    {
        if (m_pArray != nullptr)
        {
            delete[] m_pArray;
            m_size = 0;
            m_pArray = nullptr;
            std::cout << "destructed " << std::hex << this << std::endl;
        }
    }

    Data(const Data& other)
    {
        if (m_pArray != nullptr) {/*删除原来的内存*/ };

        m_size = other.m_size;
        m_pArray = new int[100];
        memcpy(m_pArray, other.m_pArray, sizeof(int) * m_size);
        std::cout << "copy constructor " << std::hex << this << std::endl;
    }

    Data(Data&& other)noexcept
    {
        if (m_pArray != other.m_pArray)
        {
            m_size = other.m_size;
            m_pArray = other.m_pArray;

            other.m_pArray = nullptr;
            other.m_size = 0;
            std::cout << "move constructor " << std::hex << this << std::endl;
        }
    }





};
