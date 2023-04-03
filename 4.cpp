#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    fs::path given_path;
    std::string file_path;
    std::cout << "Sciezka katalogu: ";
    std::getline(std::cin, file_path);
    given_path = file_path;
    bool exists=false;
    unsigned long size;

    if (fs::is_empty(given_path))
    {
        std::cout<<"Katalog jest pusty!\n";
        exit(1);
    }

    for(auto it = fs::directory_iterator(file_path); it != fs::directory_iterator(); ++it)
    {
        if (fs::is_regular_file(*it))
        {
            std::cout<<"Nazwa: "<<fs::path( *it ).filename()<<"  ";
            std::cout<<"Rozmiar: ";
            size=fs::file_size(*it);
            if (size<1000)
            {
                std::cout<<size<<"B\n";
            }
            else if (size<1000000)
            {
                std::cout<<size/1000<<"kB\n";
            }
            else if(size<1000000000)
            {
                std::cout<<size/1000000<<"MB\n";
            }
            else
            {
                std::cout<<size/1000000000<<"GB\n";
            }
            exists=true;
        }
    }

    if (!exists)
    {
        std::cout<<"Nie ma zwyklych plikow!\n";
        exit(1);
    }

    return 0;
}
