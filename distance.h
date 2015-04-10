
#include <iostream>
using namespace std;


class Distance
{
        friend ostream& operator<<(ostream& s, const Distance& d);
        friend istream& operator>>(istream& s, Distance& d);
        friend bool operator<(const Distance& d1, const Distance& d2);
        friend bool operator==(const Distance& d1, const Distance& d2);
        friend bool operator!=(const Distance& d1, const Distance& d2);
        friend bool operator>(const Distance& d1, const Distance& d2) ;
        friend bool operator<=(const Distance& d1, const Distance& d2);
        friend bool operator>=(const Distance& d1, const Distance& d2);
public:
        Distance();
        Distance(int ich);
        Distance(int ml, int yd, int ft, int ich);
        void transform();
        Distance operator+(const Distance& d2) const;
        Distance operator-(const Distance& d2) const;
        Distance operator*(int s) const;
        Distance& operator++();
        Distance operator++(int);
        Distance& operator--();
        Distance operator--(int);



private:
        int miles;
        int yards;
        int feet;
        int inches;

};

