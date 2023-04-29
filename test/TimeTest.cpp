#include "gtest/gtest.h"

#define private public
#include "../src/time/Time.cpp"
#include "../src/time/TimeRange.h"

TEST(Time, constructor_sets_members)
{
        Time time = Time(1, 2, 3, 4, 5, 6, TZ::CST);
        EXPECT_EQ(time.hour, 1);
        EXPECT_EQ(time.minute, 2);
        EXPECT_EQ(time.second, 3);
        EXPECT_EQ(time.millisecond, 4);
        EXPECT_EQ(time.microsecond, 5);
        EXPECT_EQ(time.nanosecond, 6);
        EXPECT_EQ(time.timezone, TZ::CST);
}

TEST(Time, constructor_throws_invalid_argument)
{
        EXPECT_THROW(Time(24), std::invalid_argument);
        EXPECT_THROW(Time(0, 61), std::invalid_argument);
        EXPECT_THROW(Time(0, 0, 60), std::invalid_argument);
        EXPECT_THROW(Time(0, 0, 0, 1001), std::invalid_argument);
        EXPECT_THROW(Time(0, 0, 0, 0, 1000), std::invalid_argument);
        EXPECT_THROW(Time(0, 0, 0, 0, 0, 1001), std::invalid_argument);
}

TEST(Time, now_sets_timezone)
{
        Time time = Time::now(TZ::CST);
        EXPECT_EQ(time.timezone, TZ::CST);
        int old_hour = time.hour;
        time.set_timezone(TZ::EST);
        EXPECT_EQ(time.hour - old_hour, 1);
}

TEST(Time, operator_plusequal_hour_basic)
{
        Time time = Time(1);
        time += Hour(1);
        EXPECT_EQ(time.hour, 2);
}

TEST(Time, operator_plusequal_hour_wraps)
{
        Time time = Time(22);
        time += Hour(4);
        EXPECT_EQ(time.hour, 2);
}

TEST(Time, operator_minusequal_hour_basic)
{
        Time time = Time(3);
        time -= Hour(1);
        EXPECT_EQ(time.hour, 2);
}

TEST(Time, operator_minusequal_hour_throws_out_of_range)
{
        Time time = Time(0);
        EXPECT_THROW(time -= Hour(1), std::out_of_range);
}

TEST(Time, operator_plusequal_minute_basic)
{
        Time time = Time(0, 1);
        time += Minute(1);
        EXPECT_EQ(time.minute, 2);
}

TEST(Time, operator_plusequal_minute_adds_hour)
{
        Time time = Time(0, 58);
        time += Minute(4);
        EXPECT_EQ(time.hour, 1);
        EXPECT_EQ(time.minute, 2);
}

TEST(Time, operator_minusequal_minute_basic)
{
        Time time = Time(0, 3);
        time -= Minute(1);
        EXPECT_EQ(time.minute, 2);
}

TEST(Time, operator_minusequal_minute_subtracts_hour)
{
        Time time = Time(1, 1);
        time -= Minute(2);
        EXPECT_EQ(time.hour, 0);
        EXPECT_EQ(time.minute, 59);
}

TEST(Time, operator_plusequal_second_basic)
{
        Time time = Time(0, 0, 1);
        time += Second(1);
        EXPECT_EQ(time.second, 2);
}

TEST(Time, operator_plusequal_second_adds_minute)
{
        Time time = Time(0, 0, 58);
        time += Second(4);
        EXPECT_EQ(time.minute, 1);
        EXPECT_EQ(time.second, 2);
}

TEST(Time, operator_minusequal_second_basic)
{
        Time time = Time(0, 0, 3);
        time -= Second(1);
        EXPECT_EQ(time.second, 2);
}

TEST(Time, operator_minusequal_second_subtracts_minute)
{
        Time time = Time(0, 1, 1);
        time -= Second(2);
        EXPECT_EQ(time.minute, 0);
        EXPECT_EQ(time.second, 59);
}

TEST(Time, operator_plusequal_millisecond_basic)
{
        Time time = Time(0, 0, 0, 1);
        time += Millisecond(1);
        EXPECT_EQ(time.millisecond, 2);
}

