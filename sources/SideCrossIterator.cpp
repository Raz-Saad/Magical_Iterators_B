#include "MagicalContainer.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;

namespace ariel
{
    // constructor, isEndIterator true if we want to set the iterator to end , false to begin
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container, bool isEndIterator) : m_container(container), m_decisive(0)
    {
        if (isEndIterator || m_container.m_array.empty())
        {
            m_start_iter = m_container.m_array.end(); // set iterator to end
            m_end_iter = m_container.m_array.end();   // set iterator to end
        }
        else
        {
            m_start_iter = m_container.m_array.begin(); // set iterator to begin
            m_end_iter = --m_container.m_array.end();   // set iterator to point to the last spot on the vector
        }
    }
    // copy constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : m_container(other.m_container)
    {
        // Copy the iterator position
        m_start_iter = other.m_start_iter;
        m_end_iter = other.m_end_iter;
        m_decisive = other.m_decisive;
    }
    
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
    {
        if (&m_container != &other.m_container)
        { // checking if the container are not the same
            throw std::runtime_error("Not the same container");
        }

        if (this != &other)
        { // set all the members of this class to be the same as the other
            m_start_iter = other.m_start_iter;
            m_end_iter = other.m_end_iter;
            m_decisive = other.m_decisive;
        }
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
    {
        return ((this->m_start_iter == other.m_start_iter) && (this->m_end_iter == other.m_end_iter));
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
    {
        return (m_start_iter > other.m_start_iter);
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
    {
        return !((*this == other) || (*this > other));
    }
    // return the value of the element that the iterator is points at
    int MagicalContainer::SideCrossIterator::operator*()
    { // 0 - return whats m_start_iter is pointing at. 1 -return whats m_end_iter is pointing at.
        // 2 - we are the the end of the container so we return 0
        switch (m_decisive)
        {
        case 0:
            return *m_start_iter;
            break;
        case 1:
            return *m_end_iter;
            break;
        case 2:
            return 0;
            break;
        default:
            return 0;
        }
    }
    // increasing the iteartor by 1
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {   //m_decisive explanation:
        // m_decisive = 0 - we are looking at the m_start_iter.
        // m_decisive = 1 - we are looking at the m_end_iter.
        // m_decisive = 2 - we are looking at the end of the container.

        if (m_decisive == 2)
        {
            m_end_iter = m_container.m_array.end();
            m_start_iter = m_container.m_array.end();
            throw std::runtime_error("Iterating beyond end");
        }
        // if the size of the container is even we need to check if end==start on m_end_iter turn
        if (m_container.size() % 2 == 0)
        {
            if (m_decisive == 0)
            { // we increase the iterator by 1 and then update decisive to 1 so next turn we will look at m_end_iter
                ++m_start_iter;
                m_decisive = 1;
                return *this;
            }
            if (m_decisive == 1)
            {
                if (*m_end_iter == *m_start_iter)
                { // if m_end_iter == m_start_iter we want to set decisive to 2 so we know that we are at the end
                    m_decisive = 2;
                    m_end_iter = m_container.m_array.end();
                    m_start_iter = m_container.m_array.end();
                }
                else
                { // we decrease the iterator by 1 and then update decisive to 0 so next turn we will look at m_start_iter
                    --m_end_iter;
                    m_decisive = 0;
                }

                return *this;
            }
        }
        else // if the size of the container is odd we need to check if start==end on m_start_iter turn
        {
            if (m_decisive == 1)
            { // we decrease the iterator by 1 and then update decisive to 0 so next turn we will look at m_start_iter
                --m_end_iter;
                m_decisive = 0;
                return *this;
            }
            if (m_decisive == 0)
            {
                if (*m_end_iter == *m_start_iter)
                { // if the size of the container is odd we need to check if end==start on m_start_iter turn
                    m_decisive = 2;
                    m_end_iter = m_container.m_array.end();
                    m_start_iter = m_container.m_array.end();
                }
                else
                { // we increase the iterator by 1 and then update decisive to 1 so next turn we will look at m_end_iter
                    ++m_start_iter;
                    m_decisive = 1;
                }

                return *this;
            }
        }

        return *this;
    }
    // returns an SideCrossIterator that points to the begin of m_array
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
    {
        return SideCrossIterator(m_container);
    }
    // returns an SideCrossIterator that points to the end of m_array
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
    {
        return SideCrossIterator(m_container, true);
    }
}