#Programming course (Assignment 1) 
#MD Adnan Karim
#7002536

Task 1: 

1. The 8 built-in types provided by C++ are: integer (int), floating point (float), character (char), double floating point (double), long double (long double), void (void), boolean (bool), short (short) and long long (long long). 

2. An expression is a sequence of operators and operands that evaluates a value. For example; a+b is an expression where both a and b takes a value and evaluates using the operator +.  

3. Type safety allows the compiler to check whether the variable defined by the user is of right type of wrong. It is important for successful execution of a code without giving failures. 

4. Switch statement is a faster selection statement that selects a single expression for multiple statements. Switch statements are not capable of comparing logical expressions, but only equality. It is incapable of handling float constants and also cannot use a same constant in different cases.  

5. The common problem of working with Switch is its incapability to handle float/double type: 

#include <iostream> 

#include <vector> 

#include <stdio.h> 

using namespace std; 

int main() 

{    

double fruit; 

      cin >> fruit; 

      switch (fruit){ 

            case 1.1: 

                  cout << "Red Apple" << endl; 

                  break; 

            case 1.2: 

                  cout << "Green Apple" << endl; 

                  break; 

            case 2: 

                  cout << "Banana" << endl; 

                  break; 

        } 

} 

This code will give an error.

6. Use of operator is different for strings and integers. We can use the + operator to concatenate two strings while for integer it will return the sum. On the other hand we can use ++/-- operator to return an increment/reduction for each iteration while using for loop, which is not possible for strings.

7. A pointer is a different type of variable that stores the memory address of a variable. A pointer is declared by assigning a * symbol in front of the variable name. 

A reference is referred as another name for a variable that already exists. It's constructed similarly to a pointer by storing an object's address. Symbol of reference is &. for example:

string s="ABCDE"; 
//assigning a pointer
string *p; 
//declaring the address variable of a pointer using reference symbol &
p = &s;  
string &ss = s; // Adding reference to s

8. An array contains sequential data. An array of size n reserves a memory location for n number of values. Thus an array variable points to the memory location of the first element of the array. Similarly, pointers also refers to the memory address of variable. Which means for an array called array[], array and &array[0] points to the same address of the memory location, the first element.  As a result array[0] and *array is equivalent.

int main()
{
int array[] = {1,2,3,4,5};
int* ptr = array;
//pointing to 2nd element of an array 
ptr++; 
array[1];}

9. Passing values as function parameters is referred to as pass_by_value. And sending variables as function parameters is referred to as pass_by_reference.

void pass_by_value(int value)
{
  count=count+1;
}
void pass_by_reference(int& val){
	
  count=count+1;
}

int main(){
  int num = 1;
  cout << num << endl; // returns 1 as output
  pass_by_value(num);              // this will return 2 as output
  cout << num << endl; // this will again return 1 since value of num not changed
  pass_by_reference(num);          // this will again return 2 
  cout << num << endl; // returns 2 as the initial value of num changed
  return 0;
}

10. An identifier's type, object, or function is described in a declaration. To allow references to such identifier, the compiler requires declaration. As an example, consider class <name_of_the_class>.

The implementation of the identifier is what a definition is. It's necessary for the linker to connect references to such things. As an example, consider class <name_of_the_class> {}.

11. A namespace is a declarative function that is used to avoid name conflicts by providing identifiers in it. For example, in order to execute two functions of similar name, from different libraries, it is recommended to use identifiers included to the functions in namespace. 

#include <iostream>
using namespace std;


namespace bachelor {
   void student() {
      cout << "print bachelor students" << endl;
   }
}

namespace master {
   void student() {
      cout << "print master students" << endl;
   }
}

int main () {
   // Calls function bachelor students.
   bachelor::student();
   
   // Calls function for master student.
   master::student(); 

   return 0;
}

12. Using directives in header is considered as a bad practice. Namespace are directed to header files (.h) in source codes. As a result, name space specific for a function will be called upon execution of the function. Two header files may conflict if they decide to import names from a namespace into them, rendering namespaces worthless.

13. Below given an example of for types of error:

void sum(int a, int b){
	return a-b;
}

//above function has an error called logic error as we defined a function that shall return 
the sum of two integer. Instead the function subtracts two integers//.

int(main){
	int a=7;
	int b=9;
	c=10; //no variable type is assigned[compile-time error]
	sum(a); //another parameter is missing, returns[linker-type error]
	sum(a,b); // works on wrong logical operator[logic error]
	sum(a,b)/0;//division by  0 not possible[runtime error]
}

14. A free store, also known as heap memory is a type of dynamic memory process manually allocated by a programmer while executing a programme. Upon execution with a function on a object type, the free store feature allocates memory for the subobjects of the functions and retains then untill the information is executed. The objects stored in the free store can be manipulated by addressing to its memory location using a pointer. Free store memory allocation is done using "new" operator and it shall be delocated upon completion of the function execution to prevent information leak.

15. When using dynamically allocated memory, such as "int *p = new int[10]," it is the duty of the programmer to deallocate memory when it is no longer required. Memory leaks occur when a programmer fails to deallocate memory.

int(main){
// declaring pointer
int* point;

// allocating memory to the pointer

point = new int;

// value assignment to the memory location
*point = 100;

// print values in memory
cout << *point << endl;

// deallocate the memory
delete point;
}

16. unique_ptr() is a smart pointer function that can automatically manage memory allocation and delocation. Upon execution of the function unique_ptr() automatically allocated memory for subobjects constructed during the process and delocates the memory when it is out of scope. 

17. RAII is a general resource management strategy that combines with the life time of a programme executed and ensures the availability of all the resources that a function will require in order to access an object. Upon execution, RAII ensures the release of all the resources required by the function to control the object. Upon failure of RAII, In reverse sequence of initialization, all resources collected by each fully-constructed member and base subobject are freed. It also has a automatic storage duration governed by a the lifetime of a temporary object. It is also known as "scoped resource management".


