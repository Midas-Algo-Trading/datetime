#include "gtest/gtest.h"
#include <datetime/datetime.h>

TEST(TimeDelta, operator_minus_date_date_no_difference)
{
    TimeDelta time_delta = Date(2000, 1, 1) - Date(2000, 1, 1);
    EXPECT_EQ(time_delta, TimeDelta(0));
}

TEST(TimeDelta, operator_minus_date_date_day_difference_pos)
{
    TimeDelta time_delta = Date(2000, 1, 3) - Date(2000, 1, 1);
    EXPECT_EQ(time_delta, TimeDelta(2));
}

TEST(TimeDelta, operator_minus_date_date_day_difference_neg)
{
    TimeDelta time_delta = Date(2000, 1, 1) - Date(2000, 1, 3);
    EXPECT_EQ(time_delta, TimeDelta(-2));
}

TEST(TimeDelta, operator_minus_date_date_month_difference_pos)
{
    TimeDelta time_delta = Date(2000, 3, 1) - Date(2000, 1, 1);
    EXPECT_EQ(time_delta, TimeDelta(60));
}

TEST(TimeDelta, operator_minus_date_date_month_difference_neg)
{
    TimeDelta time_delta = Date(2000, 1, 1) - Date(2000, 3, 1);
    EXPECT_EQ(time_delta, TimeDelta(-60));
}

TEST(TimeDelta, operator_minus_date_date_leap_year_difference_pos)
{
    TimeDelta time_delta = Date(2001, 1, 1) - Date(2000, 1, 1);
    EXPECT_EQ(time_delta, TimeDelta(366));
}

TEST(TimeDelta, operator_minus_date_date_leap_year_difference_neg)
{
    TimeDelta time_delta = Date(2000, 1, 1) - Date(2001, 1, 1);
    EXPECT_EQ(time_delta, TimeDelta(-366));
}

TEST(TimeDelta, operator_minus_date_date_non_leap_year_difference_pos)
{
    TimeDelta time_delta = Date(2002, 1, 1) - Date(2001, 1, 1);
    EXPECT_EQ(time_delta, TimeDelta(365));
}

TEST(TimeDelta, operator_minus_date_date_non_leap_year_difference_neg)
{
    TimeDelta time_delta = Date(2001, 1, 1) - Date(2002, 1, 1);
    EXPECT_EQ(time_delta, TimeDelta(-365));
}

TEST(TimeDelta, operator_plus_time_time_no_difference)
{
    TimeDelta time_delta = Time(1, 2, 3, 4, 5, 6) + Time();
    EXPECT_EQ(time_delta, TimeDelta(0, 1, 2, 3, 4, 5, 6));
}

TEST(TimeDelta, operator_plus_time_time_difference_pos)
{
    TimeDelta time_delta = Time(1, 2, 3, 4, 5, 6) + Time(1, 2, 3, 4, 5, 6);
    EXPECT_EQ(time_delta, TimeDelta(0, 2, 4, 6, 8, 10, 12));
}

TEST(TimeDelta, operator_plus_time_time_pos_day_wrap)
{
    TimeDelta time_delta = Time(23) + Time(1);
    EXPECT_EQ(time_delta, TimeDelta(1));
}

TEST(TimeDelta, operator_minus_time_time_no_difference)
{
    TimeDelta time_delta = Time(1, 2, 3, 4, 5, 6) - Time();
    EXPECT_EQ(time_delta, TimeDelta(0, 1, 2, 3, 4, 5, 6));
}

TEST(TimeDelta, operator_minus_time_time_difference_pos)
{
    TimeDelta time_delta = Time(1, 2, 3, 4, 5, 6) - Time(1, 2, 3, 4, 5, 6);
    EXPECT_EQ(time_delta, TimeDelta(0));
}

TEST(TimeDelta, operator_minus_time_time_pos_day_wrap)
{
    TimeDelta time_delta = Time(1) - Time(23);
    EXPECT_EQ(time_delta, TimeDelta(-1, 2));
}

TEST(TimeDelta, timedelta_days_hour_minute_second_millisecond_microsecond_nanosecond)
{
    TimeDelta time_delta = TimeDelta(1, 2, 3, 4, 5, 6, 7);
    EXPECT_EQ(time_delta.days, 1);
    EXPECT_EQ(time_delta.hour, 2);
    EXPECT_EQ(time_delta.minute, 3);
    EXPECT_EQ(time_delta.second, 4);
    EXPECT_EQ(time_delta.millisecond, 5);
    EXPECT_EQ(time_delta.microsecond, 6);
    EXPECT_EQ(time_delta.nanosecond, 7);
}

