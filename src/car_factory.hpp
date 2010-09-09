#ifndef TRAFFICO_CAR_FACTORY_HPP
#define TRAFFICO_CAR_FACTORY_HPP

namespace traffico
{

    template <class CreationPolicy>
    class car_factory
    {
    public:
        car_p create ();
    };

}

#endif
