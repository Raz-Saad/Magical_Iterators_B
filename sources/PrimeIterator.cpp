#include "MagicalContainer.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;

namespace ariel
{
    // constructor, isEndIterator true if we want to set the iterator to end , false to begin
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container, bool isEndIterator) : m_container(container)
    {
        if (isEndIterator)
        {                                             // only if we call this constructor from end fucntion m_iter = to end
            m_iter = m_container.m_prime_array.end(); // set iterator to end
        }
        else
        {
            m_iter = m_container.m_prime_array.begin(); // set iterator to begin
        }
    }
    // copy constructor
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : m_container(other.m_container)
    {
        // copy the iterator position
        m_iter = other.m_iter;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        if (&m_container != &other.m_container)
        { // checking if the container are not the same
            throw std::runtime_error("Not the same container");
        }
        if (this != &other)
        {
            m_iter = other.m_iter;
        }
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
    {
        return (this->m_iter == other.m_iter);
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
    {
        return (m_iter > other.m_iter);
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
    {
        return !((*this == other) || (*this > other));
    }
    // return the value of the element that the iterator is points at
    int MagicalContainer::PrimeIterator::operator*()
    {
        return **m_iter;
    }
    // increasing the iteartor by 1
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        if (m_iter == m_container.m_prime_array.end())
        { // if m_iter points to the end and we try to ++ we throw
            throw std::runtime_error("Iterating beyond end");
        }

        ++m_iter;
        return *this;
    }
    // returns an PrimeIterator that points to the begin of m_array
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
    {
        return PrimeIterator(m_container);
    }
    // returns an PrimeIterator that points to the end of m_array
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
    {
        return PrimeIterator(m_container, true);
    }
}