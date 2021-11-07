#include <iostream>
using namespace std;

struct Strategy 
{ // Saving space , should be classes .
    virtual void Print () const = 0;
};
struct StrategyA : public Strategy 
{
    void Print () const override 
    { 
        cout << "A" << endl; 
    }
};
struct StrategyB : public Strategy
{
    void Print () const override 
    { 
        cout << "B" << endl; 
    }
};
struct MyStruct 
{
    MyStruct ( const Strategy & s): strategy_ (s) {}
    void Print () const { strategy_ .Print (); }
    const Strategy & strategy_ ;
};
int main () {
// Create a local var of MyStruct and call its Print
    StrategyA A;
    StrategyB B;
    MyStruct (A).Print ();
    MyStruct (B).Print ();
}