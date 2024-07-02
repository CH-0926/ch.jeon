cmake_minimum_required(VERSION 3.10)
project(freeram_project C)

set(CMAKE_C_STANDARD 99)

# CMocka 라이브러리 경로 설정
find_package(PkgConfig REQUIRED)
pkg_check_modules(CMOCKA REQUIRED cmocka)

# freeram 실행 파일 소스 파일 목록
set(FREERAM_SOURCE_FILES
    freeram.c
    proc_freeram.c
)

# freeram_test 실행 파일 소스 파일 목록
set(TEST_SOURCE_FILES
    freeram_test.c
    proc_freeram.c
)

# freeram 실행 파일 생성
add_executable(freeram ${FREERAM_SOURCE_FILES})

# freeram_test 실행 파일 생성
add_executable(freeram_test ${TEST_SOURCE_FILES})

# CMocka 라이브러리 링크 (freeram_test에만 필요)
target_link_libraries(freeram_test ${CMOCKA_LIBRARIES})

# include 디렉토리 설정 (freeram_test에만 필요)
target_include_directories(freeram_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMOCKA_INCLUDE_DIRS})

# 테스트 실행 설정
add_test(NAME freeram_test COMMAND freeram_test)
