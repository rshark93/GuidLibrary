set(TEST_TARGET_NAME ${PROJECT_NAME}Main)

add_executable(${TEST_TARGET_NAME} "main.cpp")

target_link_libraries(${TEST_TARGET_NAME} PRIVATE Guid)
target_include_directories(${TEST_TARGET_NAME} PRIVATE "../guid")

if(${BP_BUILD_TESTS_COVERAGE})
    set(CMAKE_STATIC_LINKER_FLAGS "--whole-archive")
    set(CMAKE_SHARED_LINKER_FLAGS "--whole-archive")

    include("../cmake/CodeCoverage.cmake")
    APPEND_COVERAGE_COMPILER_FLAGS("-g -O0 -fprofile-arcs -ftest-coverage")
    set(COVERAGE_LCOV_EXCLUDES '/usr/*' '*/test/*' 'test/*')
    SETUP_TARGET_FOR_COVERAGE_LCOV(
            NAME coverage                    # New target name
            EXECUTABLE ${TEST_TARGET_NAME}
            DEPENDENCIES ${TEST_TARGET_NAME}  # Dependencies to build first
    )
endif()

enable_testing()