#include "Character.hpp"
#include "AMateria.hpp"

int Character::index = 0;

Character::Character(std::string name) : name(name)
{
    int i = 0;
    while (i < 4)
    {
        this->inventory[i] = NULL;
        i++;
    }
    i = 0;
    while (i < MAX_CONTAINER)
    {
        this->container[i] = NULL;
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
    i = 0;
    while (i < MAX_CONTAINER)
    {
        this->container[i] = NULL;
        i++;
    }
    this->name = "GoGo default";
    std::cout << "Character Default constructor called" << std::endl;
}

Character::~Character()
{
    AMateria* deleted[MAX_CONTAINER];
    int count = 0;
    bool check;
    for (int k = 0; k < 4; ++k) {
        check = false;
        if (this->inventory[k] != NULL) {
            // deleted[count++] = this->inventory[k];
            for (int j = 0; j < count; ++j) {
                if (deleted[j] == this->inventory[k]) { 
                    check = true; 
                    break; 
                }
            }
            if (!check) {
                deleted[count++] = this->inventory[k];
                delete this->inventory[k];
            }
        }
        this->inventory[k] = NULL; 
    }
    for (int k = 0; k < Character::index && k < MAX_CONTAINER; k++) {
        AMateria* ptr = this->container[k];
        if (ptr == NULL) 
            continue;
        check = false;
        for (int j = 0; j < count; ++j) {
            if (deleted[j] == ptr) { 
                check = true; 
                break; 
            }
        }
        if (!check) {
            delete ptr;
            if (count < MAX_CONTAINER) 
                deleted[count++] = ptr;
        }
        this->container[k] = NULL;
    }
    std::cout << "Character Destructor called" << std::endl;
}

Character::Character(const Character& other) {
    std::cout << "Character Copy constructor called" << std::endl;
    int i = 0;
    this->name = other.name;
    while (i < 4)
    {
        if (other.inventory[i]) {
            this->inventory[i] = other.inventory[i]->clone();
        }
        else
            this->inventory[i] = NULL;
        i++;
    }
    i = 0;
    while (i < MAX_CONTAINER)
    {
        this->container[i] = NULL;
        i++;
    }
}

Character &Character::operator=(const Character& other)
{
    std::cout << "Character Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->name = other.name;
        int i = 0;
        while (i < 4)
        {
            if (other.inventory[i]) {
                delete this->inventory[i];
                this->inventory[i] = other.inventory[i]->clone();
            }
            i++;
        }
    }
    return *this;
}

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
            this->inventory[i] = m;
            return ;
        }
        i++;
    }
    delete m;
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx <= 3) {
        if (this->inventory[idx] != NULL)
        {
            if (Character::index < MAX_CONTAINER) {
                this->container[Character::index] = this->inventory[idx];
                Character::index++;
                this->inventory[idx] = NULL;
            }
            else
                std::cout << "container of addresses to be deleted is full" << std::endl;
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