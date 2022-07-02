
#include <iostream>

bool is_collection_sorted(int numbers[], unsigned int collection_size){


bool sorted {true};
unsigned int unique_number{};
  // Don't modify anything above this line
  //Your code will go below this line
 for(size_t i{}; i < collection_size; i++)
 {
     for (size_t j{}; j < unique_number ; j++)
     {
        if(numbers[i] < numbers[j])
        {
            sorted = false;
            break;
        }
     }
     
     unique_number++;
 }
  //Your code will go above this line
  //Don't modify anything below this line

  return sorted;
}

int main()
{
    int data[] {1,2,4,5,1,8,2,3,6,1,4,2};

    std::cout<< "Collection is Sorted? : " << is_collection_sorted(data, 12) ;
    return 0;
}