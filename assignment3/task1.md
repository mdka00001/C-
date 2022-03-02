-----
Empty
-----
-----
#Assignment 3
#Md Adnan Karim 7002536
-----
1. In the computer languages C and C++, typedef is a reserved keyword. It's used to give another data type a new name (alias), but it doesn't generate a new type. In C++, the keyword 'using' is used to specify type synonyms. The alias-declaration approach is another name for this procedure. Defining these alias-declarations is akin to using the 'using' statement in C++ to define variables. It aids in increasing the code's general readability. 

One major difference between "Using" and "typedef" is "Using" can be templatized and utilized to construct generic templates. These templates can be customized in the future to meet your individual needs.‘typedef’ in C++ cannot be templatized unlike ‘using’. 

Implemtation "using":

template<typename T>
using Info = std::unordered_map<Age_info, std::vector<T>>;

Implementation "typedef":

template<typename T>
struct Info {
typedef std::map<Age_info, std::vector<T>> type;
};
Info<Student_Detail>::type Male_info;

2. An iterator is an object (similar to a pointer) that refers to a container element. Iterators may be used to traverse the contents of the container. They may be compared to a pointer pointing to a certain position, and we can use them to retrieve stuff at that specific area. Iterators are important for linking algorithms to containers as well as manipulating data contained inside containers. 
a.Inputiterator: An InputIterator may read and perform increment operations without requiring numerous passes. It applies solely to single-pass algorithms. If the InputIterator is increased, all previous value copies will become invalid.
b. Outputiterator: In contrast to input iterators, which perform the opposite of accessing values and cannot be assigned values, output iterators can be assigned values in a sequence but cannot be used to access values. As a result, we may claim that input and output iterators are mutually beneficial.
c. ForwardIterator: Unlike inputIterator and outputIterator, ForwardIterator can read data from the pointed-to element and can be used in multiple pass algorithms.

3. Inputiterator is a type of one pass iterator, Forward iterator on the other hand is a multipass iterator. After one pass, the resources behind an InputIterator are gone, whereas the resources behind a ForwardIterator are available until invalidation. Inputiterator can only read forward, whereas Forward iterator can both readn and write forward. 

Example; forward iterator x == y implies ++x == ++y, which does not imply for inputiterator.

4. When iterating the vector, the size of the vector can exceed the maximum size, causing a new memory allocation to be made for the vector and all members to be copied there. Our iterator, however, continues to refer to the prior old memory location. As a result, we can now state that the iterator is invalidated. When a new element is added or erased from a vector, the elements are internally shifted, and the existing iterators are invalidated. All this invalidates the current pointer.

5. 
a. std::set: It contains a collection of unique keys that's ordered by keys by definition. Because it is implemented as a red black tree, it is quicker and has a runtime of O(log(n)).

b. std::unordered set: is contains a collection of unique keys that's hashed by keys by definition. Because it is implemented as a hashed table, it is quicker and has an O(1) runtime.

c. std::queue: for this because it only inserts and deletes data at the end. It is quicker, and the insert or remove runtime is O. (1).

d. std::multimap, which stores a sorted list of key-value pairs while allowing multiple entries with the same key.

6. In this case we can consider the find() function to search for a sub-string or a char in a string. The algorithm is mainly parameterized by three operations, which can be specified as functions or function objects. The algorithms signal failure by returning the end of an input sequence. For example, find(begin,end,v) returns failure if v not found.

7. sort(b,e) mainly takes two parameters and utilizes the inequality operator "<" to compare the elements and sort in ascending or descending order as per the user command. 

8. Set1=1,2,3,4 and set2=4,3,2,1 are equal in mathematics. As a result, subscript operator will return different elements for both of the different sets which invalidate the base of mathematical set. 

9. A map is a type of container where elements are stored in a key, value fashion. Here a key points to a value. While copying a map container to refer to the same value as the main map, the key has to be copied as a copy constructor and the value as default constructor.The stl::map requires a constructor without parameters since it is utilized when operator[] is used with a key that hasn't been saved by the map. In this scenario, the operator[] creates a new entry with a new key and value created with the parameterless constructor. After that, the updated value is returned.

10. The first is to prevent the usage of a size() member function as a way to get around the iterator interface. It doesnt  want us to iterate through the list with counting loops. It wants to underline that the node order is a useless indicator; the value of the node payload is what matters. Because the nodes in the list are not always contiguous in memory, std:forwardlist iterators are not fundamental pointer types. In the forward iteration of a std::forward list, complicated pathways may be taken. In a std::forward list, updating a size member and providing a proper result may take longer than in another container.

In forward_list, empty member function is implemented even in case of container.size() == 0. This is because unlike list, forward list can only keep track of its next element. So, even with size equal to 0 might end up leaving the initial elemnt in the forward_list. That is why empty() function is used to check if the forward list container is empty or not.
