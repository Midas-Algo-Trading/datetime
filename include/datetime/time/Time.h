#ifndef TIME_TIME_H
#define TIME_TIME_H

#include <iostream>
#include "datetime/time/components/Hour.h"
#include "datetime/time/components/Minute.h"
#include "datetime/time/components/Second.h"
#include "datetime/time/components/Microsecond.h"
#include "datetime/time/components/Nanosecond.h"
#include "datetime/time/Timezone.h"
#include "datetime/time/components/Millisecond.h"
#include "StringHelpers/StringHelpers.h"
#include "../../../util/macros.h"

/**
 * Time with components: 'hour', 'minute', 'second', 'millisecond', 'microsecond',
 * and 'nanosecond'.
 */
class Time
{
public:
    /**
     * Hour of a day.
     */
    uint8_t hour = 0;

    /**
     * Minute of a day.
     */
    uint8_t minute = 0;

    /**
     * Second of a day.
     */
    uint8_t second = 0;

    /**
     * Millisecond of a day.
     */
    uint16_t millisecond = 0;

    /**
     * Microsecond of a day.
     */
    uint16_t microsecond = 0;

    /**
     * Nanosecond of a day.
     */
    uint16_t nanosecond = 0;

    /**
     * 'Timezone' of the 'Time'.
     */
    Timezone timezone = default_timezone;

    /**
     * Default 'Timezone' of all 'Time' objects.
     *
     * All newly created 'Time' objects' 'timezone' will be set to this value.
     */
    static Timezone default_timezone;

    /**
     * Creates a 'Time' whose components match the values of 'hour', 'minute',
     * 'second', 'millisecond', 'microsecond', 'nanosecond', and 'timezone'.
     *
     * @param hour hour the 'Time' will be set to.
     * @param minute minute the 'Time' will be set to.
     * @param second second the 'Time' will be set to.
     * @param millisecond millisecond the 'Time' will be set to.
     * @param microsecond microsecond the 'Time' will be set to.
     * @param nanosecond nanosecond the 'Time' will be set to.
     * @param timezone timezone the 'Time' will be set to.
     */
    explicit Time(int hour=0, int minute = 0, int second = 0, int millisecond = 0,
                  int microsecond = 0, int nanosecond = 0, Timezone timezone = default_timezone);

    /**
     * Creates a 'Time' from a std::string.
     *
     * @tparam TimeComponents should be of type 'Component'.
     *
     * @param string string representation of the date.
     * @param time_components 'Components' that correspond to each number in 'string'.
     */
    template<typename... TimeComponents>
    explicit Time(std::string_view string, TimeComponents... time_components);

    /**
     * Creates a 'Time' whose components' values match the current time.
     *
     * @param timezone 'Timezone' to set the current time to.
     *
     * @return created 'Time'.
     */
    static Time now(Timezone timezone = default_timezone);

    /**
     * Components of a time.
     */
    enum Component { HOUR, MINUTE, SECOND, MILLISECOND, MICROSECOND, NANOSECOND};

    /**
     * Adds 'hours' to this 'Time'.
     *
     * @param days number of days to add to this 'Time'.
     *
     * @return reference to this modified 'Time'.
     */
    virtual Time& operator+=(const Hour& hours);

    /**
     * Subtracts 'hours' from this 'Time'.
     *
     * @param days number of days to subtract from this 'Time'.
     *
     * @return reference to this modified 'Time'.
     */
    virtual Time& operator-=(const Hour& hours);

    /**
     * Adds 'minutes' to this 'Time'.
     *
     * @param days number of days to add to this 'Time'.
     *
     * @return reference to this modified 'Time'.
     */
    virtual Time& operator+=(const Minute& minutes);

    /**
     * Subtracts 'minutes' from this 'Time'.
     *
     * @param days number of days to subtract from this 'Time'.
     *
     * @return reference to this modified 'Time'.
     */
    virtual Time& operator-=(const Minute& minutes);

    /**
     * Adds 'seconds' to this 'Time'.
     *
     * @param days number of days to add to this 'Time'.
     *
     * @return reference to this modified 'Time'.
     */
    virtual Time& operator+=(const Second& seconds);

