/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "buzzer/buzzer_mock.h"

#include "CppUTestExt/MockSupport.h"

BuzzerMock::BuzzerMock() : Buzzer(buzzer::kBuzzerPin) {}

void BuzzerMock::Beep() {
  mock("buzzer").actualCall("Beep");
}

void BuzzerMock::Beep(std::uint16_t number_of_beeps) {
  mock("buzzer").actualCall("Beep").withParameter("number_of_beeps", number_of_beeps);
}
