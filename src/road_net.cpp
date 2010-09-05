#include "road_net.hpp"

#include "route.hpp"

#include <boost/graph/astar_search.hpp>

namespace traffico
{

    road_net::road_net () {}

    road_net::node_descriptor road_net::add_node ()
    {
        node n = { true };
        return add_vertex (n, net_);
    }

    road_net::node_descriptor road_net::add_crossing ()
    {
        node n = { false };
        return add_vertex (n, net_);
    }

    road_net::road_descriptor road_net::add_road (road_net::node_descriptor start_node,
                                                  road_net::node_descriptor end_node)
    {
        road r = { 1.0, 1.0 };
        auto res = add_edge (start_node, end_node, r, net_);
        if (!res.second)
            throw road_exists();
        return res.first;
    }

    namespace
    {
        struct heuristic
        {
            heuristic (road_net::node_descriptor v) : start (v) {}
            double operator() (road_net::node_descriptor u)
            {
                // to be refined
                return 0.0;
            }
            road_net::node_descriptor start;
        };

        struct found_goal {};
        struct goal_visitor : default_astar_visitor
        {
            goal_visitor (road_net::node_descriptor goal) : goal_(goal) {}
            template <typename Graph>
            void examine_vertex (road_net::node_descriptor v, Graph& g)
            {
                if (v == goal_)
                    throw found_goal();
            }
            
            road_net::node_descriptor goal_;
        };

        class speed_weight_map
        {
        public:
            typedef double value_type;
            typedef double reference;
            typedef road_net::road_descriptor key_type;
            typedef readable_property_map_tag category;

            speed_weight_map (road_net::graph_type const& g) : graph(g) {}

            road_net::graph_type const& graph;
        };

        speed_weight_map::reference get
            (speed_weight_map const& m, speed_weight_map::key_type k)
        {
            auto road = m.graph[k];
            return road.length * road.speed_limit;
        }

        // TODO: Crossing visitor
    }

    route road_net::get_route (road_net::node_descriptor start_node,
                               road_net::node_descriptor end_node) const
    {
        route_visitor vis;

        try
        {
            astar_search (net_, start_node,
                          heuristic(start_node),
                          visitor(goal_visitor(end_node)).
                          weight_map(speed_weight_map(net_))
                         );
        }
        catch (found_goal const& exc)
        {
            return vis.result;
        }

        throw no_route_found();
    }
}
