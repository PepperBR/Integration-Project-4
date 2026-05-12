#include "meters/Cronos/Cronos7023.h"

Cronos7023::Cronos7023()
    : Cronos(5, "7023"){};

Cronos7023::Cronos7023(const Cronos7023 &other, int new_id)
    : Cronos(other, new_id){};

Cronos7023::~Cronos7023(){};

std::vector<double> &Cronos7023::getPhaseValues()
{
    return ThreePhaseMeter::getPhaseValues();
};

std::shared_ptr<Meter> Cronos7023::cloneMeter(int unique_id) const
{
    return std::make_shared<Cronos7023>(*this, unique_id);
}
