#pragma once
#include <vector>
using namespace std;

namespace ariel
{

    class MagicalContainer
    {
    private:
        vector<int> m_array;
        vector<int *> m_prime_array; // array of int* that points to the prime numbers in m_array
        bool isPrime(int num);       // checking if a number is a prime number
        void reorder_prime();        // reorder the pointer to prime numbers in m_prime_array

    public:
        MagicalContainer();              // constructor
        void addElement(int element);    // adding an element to the m_array and pointers m_prime_array to prime elements
        void removeElement(int element); // removing an element from m_array and m_prime_array if the element is prime
        size_t size();                   // return the size of m_array

        class AscendingIterator
        {
        public:
            AscendingIterator(MagicalContainer &container, bool isEndIterator = false); // constructor, isEndIterator true if we want to set the iterator to end , false to begin
            AscendingIterator(const AscendingIterator &other);                          // copy constructor
            ~AscendingIterator() = default;                                             // default destructor

            AscendingIterator &operator=(const AscendingIterator &other);
            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            int operator*();                 // return the value of the element that the iterator is points at
            AscendingIterator &operator++(); // increasing the iteartor by 1
            AscendingIterator begin();       // returns an AscendingIterator that points to the begin of m_array
            AscendingIterator end();         // returns an AscendingIterator that points to the end of m_array

        private:
            vector<int>::iterator m_iter;  // iterator that moving on m_array vector of m_container
            MagicalContainer &m_container; // refernce to the magical container
        };

        class SideCrossIterator
        {
        public:
            SideCrossIterator(MagicalContainer &container, bool isEndIterator = false); // constructor, isEndIterator true if we want to set the iterator to end , false to begin
            SideCrossIterator(const SideCrossIterator &other);                          // copy constructor
            ~SideCrossIterator() = default;                                             // default destructor

            SideCrossIterator &operator=(const SideCrossIterator &other);
            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            int operator*();                 // return the value of the element that the iterator is points at
            SideCrossIterator &operator++(); // increasing the iteartor by 1
            SideCrossIterator begin();       // returns an SideCrossIterator that points to the begin of m_array
            SideCrossIterator end();         // returns an SideCrossIterator that points to the end of m_array

        private:
            vector<int>::iterator m_start_iter; // iterator that starts from the beginning of m_array
            vector<int>::iterator m_end_iter;   // iterator that starts from the end of m_array
            size_t m_decisive;                  // to decide whice iterator we should return. 0 - m_start_iter , 1 - m_end_iter , 2 - nullptr , 3 - throw
            MagicalContainer &m_container;      // refernce to the magical container
        };

        class PrimeIterator
        {
        public:
            PrimeIterator(MagicalContainer &container, bool isEndIterator = false); // constructor, isEndIterator true if we want to set the iterator to end , false to begin
            PrimeIterator(const PrimeIterator &other);                              // copy constructor
            ~PrimeIterator() = default;                                             // default destructor

            PrimeIterator &operator=(const PrimeIterator &other);
            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            int operator*();             // return the value of the element that the iterator is points at
            PrimeIterator &operator++(); // increasing the iteartor by 1
            PrimeIterator begin();       // returns an PrimeIterator that points to the begin of m_array
            PrimeIterator end();         // returns an PrimeIterator that points to the end of m_array

        private:
            vector<int *>::iterator m_iter; // iterator that moving on m_array vector of m_container
            MagicalContainer &m_container;  // refernce to the magical container
        };
    };
}