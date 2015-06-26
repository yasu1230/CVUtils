# Enable GTest
enable_testing()

if(NOT "$ENV{GTEST_ROOT}" STREQUAL "")
  set(GTEST_LIB)
  if(WIN32)
    set(GTEST_LIB "gtest.lib")
    set(GTEST_MAIN_LIB "gtest_main.lib")
  else()
    set(GTEST_LIB "libgtest.a")
    set(GTEST_MAIN_LIB "libgtest_main.a")
  endif()
  set(GTEST_LIBRARY $ENV{GTEST_ROOT}/lib/${GTEST_LIB})
  set(GTEST_MAIN_LIBRARY $ENV{GTEST_ROOT}/lib/${GTEST_MAIN_LIB})
  set(GTEST_INCLUDE_DIRS $ENV{GTEST_ROOT}/include)
else()
  set(GTEST_LIBRARY $ENV{GTEST_LIBRARY})
  set(GTEST_MAIN_LIBRARY $ENV{GTEST_MAIN_LIBRARY})
  set(GTEST_INCLUDE_DIRS $ENV{GTEST_INCLUDE_DIRS})
endif()


# Define function to add test
function(add_gtest_with_opencv test_name test_source)
  set(SOURCE_FILES ${test_source})

  add_executable(${test_name} ${SOURCE_FILES})
  target_link_libraries(${test_name} ${GTEST_LIBRARY})
  target_link_libraries(${test_name} ${GTEST_MAIN_LIBRARY})
  target_link_libraries(${test_name} ${OpenCV_LIBS})

  add_test(NAME ${test_name} COMMAND ${test_name})
endfunction(add_gtest_with_opencv)

add_gtest_with_opencv(test_utils test_runner.cpp)

# Add tests to "make check"
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} DEPENDS test_utils)

# Include directories
include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${OpenCV_INCLUDE_DIRS})
