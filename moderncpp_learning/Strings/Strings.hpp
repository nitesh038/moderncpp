#ifndef C6246AB9_E71B_4568_8A5C_7CFE923F8E28
#define C6246AB9_E71B_4568_8A5C_7CFE923F8E28

#include<iostream>
#include <string.h>

class String
{
    public:
        //Default Constructor
        String() : res{nullptr}, length{0} {}
        //Parameterised Constructor
        String(const char* buffer)
        {
            if(buffer) // not needed
            {
                length = strlen(buffer);
                res = new char[length+1];//+1 to mark ending of string with \0
                strcpy(res, buffer);
            }
        }
        //Copy Constructor
        String(const String& buffer)
        {
            length = buffer.length;
            res = new char[length+1];
            strcpy(res, buffer.res);
        }
        
        //Move Constructor
        String(String&& buffer)
        {
            length = buffer.length;
            res = buffer.res;//diffence from Copy Constructor- Only Moving Not Copying
            buffer.res = nullptr;
            buffer.length = 0;
        }
        
        //Copy Assignment Operator
        // String& operator= (const String& buffer)
        // {
        //     if( this != &buffer)
        //     {
        //         // or delete[] res // important to remember as lhs might 
        //         // have been holding already value
        //         //delete[] this->res; -- 
        //         //one way
        //         char* temp = this->res;
        //         length = buffer.length;
        //         res = new char[length+1];
        //         strcpy(res, buffer.res);
        //         delete[] temp;
        //     }
        //     return *this; //don't forget
        // }
        void Swap(String& S1, String& S2)
        {
            std::swap(S1.res, S2.res);
            std::swap(S1.length, S2.length);
        }
        //Copy Assignment Operator Using CAS(Copy and Swap Idiom)
        String& operator= (String buffer)
        {
            Swap(*this, buffer);
            return *this; //CAS Idiom
        }

        //Move Assignment Operator
        String& operator= (String&& buffer)
        {
            if (this != &buffer)
            {
                // Release the current resources
                if (res)
                {
                    delete[] res;
                }

                // Move the resources from buffer
                length = buffer.length;
                res = buffer.res;

                // Nullify buffer's resources
                buffer.res = nullptr;
                buffer.length = 0;
            }
            return *this;
        }
        unsigned int len()
        {
            return this->length;
        }

        ~String()
        {
            if(res)
            {
                delete[] res;
                res = nullptr;
                length = 0;
            }

        }
    friend std::ostream& operator<< (std::ostream& out, const String& res);
    friend std::istream& operator>> (std::istream& in, const String& res);

    private:
        char* res;
        unsigned int length;
};

#endif /* C6246AB9_E71B_4568_8A5C_7CFE923F8E28 */
