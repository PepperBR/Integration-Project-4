#include "meters/Zeus/Zeus8031.h"
#include "core/GlobalID.h"


Zeus8031::Zeus8031()
    : Zeus(GlobalID::generateID(), "8031")
{
};

Zeus8031::~Zeus8031()
{
};

Zeus8031::Zeus8031(const Zeus8031& other, int new_id)
    : Zeus(other, new_id) 
{
};


std::vector<double> & Zeus8031::getPhaseValues()
{
    return ThreePhaseMeter::getPhaseValues();
};

std::unique_ptr<Meter> Zeus8031::cloneMeter() const
{
    return std::make_unique<Zeus8031>(*this, GlobalID::generateID());
}



