#include "distance.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& s, const Distance& d)
{
         if ((d.miles != 0) || (d.yards != 0) || (d.feet != 0))
                s << "(" << d.miles << 'm' <<" "<< d.yards <<'y'<<" "<< d.feet << "\'" <<" "<< d.inches << "\"" <<" "<< ")";
        else
                s << "(" << d.inches << "\"" << ")";
        return s;
}


istream& operator>>(istream& s, Distance& d)
{
        char symbol = ',';
        int ml, yd, ft, ich;
        s >> ml >> symbol >> yd >> symbol >> ft >> symbol >> ich;
        d.miles = ml;
        d.yards = yd;
        d.feet = ft;
        d.inches = ich;
        d.transform();
        return s;
}


bool operator<(const Distance& d1,const Distance& d2)
{
        int t1, t2;
        t1 = 63360 * (d1.miles) + 36 * (d1.yards) + 12 * (d1.feet) + d1.inches;
        t2 = 63360 * (d2.miles) + 36 * (d2.yards) + 12 * (d2.feet) + d2.inches;
        if (t1 < t2)
            return true;
        else
            return false;
}


bool operator== (const Distance& d1, const Distance& d2)
{
        int t1, t2;
        t1 = 63360 * (d1.miles) + 36 * (d1.yards) + 12 * (d1.feet) + d1.inches;
        t2 = 63360 * (d2.miles) + 36 * (d2.yards) + 12 * (d2.feet) + d2.inches;
        if (t1 == t2)
            return true;
        else
            return false;
}

bool operator!=(const Distance& d1, const Distance& d2)
{
        if ((d1 == d2) == false)
            return true;
}


bool operator>(const Distance& d1, const Distance& d2)
{
        if (((d1<d2) == false) && ((d1 == d2) == false))
            return true;
        else
            return false;
}


bool operator<=(const Distance& d1, const Distance& d2)
{
        if (((d1 < d2) == true) || ((d1 == d2) == true))
            return true;
        else
            return false;
}
bool operator>=(const Distance& d1, const Distance& d2)
{
        if (((d1 < d2) == true) || ((d1 == d2) == true))
                return false;
        else
                return true;
}


Distance::Distance()
{
        miles = 0;
        yards = 0;
        inches = 0;
        feet = 0;
}


Distance::Distance(int ich)
{
        inches = ich;
        miles = 0;
        feet = 0;
        yards = 0;
        transform();
}


Distance::Distance(int ml, int yd, int ft, int ich)
{
        miles = ml;
        yards = yd;
        feet = ft;
        inches = ich;
        transform();
}
void Distance::transform()
{
        int ich, ft, yd, ml;
        if ((inches < 0)||(feet<0)||(yards <0)||(miles<0))
            {
             inches = 0;
             feet = 0;
             yards = 0;
             miles = 0;
            }

        ft = inches / 12 + feet;
        ich = inches % 12;

        yd = ft / 3 + yards;
        ft = ft % 3;

        ml = yd /( 1760) + miles;
        yd = yd % 1760;

        inches = ich;
        feet = ft;
        yards = yd;
        miles = ml;
}

Distance Distance::operator+ (const Distance& d2) const
{
        Distance r;
        int ml, yd, ft, ich;
        ml= miles + d2.miles;
        yd= yards + d2.yards;
        ft= feet + d2.feet;
        ich = inches + d2.inches;

        r.miles = ml;
        r.yards = yd;
        r.feet = ft;
        r.inches = ich;
        r.transform();
        return r;
}


Distance Distance::operator-(const Distance& d2) const
{
        int t1,t2,t;
        Distance r;
        t1 = 63360 * miles + 36 *yards + 12 *feet +inches;
        t2 = 63360 * (d2.miles) + 36 * (d2.yards) + 12 * (d2.feet) +d2.inches;
        t = t1-t2;
        r.inches = t;
        r.transform();
        return r;
}

Distance& Distance::operator++()    //preincrement
{
        inches = inches + 1;
        transform();
        return *this;
}


Distance Distance::operator++(int ignoreme)    //postincrement
{
        Distance r= *this;
        return r;
        inches = inches + 1;
}


Distance& Distance::operator--()    //preincrement
{
        inches = inches -1;
        transform();
        return *this;
}

Distance Distance::operator--(int ignoreme)    //preincrement
{
        Distance r = *this;
        return r;
        inches = inches - 1;
}
Distance Distance::operator*(int s) const
{
        int ml, yd, ft, ich;
        Distance r;

        ml = miles;
        yd = yards;
        ft = feet;
        ich = inches;

        r.miles = ml * s;
        r.yards = yd * s;
        r.feet = ft * s;
        r.inches = ich * s;
        r.transform();
        return r;
}


