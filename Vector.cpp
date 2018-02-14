/***************************************************************
Title:			Vector.cpp
Author:			Mohammed Salam
Date Created:	2/9/2018
Class:			Spring 2018, CSCI 235-03, Mon - Wed 7:00pm-8:15 pm
Professor:		Aarsh Vora
Purpose:		Assignment #1
Description:	Create a vector class that uses dynamic arrays
			    in order to create functions similar to how a vector
			    behaves, such as adding, removing, and returning
			    values in the vector. **Comments in Header Files
***************************************************************/
#include "Vector.h"
#include <cstddef>

Vector::Vector(unsigned int capacity) {
	d_capacity = DEFAULT_CAPACITY;
	d_arr = new int[d_capacity];
	d_size = 0;
}

Vector::~Vector() {
	delete[] d_arr;
}

// copy data to a new vector, rhs
Vector::Vector(const Vector& rhs) {
	d_capacity = rhs.d_capacity;
	d_arr = new int[d_capacity];
	d_size = rhs.d_size;

	for (unsigned int i = 0; i < rhs.d_size; i++) {
		d_arr[i] = rhs.d_arr[i];
	}
}

// copy memory allocated to a new vector, rhs
Vector& Vector::operator=(const Vector& rhs) {
	this->d_capacity = rhs.d_capacity;
	this->d_size = rhs.d_size;
	delete[] this->d_arr;
	this->d_arr = new int[d_capacity];
	for (unsigned int i = 0; i < rhs.d_size; ++i) {
		d_arr[i] = rhs.d_arr[i];
	}
	return *this;
}

// returns max capacity array can hold
unsigned int Vector::capacity() const {
	return d_capacity;
}

// returns number of elements inside dynamic array
unsigned int Vector::size() const {
	return d_size;
}

// if dynamic array is empty return true, false otherwise
bool Vector::empty() const {
	if (d_size == 0) {
		return true;
	}
	else {
		return false;
	}
}

// create temporary array with double the capcity, copy data from one array to another and delete
// memory when applicable
void Vector::resize(unsigned int capacity) {
	int* temparr;
	temparr = new int[capacity * 2];
	for (unsigned int i = 0; i < d_size; i++) {
		temparr[i] = d_arr[i];
	}
	d_capacity = d_capacity * 2;
	delete[] d_arr;
	d_arr = temparr;
	temparr = NULL;
}

// if capacity has been reached, call resize function, otherwise add data to the end of the array
void Vector::push_back(const int& data) {
	if (d_size == d_capacity) {
		resize(d_capacity);
	}
	d_arr[d_size] = data;
	++ d_size;
}

// if data is found within in the array, remove it and shift elements and return true, false otherwise
bool Vector::remove(const int& data) {
	for (unsigned int i = 0; i < d_size; ++i) {
		if (d_arr[i] == data) {
			for (unsigned int j = i; j < d_size; ++j) {
				d_arr[j] = d_arr[j+1];
			}
			--d_size;
			return true;
		}
	}
	return false;
}

//clear array and set new size to 3
void Vector::clear() {
	delete[] d_arr;
	d_size = 0;
	d_arr = new int[3];
}

// return current pos
int& Vector::operator[](unsigned int pos) {
	return d_arr[pos];
}

const int& Vector::operator[](unsigned int pos) const {
	return d_arr[pos];
}

// checks to see if pos is valid, sets data in the current position, returns true if successful, 
// false otherwise
bool Vector::at(unsigned int pos, int& data) const {
	if (pos < d_size && pos >= 0) {
		data = d_arr[pos];
		return true;
	}
	else {
		return false;
	}
}

