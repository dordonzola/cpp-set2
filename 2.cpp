#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;
vector <int> numbers;

int partition(int a,int b)
{
    int x,i;
    x=numbers[b];
    i=a-1;
    for(int j=a;j<b;++j)
    {
        if (numbers[j]<=x)
         {
             i+=1;
             swap(numbers[i],numbers[j]);
         }
    }
    swap(numbers[i+1],numbers[b]);

    return i+1;
}



void quicksort(int a,int b)
{
    int q;
    if (a < b)
    {
        q = partition(a, b);
        quicksort(a, q - 1);
        quicksort(q + 1, b);
    }
}



int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 1000);

    printf("Przed posortowaniem:\n\n");

    for( int i = 0; i < 1000; ++i )
    {
        numbers.push_back(distrib(gen));
        printf("%d,",numbers[i]);
    }

    quicksort(0,numbers.size());

    printf("\n\n Po posortowaniu:\n\n");

    for( int i = 0; i < 1000; ++i )
    {
        printf("%d,",numbers[i]);
    }

    return 0;
}
