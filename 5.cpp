#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <utility>
#include <functional>
#include <map>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc!=2)
    {
        perror("Zla ilosc argumentow!");
        exit(1);
    }

    long num=strtol(argv[1],NULL,0);

    if(errno==ERANGE)
    {
        perror("Podano zly argument!");
        exit(1);
    }

    if (num<1 || num>3999)
    {
        perror("Liczba spoza przedzialu!");
        exit(1);
    }

    int len=to_string(num).length();
    int num_tab[len], counter=1,n=0,current,ten=pow(10,(len-1));
    string roman="";

    while (num>1)
    {
        num_tab[len-counter]=(num%10);
        num=num/10;
        n++;
        counter+=1;
    }

    map<int,string > map;
    map[1]='I';
    map[5]='V';
    map[10]='X';
    map[50]='L';
    map[100]='C';
    map[500]='D';
    map[1000]='M';

    for(int i=0;i<len;++i)
    {
            current=num_tab[i];
            if(current==4 || current==9)
            {
                roman+=map[1*ten];
                roman+=map[(current+1)*ten];
            }
            else
            {
                if (current>=5)
                {
                    roman+=map[5*ten];
                    current-=5;
                }
                for (int j=0;j<current;++j)
                {
                    roman+=map[1*ten];
                }
            }
        ten/=10;
    }
    cout<<roman;

    return 0;
}
