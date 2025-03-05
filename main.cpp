#include <iostream>




int main(){
    // int x{4};
    
    // double y{5.5} ;
    
    // //int z{5.5} ;
    
    // //char c{300} ;
    // // Implicit Casting "Narrowing"
    // x = y ;

    // // Modern Cpp ---> Static_Cast 


    // x = static_cast<int>(y);
    
    // std::cout<<x;


    // int x= 5 ; 

    // char y = 'a';

    // std::cout<<"X: "<<x<<"\t"<<"Y: "<<std::endl;

    // int* ptr = (int*)&y;
    // std::cout<<ptr<<"-------"<<*ptr<<std::endl;

    // int *ptr1 = static_cast<int*>(&y);

    // std::cout<<ptr<<"-------"<<*ptr<<std::endl;

    // int a = 10;
    // char c = 'a';
    
    // // Pass at compile time, 
    // // may fail at run time
    // int* q = (int*)&c;
    // int* p = static_cast<int*>(&c);
    

    // volatile const  int x = 5 ;

    

    // int* ptr=(int*)&x; //--->Stack 

    // *ptr = 50 ;
    // std::cout<<"X: "<<x<<std::endl;

    int arr[5] = {1,2,3,4,5};
    // // the iterator take copy from the elements, and don't change it 
    // for(int i : arr){
    //     //std::cout<<i<<" ";
    //     i*=2;
    // }
    // // the iterator take copy from the elements referance, and can change them
    // for(int &i : arr){
    //     //std::cout<<i<<" ";
    //     i*=2;
    // }
    // TO prevent the iterator take copy from the elements referance, and can't change them
    // for(const int &i : arr){
    //     //std::cout<<i<<" ";
    //     i*=2;
    // }

    for(int i : arr){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;




    return 0;
}