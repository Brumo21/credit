#include "Common.h"

#include "Card.h"

int main(int argc, char* argv[]) {
    l_long card_number = 0;
    if(argc > 1) {
        card_number = atoll(argv[1]);
    } else {
        std::cout << "INVALID INPUT" << std::endl;
        return -1;
    }

    if (card_number == 0) {
        std::cout << "INVALID INPUT" << std::endl;
        return -1;
    }

    Card card(card_number);
    
    if (card.is_valid()) {
        std::cout << card.get_card_company() << std::endl;
    } else {
        std::cout << "INVALID" << std::endl;
    }

    return 0;
}
