/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* p);  //1
    //2
    int value;
    //3
    std::string name;
};

T::T(int v, const char* p): value(v), name(p) {}

struct Comparator                               //4
{
    T* compare(T& a, T& b) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;     
        return nullptr;
    }
};

struct U
{
    float x { 0 }, y{ 0 };
    float computeDistance(const float& xUpdated)      //12
    {
        std::cout << "U's x value: " << this->x << std::endl;
        this->x = xUpdated;
        std::cout << "U's y updated value: " << this->x << std::endl;
        while( std::abs( this->y - this->x ) > 0.001f )
        {
            this->y += .1f;
        }
        std::cout << "U's computeDistance updated value: " << this->y << std::endl;
        return this->y * this->x;
    }
};

struct StaticU
{
    static float computeDistance(U& that, const float& xUpdated )        //10
    {
        std::cout << "U's x value: " << that.x << std::endl;
        that.x = xUpdated;
        std::cout << "U's y updated value: " << that.x << std::endl;
        while( std::abs( that.y - that.x ) > 0.001f )
        {
            /*
            write something that makes the distance between that->yand that->x get smaller
            */
            that.y += .1f;
        }
        std::cout << "U's computeDistance updated value: " << that.y << std::endl;
        return that.y * that.x;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1(6, "value 6");                                            //6
    T t2(8, "value 8");                                             //6
    
    Comparator f;                                            //7
    auto* smaller = f.compare(t1, t2);                           //8
    if(smaller != nullptr)
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    std::cout << "Non allocated pointer" << std::endl; //9
    
    U distance1;
    float updatedValue = 5.f;
    std::cout << "[static func] distance1's multiplied values: " << StaticU::computeDistance(distance1, updatedValue) << std::endl;                  //11
    
    U distance2;
    std::cout << "[member func] distance2's multiplied values: " << distance2.computeDistance( updatedValue ) << std::endl;
}
