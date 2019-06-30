#ifndef QONTAINER_H
#define QONTAINER_H

#include <iostream>
#include <algorithm>

template <class T>
class Qontainer {
private:
	T* buffer;
	unsigned int size;
	unsigned int capacity;

	static unsigned int DEFAULT_CAPACITY;

	void resize();

public:
    class iterator;
    class const_iterator;

	class iterator {
		friend class Qontainer<T>;
	private:
		T* item;
		iterator(T* = nullptr);
	public:
        typedef std::forward_iterator_tag iterator_category;
        typedef iterator self_type;
        typedef T value_type;
        typedef T& reference;
        typedef T* pointer;
		typedef int difference_type;

		T& operator*() const;
		T* operator->() const;

		iterator& operator++();
		iterator operator++(int);
		iterator operator+(int) const;
		iterator& operator+=(int);
		iterator& operator--();
		iterator operator--(int);
		iterator operator-(int) const;
		iterator& operator-=(int);

        bool operator==(const const_iterator&) const;
        bool operator!=(const const_iterator&) const;
		bool operator==(const iterator&) const;
		bool operator!=(const iterator&) const;
		bool operator<(const iterator&) const;
		bool operator>(const iterator&) const;

	};

	class const_iterator {
		friend class Qontainer<T>;
	private:
		const T* item;
		const_iterator(const T* = nullptr);
	public:
	        typedef std::forward_iterator_tag iterator_category;
        	typedef iterator self_type;
        	typedef T value_type;
        	typedef T& reference;
        	typedef T* pointer;
		typedef int difference_type;
		
		const T& operator*() const;
		const T* operator->() const;

		const_iterator& operator++();
		const_iterator operator++(int);
		const_iterator operator+(int) const;
		const_iterator& operator+=(int);
		const_iterator& operator--();
		const_iterator operator--(int);
		const_iterator operator-(int) const;
		const_iterator& operator-=(int);

		bool operator==(const const_iterator&) const;
		bool operator!=(const const_iterator&) const;
		bool operator<(const const_iterator&) const;
		bool operator>(const const_iterator&) const;
	};
	
	Qontainer(unsigned int = DEFAULT_CAPACITY);
	Qontainer(const T&, unsigned int);
	Qontainer(const Qontainer<T>&);
	Qontainer<T>& operator= (const Qontainer<T>&);
	~Qontainer();

	int getSize() const;
	bool isEmpty() const;
	int getCapacity() const;

	T& operator[] (int);
	const T& operator[](int) const;
	T& at(int);
	const T& at(int) const;
	T& front();
	const T& front() const;
	T& back();
	const T& back() const;

	iterator begin();
	const_iterator begin() const;
	const_iterator cbegin() const;
	iterator end();
	const_iterator end() const;
	const_iterator cend() const;

	void push_back(const T&);
	void pop_back();
    void remove(const T&);
    iterator erase(iterator);
	void clear();

	iterator search(const T&);

	bool operator==(const Qontainer<T>&) const;
	bool operator!=(const Qontainer<T>&) const;
};

/* ----- STATIC ----- */
template <class T>
unsigned int Qontainer<T>::DEFAULT_CAPACITY = 2;

/* ----- ITERATOR ----- */
template<class T>
Qontainer<T>::iterator::iterator(T* item) : item(item) {}

template <class T>
T& Qontainer<T>::iterator::operator*() const {
	return *item;
}

template <class T>
T* Qontainer<T>::iterator::operator->() const {
	return item;
}

template <class T>
typename Qontainer<T>::iterator& Qontainer<T>::iterator::operator++() {
	item++;
	return *this;
}

template <class T>
typename Qontainer<T>::iterator Qontainer<T>::iterator::operator++(int) {
	iterator old = iterator(*this);
	item++;
	return old;
}

template <class T>
typename Qontainer<T>::iterator Qontainer<T>::iterator::operator+(int i) const {
	return iterator(item + i);
}

template <class T>
typename Qontainer<T>::iterator& Qontainer<T>::iterator::operator+=(int i) {
	item += i;
	return *this;
}

