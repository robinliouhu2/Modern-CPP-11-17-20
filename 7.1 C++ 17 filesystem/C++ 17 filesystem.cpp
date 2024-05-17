/*
C++ 17 filesystem 文件系统库
*/

#include <iostream>
#include <filesystem>

//using namespace std::filesystem;
namespace fs = std::filesystem;

int main()
{
    fs::path root("C://");
    fs::path windows_dir = root / "Windows";

    if (!fs::exists(windows_dir))
    {
        return 0;
        std::cout << "dir not exists \n";
    }

    fs::directory_entry windows_entry(windows_dir);

    for (auto& entry : fs::directory_iterator(windows_entry))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".log")
        {
            std::cout << entry.path() << std::endl;
            //fs::copy();
            //fs::remove();
        }
    }
}

