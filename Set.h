#ifndef __CS235_SET_H_
#define __CS235_SET_H_

#include "Vector.h"

class Set {
  public:
  	/** size() - Returns the current number of elements in the set,
  				 by calling the size function in the Vector Class
  				 and using d_vector.
  	 * @pre - none
  	 * @post - none
  	 * @return - d_size, which is the number of elements in the set.
  	 */
	unsigned int size() const;
	
	/** empty() - If the vector contains 0 elements, return 
			  	  true; otherwise, return false. The size() function
			  	  of the Vector class will be used again.
 	*	@pre 	none
 	*	@post	none
 	*	@return true if there is 0 elements in the array, false 
 				otherwise
 	*/	
	bool empty() const;

	/** contains() - Checks to see if the set contians int data. The size()
					 and at() functions are used from the Vector class by parsing 
					 through the entire Set, and comparing the value in each position
					 to data.
	*	@param	int 	data	[in]	integer value we are trying to look for in the set
	*	@pre 	none
	*	@pos 	none
	*	@return True if data is found within the Set, false otherwise
	*/
	bool contains(const int& data) const;
	
	/** insert() - Using the contains functions, check to see if data is in the set,
				   if it is not then use the push_back function defined in the Vector
				   class to add it. 
	*	@param	int 	data	[in]	data to add or check to see if it is already added
	*	@pre 	none
	*	@post 	none
	*	@return True if data is not within the set and it is successfully added, false otherwise
	*/
	bool insert(const int& data);

	/** remove() - Using the contain function, check to see if data is in the set,
				   if it is then use the remove function defined in the Vector class
				   to pop it. 
	*	@param	int 	data	[in]	data to remove if in the set
	*	@pre 	none
	*	@post 	none
	*	@return True if data was in the set and is successfully removed, false otherwise
	*/
	bool remove(const int& data);

	/** clear() - Empties the Set of its elements using the clear() function in the Vector
				  class.
 	*	@pre 	none
 	*	@pos 	clears array
 	*/	
	void clear();

  private:
	Vector d_vector;

};

#endif