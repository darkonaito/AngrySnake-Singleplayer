#include "dyn_arr.hpp"

template <class T, counter _size>
DynamicArray<T, _size>::DynamicArray():
    length(_size),
    dedicated(_size + minDiffer)
{
    try
    {
        elements = new T[dedicated];
    } catch(std::exception &e)
    {
        std::cout << "Error on allocation \"elements = new T[dedicated]\".\n";
    }
}

template <class T, counter _size>
T& DynamicArray<T, _size>::transfer(counter len)
{
    T* tmpPtr;
    try
    {
        tmpPtr = new T[len + minDiffer];
        for(
            counter i = 0;
            i < length;
            tmpPtr[i] = elements[i], i++
           );
        delete [] elements, elements = tmpPtr,
        length = len, dedicated = len + minDiffer;
    } catch(std::exception &e)
    {
        std::cout << "Error on allocation \"T* tmpPtr = new T[len + minDiffer]\".\n";
    }
}

template <class T, counter _size>
T& DynamicArray<T, _size>::append(const T& newE)
{
    if((dedicated - (length + 1) == 0))
    {
        transfer(length + 1);
        elements[length - 1] = newE;
        return elements[length - 1] = newE;
    } else return (elements[length++] = newE);
}

template <class T, counter _size>
bool DynamicArray<T, _size>::kickoutLast()
{
    try
    {
        if((length - 1) != 0)
        {
            delete (elements + length - 1);
            dedicated--;
            length--;
            return 1;
        } return 0;
    } catch(std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
}

template <class T, counter _size>
bool DynamicArray<T, _size>::remove(counter n)
{
    try
    {
        if(n >= (length - 1)) return false;

        kickoutLast();

        for(counter i = n; i < (length); i++)
        {
            elements[i] = elements[i + 1];
        } return true;
    } catch(std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
}

template <class T, counter _size>
T& DynamicArray<T, _size>::insert(const T& newE, counter n)
{
    if((dedicated - (length + 1) == 0)) transfer(length + 1);

    for(short i = length; i > n; i--)
    {
        elements[i] = elements[i - 1];
    }

    elements[n] = newE;
    length++;
}

template <class T, counter _size>
T& DynamicArray<T, _size>::operator[] (counter n)
{
    return elements[n];
}

template <class T, counter _size>
T DynamicArray<T, _size>::operator[] (counter n) const
{
    return elements[n];
}

template <class T, counter _size>
void writeDynamicArray(const DynamicArray <T, _size>& da)
{
    for(counter i = 0; i < da.getLength(); i++)
        std::cout << da[i] << '\n';
}

template <class T, counter _size>
counter DynamicArray<T, _size>::minDiffer = 8;
