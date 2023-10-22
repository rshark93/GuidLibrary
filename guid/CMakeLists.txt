file(GLOB Guid_SRC
        "*.h"
        "*.cpp")

add_library(Guid SHARED ${Guid_SRC})

if(${BUILD_TESTS_COVERAGE})
    target_compile_options(Guid PUBLIC -fprofile-arcs -ftest-coverage)
    target_link_libraries(Guid PUBLIC gcov)
endif()