template <class T>
typename Qontainer<T>::iterator& Qontainer<T>::iterator::operator--() {
	item--;
	return *this;
}

template <class T>
typename Qontainer<T>::iterator Qontainer<T>::iterator::operator--(int) {
	iterator old = iterator(*this);
	item--;
	return old;
}

template <class T>
typename Qontainer<T>::iterator Qontainer<T>::iterator::operator-(int i) const {
	return iterator(item - i);
}

template <class T>
typename Qontainer<T>::iterator& Qontainer<T>::iterator::operator-=(int i) {
	item -= i;
	return *this;
}

template <class T>
bool Qontainer<T>::iterator::operator==(const const_iterator& it) const {
    return item == it.item;
}

template <class T>
bool Qontainer<T>::iterator::operator!=(const const_iterator& it) const {
    return item != it.item;
}

template <class T>
bool Qontainer<T>::iterator::operator==(const iterator& it) const {
	return item == it.item;
}

template <class T>
bool Qontainer<T>::iterator::operator!=(const iterator& it) const {
	return item != it.item;
}

template <class T>
bool Qontainer<T>::iterator::operator<(const iterator& it) const {
	return item < it.item;
}

template <class T>
bool Qontainer<T>::iterator::operator>(const iterator& it) const {
	return item > it.item;
}

/* ----- CONST_ITERATOR ----- */
template <class T>
Qontainer<T>::const_iterator::const_iterator(const T* t) : item(t) {}

template <class T>
const T& Qontainer<T>::const_iterator::operator*() const { 
	return *item; 
}

template <class T>
const T* Qontainer<T>::const_iterator::operator->() const {
	return &item;
}

template <class T>
typename Qontainer<T>::const_iterator& Qontainer<T>::const_iterator::operator++() {
	++item;
	return *this;
}

template <class T>
typename Qontainer<T>::const_iterator Qontainer<T>::const_iterator::operator++(int) {
	const_iterator temp = const_iterator(*this);
	item++;
	return temp;
}

template <class T>
typename Qontainer<T>::const_iterator Qontainer<T>::const_iterator::operator+(int index) const {
	return const_iterator(item + index);
}

template <class T>
typename Qontainer<T>::const_iterator& Qontainer<T>::const_iterator::operator+=(int index) {
	item += index;
	return *this;
}

template <class T>
typename Qontainer<T>::const_iterator& Qontainer<T>::const_iterator::operator--() {
	item--;
	return *this;
}

template <class T>
typename Qontainer<T>::const_iterator Qontainer<T>::const_iterator::operator--(int) {
	const_iterator temp = const_iterator(*this);
	item++;
	return temp;
}

template <class T>
typename Qontainer<T>::const_iterator Qontainer<T>::const_iterator::operator-(int index) const {
	return const_iterator(item + index);
}

template <class T>
typename Qontainer<T>::const_iterator& Qontainer<T>::const_iterator::operator-=(int index) {
	item -= index;
	return *this;
}

template <class T>
bool Qontainer<T>::const_iterator::operator==(const const_iterator& it) const {
	return item == it.item;
}

template <class T>
bool Qontainer<T>::const_iterator::operator!=(const const_iterator& it) const {
	return item != it.item;
}

template <class T>
bool Qontainer<T>::const_iterator::operator<(const const_iterator& it) const {
	return item < it.item;
}

template <class T>
bool Qontainer<T>::const_iterator::operator>(const const_iterator& it) const {
	return item > it.item;
}

/* ----- QONTAINER ----- */
template <class T>
Qontainer<T>::Qontainer(unsigned int cp) : buffer(new T[cp]), size(0), capacity(cp) {}

template <class T>
Qontainer<T>::Qontainer(const T& item, unsigned int cp) : buffer(new T[cp]), size(0), capacity(cp) {
	for (int i = 0; i < capacity; i++)
		push_back(item);
}

template <class T>
Qontainer<T>::Qontainer(const Qontainer<T>& toCopy) : buffer(new T[DEFAULT_CAPACITY]), size(0), capacity(DEFAULT_CAPACITY) {
	for (unsigned int i = 0; i < toCopy.size; i++)
		push_back(toCopy.buffer[i]);
}

