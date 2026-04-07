#include "meters/Cronos/Cronos7023_L.h"
#include "core/GlobalID.h"


Cronos7023_L::Cronos7023_L()
    : Cronos(GlobalID::generateID(), "7023 L")
{
};

Cronos7023_L::Cronos7023_L(const Cronos7023_L& other, int new_id)
    : Cronos(other, new_id) 
{
};

Cronos7023_L::~Cronos7023_L()
{
};

std::vector<double> & Cronos7023_L::getPhaseValues()
{
    return SinglePhaseMeter::getPhaseValues();
};

std::unique_ptr<Meter> Cronos7023_L::cloneMeter() const
{
    return std::make_unique<Cronos7023_L>(*this, GlobalID::generateID());
}
