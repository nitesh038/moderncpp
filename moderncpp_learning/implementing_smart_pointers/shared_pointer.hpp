#ifndef CF9CD0C3_7791_4B7F_9F57_5CE4EC57B594
#define CF9CD0C3_7791_4B7F_9F57_5CE4EC57B594

#include<iostream>

template<typename T>
class SharedPointer
{
    public:
        //SharedPointer() : raw_pointer{nullptr},counter {new int(1){}//default constructor
        SharedPointer(T* data = nullptr) : raw_pointer{data}, counter {new int(1)}//parameterised constructor and also default constructor
        {
            std::cout<< " Constructor Called\n";
        }
        SharedPointer(const SharedPointer& data)//copy constructor
        {
            
            raw_pointer = data.raw_pointer;
            counter = data.counter;
            incrementcounter();
            std::cout<< "Copy Constructor Called\n";
        }
        SharedPointer<T>& operator= (const SharedPointer<T>& data)//copy assignment operator
        {
            if( this!=&data )
            {
                decrementcounter(); // S4 will leave it's resource first
                raw_pointer = data.raw_pointer;
                counter = data.counter;
                incrementcounter(); //S3 will have one more object pointing to it's resource
            }
            
            std::cout<< " Copy Assignment Operator Called\n";
            return *this;
        }

        SharedPointer(SharedPointer&& data)//move constructor
        {
            raw_pointer = data.raw_pointer;
            counter = data.counter;
            data.raw_pointer = nullptr;
            data.counter = nullptr;
            std::cout<< "Move Constructor Called\n";
        }
        SharedPointer& operator= (SharedPointer&& data)//move assignment operator
        {
            if( this!=&data )
            {
                decrementcounter();
                raw_pointer = data.raw_pointer;
                counter = data.counter;
                data.raw_pointer = nullptr;
                data.counter = nullptr;
            }
            std::cout<< "Move Assignment Operator Called\n";
            return *this;
        }

        T* get()
        {
            return raw_pointer;
        }

        T* operator-> ()
        {
            return raw_pointer;
        }

        T& operator* ()
        {
            return *raw_pointer;
        }

        int get_count()
        {
            if(counter)
                return *counter;

            return -1;
        }

        void reset(T* data = nullptr)
        {
            decrementcounter();
            raw_pointer = data;
            counter = new int(1);
            std::cout<<"Reset called\n";
        }


        ~SharedPointer()
        {
            decrementcounter();
        }


    private:
        T* raw_pointer;
        //not static (because we won't be able to per resource but only for per class)
        // and not integer also because it will be per object then
        //we want per resource but on a class level that's why we 
        //are using int* counter
        int* counter; 

        void incrementcounter()
        {
            if(counter)
            {
                (*counter)++;   
            }
        }
        void decrementcounter()
        {
            if(counter)
            {
                (*counter)--;
                if( (*counter) == 0 ) // if resource is not getting utilized
                {
                    if(raw_pointer) 
                    {
                        delete raw_pointer;
                        delete counter;
                        raw_pointer = nullptr;
                        counter = nullptr;
                    }
                }
            }
        }

};


#endif /* CF9CD0C3_7791_4B7F_9F57_5CE4EC57B594 */
