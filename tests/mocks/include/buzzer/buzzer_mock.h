/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef BUZZER_BUZZER_MOCK_H_
#define BUZZER_BUZZER_MOCK_H_

#include "buzzer/buzzer.h"

class BuzzerMock : public Buzzer {
 public:  // editorconfig-checker-disable-line
  BuzzerMock();
  void Beep() final;
  void Beep(std::uint16_t number_of_beeps) final;
};

#endif  // BUZZER_BUZZER_MOCK_H_
