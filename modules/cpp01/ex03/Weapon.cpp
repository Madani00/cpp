#include "Weapon.hpp"
// first const : means the returned reference is read-only.
// const std::string& Weapon::getType() const { // const means : function itself is const, i.e. it does not modify the object.
// 	return this->type;
// }

const std::string& Weapon::getType() {
	return this->type;
}

void Weapon::setType(const std::string& type) {
	this->type = type;
}

Weapon::Weapon(const std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{
}
