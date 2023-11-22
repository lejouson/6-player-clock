/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "clock/clock.h"

#include <cstdint>

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "buzzer/buzzer.h"
#include "buzzer/buzzer_mock.h"
#include "clock/clock_mock.h"
#include "display/display.h"
#include "display/display_mock.h"

TEST_GROUP(Clock) {
  Buzzer* buzzer_;
  Clock* clock_;
  Display* display_;

  void setup() {
    buzzer_ = new BuzzerMock();
    display_ = new DisplayMock();
    clock_ = new Clock(buzzer_, display_);
  }

  void teardown() {
    delete clock_;
    delete buzzer_;
    delete display_;
  }
};

TEST(Clock, Resume) {
  mock("buzzer").expectOneCall("Beep");
  mock("repeating_timer").expectOneCall("add_repeating_timer_ms")
    .withParameter("delay_ms", clock_clock::k1SecondDelayInMs);
  mock("display").ignoreOtherCalls();
  clock_->Resume(clock_mock::kRemainingSeconds);
}

/** Test that the clock resumes from the last seen time.
  */
TEST(Clock, ResumeShowsLastSeenTime) {
  mock("buzzer").expectOneCall("Beep");
  mock("display").expectOneCall("ShowAsMinutesAndSeconds")
    .withParameter("seconds", clock_mock::kRemainingSeconds);
  mock("repeating_timer").expectOneCall("add_repeating_timer_ms")
    .withParameter("delay_ms", clock_clock::k1SecondDelayInMs);
  mock("display").expectOneCall("ShowAsMinutesAndSeconds")
    .withParameter("seconds", clock_mock::kRemainingSeconds - 1);
  clock_->Resume(clock_mock::kRemainingSeconds);
}

/** Test that zero is displayed when there are no remaining seconds.
  */
TEST(Clock, ResumeShowsZeroWhenNoRemainingSeconds) {
  mock("buzzer").expectOneCall("Beep").withParameter("number_of_beeps", 2);
  mock("display").expectOneCall("ShowAsMinutesAndSeconds").withParameter("seconds", 0);
  mock("repeating_timer").ignoreOtherCalls();
  clock_->Resume(0);
}
