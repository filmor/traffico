#ifndef TRAFFICO_ROUTE_HPP
#define TRAFFICO_ROUTE_HPP

#include <boost/variant.hpp>

namespace traffico
{
    using namespace boost;

    class route
    {
    public:

    private:
        struct road { road_net::road_descriptor desc; };
        struct node { road_net::node_descriptor desc; };
        
        std::vector<variant<road, node>> route_;
    };

    class route_visitor
    {
    public:
        route result;
    };

}

#endif
