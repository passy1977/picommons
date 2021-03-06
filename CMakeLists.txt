cmake_minimum_required(VERSION 3.13)

cmake_policy(SET CMP0048 NEW)
PROJECT(picommons VERSION "0.1.0" LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS ON)
set(RASPBIAN_ROOTFS $ENV{RASPBIAN_ROOTFS})

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

if(CROSS_COMPILE)
  if(${RASPBIAN_ROOTFS})
    message( FATAL " Env RASPBIAN_ROOTFS not set" )
  endif()

  include_directories("${RASPBIAN_ROOTFS}/usr/local/include")
  link_directories("${RASPBIAN_ROOTFS}/usr/local/lib")
endif(CROSS_COMPILE)

include_directories(include)

add_library(picommons
        include/picommons/display.h
        include/picommons/lcd1602.h
        include/picommons/constants.h
        include/picommons/pinhelper.h
        include/picommons/convenience.h
        src/lcd1602.cpp
        src/display.cpp
        src/constants.cpp
        src/pinhelper.cpp
        src/convenience.cpp
)

add_executable(picommonsTest
        test/displaytest.cpp
        test/pinhelpertest.cpp
        test/conveniencetest.cpp
)


target_link_libraries(picommonsTest
                        picommons
                        wiringPi
                        wiringPiDev
                        pthread
                        gtest
                        gtest_main
                        )