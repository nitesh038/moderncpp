#ifndef E05E1BC9_FE5B_4224_BAE3_D5FB0559466F
#define E05E1BC9_FE5B_4224_BAE3_D5FB0559466F

#include<iostream>

template<typename T>
class Unique_Ptr 
{
    public:
        
        Unique_Ptr(T* data) : raw_pointer{data}{std::cout<<"Parameterised Constructor called\n";}// parameterised constructor
        Unique_Ptr(const Unique_Ptr& data) = delete; //as unique pointer has exclusive ownership
        Unique_Ptr& operator= (const Unique_Ptr& data) = delete;//as unique pointer has exclusive ownership

        Unique_Ptr(Unique_Ptr&& data) //move constructor
        {
                raw_pointer = data.raw_pointer;
                data.raw_pointer = nullptr;
                std::cout<<"Move Constructor called\n";
        }
        Unique_Ptr& operator= (Unique_Ptr&& data) // move assignment operator
        {
            if( this!= &data)
            {
                if(raw_pointer)
                {
                    delete raw_pointer;
                }
                raw_pointer = data.raw_pointer;
                data.raw_pointer = nullptr;
            }
            std::cout<<"Move Assignment Operator called\n";
            return *this;
        }


        T* operator->()
        {
            return raw_pointer;
        }

        T& operator * ()
        {
            return *raw_pointer;
        }

        T* get()
        {
            return raw_pointer;
        }

        void reset(T* data = nullptr)
        {
            if(raw_pointer)
            {
                delete raw_pointer;
            }
            raw_pointer = data;
            std::cout<<"Reset called\n";
        }

        ~Unique_Ptr()
        {
            if(raw_pointer)
            {
                delete raw_pointer;
                raw_pointer = nullptr;
            }
            std::cout<<"Destructor called\n";
        }

    private:
        T* raw_pointer;
};


#endif /* E05E1BC9_FE5B_4224_BAE3_D5FB0559466F */