TEST(TimeDelta, timedelta_days_time)
{
    TimeDelta time_delta = TimeDelta(1, 2, 3, 4, 5, 6, 7);
    EXPECT_EQ(time_delta.days, 1);
    EXPECT_EQ(time_delta.hour, 2);
    EXPECT_EQ(time_delta.minute, 3);
    EXPECT_EQ(time_delta.second, 4);
    EXPECT_EQ(time_delta.millisecond, 5);
    EXPECT_EQ(time_delta.microsecond, 6);
    EXPECT_EQ(time_delta.nanosecond, 7);
}

TEST(TimeDelta, operator_greater_than_timedelta)
{
    TimeDelta time_delta_greater = TimeDelta(1);
    TimeDelta time_delta_lesser = TimeDelta(0);
    EXPECT_GT(time_delta_greater, time_delta_lesser);

    time_delta_greater = TimeDelta(1, 1);
    time_delta_lesser = TimeDelta(1);
    EXPECT_GT(time_delta_greater, time_delta_lesser);

    time_delta_greater = TimeDelta(1, 1, 1);
    time_delta_lesser = TimeDelta(1, 1);
    EXPECT_GT(time_delta_greater, time_delta_lesser);

    time_delta_greater = TimeDelta(1, 1, 1, 1);
    time_delta_lesser = TimeDelta(1, 1, 1);
    EXPECT_GT(time_delta_greater, time_delta_lesser);

    time_delta_greater = TimeDelta(1, 1, 1, 1, 1);
    time_delta_lesser = TimeDelta(1, 1, 1, 1);
    EXPECT_GT(time_delta_greater, time_delta_lesser);

    time_delta_greater = TimeDelta(1, 1, 1, 1, 1, 1);
    time_delta_lesser = TimeDelta(1, 1, 1, 1, 1);
    EXPECT_GT(time_delta_greater, time_delta_lesser);

    time_delta_greater = TimeDelta(1, 1, 1, 1, 1, 1, 1);
    time_delta_lesser = TimeDelta(1, 1, 1, 1, 1, 1);
    EXPECT_GT(time_delta_greater, time_delta_lesser);
}

TEST(TimeDelta, operator_greater_than_or_equal_to_timedelta)
{
    TimeDelta time_delta_greater = TimeDelta(1);
    TimeDelta time_delta_lesser = TimeDelta(0);
    EXPECT_LE(time_delta_lesser, time_delta_greater);

    time_delta_greater = TimeDelta(1, 1);
    time_delta_lesser = TimeDelta(1);
    EXPECT_LE(time_delta_lesser, time_delta_greater);

    time_delta_greater = TimeDelta(1, 1, 1);
    time_delta_lesser = TimeDelta(1, 1);
    EXPECT_LE(time_delta_lesser, time_delta_greater);

    time_delta_greater = TimeDelta(1, 1, 1, 1);
    time_delta_lesser = TimeDelta(1, 1, 1);
    EXPECT_LE(time_delta_lesser, time_delta_greater);

    time_delta_greater = TimeDelta(1, 1, 1, 1, 1);
    time_delta_lesser = TimeDelta(1, 1, 1, 1);
    EXPECT_LE(time_delta_lesser, time_delta_greater);

    time_delta_greater = TimeDelta(1, 1, 1, 1, 1, 1);
    time_delta_lesser = TimeDelta(1, 1, 1, 1, 1);
    EXPECT_LE(time_delta_lesser, time_delta_greater);

    time_delta_greater = TimeDelta(1, 1, 1, 1, 1, 1, 1);
    time_delta_lesser = TimeDelta(1, 1, 1, 1, 1, 1);
    EXPECT_LE(time_delta_lesser, time_delta_greater);


    time_delta_greater = TimeDelta(1, 1, 1, 1, 1, 1, 1);
    time_delta_lesser = TimeDelta(1, 1, 1, 1, 1, 1, 1);
    EXPECT_LE(time_delta_lesser, time_delta_greater);
}

