# Copyright (c) Team CharLS.
# SPDX-License-Identifier: BSD-3-Clause

add_executable(charlstest "")

target_sources(charlstest
  PRIVATE
    bitstreamdamage.cpp
    bitstreamdamage.h
    compliance.cpp
    compliance.h
    dicomsamples.cpp
    dicomsamples.h
    main.cpp
    performance.cpp
    performance.h
    util.cpp
    util.h
)

set_target_properties(charlstest PROPERTIES CXX_VISIBILITY_PRESET hidden)

target_link_libraries(charlstest PRIVATE charls)