TEST(Time, operator_plusequal_millisecond_adds_minute)
{
        Time time = Time(0, 0, 0, 999);
        time += Millisecond(3);
        EXPECT_EQ(time.second, 1);
        EXPECT_EQ(time.millisecond, 2);
}

TEST(Time, operator_minusequal_millisecond_basic)
{
        Time time = Time(0, 0, 0, 3);
        time -= Millisecond(1);
        EXPECT_EQ(time.millisecond, 2);
}

TEST(Time, operator_minusequal_millisecond_subtracts_second)
{
        Time time = Time(0, 0, 1, 1);
        time -= Millisecond(2);
        EXPECT_EQ(time.second, 0);
        EXPECT_EQ(time.millisecond, 999);
}

TEST(Time, operator_plusequal_microsecond_basic)
{
        Time time = Time(0, 0, 0, 0, 1);
        time += Microsecond(1);
        EXPECT_EQ(time.microsecond, 2);
}

TEST(Time, operator_plusequal_microsecond_adds_millisecond)
{
        Time time = Time(0, 0, 0, 0, 999);
        time += Microsecond(3);
        EXPECT_EQ(time.millisecond, 1);
        EXPECT_EQ(time.microsecond, 2);
}

TEST(Time, operator_minusequal_microsecond_basic)
{
        Time time = Time(0, 0, 0, 0, 3);
        time -= Microsecond(1);
        EXPECT_EQ(time.microsecond, 2);
}

TEST(Time, operator_minusequal_microsecond_subtracts_millisecond)
{
        Time time = Time(0, 0, 0, 1, 1);
        time -= Microsecond(2);
        EXPECT_EQ(time.millisecond, 0);
        EXPECT_EQ(time.microsecond, 999);
}

TEST(Time, operator_plusequal_nanosecond_basic)
{
        Time time = Time(0, 0, 0, 0, 0, 1);
        time += Nanosecond(1);
        EXPECT_EQ(time.nanosecond, 2);
}

TEST(Time, operator_plusequal_nanoecond_adds_minute)
{
        Time time = Time(0, 0, 0, 0, 0, 999);
        time += Nanosecond(3);
        EXPECT_EQ(time.microsecond, 1);
        EXPECT_EQ(time.nanosecond, 2);
}

TEST(Time, operator_minusequal_nanosecond_basic)
{
        Time time = Time(0, 0, 0, 0, 0, 3);
        time -= Nanosecond(1);
        EXPECT_EQ(time.nanosecond, 2);
}

TEST(Time, operator_minusequal_nanosecond_subtracts_microsecond)
{
        Time time = Time(0, 0, 0, 0, 1, 1);
        time -= Nanosecond(2);
        EXPECT_EQ(time.microsecond, 0);
        EXPECT_EQ(time.nanosecond, 999);
}

TEST(Time, set_timezone_basic)
{
        Time time = Time(0 ,0 ,0, 0, 0, 0, TZ::CST);
        time.set_timezone(TZ::EST);
        EXPECT_EQ(time.hour, 1);
}

TEST(Time, set_timezone_wraps)
{
        Time time = Time(23 ,0 ,0, 0, 0, 0, TZ::CST);
        time.set_timezone(TZ::EST);
        EXPECT_EQ(time.hour, 0);
}

TEST(Time, set_default_timezone)
{
        Timezone original_default_timezone = Time::default_timezone;
        Time::set_default_timezone(TZ::UTC);
        EXPECT_EQ(Time::default_timezone, TZ::UTC);
        Time::default_timezone = original_default_timezone;
}

TEST(Time, get_hour_at_timezone_basic)
{
        Time time = Time(1);
        EXPECT_EQ(time.get_hour_at_timezone(TZ::UTC), 7);
}

TEST(Time, get_hour_at_timezone_wrap)
{
        Time time = Time(20);
        EXPECT_EQ(time.get_hour_at_timezone(TZ::UTC), 2);
}