TEST(TimeDelta, operator_equal_to_timedelta)
{
    TimeDelta time_delta_1 = TimeDelta(1);
    TimeDelta time_delta_2 = TimeDelta(1);
    EXPECT_EQ(time_delta_1, time_delta_2);

    time_delta_1 = TimeDelta(1, 1);
    time_delta_2 = TimeDelta(1, 1);
    EXPECT_EQ(time_delta_1, time_delta_2);

    time_delta_1 = TimeDelta(1, 1, 1);
    time_delta_2 = TimeDelta(1, 1, 1);
    EXPECT_EQ(time_delta_1, time_delta_2);

    time_delta_1 = TimeDelta(1, 1, 1, 1);
    time_delta_2 = TimeDelta(1, 1, 1, 1);
    EXPECT_EQ(time_delta_1, time_delta_2);

    time_delta_1 = TimeDelta(1, 1, 1, 1, 1);
    time_delta_2 = TimeDelta(1, 1, 1, 1, 1);
    EXPECT_EQ(time_delta_1, time_delta_2);

    time_delta_1 = TimeDelta(1, 1, 1, 1, 1, 1);
    time_delta_2 = TimeDelta(1, 1, 1, 1, 1, 1);
    EXPECT_EQ(time_delta_1, time_delta_2);

    time_delta_1 = TimeDelta(1, 1, 1, 1, 1, 1, 1);
    time_delta_2 = TimeDelta(1, 1, 1, 1, 1, 1, 1);
    EXPECT_EQ(time_delta_1, time_delta_2);
}

TEST(TimeDelta, operator_not_equal_to_timedelta)
{
    TimeDelta time_delta_1 = TimeDelta(1);
    TimeDelta time_delta_2 = TimeDelta(2);
    EXPECT_NE(time_delta_1, time_delta_2);

    time_delta_1 = TimeDelta(1, 1);
    time_delta_2 = TimeDelta(1, 2);
    EXPECT_NE(time_delta_1, time_delta_2);

    time_delta_1 = TimeDelta(1, 1, 1);
    time_delta_2 = TimeDelta(1, 1, 2);
    EXPECT_NE(time_delta_1, time_delta_2);

    time_delta_1 = TimeDelta(1, 1, 1, 1);
    time_delta_2 = TimeDelta(1, 1, 1, 2);
    EXPECT_NE(time_delta_1, time_delta_2);

    time_delta_1 = TimeDelta(1, 1, 1, 1, 1);
    time_delta_2 = TimeDelta(1, 1, 1, 1, 2);
    EXPECT_NE(time_delta_1, time_delta_2);

    time_delta_1 = TimeDelta(1, 1, 1, 1, 1, 1);
    time_delta_2 = TimeDelta(1, 1, 1, 1, 1, 2);
    EXPECT_NE(time_delta_1, time_delta_2);

    time_delta_1 = TimeDelta(1, 1, 1, 1, 1, 1, 1);
    time_delta_2 = TimeDelta(1, 1, 1, 1, 1, 1, 2);
    EXPECT_NE(time_delta_1, time_delta_2);
}

TEST(TimeDelta, operator_less_than_timedelta)
{
    TimeDelta time_delta_greater = TimeDelta(1);
    TimeDelta time_delta_lesser = TimeDelta(0);
    EXPECT_LT(time_delta_lesser, time_delta_greater);

    time_delta_greater = TimeDelta(1, 1);
    time_delta_lesser = TimeDelta(1);
    EXPECT_LT(time_delta_lesser, time_delta_greater);

    time_delta_greater = TimeDelta(1, 1, 1);
    time_delta_lesser = TimeDelta(1, 1);
    EXPECT_LT(time_delta_lesser, time_delta_greater);

    time_delta_greater = TimeDelta(1, 1, 1, 1);
    time_delta_lesser = TimeDelta(1, 1, 1);
    EXPECT_LT(time_delta_lesser, time_delta_greater);

    time_delta_greater = TimeDelta(1, 1, 1, 1, 1);
    time_delta_lesser = TimeDelta(1, 1, 1, 1);
    EXPECT_LT(time_delta_lesser, time_delta_greater);

    time_delta_greater = TimeDelta(1, 1, 1, 1, 1, 1);
    time_delta_lesser = TimeDelta(1, 1, 1, 1, 1);
    EXPECT_LT(time_delta_lesser, time_delta_greater);

    time_delta_greater = TimeDelta(1, 1, 1, 1, 1, 1, 1);
    time_delta_lesser = TimeDelta(1, 1, 1, 1, 1, 1);
    EXPECT_LT(time_delta_lesser, time_delta_greater);
}

