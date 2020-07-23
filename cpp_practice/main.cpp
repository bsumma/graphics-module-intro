//
//  main.cpp
//  
//
//  Created by Brian Summa on 8/21/18.
//

#include <iostream>
#include <vector>
#include "vec.h"


//http://www.cplusplus.com/reference/vector/vector/
//http://www.cplusplus.com/reference/cstdio/
//http://www.cplusplus.com/reference/iostream/
//http://www.cplusplus.com/reference/cstring/

using namespace std;
using namespace Angel;

int main()
{

  /* ===================== */
  /*       Pointers        */
  /* ===================== */

  //This is a floating point number set to 100.0
  float my_float = 100.0;
  
  //cout is how you ouput text to screen
  cout << my_float << endl;
  
  //It's just a piece of memory pretending to be a number
  cout << "It is " << sizeof(my_float) << " bytes long" << endl;
  cout << "It's at address " << &my_float  << endl;
  
  //As you can see & means "address of"
  //Pointers are refrences to pieces of memory
  float *my_pointer = &my_float;
  
  //You can dereference the pointer to get the value
  cout << "Dereferenced: " << *my_pointer << endl;

  //You can also change the value
  *my_pointer  = 200;
  cout << "New value: " << my_float << endl;
  
  //Pointers don't need to be pointing to a predefined variable
  int *another_pointer = new int();
  
  *another_pointer = 2;
  cout << "New pointer: " << *another_pointer << endl;

  //1: Create an integer pointer
  
  
  //2: Set its value
  
  
  //3: Print out its address
  
  
  //4: Print out its value

  /* ===================== */
  /*   Arrays and vectors  */
  /* ===================== */

  //Here is a vector of 16 unsigned 8-bit integers:
  std::vector < uint8_t > my_vector_b(16);
  
  //Here is the eqivalent array:
  uint8_t *my_array_b = new uint8_t[16];
  
  //1: Make a vector of 16 32-bit floating point numbers (called floats)
  // my_vector_f
  
  //2: And now the array:
  //my_array_f
  
  //You can iterate over them like Python lists
  for(unsigned int i =0; i < my_vector_b.size(); i++){
    my_vector_b[i] = 100;
  }
  
  //But arrays don't have a size() function
  for(unsigned int i =0; i < 16; i++){
    my_array_b[i] = 100;
  }
  
  //Vectors even have a special way of iterating
  for (std::vector<uint8_t>::iterator it = my_vector_b.begin() ; it != my_vector_b.end(); ++it){
    *it = 100;
  }
  //cout is how you ouput text to screen
  cout << (int)my_vector_b[5] << endl;
  
  
  //3: Iterate over the floating point vector and set each element equal to the current index
  
  
  
  //4: Now try the array
  
  
  //Arrays and vectors are just blocks of memory and can be referenced as pointers
  //Go look at defining an array again, it's just a pointer!  That
  //points to the first element of an array.
  
  uint8_t fifth_element;
    
  fifth_element = my_array_b[5];
  cout << (int)fifth_element << endl;

  //or

  fifth_element = *(my_array_b+5); //deference start of array + 5 memory units to the right
  cout << (int)fifth_element << endl;

  //5:  How do you find the last element of my_array_b without using indexing?

  
  
  //6:  Use the function memcpy() to copy my_array_f into a new array
  //
  //    void *memcpy(void *dest, const void *src, size_t n);
  //    that copies an array at starting memory location src
  //    into a block of memory starting at memory location dest
  //    both blocks of memory is of size n BYTES.  sizeof(<type>) will give
  //    you the number of bytes for a varaible type
    
  
  
  
  //ALWAYS delete anything made with "new"
  delete another_pointer;
  delete[] my_array_b;
  
  return 0;
}
