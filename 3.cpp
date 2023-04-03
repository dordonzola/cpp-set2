#include <iostream>
#include <initializer_list>

template<typename T>

auto fun(const std::initializer_list<T>& arg)
{
    auto sum_val=T{};
    for (auto it = begin(arg); it != end(arg); it++)
    {
        sum_val+=*it;
    }
    return sum_val;
}


int main()
{

    auto arg = {1.4,43.2,1.3};
    std::cout<<"Zmiennoprzecinkowe:"<<fun(arg)<<"\n";
    arg = {1,2,3};
    std::cout<<"Calkowite:"<<fun(arg)<<"\n";


    return 0;
}

