# Install script for directory: /home/drgrid/lightning/hardwared/yajl/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libyajl.so.2.1.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libyajl.so.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libyajl.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/drgrid/lightning/hardwared/yajl/yajl-2.1.1/lib/libyajl.so.2.1.1"
    "/home/drgrid/lightning/hardwared/yajl/yajl-2.1.1/lib/libyajl.so.2"
    "/home/drgrid/lightning/hardwared/yajl/yajl-2.1.1/lib/libyajl.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libyajl.so.2.1.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libyajl.so.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libyajl.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/drgrid/lightning/hardwared/yajl/yajl-2.1.1/lib/libyajl_s.a")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/yajl" TYPE FILE FILES
    "/home/drgrid/lightning/hardwared/yajl/src/api/yajl_parse.h"
    "/home/drgrid/lightning/hardwared/yajl/src/api/yajl_gen.h"
    "/home/drgrid/lightning/hardwared/yajl/src/api/yajl_common.h"
    "/home/drgrid/lightning/hardwared/yajl/src/api/yajl_tree.h"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/yajl" TYPE FILE FILES "/home/drgrid/lightning/hardwared/yajl/src/../yajl-2.1.1/include/yajl/yajl_version.h")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pkgconfig" TYPE FILE FILES "/home/drgrid/lightning/hardwared/yajl/src/../yajl-2.1.1/share/pkgconfig/yajl.pc")
endif()

