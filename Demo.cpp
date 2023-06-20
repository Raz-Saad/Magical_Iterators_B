#include <iostream>
#include "sources/MagicalContainer.hpp"

using namespace ariel;
int main()
{

    cout << "===========================" << endl;
    cout << "        original demo:" << endl;
    cout << "===========================" << endl;
    // Create a MagicalContainer and add some elements
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);

    // Print container size
    std::cout << "Size of container: " << container.size() << std::endl;

    // Use AscendingIterator to display elements in ascending order
    std::cout << "Elements in ascending order:\n";
    MagicalContainer::AscendingIterator ascIter(container);
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it)
    {
        std::cout << *it << ' '; // 2 3 9 17 25
    }
    std::cout << std::endl;

    // Use DescendingIterator to display elements in descending order
    std::cout << "Elements in cross order:\n";
    MagicalContainer::SideCrossIterator crossIter(container);
    for (auto it = crossIter.begin(); it != crossIter.end(); ++it)
    {
        std::cout << *it << ' '; // 2 25 3 17 9
    }
    std::cout << std::endl;

    // Use PrimeIterator to display prime numbers only
    std::cout << "Prime numbers:\n";
    MagicalContainer::PrimeIterator primeIter(container);
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it)
    {
        std::cout << *it << ' '; // 2 3 17
    }
    std::cout << std::endl;

    // Remove an element from the container and display the size
    container.removeElement(9);
    std::cout << "Size of container after removing an element: " << container.size() << std::endl;

    cout << "===========================" << endl;
    cout << "         my demo:" << endl;
    cout << "===========================" << endl;

    // create MagicalContainer
    MagicalContainer container2;
    // print size - should be 0
    cout << "the container size: " << container2.size() << endl;
    // add elements
    container2.addElement(17);
    // the same element twice
    container2.addElement(17);
    // print size - should be 1
    cout << "the container size: " << container2.size() << endl;
    // remove element
    container2.removeElement(17);
    // print size - should be 0
    cout << "the container size: " << container2.size() << endl;

    container2.addElement(2);
    container2.addElement(3);
    container2.addElement(5);
    container2.addElement(7);
    container2.addElement(13);
    cout << "container2: (2,3,5,7,13)" << endl;
    // AscendingIterator
    cout << "\n\nAscendingIterator: " << endl;

    // constructor
    MagicalContainer::AscendingIterator asc_iter1(container2);
    // copy constructor
    MagicalContainer::AscendingIterator asc_iter2(asc_iter1);
    // should be true - 1
    cout << "(asc_iter1 == asc_iter2): " << (asc_iter1 == asc_iter2) << endl;
    // Assignment operator
    MagicalContainer::AscendingIterator asc_iter3 = asc_iter1;
    // should be true - 1
    cout << "(asc_iter1 == asc_iter3): " << (asc_iter1 == asc_iter3) << endl;
    // operator!= - should be false -0
    cout << "(asc_iter1 != asc_iter3): " << (asc_iter1 != asc_iter3) << endl;
    // operator++
    ++asc_iter1;
    // operator> - should be true - 1
    cout << "(asc_iter1 > asc_iter3): " << (asc_iter1 > asc_iter3) << endl;
    // operator< - should be false -0
    cout << "(asc_iter1 < asc_iter3): " << (asc_iter1 < asc_iter3) << endl;
    // operator*
    cout << "*asc_iter2: " << *asc_iter2 << endl;
    // begin
    MagicalContainer::AscendingIterator asc_iter4 = asc_iter1.begin();
    cout << "*asc_iter4: " << *asc_iter4 << endl;
    // end
    MagicalContainer::AscendingIterator asc_iter5 = asc_iter4.end();
    // should be true - 1
    cout << "(asc_iter4 != asc_iter5): " << (asc_iter4 != asc_iter5) << endl;

    // SideCrossIterator
    cout << "\n\nSideCrossIterator: " << endl;

    // constructor
    MagicalContainer::SideCrossIterator side_iter1(container2);
    // copy constructor
    MagicalContainer::SideCrossIterator side_iter2(side_iter1);
    // should be true - 1
    cout << "(side_iter1 == side_iter2): " << (side_iter1 == side_iter2) << endl;
    // Assignment operator
    MagicalContainer::SideCrossIterator side_iter3 = side_iter1;
    // should be true - 1
    cout << "(side_iter1 == side_iter3): " << (side_iter1 == side_iter3) << endl;
    // operator!= - should be false -0
    cout << "(side_iter1 != side_iter3): " << (side_iter1 != side_iter3) << endl;
    // operator++
    ++side_iter1;
    // operator> - should be true - 1
    cout << "(side_iter1 > side_iter3): " << (side_iter1 > side_iter3) << endl;
    // operator< - should be false -0
    cout << "(side_iter1 < side_iter3): " << (side_iter1 < side_iter3) << endl;
    // operator*
    cout << "*side_iter2: " << *side_iter2 << endl;
    // begin
    MagicalContainer::SideCrossIterator side_iter4 = side_iter1.begin();
    cout << "*side_iter4: " << *side_iter4 << endl;
    // end
    MagicalContainer::SideCrossIterator side_iter5 = side_iter4.end();
    // should be true - 1
    cout << "(side_iter4 != side_iter5): " << (side_iter4 != side_iter5) << endl;

    // PrimeIterator
    cout << "\n\nPrimeIterator: " << endl;

    // constructor
    MagicalContainer::PrimeIterator prime_iter1(container2);
    // copy constructor
    MagicalContainer::PrimeIterator prime_iter2(prime_iter1);
    // should be true - 1
    cout << "(prime_iter1 == prime_iter2): " << (prime_iter1 == prime_iter2) << endl;
    // Assignment operator
    MagicalContainer::PrimeIterator prime_iter3 = prime_iter1;
    // should be true - 1
    cout << "(prime_iter1 == prime_iter3): " << (prime_iter1 == prime_iter3) << endl;
    // operator!= - should be false -0
    cout << "(prime_iter1 != prime_iter3): " << (prime_iter1 != prime_iter3) << endl;
    // operator++
    ++prime_iter1;
    cout << "++prime_iter1 " << endl;
    // operator> - should be true - 1
    cout << "(prime_iter1 > prime_iter3): " << (prime_iter1 > prime_iter3) << endl;
    // operator< - should be false -0
    cout << "(prime_iter1 < prime_iter3): " << (prime_iter1 < prime_iter3) << endl;
    // operator*
    cout << "*prime_iter1: " << *prime_iter1 << endl;
    // begin
    MagicalContainer::PrimeIterator prime_iter4 = prime_iter1.begin();
    cout << "*prime_iter4: " << *prime_iter4 << endl;
    // end
    MagicalContainer::PrimeIterator prime_iter5 = prime_iter4.end();
    // should be true - 1
    cout << "(prime_iter4 != prime_iter5): " << (prime_iter4 != prime_iter5) << endl;

    cout << "==================" << endl;

    cout << "Adding and deleting elements" << endl;
    cout << "AscendingIterator" << endl;
    MagicalContainer container3;
    container3.addElement(2);
    container3.addElement(3);
    container3.addElement(7);
    container3.addElement(10);
    cout << "container3: (2,3,7,10)" << endl;
    MagicalContainer::AscendingIterator ascend_iter(container3);

    cout << *ascend_iter << endl;
    cout << "++ascend_iter" << endl;
    ++ascend_iter;
    cout << *ascend_iter << endl;
    cout << "++ascend_iter" << endl;
    ++ascend_iter;
    container3.removeElement(2); // deleting an element(3,7,10)
    cout << "deleting element 2 , (3,7,10)" << endl;
    container3.addElement(5); // adding an element (3,5,7,10)
    cout << "adding element 5 , (3,5,7,10)" << endl;
    cout << *ascend_iter << endl;
    cout << "++ascend_iter" << endl;
    ++ascend_iter;
    cout << *ascend_iter << endl;
    container3.removeElement(10); // deleting an element(3,5,7)
    cout << "(ascend_iter == ascend_iter.end()): " << (ascend_iter == ascend_iter.end()) << endl;
    // checking if 3 is the first element as it should be
    cout << "*ascend_iter.begin() == 3: " << (*ascend_iter.begin() == 3) << endl;

    std::cout << "Elements in ascending order:\n";
    MagicalContainer::AscendingIterator ascIter1(container3);
    for (auto it = ascIter1.begin(); it != ascIter1.end(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    cout << "==================" << endl;

    cout << "Adding and deleting elements" << endl;
    cout << "SideCrossIterator" << endl;
    MagicalContainer container4;
    container4.addElement(2);
    container4.addElement(3);
    container4.addElement(5);
    container4.addElement(7);
    container4.addElement(10);
    container4.addElement(12);
    cout << "container4: (2,3,5,7,10,12)" << endl;

    MagicalContainer::SideCrossIterator side_iter(container4);
    // checking AscendingIterator
    cout << *side_iter << endl;
    cout << "++side_iter" << endl;
    ++side_iter;
    cout << *side_iter << endl;
    cout << "++side_iter" << endl;
    ++side_iter;

    cout << "adding element 11 , (2,3,5,7,10,11,12)" << endl;
    container4.addElement(11); // adding an element (2,3,5,7,10,11,12)

    cout << *side_iter << endl;
    cout << "++side_iter" << endl;
    ++side_iter;

    cout << "deleting element 5 , (2,3,7,10,11,12)" << endl;
    container4.removeElement(5); // deleting an element (2,3,7,10,11,12)

    cout << *side_iter << endl;
    cout << "++side_iter" << endl;
    ++side_iter;
    cout << *side_iter << endl;
    cout << "++side_iter" << endl;
    ++side_iter;
    cout << *side_iter << endl;
    cout << "++side_iter" << endl;
    ++side_iter;
    cout << "side_iter == side_iter.end(): " << (side_iter == side_iter.end()) << endl;
    // checking if 3 is the first element as it should be

    cout << "adding element 1 , (1,2,3,7,10,11,12)" << endl;
    container4.addElement(1); // adding an element (1,2,3,7,8,10,11,12)
    // checking if 1 is the first element as it should be
    cout << "*side_iter.begin() == 1: " << (*side_iter.begin() == 1) << endl;

    // Use DescendingIterator to display elements in descending order
    std::cout << "Elements in cross order:\n";
    MagicalContainer::SideCrossIterator crossIter1(container4);
    for (auto it = crossIter1.begin(); it != crossIter1.end(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;


    return 0;
}