#include "Character.h"

Character::Character(const std::string &name, int max_health_points) : name(name), max_health_points(max_health_points)
{
}

void Character::Attack(Character &character)
{
    if (character.max_health_points > 0){
        character.max_health_points -= 2;
    }
}

void Character::Rest(int hours)
{
    if (this->current_health_points + hours <= this->max_health_points){
        this->current_health_points += hours;
    } else{
        this->current_health_points = 0;
    }
}

void Character::TakeDamage(int damage)
{
    if (this->current_health_points - damage >= 0){
        this->current_health_points -= damage;
    } else{
        this->current_health_points = 0;
    }
}

void Character::GetHealed(int heal)
{
    this->Rest(heal);
}

void Character::Serialize(std::ostream &os) const
{
    os << this->name << "(HP: " << this->current_health_points << "/" << this->max_health_points << ")";
}

std::ostream &operator<<(std::ostream &os, const Character &character)
{
    os << character.name << "(HP: " << character.current_health_points << "/" << character.max_health_points << ")";
    return os;
}
