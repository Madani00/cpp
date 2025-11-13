#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string name) : name(name)
{
    int i = 0;
    while (i < 4)
    {
        this->inventory[i] = NULL;
        this->container[i] = NULL; // i added this cause so i can check in desctructor if it is NULL
        i++;
    }
    std::cout << "Character Default constructor called" << std::endl;
}

Character::Character()
{
    int i = 0;
    while (i < 4)
    {
        this->inventory[i] = NULL;
        i++;
    }
    this->name = "GoGo default";
    std::cout << "Character Default constructor called" << std::endl;
}

Character::~Character()
{
    int k = 0;
    while (k < 4) // has pointers to be delted
    {
        if (this->container[k])
            delete this->container[k];
        if (this->inventory[k])
            delete this->inventory[k];
        k++;
    }
    std::cout << "Character Destructor called" << std::endl;
}

Character::Character(const Character& other) {
    std::cout << "Character Copy constructor called" << std::endl;
    int i = 0;
    this->name = other.name;
    while (i < 4)
    {
        // if (this->name == "Ice") {
        //     this->inventory[i] = Ice::clone();
        // }  
        this->inventory[i] = other.inventory[i]->clone();
        i++;
    }
}

Character &Character::operator=(const Character& other)
{
    std::cout << "Character Copy assignment operator called" << std::endl;
    if (this != &other) {
        // this->name = other.name;
        int i = 0;
        while (i < 4)
        {
            delete this->inventory[i]; // delete currect ones
            this->inventory[i] = other.inventory[i]->clone();
            i++;
        }
    }
    return *this;
}

// pure virtual functions to implement
std::string const & Character::getName() const {
    return this->name;
}

void Character::equip(AMateria* m) {
    int i = 0;
    if (!m)
        return ;
    while (i < 4)
    {
        if (this->inventory[i] == NULL) {
            this->inventory[i] = m; // store the Materia pointer m in that slot.
            return ;
        }
        i++;
    }
    delete m;        // mm i guess if the inventory is full
}
void Character::unequip(int idx) { // do not delete in this function please lol
    if (idx >= 0 && idx <= 3) {
        if (this->inventory[idx] != NULL)
        {
            this->container[idx] = this->inventory[idx];
            this->inventory[idx] = NULL;
        }
    }
}
void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx <= 3) {
        if (this->inventory[idx]) {
            this->inventory[idx]->use(target);
        }
    }
}