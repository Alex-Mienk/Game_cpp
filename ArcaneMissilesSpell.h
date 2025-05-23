#pragma once

#include "Spell.h"


class ArcaneMissilesSpell : public Spell {
    static const int DAMAGE = 1;
    static const int MISSILES_COUNT = 3;
    void Cast(Character& caster, Character& target) override;
    void Serialize(std::ostream& os) const override;
    Spell* Clone() const override;
};