TEST(Time, unit_conversions)
{
        EXPECT_EQ(Time::HOURS_PER_DAY, 24);
        EXPECT_EQ(Time::MINUTES_PER_HOUR, 60);
        EXPECT_EQ(Time::SECONDS_PER_MINUTE, 60);
        EXPECT_EQ(Time::SECONDS_PER_HOUR, 3'600);
        EXPECT_EQ(Time::MILLISECONDS_PER_SECOND, 1'000);
        EXPECT_EQ(Time::MILLISECONDS_PER_MINUTE, 60'000);
        EXPECT_EQ(Time::MILLISECONDS_PER_HOUR, 3'600'000);
        EXPECT_EQ(Time::MICROSECONDS_PER_MILLISECOND, 1'000);
        EXPECT_EQ(Time::MICROSECONDS_PER_HOUR, 3'600'000'000);
        EXPECT_EQ(Time::MICROSECONDS_PER_MINUTE, 60'000'000);
        EXPECT_EQ(Time::MICROSECONDS_PER_SECOND, 1'000'000);
        EXPECT_EQ(Time::NANOSECONDS_PER_MICROSECOND, 1'000);
        EXPECT_EQ(Time::NANOSECONDS_PER_HOUR, 3'600'000'000'000);
        EXPECT_EQ(Time::NANOSECONDS_PER_MINUTE, 60'000'000'000);
        EXPECT_EQ(Time::NANOSECONDS_PER_SECOND, 1'000'000'000);
        EXPECT_EQ(Time::NANOSECONDS_PER_MILLISECOND, 1'000'000);
}

TEST(Time, ostream)
{
        Time time = Time(1, 2, 3, 4, 5, 6);
        std::stringstream actual;
        actual << time;
        EXPECT_EQ(actual.str(), "1:02:03.4.5.6");
}

TEST(TimeRange, constructor_sets_variables)
{
        Time start = Time(0, 0, 0, 0, 0, 0);
        Time end = Time(1, 0, 0, 0, 0, 0);
        TimeRange time_range = TimeRange(start, end);
        EXPECT_EQ(time_range.start, start);
        EXPECT_EQ(time_range.end, end);
}

TEST(TimeRange, constructor_start_greater_than_end_throws_illegal_argument)
{
        Time start = Time(1);
        Time end = Time(0);
        EXPECT_THROW(TimeRange(start, end), std::invalid_argument);
}

TEST(TimeRange, in_range)
{
        Time start = Time(1, 0, 0, 0, 0, 0);
        Time end = Time(3, 0, 0, 0, 0, 0);
        TimeRange date_range = TimeRange(start, end);

        Time date = Time(2, 0, 0, 0, 0, 0);
        EXPECT_TRUE(date_range.in_range(date));

        date = Time(1, 0, 0, 0, 0, 0);
        EXPECT_TRUE(date_range.in_range(date));

        date = Time(3, 0, 0, 0, 0, 0);
        EXPECT_TRUE(date_range.in_range(date));

        date = Time(0, 0, 0, 0, 0, 0);
        EXPECT_FALSE(date_range.in_range(date));

        date = Time(4, 0, 0, 0, 0, 0);
        EXPECT_FALSE(date_range.in_range(date));
}

TEST(Time, operator_greater_than)
{
        Time time_greater = Time(2, 0, 0, 0, 0, 0);
        Time time_lesser = Time(1, 0, 0, 0, 0, 0);
        EXPECT_GT(time_greater, time_lesser);

        time_greater = Time(0, 2, 0, 0, 0, 0);
        time_lesser = Time(0, 1, 0, 0, 0, 0);
        EXPECT_GT(time_greater, time_lesser);

        time_greater = Time(0, 0, 2, 0, 0, 0);
        time_lesser = Time(0, 0, 1, 0, 0, 0);
        EXPECT_GT(time_greater, time_lesser);

        time_greater = Time(0, 0, 0, 2, 0, 0);
        time_lesser = Time(0, 0, 0, 1, 0, 0);
        EXPECT_GT(time_greater, time_lesser);

        time_greater = Time(0, 0, 0, 0, 2, 0);
        time_lesser = Time(0, 0, 0, 0, 1, 0);
        EXPECT_GT(time_greater, time_lesser);

        time_greater = Time(0, 0, 0, 0, 0, 2);
        time_lesser = Time(0, 0, 0, 0, 0, 1);
        EXPECT_GT(time_greater, time_lesser);
}

TEST(Time, operator_greater_than_or_equal_to)
{
        Time time_greater = Time(2, 0, 0, 0, 0, 0);
        Time time_lesser = Time(1, 0, 0, 0, 0, 0);
        EXPECT_GE(time_greater, time_lesser);

        time_greater = Time(0, 2, 0, 0, 0, 0);
        time_lesser = Time(0, 1, 0, 0, 0, 0);
        EXPECT_GE(time_greater, time_lesser);

        time_greater = Time(0, 0, 2, 0, 0, 0);
        time_lesser = Time(0, 0, 1, 0, 0, 0);
        EXPECT_GE(time_greater, time_lesser);

        time_greater = Time(0, 0, 0, 2, 0, 0);
        time_lesser = Time(0, 0, 0, 1, 0, 0);
        EXPECT_GE(time_greater, time_lesser);

        time_greater = Time(0, 0, 0, 0, 2, 0);
        time_lesser = Time(0, 0, 0, 0, 1, 0);
        EXPECT_GE(time_greater, time_lesser);

        time_greater = Time(0, 0, 0, 0, 0, 2);
        time_lesser = Time(0, 0, 0, 0, 0, 1);
        EXPECT_GE(time_greater, time_lesser);

        time_lesser = Time(0, 0, 0, 0, 0, 2);
        EXPECT_GE(time_greater, time_lesser);
}

TEST(Time, operator_less_than)
{
        Time time_greater = Time(2, 0, 0, 0, 0, 0);
        Time time_lesser = Time(1, 0, 0, 0, 0, 0);
        EXPECT_LT(time_lesser, time_greater);

        time_greater = Time(0, 2, 0, 0, 0, 0);
        time_lesser = Time(0, 1, 0, 0, 0, 0);
        EXPECT_LT(time_lesser, time_greater);

        time_greater = Time(0, 0, 2, 0, 0, 0);
        time_lesser = Time(0, 0, 1, 0, 0, 0);
        EXPECT_LT(time_lesser, time_greater);

        time_greater = Time(0, 0, 0, 2, 0, 0);
        time_lesser = Time(0, 0, 0, 1, 0, 0);
        EXPECT_LT(time_lesser, time_greater);

        time_greater = Time(0, 0, 0, 0, 2, 0);
        time_lesser = Time(0, 0, 0, 0, 1, 0);
        EXPECT_LT(time_lesser, time_greater);

        time_greater = Time(0, 0, 0, 0, 0, 2);
        time_lesser = Time(0, 0, 0, 0, 0, 1);
        EXPECT_LT(time_lesser, time_greater);
}

TEST(Time, operator_less_than_or_equal_to)
{
        Time time_greater = Time(2, 0, 0, 0, 0, 0);
        Time time_lesser = Time(1, 0, 0, 0, 0, 0);
        EXPECT_LE(time_lesser, time_greater);

        time_greater = Time(0, 2, 0, 0, 0, 0);
        time_lesser = Time(0, 1, 0, 0, 0, 0);
        EXPECT_LE(time_lesser, time_greater);

        time_greater = Time(0, 0, 2, 0, 0, 0);
        time_lesser = Time(0, 0, 1, 0, 0, 0);
        EXPECT_LE(time_lesser, time_greater);

        time_greater = Time(0, 0, 0, 2, 0, 0);
        time_lesser = Time(0, 0, 0, 1, 0, 0);
        EXPECT_LE(time_lesser, time_greater);

        time_greater = Time(0, 0, 0, 0, 2, 0);
        time_lesser = Time(0, 0, 0, 0, 1, 0);
        EXPECT_LE(time_lesser, time_greater);

        time_greater = Time(0, 0, 0, 0, 0, 2);
        time_lesser = Time(0, 0, 0, 0, 0, 1);
        EXPECT_LE(time_lesser, time_greater);

        time_lesser = Time(0, 0, 0, 0, 0, 2);
        EXPECT_LE(time_lesser, time_greater);
}

TEST(Time, operator_equal_to)
{
        Time time1 = Time(0, 0, 0, 0, 0, 0);
        Time time2 = Time(0, 0, 0, 0, 0, 0);
        EXPECT_EQ(time1, time2);

        time2 = Time(1, 0, 0, 0, 0, 0);
        EXPECT_NE(time1, time2);

        time2 = Time(0, 1, 0, 0, 0, 0);
        EXPECT_NE(time1, time2);

        time2 = Time(0, 0, 1, 0, 0, 0);
        EXPECT_NE(time1, time2);

        time2 = Time(0, 0, 0, 1, 0, 0);
        EXPECT_NE(time1, time2);

        time2 = Time(0, 0, 0, 0, 1, 0);
        EXPECT_NE(time1, time2);

        time2 = Time(0, 0, 0, 0, 0, 1);
        EXPECT_NE(time1, time2);
}

TEST(Time, operator_not_equal_to)
{
        Time time1 = Time(0, 0, 0, 0, 0, 0);
        Time time2 = Time(1, 0, 0, 0, 0, 0);
        EXPECT_NE(time1, time2);

        time2 = Time(0, 1, 0, 0, 0, 0);
        EXPECT_NE(time1, time2);

        time2 = Time(0, 2, 1, 0, 0, 0);
        EXPECT_NE(time1, time2);

        time2 = Time(0, 0, 0, 1, 0, 0);
        EXPECT_NE(time1, time2);

        time2 = Time(0, 0, 0, 0, 1, 0);
        EXPECT_NE(time1, time2);

        time2 = Time(0, 0, 0, 0, 0, 1);
        EXPECT_NE(time1, time2);

        time2 = Time(0, 0, 0, 0, 0, 0);
        EXPECT_EQ(time1, time2);
}

TEST(Timezone, get_from_str)
{
        EXPECT_EQ(TZ::get_from_str("Coordinated Universal Time"), TZ::UTC);
        EXPECT_EQ(TZ::get_from_str("Pacific Standard Time"), TZ::PST);
        EXPECT_EQ(TZ::get_from_str("Central Daylight Time"), TZ::CST);
        EXPECT_EQ(TZ::get_from_str("Eastern Standard Time"), TZ::EST);
}

TEST(Timezone, get_from_str_throws_if_not_timezone_str)
{
        EXPECT_THROW(TZ::get_from_str("Invalid timezone str"), std::invalid_argument);
}


TEST(Time, round_up)
{
        Time time = Time(11, 29, 30, 1, 1, 1);
        time.round(Time::Component::HOUR);
        EXPECT_EQ(time, Time(12, 0, 0, 0, 0, 0));

        time = Time(1, 29, 29, 500, 1, 1);
        time.round(Time::Component::MINUTE);
        EXPECT_EQ(time, Time(1, 30, 0, 0, 0, 0));

        time = Time(1, 0, 29, 499, 500, 1);
        time.round(Time::Component::SECOND);
        EXPECT_EQ(time, Time(1, 0, 30, 0, 0, 0));

        time = Time(1, 0, 0, 499, 499, 500);
        time.round(Time::Component::MILLISECOND);
        EXPECT_EQ(time, Time(1, 0, 0, 500, 0, 0));

        time = Time(1, 0, 0, 0, 499, 500);
        time.round(Time::Component::MICROSECOND);
        EXPECT_EQ(time, Time(1, 0, 0, 0, 500, 0));
}

TEST(Time, round_down)
{
        Time time = Time(11, 29, 1, 1, 1, 1);
        time.round(Time::Component::HOUR);
        EXPECT_EQ(time, Time(11, 0, 0, 0, 0, 0));

        time = Time(1, 29, 29, 1, 1, 1);
        time.round(Time::Component::MINUTE);
        EXPECT_EQ(time, Time(1, 29, 0, 0, 0, 0));

        time = Time(1, 1, 29, 499, 1, 1);
        time.round(Time::Component::SECOND);
        EXPECT_EQ(time, Time(1, 1, 29, 0, 0, 0));

        time = Time(1, 1, 1, 499, 499, 1);
        time.round(Time::Component::MILLISECOND);
        EXPECT_EQ(time, Time(1, 1, 1, 499, 0, 0));

        time = Time(1, 1, 1, 1, 499, 499);
        time.round(Time::Component::MICROSECOND);
        EXPECT_EQ(time, Time(1, 1, 1, 1, 499, 0));

        time = Time(1, 1, 1, 1, 1, 499);
        time.round(Time::Component::NANOSECOND);
        EXPECT_EQ(time, Time(1, 1, 1, 1, 1, 499));
}

TEST(Time, ceil_up)
{
        Time time = Time(11, 1, 0, 0, 0, 0);
        time.ceil(Time::Component::HOUR);
        EXPECT_EQ(time, Time(12, 0, 0, 0, 0, 0));

        time = Time(1, 29, 29, 1, 1, 1);
        time.ceil(Time::Component::MINUTE);
        EXPECT_EQ(time, Time(1, 30, 0, 0, 0, 0));

        time = Time(1, 1, 29, 1, 1, 1);
        time.ceil(Time::Component::SECOND);
        EXPECT_EQ(time, Time(1, 1, 30, 0, 0, 0));

        time = Time(1, 1, 1, 499, 1, 1);
        time.ceil(Time::Component::MILLISECOND);
        EXPECT_EQ(time, Time(1, 1, 1, 500, 0, 0));

        time = Time(1, 1, 1, 1, 499, 1);
        time.ceil(Time::Component::MICROSECOND);
        EXPECT_EQ(time, Time(1, 1, 1, 1, 500, 0));

        time = Time(1, 1, 1, 1, 1, 499);
        time.ceil(Time::Component::NANOSECOND);
        EXPECT_EQ(time, Time(1, 1, 1, 1, 1, 499));
}

TEST(Time, ceil_no_up)
{
        Time time = Time(1, 0, 0, 0, 0, 0);
        time.ceil(Time::Component::HOUR);
        EXPECT_EQ(time, Time(1, 0, 0, 0, 0, 0));

        time = Time(0, 1, 0, 0, 0, 0);
        time.ceil(Time::Component::MINUTE);
        EXPECT_EQ(time, Time(0, 1, 0, 0, 0, 0));

        time = Time(0, 0, 1, 0, 0, 0);
        time.ceil(Time::Component::SECOND);
        EXPECT_EQ(time, Time(0, 0, 1, 0, 0, 0));

        time = Time(0, 0, 0, 1, 0, 0);
        time.ceil(Time::Component::MILLISECOND);
        EXPECT_EQ(time, Time(0, 0, 0, 1, 0, 0));

        time = Time(0, 0, 0, 0, 1, 0);
        time.ceil(Time::Component::MICROSECOND);
        EXPECT_EQ(time, Time(0, 0, 0, 0, 1, 0));

        time = Time(1, 1, 1, 1, 1, 499);
        time.ceil(Time::Component::NANOSECOND);
        EXPECT_EQ(time, Time(1, 1, 1, 1, 1, 499));
}

TEST(Time, floor)
{
        Time time = Time(1, 59, 0, 0, 0, 0);
        time.floor(Time::Component::HOUR);
        EXPECT_EQ(time, Time(1, 0, 0, 0, 0, 0));

        time = Time(0, 1, 59, 0, 0, 0);
        time.floor(Time::Component::MINUTE);
        EXPECT_EQ(time, Time(0, 1, 0, 0, 0, 0));

        time = Time(0, 0, 1, 999, 0, 0);
        time.floor(Time::Component::SECOND);
        EXPECT_EQ(time, Time(0, 0, 1, 0, 0, 0));

        time = Time(0, 0, 0, 1, 999, 0);
        time.floor(Time::Component::MILLISECOND);
        EXPECT_EQ(time, Time(0, 0, 0, 1, 0, 0));

        time = Time(0, 0, 0, 0, 1, 999);
        time.floor(Time::Component::MICROSECOND);
        EXPECT_EQ(time, Time(0, 0, 0, 0, 1, 0));

        time = Time(1, 1, 1, 1, 1, 499);
        time.floor(Time::Component::NANOSECOND);
        EXPECT_EQ(time, Time(1, 1, 1, 1, 1, 499));
}