#ifndef TRAFFICO_UNITS_HPP
#define TRAFFICO_UNITS_HPP

#include <boost/units/base_dimension.hpp>
#include <boost/units/derived_dimension.hpp>
#include <boost/units/quantity.hpp>

namespace traffico
{
namespace units
{
    using namespace boost::units;

    // Dimensions
    struct length_base_dimension : base_dimension<length_base_dimension, 1> {};
    struct mass_base_dimension : base_dimension<mass_base_dimension, 2> {};
    struct time_base_dimension : base_dimension<time_base_dimension, 3> {};

    typedef length_base_dimension::dimension_type length_dimension;
    typedef mass_base_dimension::dimension_type mass_dimension;
    typedef time_base_dimension::dimension_type time_dimension;

    // Derived Dimensions
    typedef derived_dimension<
                length_base_dimension, 1,
                time_base_dimension, -1
            >
            velocity_dimension;

    typedef derived_dimension<
                length_base_dimension, 1,
                time_base_dimension, -2
            >
            acceleration_dimension;

    typedef derived_dimension<
                mass_base_dimension, 1,
                length_base_dimension, 1,
                time_base_dimension, -2
            >
            force_dimension;

    // Base Units
    struct meter_base_unit : base_unit<meter_base_unit, length_dimension, 1> {};
    struct kilogram_base_unit : base_unit<kilogram_base_unit, mass_dimension, 2> {};
    struct second_base_unit : base_unit<second_base_unit, time_dimension, 3> {};

    typedef make_system<meter_base_unit, kilogram_base_unit, second_base_unit>
        mks_system;

    typedef unit<length_dimension, mks_system>          length;
    typedef unit<mass_dimension, mks_system>            mass;
    typedef unit<time_dimension, mks_system>            time;
    typedef unit<velocity_dimension, mks_system>        velocity;
    typedef unit<acceleration_dimension, mks_system>    acceleration;
    typedef unit<force_dimension, mks_system>           force;

    BOOST_UNITS_STATIC_CONSTANT(meter, length);
    BOOST_UNITS_STATIC_CONSTANT(kilogram, mass);
    BOOST_UNITS_STATIC_CONSTANT(second, time);
    BOOST_UNITS_STATIC_CONSTANT(meter_per_second, velocity);
    BOOST_UNITS_STATIC_CONSTANT(meter_per_second_squared, acceleration);
    BOOST_UNITS_STATIC_CONSTANT(newton, force);

    // Derived Units
    typedef scaled_base_unit<second_base_unit, scale<60> > minute_base_unit;
    typedef scaled_base_unit<minute_base_unit, scale<60> > hour_base_unit;

    typedef scaled_base_unit<meter_base_unit, scale<10, static_rational<3> >
        kilometer_base_unit;

}
    typedef units::quantity<units::velocity> velocity;
    typedef units::quantity<units::length> length;
    typedef units::quantity<units::mass> mass;
}

#endif

