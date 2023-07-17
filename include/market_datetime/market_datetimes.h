#ifndef INCLUDE_DATETIME_MARKET_DATETIMES_H
#define INCLUDE_DATETIME_MARKET_DATETIMES_H

#include "datetime/time/Time.h"
#include "../datetime/time/Timezone.h"
#include "../datetime/time/TimeRange.h"
#include "market_date/MarketDate.h"
#include <map>


Time time = Time(1, 2, 3, 4, 5, 6, TZ::CST);

std::map<MarketDate, Time> market_dates = {
    {MarketDate(1995, 1, 3), TimeRange(Time(static_cast<uint16_t>(14), 30), Time(21))}
};

#endif //INCLUDE_DATETIME_MARKET_DATETIMES_H
