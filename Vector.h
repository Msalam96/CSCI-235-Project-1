#ifndef __CS235_VECTOR_H_
#define __CS235_VECTOR_H_

class Vector {
  public:

   /** Vector() - default constructor 
 	*  @param	int	capacity 	[in]	default capacity
 	*/
	Vector(unsigned int capacity = DEFAULT_CAPACITY);

	/** ~Vector() - default destructor 
	 *	@pre 	none
 	 *	@post 	delete memory allocated
 	 */
	~Vector();

	/** Vector() - copy assignment operator, that copies over data 
			   	   from rhs to d_arr
 	 *	@param vector 	rhs		[in]	vector for data to be copied from
 	 *	@pre 	none
 	 *	@post 	rhs is copied into d_arr
 	 */
	Vector(const Vector& rhs);

	/** operator=() - overloaded copy assignment operator. similar to 
				  	  copy assignment operator, except the memory allocated
				  	  is copied instead of the actual data.
 	*	@param	Vector 	rhs		[in]	vector
 	*	@return memory allocated to the current index this is pointing too
 	*	@pre 	none
 	*	@post 	data and memory is allocated from rhs
 	*/
	Vector& operator=(const Vector& rhs);

	/** capacity() - Returns the size of the space currently 
				 	 allocated for the vector.
 	*	@pre 	none
 	*	@post	none
 	*	@return an int, d_capacity
 	*/
	unsigned int capacity() const;
	
	/** size() - Returns the current number of elements in 
			 the vector.
 	*	@pre 	none
 	*	@post	none
 	*	@return an int, d_size
 	*/
	unsigned int size() const;
	
	/** empty() - If the vector contains 0 elements, return 
			  	  true; otherwise, return false.
 	*	@pre 	none
 	*	@post	none
 	*	@return true if there is 0 elements in the array, false 
 				otherwise
 	*/	
 	bool empty() const;
	
	/** push_back() - Add data to the end of the vector, doubling the size 
				  	  of the underlying dynamic array if necessary.
				  	  **If the size fo the array has met the capacity, the resize
				  	  function is called and data is inserted to last position.
				  	  Size of the array is always incremented. 
	@param	int 	data	[in]	data to be inserted
 	*/
	void push_back(const int& data);
	
	/** remove() -  If the vector contains data, removes the first instance of data 
					from the vector, and returns true; otherwise, returns false. You 
					will need to shift elements if the element being removed is not the 
					last element in the vector.
 	*	@param	int 	data	[in]	data to be removed
 	*	@pre 	none
 	*	@post 	removes data from array and shifts element
	 *	@return true if the data was successfully removed, false otherwise.
 	*/	
 	bool remove(const int& data);
	
	/** clear() - Empties the vector of its elements and resets the capacity to 3.
 	*	@pre 	none
 	*	@pos 	clears array
 	*/	
 	void clear();

	/** operator[]() - returns element in pos requested.
 	*  @param	int 	pos 	[in]	position of the array
 	*  @return data in the position passed through
 	*/
	int& operator[](unsigned int pos);
	const int& operator[](unsigned int pos) const;

	/** at() - If the position pos is valid set the value of data to the element in the 
		   	   vector at position pos. Return true on success, false on failure. 
 	*	@param	int 	pos 	[in]	position/index number of the array
 	*	@param	int 	data	[in]	data to be inserted in position
 	*	@return returns true if the position is less than the size of the array and data can be
 				inserted into that position, false otherwise. 
 	*/
	bool at(unsigned int pos, int& data) const;


  private:
	int* d_arr;
	unsigned int d_size;
	unsigned int d_capacity;

	static const unsigned int DEFAULT_CAPACITY = 3;

	/** resize() - Creates a temporary int array pointer that points
			   	   to an array with double the capacity. Information from 
			   	   the current array is then passed to the temporary array.
			   	   D_capacity is then multipled by 2 as the default
			   	   capacity has been changed. The current array is deleted.
			   	   The temp array is then assigned to d_arr and the temp is 
			   	   then set to null. 
 	*	@param	int	capacity 	[in]	current array capacity 	
 	*	@pre 	none
 	*	@post 	resize array to double its capacity
 	*/	
 	void resize(unsigned int capacity);
	
};

#endif