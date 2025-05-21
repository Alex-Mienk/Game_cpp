#pragma once

#include <ostream>
#include "Character.h"
#include "Spell.h"
#include "ArcaneMissilesSpell.h"
#include "HealingTouchSpell.h"

class Spell;

class Warlock : public Character {

protected:
    Spell** spells;
    int spell_slots;
    int prepared_spells;

public:
    Warlock() = delete;
    Warlock(const Warlock& warlock) = delete;
    Warlock& operator=(const Warlock& warlock) = delete;
    ~Warlock();

    Warlock(const std::string& name, int max_health_points, int spell_slots);

    void Attack(Character& character) override;
    void Rest(int hours) override;
    //void TakeDamage(int damage);
    //void GetHealed(int heal);
    Character* Clone() const;


protected:
    void Serialize(std::ostream& os) const override;
};
