#include "meters/Zeus/Zeus8023.h"
#include "core/GlobalID.h"


Zeus8023::Zeus8023()
    : Zeus(GlobalID::generateID(), "8023")
{
};

Zeus8023::Zeus8023(const Zeus8023& other, int new_id)
    : Zeus(other, new_id)
{
};

Zeus8023::~Zeus8023()
{
};

std::vector<double> & Zeus8023::getPhaseValues()
{
    return TwoPhaseMeter::getPhaseValues();
};

std::unique_ptr<Meter> Zeus8023::cloneMeter() const
{
    return std::make_unique<Zeus8023>(*this, GlobalID::generateID());
}


