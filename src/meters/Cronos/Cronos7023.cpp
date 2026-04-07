#include "meters/Cronos/Cronos7023.h"
#include "core/GlobalID.h"


Cronos7023::Cronos7023()
    : Cronos(GlobalID::generateID(), "7023")
{
};

Cronos7023::Cronos7023(const Cronos7023& other, int new_id)
    : Cronos(other, new_id) 
{
};

Cronos7023::~Cronos7023()
{
};

std::vector<double> & Cronos7023::getPhaseValues()
{
    return ThreePhaseMeter::getPhaseValues();
};

std::unique_ptr<Meter> Cronos7023::cloneMeter() const
{
    return std::make_unique<Cronos7023>(*this, GlobalID::generateID());
}
