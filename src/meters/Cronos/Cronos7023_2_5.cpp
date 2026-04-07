#include "meters/Cronos/Cronos7023_2_5.h"
#include "core/GlobalID.h"


Cronos7023_2_5::Cronos7023_2_5()
    : Cronos(GlobalID::generateID(), "7023 2.5")
{
};

Cronos7023_2_5::Cronos7023_2_5(const Cronos7023_2_5& other, int new_id)
    : Cronos(other, new_id) 
{
};

Cronos7023_2_5::~Cronos7023_2_5()
{
};

std::vector<double> & Cronos7023_2_5::getPhaseValues()
{
    return TwoPhaseMeter::getPhaseValues();
};

std::unique_ptr<Meter> Cronos7023_2_5::cloneMeter() const
{
    return std::make_unique<Cronos7023_2_5>(*this, GlobalID::generateID());
}
