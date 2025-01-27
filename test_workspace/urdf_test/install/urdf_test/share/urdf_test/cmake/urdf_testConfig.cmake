# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_urdf_test_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED urdf_test_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(urdf_test_FOUND FALSE)
  elseif(NOT urdf_test_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(urdf_test_FOUND FALSE)
  endif()
  return()
endif()
set(_urdf_test_CONFIG_INCLUDED TRUE)

# output package information
if(NOT urdf_test_FIND_QUIETLY)
  message(STATUS "Found urdf_test: 0.0.0 (${urdf_test_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'urdf_test' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT urdf_test_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(urdf_test_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${urdf_test_DIR}/${_extra}")
endforeach()
