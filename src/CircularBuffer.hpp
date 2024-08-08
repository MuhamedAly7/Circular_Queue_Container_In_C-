#ifndef _CIRCULARBUFFER_H_
#define _CIRCULARBUFFER_H_
#include <array>
#include <cstdint>
#include <stdexcept>

template <typename T, uint32_t SIZE>
class CircularBuffer
{
public:
    CircularBuffer() : m_head(0), m_tail(0), m_currentsize(0){}
    void push_back(T value)
    {
        // update container
        if(m_tail >= SIZE)
        {
            m_tail = 0;
        }

        if(m_head == m_tail && m_currentsize > 0)
        {
            m_head++;
            if(m_head >= SIZE)
            {
                m_head = 0;
            }
        }

        // update tail
        m_container.at(m_tail) = value;
        m_tail++;

        // update size
        m_currentsize++;
        if(m_currentsize > SIZE)
        {
            m_currentsize = SIZE;
        }

    }
    void pop()
    {
        if(empty())
        {
            throw std::runtime_error("buffer is already empty");
            // buffer is empty
        }

        if(m_currentsize == 1)
        {
            m_currentsize--;
            return;
        }

        m_head++;

        if(m_head == SIZE)
        {
            m_head = 0;
        }
        m_currentsize--;
    }
    T const& head()
    {
        return m_container[m_head];
    }
    T const& tail()
    {
        return m_container[m_tail];
    }
    uint32_t const getsize()
    {
        return m_currentsize;
    }
    bool empty()
    {
        return (m_currentsize == 0);
    }
private:
    uint32_t m_head;
    uint32_t m_tail;
    uint32_t m_currentsize;
    std::array<T, SIZE> m_container{};
};

#endif // !_CIRCULARBUFFER_H_