    /**
     * Subtracts 'seconds' from this 'Time'.
     *
     * @param days number of days to subtract from this 'Time'.
     *
     * @return reference to this modified 'Time'.
     */
    virtual Time& operator-=(const Second& seconds);

    /**
     * Adds 'milliseconds' to this 'Time'.
     *
     * @param days number of days to add to this 'Time'.
     *
     * @return reference to this modified 'Time'.
     */
    virtual Time& operator+=(const Millisecond& milliseconds);

    /**
     * Subtracts 'milliseconds' from this 'Time'.
     *
     * @param days number of days to subtract from this 'Time'.
     *
     * @return reference to this modified 'Time'.
     */
    virtual Time& operator-=(const Millisecond& milliseconds);

    /**
      * Adds 'microseconds' to this 'Time'.
      *
      * @param days number of days to add to this 'Time'.
      *
      * @return reference to this modified 'Time'.
      */
    virtual Time& operator+=(const Microsecond& microseconds);

    /**
     * Subtracts 'microseconds' from this 'Time'.
     *
     * @param days number of days to subtract from this 'Time'.
     *
     * @return reference to this modified 'Time'.
     */
    virtual Time& operator-=(const Microsecond& microseconds);

    /**
     * Adds 'nanoseconds' to this 'Time'.
     *
     * @param days number of days to add to this 'Time'.
     *
     * @return reference to this modified 'Time'.
     */
    virtual Time& operator+=(const Nanosecond& nanoseconds);

    /**
     * Subtracts 'nanoseconds' from this 'Time'.
     *
     * @param days number of days to subtract from this 'Time'.
     *
     * @return reference to this modified 'Time'.
     */
    virtual Time& operator-=(const Nanosecond& nanoseconds);

    /**
     * Checks if 'other' is greater than this 'Time'.
     *
     * @param other 'Time' to check if greater than this 'Time'.
     *
     * @return 'true' if 'other' is greater than this 'Time', 'false' otherwise.
     */
    bool operator>(const Time& other) const;

    /**
     * Checks if 'other' is greater than or equal to this 'Time'.
     *
     * @param other 'Time' to check if greater than or equal to this 'Time'.
     *
     * @return 'true' if 'other' is greater than or equal to this 'Time', 'false' otherwise.
     */
    bool operator>=(const Time& other) const;

    /**
     * Checks if 'other' is less than this 'Time'.
     *
     * @param other 'Time' to check if less than this 'Time'.
     *
     * @return 'true' if 'other' is less than this 'Time', 'false' otherwise.
     */
    bool operator<(const Time& other) const;

    /**
       * Checks if 'other' is less than or equal to this 'Time'.
       *
       * @param other 'Time' to check if less than or equal to this 'Time'.
       *
       * @return 'true' if 'other' is less than or equal to this 'Time', 'false' otherwise.
       */
    bool operator<=(const Time& other) const;

    /**
          * Checks if 'other' is not equal to this 'Time'.
          *
          * @param other 'Time' to check if not equal to this 'Time'.
          *
          * @return 'true' if 'other' is not equal to this 'Time', 'false' otherwise.
          */
    bool operator==(const Time& other) const;

    /**
     * Adds a day to this 'Time'.
     *
     * @return reference to this modified 'Time'.
     */
    bool operator!=(const Time& other) const;

    /**
     * Sets the 'timezone' of this 'Time'.
     *
     * @param new_timezone 'Timezone' to set 'timezone' to.
     */
    void set_timezone(Timezone new_timezone);

    /**
     * Sets 'default_timezone' of the 'Time' class.
     *
     * @param timezone 'Timezone' to set 'default_timezone' to.
     */
    static void set_default_timezone(Timezone timezone);

    /**
     * Rounds the components of this 'Time', stopping at 'to'.
     *
     * @param to finish the rounding of this 'Time's' components at this 'Component'.
     *
     * @example
     * Time time = Time(1, 2, 33, 4, 5, 6);
     * time.round(Time::MINUTE);
     * std::cout << time;
     *
     * // output: 1:03:00.0.0.0
     */
    void round(Component to);

    /**
     * Rounds up the components of this 'Time', stopping at 'to'.
     *
     * @param to finish the rounding up of this 'Time's' components at this 'Component'.
     */
    void ceil(Component to);

