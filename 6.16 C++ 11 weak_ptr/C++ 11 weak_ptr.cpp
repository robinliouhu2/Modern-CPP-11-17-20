/*
weak_ptr
weak_ptr只能和 shared_ptr 类型指针搭配使用
weak_ptr 指针不会改变shared_ptr管理内存空间的引用计数，但可以查询所指向的对象是否还有效
*/


#include <iostream>
#include <memory>
#include <vector>

class CGameWord;

class CGameActor
{
public:
    CGameActor(std::shared_ptr<CGameWord> pWord)
    {
        m_pWord = pWord;

        //weak ptr 必须通过lock 拿到对象对应的共享指针才能访问所指向的对象
        std::shared_ptr<CGameWord> sh_ptr = m_pWord.lock();

        //如果对象已经被释放，sh_ptr 无效。  所以lock之后，必须先判断才能使用
        if (sh_ptr)
        {

        }
    }

    ~CGameActor()
    {
        std::cout << "CGameActor delete\n";
    }
    //std::shared_ptr<CGameWord> m_pWord;
    std::weak_ptr<CGameWord> m_pWord;
};

class CGameWord
{
public:
    ~CGameWord()
    {
        std::cout << "CGameWord delete\n";
    }

    std::vector<std::shared_ptr<CGameActor>> m_ActorsInWord;

    void add_actor(std::shared_ptr<CGameActor> pActor) {
        m_ActorsInWord.push_back(pActor);
    }

};

int main()
{
    {
        std::shared_ptr<CGameWord> pWord = std::make_shared<CGameWord>();
        std::shared_ptr<CGameActor> pMonsterHome = std::make_shared<CGameActor>(pWord);
        pWord->add_actor(pMonsterHome);
    }

    std::cout << "main end\n";
  
}


