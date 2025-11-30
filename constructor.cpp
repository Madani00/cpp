Cure::Cure()
{
    std::cout << "Cure Default constructor called" << std::endl;
}

Cure::~Cure()
{
    std::cout << "Cure Destructor called" << std::endl;
}

Cure::Cure(const Cure& other) {
    std::cout << "Cure Copy constructor called" << std::endl;
    *this = other;
}

Cure &Cure::operator=(const Cure& other)
{
    std::cout << "Cure Copy assignment operator called" << std::endl;
    if (this != &other) {
        
    }
    return *this;
}

// Orthodox Canonical Form
        AMateria();
        AMateria(const AMateria& other); 
        AMateria& operator=(const AMateria& other);
        ~AMateria();