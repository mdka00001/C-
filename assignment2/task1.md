-----
Empty
-----

#Assignment 2
#Md Adnan Karim 7002536

1. Members of a class are private by default unless they are specified. On the other hand, members of a class are public by default. Class can declare template parameters, which is not possible with struct.

2. To make understanding, debugging, and maintenance easier, a class's public interface should be as short as feasible.

3. Static is a variable type that is equivalent to a global variable which can only be used in the scope of the block it is declared into.They are only initialized once and they have a lifetime throughout the execution of the entire programme. Unless a value is assigned to the static, it will be automatically initialized. On the other hand, We should use const if we require an object that will remain the same throughout the program (constant).A const instance of a class is important for making your applications more stable because we can't accidentally alter the instance.

4. If we want the objects to remain the same throughout the whole programme it is importent we use functions that do not modify them. Such objects are also called immutable objects in OOP. For such types of objetcs, functions take the input and produce the resulting outputs. On the other hand, whenn functions are used as an object inside class, the are no more immutable annd can be mutated by calling the functions for the class. For private class objects, we can use getters and setters to mutate and return the modified objects.

5. Inline functions in C++ are a useful idea that is frequently used with classes. If a function is inline, the compiler stores a copy of the function's code at each location where it is called during compile time.When the function definitions are short and the functions are called several times in a program, inline functions are typically employed. The time it takes to transfer control of the program from the calling function to the definition of the called function is reduced when inline functions are used.

6. A destructor is a class member function that deletes or de-allocates an object to free up memory. It is called either at functions end, or at the programmes end or at the end of a block chain of local variables. It does not entirely delete all instances of a class, but it is called during the objects destruction. 

The major consequences of using destructor arises while working on a dynamically allocated memory location. For dynamically allocated memory, a user has to define specific destructors to free up the memory. If it is not defined, the compiler will create a default destructor that might be incompetent for releasing the memory. This often cause memory leak during large scale programming.

7. We can utilize virtual functions to postpone function call resolution until runtime. We may use it to override a specific behavior for our derived class at runtime, rather to the one implemented for the base class, by passing a reference to it.

8. In C++, friend functions of the class are given permission to access the class's private and protected members. They are specified globally, outside of the scope of the class. Friend functions are not class member functions. On the other hand, A virtual function is a member function that is declared in a base class and overridden by a derived class. When you use a pointer or a reference to the base class to refer to a derived class object, you may call a virtual function for that object and have it run the derived class's version of the function.It is not possible to use both friend and virtual function on a same class. But a friend function can be used to call a virtual function from the object that it will print.This way the friend function will polymorphically call the virtual function of the derived class. An example was given in the Col_type.hpp file of assignment sheet 2 task 5 where the friend function was used to overload the operator for Class GenericDataType.

class GenericDataType {
public:
    virtual ~GenericDataType() = default;
    virtual std::unique_ptr<GenericDataType> clone() const = 0;
    friend std::ostream& operator<<(std::ostream& os, const GenericDataType& v);
    virtual bool operator==(const GenericDataType& other) const = 0;
    virtual bool operator<(const GenericDataType& other) const = 0;
protected:
    virtual void print(std::ostream& os) const = 0;
};

9. If we wish to utilize an abstract class, we must create a pure virtual member function.
Because it is an unimplemented function, it cannot be instantiated, but it can override by a child class to create a concrete class.

10. Multiple inheritances have a number of drawbacks. Function overriding is the most evident issue. This leads to uncertainty in the program's semantics. It may result in the "Dreaded Diamond" issue. It adds to the program's complexity.

11. There will be no pure virtual methods in concrete classes, but all methods in interfaces must be pure virtual methods.






