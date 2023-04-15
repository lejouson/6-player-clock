/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "CppUTest/TestHarness.h"
#include "./button_event.h"
#include "./button_handler.h"
#include "./button_handler_mock.h"

TEST_GROUP(ButtonHandler) {
  ButtonHandler* button;

  void setup() {
    button = new ButtonHandlerMock();
  }

  void teardown() {
    delete button;
  }
};

TEST(ButtonHandler, General) {
  mock().expectOneCall("HandlePressed");
  ButtonEvent event = 1;
  button->HandlePressed(event);
}