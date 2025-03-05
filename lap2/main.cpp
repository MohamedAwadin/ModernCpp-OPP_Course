#include <iostream>

#include <array>

#include <vector>

#include <algorithm>
int main()
{
    // int arr[]={1,2,3};

    // //std::array<int, 5> arr{1,2,3,4,5,6};

    // std::cout<<arr[0]<<std::endl ;
    // std::cout<<arr[1]<<std::endl ;
    // std::cout<<arr[2]<<std::endl ;
    // std::cout<<arr.at(3)<<std::endl ;


    // int x= 5 ;
    // int &z=x ;

    // std::cout<<"x:  "<<x<<"---- Add: "<<&x<<std::endl;
    // std::cout<<"y:  "<<z<<"---- Add: "<<&z<<std::endl;

    // std::array<int, 4> arr{1,2,3,4};

    // std::cout<<arr.back()<<std::endl; // Get Last Element 


    // for (auto  i = arr.begin(); i != arr.end(); ++i)
    // {
    //     std::cout<< *i << " " ;
    // }
    // std::cout<<std::endl;
    // //g++ -D_GLIBCXX_DEBUG main.cpp -o main
    // std::cout<<*arr.end()<<std::endl;


    // std :: array<int, 3>arr={1,2,3};

    // for (auto it = arr.crbegin(); it != arr.crend(); it++)
    // {
    //     //(*it)=(*it)+2;
    //     std::cout<<*it<<" ";
    // }
    
    // for(int num:arr)
    // {
    //     std::cout<<num<<" ";
    // }


    // std::array<int, 3>arr={1};
    // std::cout<<"is array empty: "<<std::boolalpha<<arr.empty()<<std::endl;

    // //arr.fill(0);


    // std::cout<<"First Element: "<<arr.front()<<"\n";

    // for(int num:arr)
    // {
    //     std::cout<<num<<" ";
    // }

    // std::array<int, 3>arr={1,2,3};

    // std::cout<<arr.max_size(); //return size od the array 

    // std::cout<<"Index1: "<<arr[1];

    // std::array<int, 3>arr1={4,5,6};
    // std::array<int, 3>arr2={1,2,3};

    // for(int num:arr1)
    // {
    //     std::cout<<num<<" ";
    // }
    // std::cout<<"\n";

    // for(int num:arr2)
    // {
    //     std::cout<<num<<" ";
    // }
    // std::cout<<"\n";

                                      
    //>>>>>>>>>>>Vectors<<<<<<<<<<<<
    //std::vector<int> myVector ;
    // ***Vector Initilization.
    // 1- 
    
    // myVector.push_back(1);
    // myVector.push_back(2);
    // myVector.push_back(3);
    // myVector.push_back(4);

    // for (int it: myVector)
    // {
    //     std::cout<<it<<std::endl;
    // }
    

    // 2-

    // myVector.assign(5,8);
    // for (int it: myVector)
    // {
    //     std::cout<<it<<std::endl;
    // }

    // 3- 

    // std::vector<int> newvect = {1,3,2};

    // for (int it: newvect)
    // {
    //     std::cout<<it<<std::endl;
    // }


    // 4- 

    // myVector.push_back(1);
    // myVector.push_back(2);
    // myVector.push_back(3);
    // myVector.push_back(4);
    // std::vector<int> myVector2(myVector.begin(),myVector.end());
    // for (int it: myVector2)
    // {
    //     std::cout<<it<<std::endl;
    // }
    

    // 5- 
    // std::vector<int> myVector2(4) ;
    // fill(myVector2.begin(),myVector2.end(), -1);

    // for (int it: myVector2)
    // {
    //     std::cout<<it<<std::endl;
    // }

    //.............................................................


    std::vector<int> myVector = {1,2,3,4};


    std::cout<<myVector.back()<<std::endl;

    std::cout<<"----------------------- "<<"\n";

    for (auto it = myVector.begin(); it != myVector.end(); it++)
    {
        std::cout<<*(it.base())<<std::endl;
    }
    
    std::cout<<"----------------------- "<<"\n";

    std::reverse(myVector.begin(), myVector.end());

    for (auto it = myVector.begin(); it != myVector.end(); it++)
    {
        std::cout<<*(it.base())<<std::endl;
    }

    std::cout<<"----------------------- "<<"\n";

    myVector.reserve(10);

    std::cout<<myVector.capacity()<<std::endl;






    std::cout<<"\n";


    
    

    return 0;
}