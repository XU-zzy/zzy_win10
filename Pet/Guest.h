#include "Pet.h"

class Guest
{
private:
    std::string G_number;
    std::string G_name;
    std::string G_state;
public:
    Guest();
    Guest(std::string number,):{}
    ~Guest();
};

Guest::Guest(/* args */)
{
}

Guest::~Guest()
{
}
