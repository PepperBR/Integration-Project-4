#include "meters/Cronos/Cronos7023_L.h"

Cronos7023_L::Cronos7023_L()
    : Cronos(6, "7023 L", Phase::PhaseA){};

Cronos7023_L::Cronos7023_L(const Cronos7023_L &other, const int &new_id)
    : Cronos(other, new_id){};

Cronos7023_L::~Cronos7023_L(){};

std::shared_ptr<Meter> Cronos7023_L::cloneMeter(int unique_id) const
{
    return std::make_shared<Cronos7023_L>(*this, unique_id);
}
