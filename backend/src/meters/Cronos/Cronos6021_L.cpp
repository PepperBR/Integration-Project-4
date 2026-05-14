#include "meters/Cronos/Cronos6021_L.h"

Cronos6021_L::Cronos6021_L()
    : Cronos(8, "6021 L", Phase::PhaseC){};

Cronos6021_L::Cronos6021_L(const Cronos6021_L &other, const int &new_id)
    : Cronos(other, new_id){};

Cronos6021_L::~Cronos6021_L(){};

std::shared_ptr<Meter> Cronos6021_L::cloneMeter(int unique_id) const
{
    return std::make_shared<Cronos6021_L>(*this, unique_id);
}
