// Range-based For Loop
#include<iostream>

int main()
{
    int arr[] {1, 2, 3, 7, 9, 23};
    for(int counter = 0; counter < std::size(arr); counter++ )
        std::cout << "Using old-style for loop , Elements of arr are: " << arr[counter] << std::endl;

    //Rnage-based for loop works with any container having ranges
    //including initialiser-lists
    //In this range based for-loop copy of elements are happening
    for(auto counter : arr)
        std::cout << "Using Range based for loop , Elements of arr are: " << counter << std::endl;

    //better-version
    for(const auto& counter : arr)
        std::cout << "Avoiding copy in Range based for loop , Elements of arr are: " << counter << std::endl;

    //with initializer-lists
    for(const auto& counter : {78, 45, 39, 21, 90})
        std::cout << "Range based for loop with initializer-list , Elements of arr are: " << counter << std::endl;

    
    int *beg = &arr[0];//arr would have also worked
    int *end = &arr[5];
    while(beg!=end)
    {
        std::cout << *beg << std::endl;
        ++beg;
    }

    //using iterators
    auto begin = std::begin(arr);
    auto end = std::end(arr);
    for(;begin!=end; ++begin)
    {
        auto v = *begin;
    }


    return 0;
}