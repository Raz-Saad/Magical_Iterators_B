#include "MagicalContainer.hpp"
#include <stdexcept>
#include <iostream>
#include <cmath>
using namespace std;

namespace ariel
{
    // constructor
    MagicalContainer::MagicalContainer()
    {
    }
    // adding an element to the m_array and pointers m_prime_array to prime elements
    void MagicalContainer::addElement(int element)
    {
        std::vector<int>::iterator element_spot; // for holding the spot of element in the vector (for m_prime_array)
        if (m_array.size() == 0)
            m_array.push_back(element);
        else
        {
            auto iter_find = find(m_array.begin(), m_array.end(), element);
            if (iter_find == m_array.end())
            { // checking if the the element is already in the vector, if so we dont want to add it again
                
                //  finding the postion to insert the new element and insert it
                //  the vector will stay in the order from low to high
                auto iter_pos = lower_bound(m_array.begin(), m_array.end(), element);
                element_spot = iter_pos;//saving the postion that we stored the element so we can use it for m_prime array
                m_array.insert(iter_pos, element);
            }
        }

        // after the m_array is sort we want to sort/add elements to m_prime_array
        if (m_prime_array.size() == 0)
        {
            if (isPrime(element))
            {
                m_prime_array.push_back(&(*element_spot));
            }
        }
        else
        {
            reorder_prime();
        }
    }
    // removing an element from m_array and m_prime_array if the element is prime
    void MagicalContainer::removeElement(int element)
    {
        auto iter = find(m_array.begin(), m_array.end(), element);
        if (iter == m_array.end())
        {
            throw std::runtime_error("can not remove unexisting element");
        }

        m_array.erase(iter);

        reorder_prime(); // after we remove an elemnt from m_array we need to update the m_prime_array
    }
    // return the size of m_array
    size_t MagicalContainer::size()
    {
        return m_array.size();
    }
    // checking if a number is a prime number
    bool MagicalContainer::isPrime(int num)
    {
        if (num <= 1)
            return false;

        for (int i = 2; i <= sqrt(num); i++)
        {
            if (num % i == 0)
                return false;
        }

        return true;
    }
    // reorder the pointer to prime numbers in m_prime_array
    void MagicalContainer::reorder_prime()
    {
        m_prime_array.clear(); // remove all the elements from m_prime_array so we can insert them in the right order
        for (auto &num : m_array)
        {
            if (isPrime(num))
            {
                m_prime_array.push_back(&num);
            }
        }
    }
}