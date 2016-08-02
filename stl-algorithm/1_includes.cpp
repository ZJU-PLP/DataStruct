/*************************************************************************
	> File Name: 1_includes.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年08月02日 星期二 10时25分24秒
 ************************************************************************/

#include<iostream>
#include <algorithm>    // std::includes, std::sort

using namespace std;

bool myfunction (int i, int j) 
{ 
    return i<j;  
}

int main () 
{
    int container[] = {5,10,15,20,25,30,35,40,45,50};
    int continent[] = {40,30,20,10};

    std::sort (container,container+10);
    std::sort (continent,continent+4);

    // using default comparison:
    if ( std::includes(container,container+10,continent,continent+4)  )
        std::cout << "包含子序列!\n";
    
    // using myfunction as comp:
    if ( std::includes(container,container+10,continent,continent+4, myfunction)  )
        std::cout << "包含子序列!\n";
    return 0;
}

