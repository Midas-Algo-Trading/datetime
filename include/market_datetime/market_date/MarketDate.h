#ifndef INCLUDE_DATETIME_MARKETDATE_H
#define INCLUDE_DATETIME_MARKETDATE_H


#include "datetime/date/Date.h"

class MarketDate : public Date
{
public:
    explicit MarketDate(uint16_t year, uint8_t month, uint8_t day) : Date(year, month, day) {}

//    MarketDate(int i, int i_1, int i_2);

    MarketDate(int i, int i_1, int i_2);

    bool is_market_date();
};


#endif //INCLUDE_DATETIME_MARKETDATE_H
