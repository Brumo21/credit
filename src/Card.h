#include "Common.h"

class Card {

public:
    Card(l_long);
    ~Card();

    bool is_valid();
    std::string get_card_company();


private: 
    l_long _card_number;
    
    template <class T>
    static int _get_number_length(T);

};