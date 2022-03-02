-----
Assignment 4
Md Adnan Karim (7002536)
-----


1. Returning a reference instead of an object is risky since all local objects will be destroyed when the function is exited. Using heap allocated objects, on the other hand, may result in a memory leak. If we utilize static, we can get an unexpected outcome.

2. A templated class with a templated type is an implicit interface. It is made up of valid expressions and is not reliant on function signatures. Polymorphism in implicit interface happens during compilation and is achieved by function overloading resolution.

3. Because we need to write less code, we should utilize range member functions instead of single-element equivalents. It is simpler to write and explain intent in a clear and direct manner. It also demonstrates improved performance.

4. In-place key alteration in a set should be avoided since it may result in an invalid container. If we alter an element from a sorted set, we may discover that the elements are no longer sorted. The right method for changing an item in a set is to copy it first, then remove it from the set. After that, tweak it and re-insert it.

5. Predicate functions should be pure since impure predicate functions might lead to unexpected results. Data is supplied in as arguments or constants, much like in pure functions. If a pure function consults data that is subject to change, it may produce different results at various times and with different input.

6. By default, two capture modes are available: by-reference and by-value. If we use default by-reference capture, we risk having stranded references, and if we use default by-value capture, we risk having dangling pointers. It also implies that lambdas are self-contained, which is not the case. As a result, we should avoid using lambdas' default capture modes.

7. Nothing would be moved via std::move. Instead, It takes an item and turns it into a temporary object. It returns a rvalue reference as an argument. It specifies that the object's value should not be utilized again. Std::forward doesn't do anything either. Depending on how the input was supplied into the current function, it returns either a lvalue or a rvalue reference. It only has one use case: converting a templated function argument to the rvalue or lvalue value category.


8. The content of Std::set is always sorted. The addresses of the strings are sorted in std::setstd::string*>. As a result, the output will be different from what we expect. We'll need to construct our own comparison function object to sort the data lexicographically. 
