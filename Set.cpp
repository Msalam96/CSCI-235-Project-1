/***************************************************************
Title:			Set.cpp
Author:			Mohammed Salam
Date Created:	2/9/2018
Class:			Spring 2018, CSCI 235-03, Mon - Wed 7:00pm-8:15 pm
Professor:		Aarsh Vora
Purpose:		Assignment #1
Description:	A class Set that is a set of unique integers that tests
				whether our Vector class was implemented properly by using
				the functions we created in the Vector class. **Functions
				defined in header class**
***************************************************************/
#include "Set.h"

//Returns the current number of elements in the set.
unsigned int Set::size() const {
	return d_vector.size();
}

//If the set contains zero elements, returns true; otherwise, returns false.
bool Set::empty() const {
	if (d_vector.size() == 0) {
		return true;
	}
	else {
		return false;
	}
}

//If the set contains data, returns true; otherwise, returns false.
bool Set::contains(const int& data) const {
	int temp;
	for (unsigned int i = 0; i < d_vector.size(); ++i) {
		d_vector.at(i, temp);
		if (temp == data) {
			return true;
		}
	}
	return false;
}

// If the Set does not already contain data, adds a new element, data, to the Set
bool Set::insert(const int& data) {
	if (contains(data) == true) {
		return false;
	}
	else {
		d_vector.push_back(data);
		return true;
	}
}

// If the Set contains data, removes data from the Set
bool Set::remove(const int& data) {
	if (contains(data) == false) {
		return false;
	}
	else {
		d_vector.remove(data);
		return true;
	}
}

// Empties the Set of its elements
void Set::clear() {
	d_vector.clear();
}