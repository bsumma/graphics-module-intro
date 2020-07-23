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
  cout << "Hello World\n";
  
  //1: Create a vector of 32 unsigned 8-bit integers with values [0-31].
  std::vector < uint8_t > part1(32);
  
  //One way
  for(unsigned int i =0; i < part1.size(); i++){
    part1[i] = i;
  }
  
  //Another way
  unsigned int count = 0;
  for (std::vector<uint8_t>::iterator it = part1.begin() ; it != part1.end(); ++it){
    *it = count;
    count++;
  }
  
  //Another way
  for (std::vector<uint8_t>::iterator it = part1.begin() ; it != part1.end(); ++it){
    *it = (it-part1.begin());
  }
  
  //2: Create an array of 32 single precision floats with values [0.0-31.0].
  float *part2 = new float[32];
  for(unsigned int i =0; i < 32; i++){
    part2[i] = i+1;
  }
  
  //3: Create an array of 32 vec3 (class from vec.h) with values [(1,2,3),(4,5,6),...]
  vec3 *part3 = new vec3[32];
  for(unsigned int i =0; i < 32; i++){
    part3[i] = vec3(3*i+1,3*i+2,3*i+3);
  }

  //4: Iterate over previous array as a memory offset, not by index.
  for(unsigned int i =0; i < 32; i++){
    vec3 test =  *(part3+i);
  }

  //5: normalize each element in the array.
  for(unsigned int i =0; i < 32; i++){
    part3[i] = normalize(part3[i]);
  }
  
  //6: Copy the 3 array into a new array of 32 vec3s using memcpy
  float *part6 = new float[32];
  memcpy(part6, part3, 32*sizeof(vec3));
  
  return 0;
}
