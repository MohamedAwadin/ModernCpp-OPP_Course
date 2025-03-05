#include <iostream>

// Function to return the maximum of two values
// template <typename T>
// T maxVal(T x, T y)
// {
//     return ((x > y) ? x : y);
// }

// Variadic print function with a base case
// void print() // Base case to stop recursion
// {
//     std::cout << std::endl;
// }

// template <typename T, typename... Args>
// void print(T x, Args... rest)
// {
//     std::cout << x << " ";
//     print(rest...); 
// }


// template <typename... Args>
// void print(Args... args)
// {
    
//     print(args...); 
// }

// // Variadic storage class template with two different data types
// template <typename T1, typename T2>
// class storage
// {
// private:
//     T1 data1;            
//     T2 data2;

// public:
//     storage(T1 value1, T2 value2) : data1(value1), data2(value2) {}

//     void printData()
//     {
//         std::cout << "Stored Data1: " << data1 << std::endl;
//         std::cout << "Stored Data2: " << data2 << std::endl;
//     }
// };


// void MemoryLeak()
// {
//     int * ptr = new int(10);
//     std::cout<<"Value:  "<<*ptr<<std::endl;
// }

// template<class T>
// class SmartPointer{
//     T * ptr ;
//     public:
//     SmartPointer(T* p=nullptr):ptr(p){}
//     ~SmartPointer(){delete ptr;}
//     T& operator*(){return *ptr;}
//     T* operator->(){return ptr;}
// };

// class Test
// {
// private:
//     /* data */
// public:
//     void print(){
//         std::cout<<"Hello, I am Awadin"<<std::endl;
//     }
// };


// Dynamic Memory management library
#include <iostream>
#include <memory>

class Rectangle2; // Forward declaration

class Rectangle {
    int length;
    int breadth;

public:
    //std::shared_ptr<Rectangle2> rect2_ptr; 
    std::weak_ptr<Rectangle2> rect2_ptr; // Use weak_ptr to avoid circular reference

    Rectangle(int l, int b) : length(l), breadth(b) {
        std::cout << "Rectangle Object Created" << std::endl;
    }

    ~Rectangle() {
        std::cout << "Rectangle Object Destroyed" << std::endl;
    }

    int area() { return length * breadth; }

    void print() {
        std::cout << "Rectangle Object is Alive" << std::endl;
    }
};

class Rectangle2 {
    int length;
    int breadth;

public:
    std::shared_ptr<Rectangle> rect1_ptr; 

    Rectangle2(int l, int b) : length(l), breadth(b) {
        std::cout << "Rectangle2 Object Created" << std::endl;
    }

    ~Rectangle2() {
        std::cout << "Rectangle2 Object Destroyed" << std::endl;
    }
};

int main() {
    {
        std::shared_ptr<Rectangle> Rect_1_sPtr = std::make_shared<Rectangle>(10, 5);
        std::shared_ptr<Rectangle2> Rect_2_sPtr = std::make_shared<Rectangle2>(10, 5);
        std::cout<<"Before Circular :\n";
        std::cout<<"Test1:  "<< Rect_1_sPtr.use_count()<<std::endl;
        std::cout<<"Test2:  "<< Rect_2_sPtr.use_count()<<std::endl;
        std::cout<<"After Circular :\n";
        Rect_1_sPtr->rect2_ptr = Rect_2_sPtr;
        Rect_2_sPtr->rect1_ptr = Rect_1_sPtr; 
        
        std::cout<<"Test1:  "<< Rect_1_sPtr.use_count()<<std::endl;
        std::cout<<"Test2:  "<< Rect_2_sPtr.use_count()<<std::endl;

        
    }

    std::cout << "End of main function" << std::endl;

    


    // {
    //     std::shared_ptr<Rectangle> uPtr1=std::make_shared<Rectangle>(10,5);
    //     std::shared_ptr<Rectangle> uPtr2=uPtr1 ;
    //     uPtr2.reset();

    //     std::cout<<"Referance Counter :"<<uPtr1.use_count()<<std::endl;
    // }
    
    
    // {
    //     std::unique_ptr<Rectangle> P4 = std::make_unique<Rectangle>(10, 5);

    //     // Reset P4 with a new object
    //     P4.reset(new Rectangle(10, 5));

    //     P4->print();
    // } // P4 goes out of scope here, and its object is automatically destroyed

    // std::cout << "End of main function" << std::endl;

    // {
    //     std::unique_ptr<Rectangle> P1(new Rectangle(10, 5));
    //     P1->print();
    // }
    // {
    //     std::unique_ptr<Rectangle> P2(new Rectangle(10, 5));
        
    //     //P3=P2 ; 
    //     std::unique_ptr<Rectangle> P3 = std::move(P2); //Move Semantic 
    //     if (!P2)
    //     {
    //         std::cout<<"P2 now is Null After move ownership\n";
    //     }
    //     P3->print();
    //     P2->print();
        
    // }
    //std::unique_ptr<int> uPtr(new int(10)); // Don't use it Please 
    //std::unique_ptr<int> uPtr=std::make_unique<int>(10);
    //std::cout<<"Value:  "<< *uPtr <<std::endl;
    


    // SmartPointer<int> sptr1(new int(10));
    // std::cout << "Value: " << *sptr1 << std::endl; 

    // SmartPointer<Test> sptr2(new Test());
    // sptr2->print();
    // int x =  5 ; 
    // int* ptr ; 
    // ptr = &x ;

    // int * ptr = new int(10);
    // int * ptr2 = ptr ;
    // std::cout<<"Address:  "<<ptr<<"  Value:   "<<*ptr<<std::endl;
    // delete ptr;
    // //ptr2 ---> dangling pointer
    // ptr = nullptr;
    // std::cout<<"Address:  "<<ptr2<<"  Value:   "<<*ptr2<<std::endl;
    //MemoryLeak();
    // storage<int, float> intStorage(50, 50.12);
    // intStorage.printData();

    // storage<float, float> FStorage(50.11, 11.2);
    // FStorage.printData();

    // // Test variadic print function
    // std::cout << "Printing multiple values: ";
    // print(10, 20.5, "Hello", 'A'); // Mixed data types




    return 0;

}