TEST(TimeDelta, operator_less_than_or_equal_to_timedelta)
{
    TimeDelta time_delta_greater = TimeDelta(1);
    TimeDelta time_delta_lesser = TimeDelta(0);
    EXPECT_LE(time_delta_lesser, time_delta_greater);

    time_delta_greater = TimeDelta(1, 1);
    time_delta_lesser = TimeDelta(1);
    EXPECT_LE(time_delta_lesser, time_delta_greater);

    time_delta_greater = TimeDelta(1, 1, 1);
    time_delta_lesser = TimeDelta(1, 1);
    EXPECT_LE(time_delta_lesser, time_delta_greater);

    time_delta_greater = TimeDelta(1, 1, 1, 1);
    time_delta_lesser = TimeDelta(1, 1, 1);
    EXPECT_LE(time_delta_lesser, time_delta_greater);

    time_delta_greater = TimeDelta(1, 1, 1, 1, 1);
    time_delta_lesser = TimeDelta(1, 1, 1, 1);
    EXPECT_LE(time_delta_lesser, time_delta_greater);

    time_delta_greater = TimeDelta(1, 1, 1, 1, 1, 1);
    time_delta_lesser = TimeDelta(1, 1, 1, 1, 1);
    EXPECT_LE(time_delta_lesser, time_delta_greater);

    time_delta_greater = TimeDelta(1, 1, 1, 1, 1, 1, 1);
    time_delta_lesser = TimeDelta(1, 1, 1, 1, 1, 1);
    EXPECT_LE(time_delta_lesser, time_delta_greater);


    time_delta_greater = TimeDelta(1, 1, 1, 1, 1, 1, 1);
    time_delta_lesser = TimeDelta(1, 1, 1, 1, 1, 1, 1);
    EXPECT_LE(time_delta_lesser, time_delta_greater);
}

TEST(TimeDelta, total_hours_pos)
{
    TimeDelta time_delta = TimeDelta(1, 2, 3, 4, 5, 6, 7);
    ASSERT_EQ(time_delta.total_hours(), 26);
}

TEST(TimeDelta, total_minutes_pos)
{
    TimeDelta time_delta = TimeDelta(1, 2, 3, 4, 5, 6, 7);
    ASSERT_EQ(time_delta.total_minutes(), 1563);
}

TEST(TimeDelta, total_seconds_pos)
{
    TimeDelta time_delta = TimeDelta(1, 2, 3, 4, 5, 6, 7);
    ASSERT_EQ(time_delta.total_seconds(), 93784);
}

TEST(TimeDelta, total_milliseconds_pos)
{
    TimeDelta time_delta = TimeDelta(1, 2, 3, 4, 5, 6, 7);
    ASSERT_EQ(time_delta.total_milliseconds(), 93784005);
}

TEST(TimeDelta, total_microseconds_pos)
{
    TimeDelta time_delta = TimeDelta(1, 2, 3, 4, 5, 6, 7);
    ASSERT_EQ(time_delta.total_microseconds(), 93784005006);
}


TEST(TimeDelta, total_nanoseconds_pos)
{
    TimeDelta time_delta = TimeDelta(1, 2, 3, 4, 5, 6, 7);
    ASSERT_EQ(time_delta.total_nanoseconds(), 93784005006007);
}

TEST(TimeDelta, total_hours_neg_day)
{
    TimeDelta time_delta = TimeDelta(-1, 2, 3, 4, 5, 6, 7);
    ASSERT_EQ(time_delta.total_hours(), -22);
}

TEST(TimeDelta, total_minutes_neg_day)
{
    TimeDelta time_delta = TimeDelta(-1, 2, 3, 4, 5, 6, 7);
    ASSERT_EQ(time_delta.total_minutes(), -1317);
}

TEST(TimeDelta, total_seconds_neg_day)
{
    TimeDelta time_delta = TimeDelta(-1, 2, 3, 4, 5, 6, 7);
    ASSERT_EQ(time_delta.total_seconds(), -79016);
}

TEST(TimeDelta, total_milliseconds_neg_day)
{
    TimeDelta time_delta = TimeDelta(-1, 2, 3, 4, 5, 6, 7);
    ASSERT_EQ(time_delta.total_milliseconds(), -79015995);
}

TEST(TimeDelta, total_microseconds_neg_day)
{
    TimeDelta time_delta = TimeDelta(-1, 2, 3, 4, 5, 6, 7);
    ASSERT_EQ(time_delta.total_microseconds(), -79015994994);
}


TEST(TimeDelta, total_nanoseconds_neg_day)
{
    TimeDelta time_delta = TimeDelta(-1, 2, 3, 4, 5, 6, 7);
    ASSERT_EQ(time_delta.total_nanoseconds(), -79015994993993);
}

TEST(TimeDelta, abs_pos)
{
    TimeDelta time_delta = TimeDelta(1);
    ASSERT_EQ(time_delta.abs().days, 1);
}

TEST(TimeDelta, abs_neg)
{
    TimeDelta time_delta = TimeDelta(-1);
    ASSERT_EQ(time_delta.abs().days, 1);
}