#include "simulation.hpp"

#include <boost/random.hpp>

namespace traffico
{
    using namespace boost;

    simulation::simulation ()
    {
        const unsigned node_count = 3;
        road_net::node_descriptor nodes[3];
        for (unsigned i = 0; i < node_count; ++i)
            nodes[i] = net_.add_node();

        // Add crossings
        // Add roads

    }

    void simulation::run ()
    {
        // - Connect a car_factory to each node
        // Run the actual simulation
    }

}
