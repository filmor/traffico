#ifndef TRAFFICO_SIMULATION_HPP
#define TRAFFICO_SIMULATION_HPP

#include "road_net.hpp"

namespace traffico
{

    class simulation
    {
    public:
        simulation ();

        void run ();

    private:
        road_net net_;
    };
}

#endif
