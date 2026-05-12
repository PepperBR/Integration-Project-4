#include "meters/Cronos/Cronos7023_L.h"

Cronos7023_L::Cronos7023_L()
    : Cronos(6, "7023 L"){};

Cronos7023_L::Cronos7023_L(const Cronos7023_L &other, int new_id)
    : Cronos(other, new_id){};

Cronos7023_L::~Cronos7023_L(){};

std::vector<double> &Cronos7023_L::getPhaseValues()
{
    return SinglePhaseMeter::getPhaseValues();
};

std::shared_ptr<Meter> Cronos7023_L::cloneMeter(int unique_id) const
{
    return std::make_shared<Cronos7023_L>(*this, unique_id);
}
