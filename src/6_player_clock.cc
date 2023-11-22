/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"

#include "button/button.h"
#include "button/button_controller.h"
#include "buzzer/buzzer.h"
#include "clock/clock.h"
#include "display/display.h"
#include "led/led.h"
#include "player/context_switcher.h"

int main() {
  stdio_init_all();
  led::SetupLeds();
  ButtonController button_controller;
  button::SetupButtons(button_controller);
  Led led;
  Buzzer buzzer{buzzer::kBuzzerPin};
  Display display;
  Clock clock{&buzzer, &display};
  ContextSwitcher context_switcher{&led, &clock, 30};
  button_controller.button_event_handler(&context_switcher);

  while (true) {
    tight_loop_contents();
  }
}
