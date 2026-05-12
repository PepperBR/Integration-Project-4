#include "meters/Cronos/Cronos7023_2_5.h"

Cronos7023_2_5::Cronos7023_2_5()
    : Cronos(7, "7023 2.5"){};

Cronos7023_2_5::Cronos7023_2_5(const Cronos7023_2_5 &other, int new_id)
    : Cronos(other, new_id){};

Cronos7023_2_5::~Cronos7023_2_5(){};

std::vector<double> &Cronos7023_2_5::getPhaseValues()
{
    return TwoPhaseMeter::getPhaseValues();
};

std::shared_ptr<Meter> Cronos7023_2_5::cloneMeter(int unique_id) const
{
    return std::make_shared<Cronos7023_2_5>(*this, unique_id);
}
