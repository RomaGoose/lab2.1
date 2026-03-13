
set(TEST_LIB_DIR "${PROJECT_SOURCE_DIR}/../test_lib/lib")
find_library(TEST_LIB
    NAMES test_lib  
    PATHS ${TEST_LIB_DIR}
    REQUIRED
    NO_DEFAULT_PATH
)
find_path(TEST_INCLUDE_DIR
    NAMES "_assert.g" "testing.h"
    PATHS "${PROJECT_SOURCE_DIR}/../test_lib/include"
    REQUIRED
)

add_executable(test_runner
    # unit/test_vector
    unit/test_result.c
    test_runner.c
)

target_link_libraries(test_runner PRIVATE
    numbers
    linear_form
    result
    ${TEST_LIB}
    )

target_include_directories(test_runner PRIVATE
    ${TEST_INCLUDE_DIR}
)


set(MOCK_ABORT_FLAGS
    "LINKER:--wrap,abort"
)

target_link_options(test_runner PRIVATE
    ${MOCK_ABORT_FLAGS}    
)

add_test(NAME test_runner COMMAND test_runner)