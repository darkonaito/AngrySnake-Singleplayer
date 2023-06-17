#ifndef DYN_ARR_H_INCLUDED
#define DYN_ARR_H_INCLUDED

template <class T, counter _size>
class DynamicArray
{
    T* elements; //DONE
    counter length; //DONE
    counter dedicated; //DONE
    static counter minDiffer; //DONE

    T& transfer(counter); //DONE

    public:

    DynamicArray(); // DONE

    counter getDedicated() const {return dedicated;} //DONE
    counter getLength() const {return length;} //DONE
    void* getElementsPtr() const {return reinterpret_cast<void*>(elements);} //DONE

    T& append(const T&); //DONE
    T& insert(const T&, counter); //DONE
    bool kickoutLast(); //DONE
    bool remove(counter); //DONE

    T& operator[] (counter); //DONE
    T operator[] (counter) const;
};

template <class T, counter _size>
void writeDynamicArray(const DynamicArray <T, _size>& da);

#include "dyn_arr.cpp"

#endif // DYN_ARR_H_INCLUDED
