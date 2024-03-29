/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef BUTTON_BUTTON_EVENT_HANDLER_MOCK_H_
#define BUTTON_BUTTON_EVENT_HANDLER_MOCK_H_

#include "button/button_event_handler.h"

#include <cstdint>

class ButtonEventHandlerMock: public ButtonEventHandler {
  void HandlePressed(std::uint16_t gpio) final;
};

#endif  // BUTTON_BUTTON_EVENT_HANDLER_MOCK_H_
