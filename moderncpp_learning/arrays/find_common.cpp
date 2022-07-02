#include <iostream>


void common_elements(int array_1[], int array_2[]){
   // REMEMBER, The input arrays array_1 and array_2 have a fixed size of 10
   
  //Don't modify anything above this line
  //Your code will go below this line
  int array_3[10];
  unsigned int count{};
  for(unsigned int i{}; i < 10 ; i++)
  {
      for(unsigned int j{}; j < 10; j++)
      {
        if(array_1[i] == array_2[j])
        {
            array_3[count] = array_1[i];
            count++;
        }
      }
  }
  if(count<1)
  {
      std::cout << "There are 0 common elements";
  }
  else
  {
      std::cout << "There are " << count <<" common elements they are : ";
      for(unsigned int counter{}; counter < count; counter++)
      {
          std::cout << array_3[counter] << " ";
      }
  }
  
  //Your code will go above this line
  //Don't modify anything after this line

}

int main()
{
    int data1[] {1,2,4,5,9,3,6,7,44,55}; 
    int data2[] {11,2,44,45,49,43,46,47,55,88};

    common_elements(data1, data2);
    
    return 0;
}