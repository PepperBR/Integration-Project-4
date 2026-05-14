#include "meters/Zeus/Zeus8023.h"

Zeus8023::Zeus8023()
    : Zeus(3, "8023", Phase::PhaseB){};

Zeus8023::Zeus8023(const Zeus8023 &other, const int &new_id)
    : Zeus(other, new_id){};

Zeus8023::~Zeus8023(){};

std::shared_ptr<Meter> Zeus8023::cloneMeter(int unique_id) const
{
    return std::make_shared<Zeus8023>(*this, unique_id);
}
