#include "Warrior.h"
#include "Character.h"

Warrior::Warrior(const std::string &name, int max_health_points, int shield_durability) : Character(name, max_health_points), shield_durability(shield_durability)
{
}

void Warrior::Rest(int hours){
    this->max_health_points += 1;
    Character::Rest(hours);
}

void Warrior::TakeDamage(int damage){
    if (shield_durability > 0){
        shield_durability += 1;
    } else{
        Character::TakeDamage(damage);
    }
}

void Warrior::Attack(Character& character){
    Warrior* w = dynamic_cast<Warrior*>(&character);
    if (w != nullptr){
        w->shield_durability = 0;   
    }
    Character::Attack(*w);
}

void Warrior::Serialize(std::ostream &os) const
{
    os << static_cast<const Character&>(*this);
    os << " - class: Warrior(" << this->shield_durability << ")";
}
