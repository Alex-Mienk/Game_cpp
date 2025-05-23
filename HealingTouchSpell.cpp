#include "HealingTouchSpell.h"
#include "Character.h"

void HealingTouchSpell::Cast(Character &caster, Character &target)
{
    target.GetHealed(HEALING);
}

void HealingTouchSpell::Serialize(std::ostream& os) const
{
    os << "HealingTouch";
}

Spell* HealingTouchSpell::Clone() const
{
    return new HealingTouchSpell(*this);
}