    /**
     * Rounds down the components of this 'Time', stopping at 'to'.
     *
     * @param to finish the rounding down of this 'Time's' components at this 'Component'.
     */
    void floor(Component to);

    /**
     * Represents this 'Time' as a std::string.
     *
     * Represents this 'Time' as a std::string with format %-H:%M:%S.%ms.%f.%ns
     *
     * @example
     * Time time = Datetime(1, 2, 3, 4, 5, 6);
     * std::string time_string = date.to_string();
     * std::cout << time_string;
     *
     * // output: 1:02:04.4.5.6
     *
     * @return resulting std::string.
     */
    virtual std::string to_string() const;

    /**
     * Hours in a day.
     */
    static const int HOURS_PER_DAY;

    /**
     * Outputs 'time' into 'os'.
     *
     * @param os std::ostream' to insert 'time' into.
     * @param time 'Time' to insert into 'os'.
     *
     * @return reference to 'os' after inserting 'date' into 'os'.
     */
    friend std::ostream& operator<<(std::ostream& os, const Time& time);

protected:
    /**
     * Adds hours to this 'Time'.
     *
     * @param hours_to_add number of hours to add.
     */
    virtual void add_hours(int hours_to_add);

    /**
     * Adds minutes to this 'Time'.
     *
     * @param minutes_to_add number of minutes to add.
     */
    virtual void add_minutes(int minutes_to_add);

    /**
     * Adds seconds to this 'Time'.
     *
     * @param seconds_to_add number of seconds to add.
     */
    virtual void add_seconds(int seconds_to_add);

    /**
      * Adds milliseconds to this 'Time'.
      *
      * @param milliseconds_to_add number of milliseconds to add.
      */
    virtual void add_milliseconds(int64_t milliseconds_to_add);

    /**
      * Adds microseconds to this 'Time'.
      *
      * @param microseconds_to_add number of microseconds to add.
      */
    virtual void add_microseconds(int64_t microseconds_to_add);

    /**
      * Adds nanoseconds to this 'Time'.
      *
      * @param nanoseconds_to_add number of nanoseconds to add.
      */
    virtual void add_nanoseconds(int64_t nanoseconds_to_add);

    /**
     * Gets the total minutes of the day.
     *
     * @return total minutes of the day.
     */
    int total_minutes() const;

    /**
     * Gets the total seconds of the day.
     *
     * @return total seconds of the day.
     */
    int total_seconds() const;

    /**
     * Gets the total milliseconds of the day.
     *
     * @return total milliseconds of the day.
     */
    int64_t total_milliseconds() const;

    /**
     * Gets the total microseconds of the day.
     *
     * @return total microseconds of the day.
     */
    int64_t total_microseconds() const;

    /**
     * Gets the total nanoseconds of the day.
     *
     * @return total nanoseconds of the day.
     */
    int64_t total_nanoseconds() const;

private:

    // Following int64_t values are not unsigned ints to avoid numerous narrowing conversions.

    /**
     * Minutes in a hour.
     */
    static const size_t MINUTES_PER_HOUR;

    /**
     * Seconds in a minute.
     */
    static const size_t SECONDS_PER_MINUTE;

    /**
     * Seconds in a hour.
     */
    static const size_t SECONDS_PER_HOUR;

    /**
     * Milliseconds in a second.
     */
    static const size_t MILLISECONDS_PER_SECOND;

    /**
     * Milliseconds in a minute.
     */
    static const size_t MILLISECONDS_PER_MINUTE;

    /**
     * Milliseconds in a minute.
     */
    static const size_t MILLISECONDS_PER_HOUR;

    /**
     * Microseconds in a millisecond.
     */
    static const size_t MICROSECONDS_PER_MILLISECOND;

    /**
     * Microseconds in a hour.
     */
    static const size_t MICROSECONDS_PER_HOUR;

    /**
     * Microseconds in a minute.
     */
    static const size_t MICROSECONDS_PER_MINUTE;

    /**
     * Microseconds in a second.
     */
    static const size_t MICROSECONDS_PER_SECOND;

    /**
     * Nanoseconds in a microsecond.
     */
    static const size_t NANOSECONDS_PER_MICROSECOND;

    /**
     * Nanoseconds in a hour.
     */
    static const size_t NANOSECONDS_PER_HOUR;