template <class T>
Qontainer<T>& Qontainer<T>::operator= (const Qontainer<T>& toCopy) {
	if (this != &toCopy) {
		delete[] buffer;
		size = 0;
		capacity = toCopy.capacity;
		buffer = new T[capacity];
		for (unsigned int i = 0; i < toCopy.size; i++)
			push_back(toCopy.buffer[i]);
	}
	return *this;
}

template <class T>
Qontainer<T>::~Qontainer() { if (buffer) delete[] buffer; }

template <class T>
int Qontainer<T>::getSize() const {
	return size;
}

template <class T>
bool Qontainer<T>::isEmpty() const {
	return size == 0;
}

template <class T>
int Qontainer<T>::getCapacity() const {
	return capacity;
}

template <class T>
T& Qontainer<T>::operator[] (int index) { 
	return buffer[index]; 
}

template <class T>
const T& Qontainer<T>::operator[] (int index) const{
	return buffer[index];
}

template <class T>
T& Qontainer<T>::at(int index) {
	return buffer[index];
}

template <class T>
const T& Qontainer<T>::at(int index) const {
	return buffer[index];
}

template <class T>
T& Qontainer<T>::front() {
	return buffer[0];
}

template <class T>
const T& Qontainer<T>::front() const {
	return buffer[0];
}

template <class T>
T& Qontainer<T>::back() {
	return buffer[size - 1];
}

template <class T>
const T& Qontainer<T>::back() const {
	return buffer[size - 1];
}

template <class T>
typename Qontainer<T>::iterator Qontainer<T>::begin() {
	return iterator(buffer);
}

template <class T>
typename Qontainer<T>::const_iterator Qontainer<T>::begin() const {
	return const_iterator(buffer);
}

template <class T>
typename Qontainer<T>::const_iterator Qontainer<T>::cbegin() const {
	return const_iterator(buffer);
}

template <class T>
typename Qontainer<T>::iterator Qontainer<T>::end() {
	return iterator(buffer + size);
}

template <class T>
typename Qontainer<T>::const_iterator Qontainer<T>::end() const {
	return const_iterator(buffer + size);
}

template <class T>
typename Qontainer<T>::const_iterator Qontainer<T>::cend() const {
	return const_iterator(buffer + size);
}

template <class T>
void Qontainer<T>::push_back(const T& item) {
	if (size >= capacity)
		resize();
	buffer[size] = item;
	size++;
}

template <class T>
void Qontainer<T>::pop_back() {
	if (size) {
		size--;
		buffer[size].~T();
	}
}

template<class T>
void Qontainer<T>::remove(const T& t) {
    erase(search(t));
}

template<class T>
typename Qontainer<T>::iterator Qontainer<T>::erase(iterator it){
    if(it == iterator(0) || !size)
        return iterator(0);
    std::copy(it, it+1, it);
    return it;
}

template <class T>
void Qontainer<T>::clear() {
	delete[] buffer;
	buffer = new T[DEFAULT_CAPACITY];
	capacity = DEFAULT_CAPACITY;
	size = 0;
}

template <class T>
typename Qontainer<T>::iterator Qontainer<T>::search(const T& t) {
    iterator it = begin();
    for (;it!=end() && *it!=t;++it);
    if(it==end())
        return iterator(0);
    return it;
}

template <class T>
bool Qontainer<T>::operator==(const Qontainer<T>& q) const {
	if (size == q.size) {
		for (int i = 0; i < size; i++) {
			if (q[i] != buffer[i])
				return false;
		}
		return true;
	}
	else
		return false;
}

template <class T>
bool Qontainer<T>::operator!=(const Qontainer<T>& q) const {
	return !(*this == q);
}

template <class T>
void Qontainer<T>::resize() {
	capacity *= 2;
	T* resized = new T[capacity];
	for (unsigned int i = 0; i < size; i++)
		resized[i] = buffer[i];
	delete[] buffer;
	buffer = resized;
}

#endif // QONTAINER_H
