cmake_minimum_required(VERSION 3.24)
project(datetime)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(libraries/fmt)
add_subdirectory(libraries/StringHelpers)

include_directories(libraries/StringHelpers/include
                    libraries/fmt/include)

add_library(DatetimeLib
        include/datetime/time/Time.h
        include/datetime/time/Time.cpp
        include/datetime/time/components/Hour.h
        include/datetime/Component.h
        include/datetime/time/components/Minute.h
        include/datetime/time/components/Second.h
        include/datetime/time/components/Microsecond.h
        include/datetime/time/components/Nanosecond.h
        include/datetime/date/Date.cpp
        include/datetime/date/Date.h
        include/datetime/date/components/Day.h
        include/datetime/time/Timezone.h
        include/datetime/time/components/Millisecond.h
        include/datetime/time/TimeRange.h
        include/datetime/Range.h
        ../util/exceptions/not_implemented_error.h
        include/datetime/date/DateRange.h
        include/datetime/datetime/Datetime.h
        include/datetime/datetime/Datetime.cpp
        include/datetime/datetime/DatetimeRange.h
        include/datetime/time/components/TimeComponent.h
        include/market_datetime/market_date/MarketDate.h
        include/market_datetime/market_date/MarketDate.cpp
        include/market_datetime/market_datetimes.h)

include_directories(include)

target_link_libraries(DatetimeLib StringHelpers fmt)

add_subdirectory(test)