    /**
     * Nanoseconds in a minute.
     */
    static const size_t NANOSECONDS_PER_MINUTE;

    /**
     * Nanoseconds in a second.
     */
    static const size_t NANOSECONDS_PER_SECOND;

    /**
     * Nanoseconds in a millisecond.
     */
    static const size_t NANOSECONDS_PER_MILLISECOND;

    /**
     * Gets 'hour' adjusted for 'timezone'.
     *
     * @param timezone timezone to adjust 'hour' to.
     *
     * @return adjusted 'hour'.
     */
    int get_hour_at_timezone(Timezone timezone) const;

    /**
     * Checks if this 'Time's' components are all valid.
     *
     * @return 'true' if all this 'Time's' components are all valid, 'false' otherwise.
     */
    bool is_valid_time() const;

    /**
     * Checks if 'hour' is valid.
     *
     * Checks if 'hour' is less than 60 and greater than or equal to 0.
     *
     * @return 'true' is 'month' is valid, 'false' otherwise.
     */
    bool is_valid_hour() const;

    /**
     * Checks if 'minute' is valid.
     *
     * Checks if 'minute' is less than 60 and greater than or equal to 0.
     *
     * @return 'true' is 'month' is valid, 'false' otherwise.
     */
    bool is_valid_minute() const;


    /**
     * Checks if 'second' is valid.
     *
     * Checks if 'second' is less than 60 and greater than or equal to 0.
     *
     * @return 'true' is 'month' is valid, 'false' otherwise.
     */
    bool is_valid_second() const;

    /**
     * Checks if 'millisecond' is valid.
     *
     * Checks if 'millisecond' is less than 1000 and greater than or equal to 0.
     *
     * @return 'true' is 'month' is valid, 'false' otherwise.
     */
    bool is_valid_millisecond() const;

    /**
     * Checks if 'microsecond' is valid.
     *
     * Checks if 'microsecond' is less than 1000 and greater than or equal to 0.
     *
     * @return 'true' is 'month' is valid, 'false' otherwise.
     */
    bool is_valid_microsecond() const;

    /**
     * Checks if 'hour' is valid.
     *
     * Checks if 'nanosecond' is less than 1000 and greater than or equal to 0.
     *
     * @return 'true' is 'nanosecond' is valid, 'false' otherwise.
     */
    bool is_valid_nanosecond() const;
};

template<typename... TimeComponent>
Time::Time(std::string_view string, TimeComponent... time_components)
{
    std::vector<std::string> time_components_strs = strh::split_alphabetical(string);

    ASSERT(time_components_strs.size() == sizeof...(time_components),
           std::invalid_argument(fmt::format("components: '{}' with size '{}' does not match date "
                                             "strings: '{}' with size '{}'",
                                             strh::from_parameter_pack(time_components...),
                                             sizeof...(time_components),
                                             fmt::join(time_components_strs, ", "),
                                             time_components_strs.size())));

    size_t idx = 0;

    // Lambda to get each time component value from each time component string
    auto get_time_components_from_str = [&](const auto& time_component, size_t idx) {
        switch (time_component)
        {
        case Time::Component::HOUR:
            hour = std::stoi(time_components_strs[idx]);
            break;
        case Time::Component::MINUTE:
            if (time_components_strs[idx][0] == '0')
                minute = time_components_strs[idx][1] - '0'; // char to int
            else
                minute = std::stoi(time_components_strs[idx]);
            break;
        case Time::Component::SECOND:
            if (time_components_strs[idx][0] == '0')
                second = time_components_strs[idx][1] - '0'; // char to int
            else
                second = std::stoi(time_components_strs[idx]);
            break;
        case Time::Component::MILLISECOND:
            millisecond = std::stoi(time_components_strs[idx]);
            break;
        case Time::Component::MICROSECOND:
            microsecond = std::stoi(time_components_strs[idx]);
            break;
        case Time::Component::NANOSECOND:
            nanosecond = std::stoi(time_components_strs[idx]);
            break;
        }
    };

    // Call the lambda function on each time component
    (get_time_components_from_str(time_components, idx++), ...);

    ASSERT(is_valid_time(),
           std::invalid_argument(fmt::format("Time '{}' is invalid", Time::to_string())));
}


#endif //TIME_TIME_H
