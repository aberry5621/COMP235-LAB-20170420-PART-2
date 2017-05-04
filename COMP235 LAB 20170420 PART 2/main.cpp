// individual assignment

/*
 except for the use of iterators
 following code test functions
 common to all STL containers
 get rid of hidden rich code
 and run it
 
 since STL list(doubly linked list
 is a sequence container
 it should work for STL vector
 implemented using dynamic array
 
 convert the code to test stl vector instead
 and determine any differences
 */

# define prog 3

#if(prog == 1)

#include <list>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    /*** Test common functions of containers ***/
    //default constructors
    list<int> myList1;
    
    //Get an appropriate iterator for myList1
    list<int>::iterator iter1 = myList1.begin();
    
    //insert(pos, elem), 'pos' is an iterator
    myList1.insert(iter1, 111);
    myList1.insert(iter1, 222);
    myList1.insert(iter1, 333);
    
    //copy constructor
    list<int> myList2(myList1);
    
    //Get an appropriate iterator for myList1
    list<int>::iterator iter2 = myList2.begin();
    
    //erase(begin, end)
    myList2.erase(++iter2, myList2.end());
    
    //empty( )
    cout << boolalpha;
    if (!myList1.empty()) cout << "myList1.empty() returns: " << myList1.empty() << endl;
    //size( )
    if (!myList1.empty()) cout << "myList1.size() returns: " << myList1.size() << endl;
    if (!myList2.empty()) cout << "myList2.size() returns: " << myList2.size() << endl;
    //max_size( )
    if (!myList1.empty()) cout << "myList1.max_size() returns: " << myList1.max_size() << endl;
    //Question 1: Is MyList2 a shallow or deep copy of myList2? Why?
    
    //swap( )
    myList1.swap(myList2);
    
    if (!myList1.empty()) cout << "myList1.size() returns: " << myList1.size() << endl;
    cout << "Content of myList1..." << endl;
    iter1 = myList1.begin();
    while (iter1 != myList1.end())
    {
        cout << *iter1 << ' ';
        iter1++;
    }
    cout << endl;
    
    if (!myList2.empty()) cout << "myList2.size() returns: " << myList2.size() << endl;
    cout << "Content of myList2..." << endl;
    iter2 = myList2.begin();
    while (iter2 != myList2.end())
    {
        cout << *iter2 << ' ';
        iter2++;
    }
    
    cout << endl;
    
    //begin( ) and end ( )
    //for (list<int>::iterator forwardIter = myList2.begin(); forwardIter != myList2.end(); forwardIter++)
    cout << "Display list 2 forward..." << endl;
    for (auto myForwardIter = myList2.begin(); myForwardIter != myList2.end(); myForwardIter++)
        cout << *myForwardIter << ' ';
    cout << endl;
    
    //rbegin( ) and rend ( )
    cout << "Display list 2 in reverse..." << endl;
    for (auto myReverseIter = myList2.rbegin(); myReverseIter != myList2.rend(); myReverseIter++)
        cout << *myReverseIter << ' ';
    cout << endl;
    
    return 0;
}

#elif(prog == 2)

