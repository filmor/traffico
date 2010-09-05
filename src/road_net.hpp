#ifndef TRAFFICO_ROADNET_HPP
#define TRAFFICO_ROADNET_HPP

#include <boost/graph/adjacency_list.hpp>

namespace traffico
{
    using namespace boost;

    struct road_exists {};
    struct no_route_found {};

    // Declaration
    class route;

    class road_net
    {
    public:
        road_net ();

    private:
        struct road
        {
            // TODO: Use units.hpp
            // km/h
            double speed_limit;
            // km
            double length;
        };

        struct node
        {
            bool is_crossing;
            // More stuff later
        };

    public:
        typedef adjacency_list<vecS, vecS, undirectedS, node, road>
            graph_type;

        typedef graph_type::vertex_descriptor node_descriptor;
        typedef graph_type::edge_descriptor road_descriptor;

    private:
        graph_type net_;

    public:
        // Source/Sink of cars
        // Nodes have a property "factory" which is an object of class
        // car_factory (initialized with the parameters given here)
        // Distinguish later, as soon as a directed graph is used
        node_descriptor add_node ();
        // Crossings of streets
        // Crossings have a property "transition_map" which regulates traffic
        node_descriptor add_crossing ();
        // Roads are the edges
        // Roads have the properties "length" and "speed_limit", later also
        // (maybe) statistical data
        road_descriptor add_road (node_descriptor start_node, node_descriptor end_node);

        route get_route (node_descriptor start_node, node_descriptor end_node) const;
    };

}

#endif
