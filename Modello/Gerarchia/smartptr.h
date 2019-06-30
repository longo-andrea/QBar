#ifndef SMARTPTR_H
#define SMARTPTR_H

template <class T>
class SmartPtr {
private:
    T* ptr;

public:
    SmartPtr(T* = nullptr);
    SmartPtr(const SmartPtr&);
    SmartPtr& operator=(const SmartPtr&);
    ~SmartPtr();

    T& operator*() const;
    T* operator->() const;

    bool operator ==(const SmartPtr<T>&) const;
    bool operator !=(const SmartPtr<T>&) const;
};

template <class T>
SmartPtr<T>::SmartPtr(T* ptr_obj) : ptr(ptr_obj) {}

template <class T>
SmartPtr<T>::SmartPtr(const SmartPtr& ptrCopy) : ptr(ptrCopy != nullptr ? ptrCopy.ptr->clone() : nullptr) {}

template <class T>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr& ptrCopy) {
    if (&ptrCopy == this)
        return *this;

    if (ptr)
        delete ptr;

    if (ptrCopy.ptr != nullptr)
        ptr = ptrCopy.ptr->clone();
    else
        ptr = nullptr;

    return *this;
}

template <class T>
SmartPtr<T>::~SmartPtr() {
    if(ptr)
        delete ptr;;
}

template <class T>
T& SmartPtr<T>::operator* () const {
    return *ptr;
}

template <class T>
T* SmartPtr<T>::operator-> () const {
    return ptr;
}

template <class T>
bool SmartPtr<T>::operator==(const SmartPtr<T>& s) const {
        *ptr == *(s.ptr);
}

template <class T>
bool SmartPtr<T>::operator!=(const SmartPtr<T>& s) const {
    *(ptr) != *(s.ptr);
}

#endif // SMARTPTR_H