#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    /*** Test common functions of containers ***/
    //default constructors
    vector<int> myVector1;
    
    //Get an appropriate iterator for myVector1
    vector<int>::iterator itr = myVector1.begin();
    
    //insert(pos, elem), 'pos' is an iterator
    myVector1.insert(itr, 111);
    
    itr = myVector1.begin();
    
    // iterator should break after adding item to vector
    // so reset it
    
    myVector1.insert(itr, 222);
    
    itr = myVector1.begin();
    
    myVector1.insert(itr, 333);
    
    //copy constructor
    vector<int> myVector2(myVector1);
    
    //Get an appropriate iterator for myList1
    vector<int>::iterator iter2 = myVector2.begin();
    
    //erase(begin, end)
    myVector2.erase(++iter2, myVector2.end());
    
    //empty( )
    cout << boolalpha;
    if (!myVector1.empty()) cout << "myVector1.empty() returns: " << myVector1.empty() << endl;
    //size( )
    if (!myVector1.empty()) cout << "myVector1.size() returns: " << myVector1.size() << endl;
    if (!myVector2.empty()) cout << "myVector2.size() returns: " << myVector2.size() << endl;
    //max_size( )
    if (!myVector1.empty()) cout << "myVector1.max_size() returns: " << myVector1.max_size() << endl;
    //Question 1: Is MyVector2 a shallow or deep copy of myVector2? Why?
    
    //swap( )
    myVector1.swap(myVector2);
    
    if (!myVector1.empty()) cout << "myVector1.size() returns: " << myVector1.size() << endl;
    cout << "Content of myVector1..." << endl;
    itr = myVector1.begin();
    while (itr != myVector1.end())
    {
        cout << *itr << ' ';
        itr++;
    }
    cout << endl;
    
    if (!myVector2.empty()) cout << "myVector2.size() returns: " << myVector2.size() << endl;
    cout << "Content of myVector2..." << endl;
    iter2 = myVector2.begin();
    while (iter2 != myVector2.end())
    {
        cout << *iter2 << ' ';
        iter2++;
    }
    
    cout << endl;
    
    //begin( ) and end ( )
    //for (list<int>::iterator forwardIter = myList2.begin(); forwardIter != myList2.end(); forwardIter++)
    cout << "Display vector 2 forward..." << endl;
    for (auto myForwardIter = myVector2.begin(); myForwardIter != myVector2.end(); myForwardIter++)
        cout << *myForwardIter << ' ';
    cout << endl;
    
    //rbegin( ) and rend ( )
    cout << "Display vector 2 in reverse..." << endl;
    for (auto myReverseIter = myVector2.rbegin(); myReverseIter != myVector2.rend(); myReverseIter++)
        cout << *myReverseIter << ' ';
    cout << endl;
    
    return 0;
}

#elif (prog == 3)

//Testing functions from the algorithm header
//Note: New syntax to you, passing functions as arguments, some for_each( ) and generate( )

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int myRandGenerator()
{
    return 50 + rand() % (100 - 50 + 1);
}

template<class T>
void show(T item)
{
    cout << ' ' << item;
}

int main()
{
    vector<int> a(10);
    cout << "Vector size = " << a.size() << endl;
    
    cout << "Generate\t\t";
    generate(a.begin(), a.end(), myRandGenerator);
    for_each(a.begin(), a.end(), show<int>);
    cout << endl;
    
    cout << "Reversed\t\t";
    reverse(a.begin(), a.end());
    for_each(a.begin(), a.end(), show<int>);
    cout << endl;
    
    cout << "Shuffled\t\t";
    random_shuffle(a.begin(), a.end());
    for_each(a.begin(), a.end(), show<int>);
    cout << endl;
    
    cout << "Sorted\t\t\t";
    sort(a.begin(), a.end());
    for_each(a.begin(), a.end(), show<int>);
    cout << endl;
    
    //1.    rotate
    cout << "Rotate\t\t\t";
    rotate(a.begin(), a.begin() + 4, a.end());
    for_each(a.begin(), a.end(), show<int>);
    cout << endl;
    
    //2.    rotate_copy
    cout << "Rotate Copy\t\t";
    rotate_copy(a.begin(), a.begin() + 3, a.end(), a.begin());
    for_each(a.begin(), a.end(), show<int>);
    cout << endl;
    
    //3.    find
    cout << "Find\t\t\t";
    // find (InputIterator first, InputIterator last, const T& val);
    vector<int>::iterator find_it;
    // hard code 42, maybe will find it maybe not
    find_it = find(a.begin(), a.end(), 42);
    if (find_it != a.end()) {
        cout << " Found it: " << *find_it;
    } else {
        cout << " Did not find it.";
    }
    cout << endl;
    
    //4.    replace
    cout << "Replace\t\t\t";
    replace(a.begin(), a.end(), a[3], 99);
    for_each(a.begin(), a.end(), show<int>);
    
    cout << endl; // space before next e.g.
    
    //5.    fill
    //6.    remove
    //7.    search
    //8.    swap
    //9.    swap range
    //10.    count
    //11.    minimum
    //12.    maximum
    //13.    equal
    //14.    for_each
    //15.    find_if
    //16.    binary_search
    //17.    merge
    //18.    copy
    //19.    lexicographic_compare
    
    
    
    return 0;
}


#endif
