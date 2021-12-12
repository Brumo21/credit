#include "Card.h"

Card::Card(l_long _card_number) {
    this->m_card_number = _card_number;    
}

Card::~Card() 
{
    
}

template <class T>
int Card::_get_number_length(T n) {
    int ctr = 0;
    while(n > 1) {
        ctr++;
        n /= 10;
    }

    return ctr;
}

std::string Card::get_card_company() {
    int card_len = this->_get_number_length(this->m_card_number);
    int first_two = this->m_card_number / pow(10, card_len - 2);

    if (card_len == 13 || card_len == 16) {
        if (first_two / 10 == 4) {
            return "VISA";
        } else if (first_two >= 51 && first_two <= 55) {
            return "MASTERCARD";
        } else {
            return "INVALID";
        }
    } else if (card_len == 15 && (first_two == 34 || first_two == 37)) {
        return "AMEX";
    } else {
        return "INVALID";
    }
}

bool Card::is_valid() {
    l_long sum = 0;
    l_long copy = this->m_card_number;
    int n_len = this->_get_number_length(copy);

    for (int i = 0; i <= n_len; i++) {
        l_long single = copy % 10;

        if (i % 2 == 0) {
            sum += single;
        } else {
            l_long db = single * 2;
            l_long db_len = this->_get_number_length(db);

            for (int j = 0; j <= db_len; j++) {
                sum += db % 10;
                db /= 10;
            }
        }

        copy /= 10;
    }

    if (sum % 10 == 0) {
        return true;
    } 

    return false;
}
