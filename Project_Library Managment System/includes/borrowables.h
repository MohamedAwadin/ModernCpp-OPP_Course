/**
 * File : Library Items which can be borrowed Like : Books
 * 
 */
#ifndef BORROWABLES_H
#define BORROWABLES_H

 #include <string>

 class borrowables
 {
 private:
    std::string ItemName;
    std::string borrowDate;
 public:
    
    
    borrowables() = default;
    /**
     * @brief Borrow Item
     * @Description : Borrow Item from Library, to help the child class to implement the borrow functionality
     */
    virtual void borrowItem() = 0;
    /**
     * @brief Return Item
     * @Description : Return Item to Library, to help the child class to implement the return functionality
     */
    virtual void returnItem() = 0;

    /**
     * @brief Destroy the borrowables object
     */
    virtual ~borrowables() = default;
 };
 
#endif // BORROWABLES_H