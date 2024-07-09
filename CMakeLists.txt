cmake_minimum_required(VERSION 3.10)
project(freeram_project C)

set(CMAKE_C_STANDARD 99)

# CMocka 라이브러리 경로 설정
find_package(PkgConfig REQUIRED)
pkg_check_modules(CMOCKA REQUIRED cmocka)

# freeram 라이브러리 생성
add_library(proc_freeram proc_freeram.c)

# freeram 실행 파일 생성
add_executable(freeram freeram.c)
target_link_libraries(freeram proc_freeram)

# 테스트 실행 파일 생성
add_executable(freeram_test freeram_test.c)
target_compile_options(freeram_test PRIVATE ${DEFAULT_C_COMPILE_FLAGS})
target_link_libraries(freeram_test proc_freeram ${CMOCKA_LIBRARIES})
target_include_directories(freeram_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMOCKA_INCLUDE_DIRS})

# 링커 플래그 설정
set_target_properties(freeram_test PROPERTIES LINK_FLAGS "-Wl,--wrap=get_free_ram")

# 테스트 실행 설정
add_test(NAME freeram_test COMMAND freeram_test)
