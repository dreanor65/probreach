//
// Created by fedor on 26/12/15.
//
#include<capd/capdlib.h>
#include<capd/intervals/lib.h>

#ifndef PROBREACH_BOX_H
#define PROBREACH_BOX_H

using namespace std;

class box
{
protected:
    std::map<std::string, capd::interval> edges;

public:
    box();
    box(std::map<std::string, capd::interval>);
    box(string);

    //friend std::ostream& operator<<(std::ostream&, const box &);
    //inline bool operator< (const X& lhs, const X& rhs){ /* do actual comparison */ }
    //inline bool operator> (const X& lhs, const X& rhs){ return rhs < lhs; }
    //inline bool operator<=(const X& lhs, const X& rhs){ return !(lhs > rhs); }
    //inline bool operator>=(const X& lhs, const X& rhs){ return !(lhs < rhs); }
    //inline bool operator==(const X& lhs, const X& rhs){ /* do actual comparison */ }
    //inline bool operator!=(const X& lhs, const X& rhs){ return !(lhs == rhs); }

    friend std::ostream& operator<<(std::ostream&, const box&);
    friend bool operator<(const box&, const box&);
    friend bool operator==(const box&, const box&);
    friend box operator+(const box&, const box&);
    friend box operator-(const box&, const box&);
    friend box operator*(const box&, const box&);
    friend box operator/(const box&, const box&);

    std::map<std::string, capd::interval> get_map() const;
    std::vector<capd::interval> get_intervals() const;
    std::vector<std::string> get_vars() const;
    bool empty() const;
    bool contains(box) const;
    bool intersects(box) const;
    bool compatible(box) const;
    box get_keys_diff(box) const;
    box get_mean();
    box get_stddev();
    box fmod (int);
    double max_coordinate_value();
    double max_side_width();
    double min_side_width();

};

class dd_box : public box
{
public:
    dd_box(std::map<std::string, capd::interval>);
    dd_box(box);
};

class rv_box : public box
{
public:
    rv_box(std::map<std::string, capd::interval>);
    rv_box(box);
};

class nd_box : public box
{
public:
    nd_box(std::map<std::string, capd::interval>);
    nd_box(box);
};

#endif //PROBREACH_BOX_H
