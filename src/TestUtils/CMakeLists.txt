# Copyright (c) 2021 The Orbit Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

cmake_minimum_required(VERSION 3.15)

add_library(TestUtils INTERFACE)
target_sources(TestUtils INTERFACE
  include/TestUtils/TestUtils.h
  include/TestUtils/ContainerHelpers.h)
target_include_directories(TestUtils INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(TestUtils INTERFACE
  absl::flat_hash_map
  absl::flat_hash_set
  absl::strings
  absl::str_format
  GTest::gtest)

add_executable(TestUtilsTests
  TestUtilsTest.cpp
  ContainerHelpersTest.cpp)
target_link_libraries(TestUtilsTests PRIVATE TestUtils GTest::Main)
register_test(TestUtilsTests)