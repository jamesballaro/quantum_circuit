#ifndef TYPE_H
#define TYPE_H

#include <string>

class type{
    public:
        virtual ~type() = default;
        virtual std::string get_name() const=0;
};

#endif;

