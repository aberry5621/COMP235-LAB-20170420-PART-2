# define prog 1

#if(prog == 1)

/*
1. (Individual Assignment) Except for the use of iterators, the following code test the functions that are common to all STL containers. Get rid of the hidden rich code and run it. Since STL “list” (implemented using doubly-linked list) is a sequence container, it should also work for STL vector (implemented using dynamic array). You will convert the code to test STL vector instead, and determine if there is any differences. Copy and paste your code with the screenshots down below:
 */

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

#elif (prog == 2)

/*
 2. (Group assignment – group of 3) The vector code below demonstrated the use of some template functions from the <algorithm> header. Run the code, understand what it does (note that functions are passed as arguments in a couple of examples). Then demonstrate the use of other algorithms (listed below the code below) from the #include <algorithm> header. You should use some online resources to do a little research on your own:
 */

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
    cout << "Fill\t\t\t";
    fill(a.begin()+3, a.begin()+5, 99);
    for_each(a.begin(), a.end(), show<int>);
    
    cout << endl; // space before next e.g
    
    //6.    remove
    cout << "Remove\t\t\t";
    remove(a.begin(), a.end(), a[1]);
    for_each(a.begin(), a.end(), show<int>);
    
    cout << endl; // space before next e.g
    
    //7.    search
    cout << "Search\t\t\t";
    vector<int> sequence{88, 72, 94};
    vector<int>::iterator itr;
    itr = search(a.begin(), a.end(), a.begin()+4, a.begin()+7);

    if (itr != a.end()) {
        cout << " \"88, 72, 94\" found at pos " << itr-a.begin();
    } else {
        cout << " \"88, 72, 94\" not found!";
    }
    
    cout << endl; // space before next e.g
    
    //8.    swap
    cout << "Swap\t\t\t";
    int swap_flag = 0;
    for (int i = 0; i < 10; i++) {
        swap(a[swap_flag], a[swap_flag + 1]);
        swap_flag += 2;
    }
    for_each(a.begin(), a.end(), show<int>);
    
    cout << endl; // space before next e.g
    
    //9.    swap range
    cout << "Swap Ranges\t\t";
    
    swap_ranges(a.begin(), a.begin()+3, a.begin()+6);
    for_each(a.begin(), a.end(), show<int>);
    
    cout << endl; // space before next e.g
    
    //10.    count
    cout << "Count\t\t\t";
    
    cout <<  " 85 count is: " << count(a.begin(), a.end(), 85);
    
    cout << endl; // space before next e.g
    
    //11.    minimum
    cout << "Minimum\t\t\t";
    cout << " Min of a[2] and a[3]: " << min(a[2], a[3]);

    cout << endl; // space before next e.g
    
    
    //12.    maximum
    cout << "Maximum\t\t\t";
    cout << " Max of a[2] and a[3]: " << max(a[2], a[3]);
    
    cout << endl; // space before next e.g
    
    //13.    equal
    cout << "Equal\t\t\t";
    
    int myints[] = {94, 99, 97};
    
    cout << " Range is equal: "  << boolalpha << equal(a.begin()+2, a.begin()+4, myints);
    
    cout << endl; // space before next e.g
    
    //14.    for_each
    cout << "For Each\t\t";
    
    vector<int>::iterator itr8r = a.begin();
    for_each(a.begin(), a.end(), [&](int i) {
        *itr8r = *itr8r - 3;
        *itr8r++;
    });
    
    for_each(a.begin(), a.end(), show<int>);
    
    cout << endl; // space before next e.g
    
    //15.    find_if
    cout << "Find If\t\t\t";
    
    vector<int>::iterator itr15 = find_if(a.begin(), a.end(), [&](int& i) -> bool { return (i % 2 == 0);});
    cout << " First even value found: " << *itr15;
    
    cout << endl; // space before next e.g
    
    //16.    binary_search
    cout << "Binary Search\t";

    if (binary_search (a.begin(), a.end(), 95))
        cout << " Found 95!";
    else
        cout << " Did not find 95!";
    
    cout << endl; // space before next e.g
    
    //17.    merge
    cout << "Merge\t\t\t";
    vector<int> b(5);
    vector<int> c(5);
    generate(b.begin(), b.end(), myRandGenerator);
    generate(c.begin(), c.end(), myRandGenerator);
    merge(b.begin(),b.begin()+5,c.begin(),c.begin()+5,a.begin());
    
    for_each(a.begin(), a.end(), show<int>);
    
    cout << endl; // space before next e.g
    
    //18.    copy
    cout << "Copy\t\t\t";
    vector<int> d(10);
    copy(a.begin(), a.end(), d.begin());
    for_each(d.begin(), d.end(), show<int>);
    
    cout << endl; // space before next e.g
    
    //19.    lexicographic_compare
    cout << "Lexicographic Compare\t\t";
    
    char a1[5] = {'A', 'p', 'p', 'l', 'e'};
    char b1[6] = {'b', 'a', 'n', 'a', 'n', 'a'};

    cout << "Is a1 < b1?: " << lexicographical_compare(a1,a1+5,b1,b1+6);
    
    
    cout << endl; // space before next e.g

    return 0;
}


#endif
