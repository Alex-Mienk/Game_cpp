#include "Warlock.h"

Warlock::~Warlock()
{
    for (int i = 0; i < spell_slots; ++i) {
        delete spells[i];
    }
    delete[] spells;
    delete this;
}

Warlock::Warlock(const std::string &name, int max_health_points, int spell_slots) : Character(name, max_health_points), spell_slots(spell_slots)
{
    spells = new Spell* [spell_slots];
    for (int i = 0; i < spell_slots; i++){
        spells[i] = nullptr;
    }
}


void Warlock::Attack(Character& character)
{
    if (prepared_spells > 0){
        spells[prepared_spells]->Cast(*this, character);
        delete spells[prepared_spells];
        prepared_spells -= 1;
    } else{
        Character::Attack(character);
    }
}

void Warlock::Rest(int hours)
{
    Character::Rest(hours);
    
    for(int i = 0; i < spell_slots; i++){
        if (spells[i] == nullptr){
            if (hours % 2 == 0){
                spells[i] = new ArcaneMissilesSpell();
        
            } else{
                spells[i] = new HealingTouchSpell();
            }
            prepared_spells++;
            break;
        }
    }
    
}


void Warlock::Serialize(std::ostream& os) const

{
    Character::Serialize(os);
    os << "- class Warlock, prepared spells: ";
    for(int i = 0; i < prepared_spells; i++){
        os << spells[i];
    }
}


Character* Warlock::Clone() const {
    Warlock* copy = new Warlock(name, max_health_points, spell_slots);

    copy->prepared_spells = this->prepared_spells;

    for (int i = 0; i < spell_slots; ++i) {
        if (this->spells[i] != nullptr)
            copy->spells[i] = this->spells[i]->Clone();
        else
            copy->spells[i] = nullptr;
    }

    return copy;
}