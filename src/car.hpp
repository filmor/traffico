#ifndef TRAFFICO_CAR_HPP
#define TRAFFICO_CAR_HPP

namespace traffico
{

    class car
    {
    public:
        car (route const& rt, universe& uni);

        route const& get_route ();

        bool finished () const { return route_iter_ == route_.end(); }

    protected:
        void accelerate (double);
        void change_track (int);
    private:
        route route_;
        
        // TODO: Steering wheel
    };

}

#endif
