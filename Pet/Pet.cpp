#include"Pet.h"

Pet::Pet(std::string number,std::string name,std::string weight,std::string age,std::string kind,std::string price,std::string character,std::string state):
        P_number(number),
        P_name(name),
        P_weight(weight),
        P_age(age),
        P_kind(kind),
        P_price(price),
        P_character(character),
        P_state(state)
        {}
Pet::Pet(const Pet &other):
        P_number(other.P_number),
        P_name(other.P_name),
        P_weight(other.P_weight),
        P_age(other.P_age),
        P_kind(other.P_kind),
        P_price(other.P_age),
        P_character(other.P_character),
        P_state(other.P_state)
        {}

std::ostream & operator << (std::ostream& os,const Pet& pt){
        os << pt.P_number;
        return os;
}

std::istream & operator >> (std::istream& is,Pet& pt){
    is >> pt.P_number;
    return is;
}

bool Pet::operator == (Pet& pt){
    if(P_number == pt.P_number){
        return true;
    }else{
        return false;
    }
}