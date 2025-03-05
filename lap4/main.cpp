// #include <iostream>

// int z = 10 ;

// int main(){

//     int x = 5  ;
//     int y = 10 ;
//     // auto lambda = [x,y]()-> int {
//     // auto lambda = [&x,&y]()-> int {
//     // auto lambda = [=]()-> int {
//     // auto lambda = [&]()-> int {
//     // auto lambda = [x,&y]()-> int {
        
//     //     x ++ ;
//     //     y ++ ;
//     //     return x+y;
    
//     // };

//     // auto lambda = [x]() mutable -> void{
        
//     //     x ++ ;
//     //     std::cout<<x<<std::endl;
        
    
//     // };

//     //std::cout<<lambda()<< std::endl ;
//     //lambda();
//     std::cout<<x<<std::endl;

//     return 0;


// }



// #include <iostream>
// #include <functional>

// int add(int x , int y) {return x+y;}

// int main()
// {

//     // std::function<int (int,int)> operation;
//     std::function<int(int, int)> operation;

//     operation = add ;

//     std::cout<<"Sum Func :  "<< operation(5,5)<<std::endl;

//     operation = [](int x  , int y){return x-y; };


//     std::cout<<"Sub Func :  "<< operation(5,5)<<std::endl;

//     return 0 ;
// }

// #include <iostream>
// #include <algorithm>
// #include <vector>

// void risky() noexcept {
//     throw std::runtime_error("Oops"); // This will terminate the program
// }

// int main()
// {
//     std::vector<int> vec = {2,3,4,5,67,7};
    
//     //std::for_each(vec.begin(), vec.end(), [](int n){std::cout<<n*n<<"\n";});
//     std::sort(vec.begin(), vec.end(), [](int n1 , int n2){return n1>n2;});
//     for (int  n: vec)
//     {
//         std::cout<<n<<"\n";
//     }

//     try {
//         risky();
//     } catch (...) {
//         std::cout << "Caught\n"; // Won’t reach here
//     }

//     auto lambda  = []() noexcept {std :: cout << "hello";};
    
//     return 0 ;
// }


// #include <iostream>


// int main()
// {
//     int a = 10 ;
    
//     // Declaring reference to already created variable
//     int& b = a;

//     // Comparing the address of both the
//     // variable and its reference and it
//     // will turn out to be same
//     std::cout << (&a == &b) << std::endl;


//     // Declaring lvalue reference , (i.e variable a)
//     int& lref = a;

//     // Declaring rvalue reference
//     int&& rref = 20;
 
//     // Print the values
//     std::cout << "a = " << a << std::endl;
//     std::cout << "lref = " << lref << std::endl;
//     std::cout << "rref = " << rref << std::endl;

//     // Value of both 'a' and 'lref' is changed
//     lref = 30;

//     // Value of rref is changed
//     rref = 40;
//     std::cout << "a = " << a << std::endl;
//     std::cout << "lref = " << lref << std::endl;
//     std::cout << "rref = " << rref << std::endl;

//     // This line will generate an error
//     // as l-value cannot be assigned
//     // to the r-value references
//     // int &&ref = a;
// }


// #include <iostream>
// #include <vector>
// class myclass
// {
// private:
//     /* data */
// public:
//     std::string name ;

//     std::vector<int> vec ;

//     myclass(){std::cout<<"Default Constructor \n";}

//     //Copy Constructor 
//     myclass(const myclass& other)
//     {
//         vec = other.vec ;
//         std::cout<<"Copy Constructor\n";
//     }
//     //Move Constructor (Ref -- R-Value)
//     myclass(myclass &&other) noexcept
//     {
//         vec = std::move(other.vec);
//         std::cout<<"Move Constructor\n";

//     }

//     // myclass(std::string data)
//     // {
//     //     //name = data ;
//     //     // Here no copying happend, move semantic 

//     //     name=std::move(data);
//     // }
    

//     void print(){
//         std::cout<<name<<std::endl;
//     }
// };





// int main(){

//     // myclass obj("Hello, Awadin"); // Move Constructor will called here 
//     // obj.print();

//     myclass obj ; //Def Const
//     myclass obj2 = obj ; //Copy Const
//     myclass obj3 = std::move(obj) ; //mv Const


//     // Vector = {1 ,2,3}
//     // ------Default Constructor ----

//     // obj ---> {1,2,3}

//     // ------- Copy Constructor ------

//     // obj  ---> {1,2,3}
//     // obj2 ---> {1,2,3}

//     // ------- Move Constructor ------

//     // obj  ---> {1,2,3}




// }


// #include <iostream>
// #include <vector>

// int main(int argc, char const *argv[])
// {
//     // Normal String Features:
//     /**
//      * 1- Manages Memory 
//      * 2- Support Dynamic Resizing 
//      * 3- Mutables : Modify 
//      *  
//      * */
    
//      std::string str1 = "Hello";
//      std::string str2("World") ; 
//      std::string str3 = str1 + " " + str2 + "\n";
//      std::cout<<str3;

//      std::cout<<"String Size: "<<str1.size()<<"\n";
//      std::cout<<"String Capacity: "<<str1.capacity()<<"\n";


//     return 0;
// }


#include <iostream>

void print(std::string_view sv){
    //sv = sv + "Extra" ;
    std::cout<<sv<<std::endl;
}


int main()
{
    // std::string str = "Awadin";
    // print(str); // No Copy --> View on the string ref 
    // print("Hello World\n");

    // std::string str = "Awadin, Hello";
    // std::string_view sv (str.c_str()+6,5);
    // std::cout<<sv<<std::endl;


    
    // std::string_view sv ("Awadin, Hello", 5);
    // std::cout<<sv<<std::endl;

    std::string str = "Hello World";
    std::string_view sv(str);

    std::cout<<"Data:  "<<sv.data()<<std::endl;
    std::cout<<"Size:  "<<sv.size()<<std::endl;
    std::cout<<"IsEmpty:  "<<std::boolalpha<<sv.empty()<<std::endl;

    return 0;
}