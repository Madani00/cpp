
#include <iostream>

class tt
{
    private:
        // int num;
    public:
        tt(int nmb);
        ~tt();
        int num;
};

tt::tt(int num)
{
    if (num > 0)
        this->num = num;
    else
        throw "NUmber is negative";
}

tt::~tt()
{
}


int main() {
    
    try {
        tt basic(-2);
    }
    catch(char const * e) {
        std::cout << "error " << e << std::endl;
    }


}
