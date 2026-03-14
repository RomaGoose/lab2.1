add_library(numbers STATIC
    numbers/float.c
    numbers/integer.c    
)

target_include_directories(numbers PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(numbers PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/numbers
)


add_library(linear_form STATIC
    linear_form/linear_form.c    
    linear_form/vector.c    
    linear_form/scalar.c
)

target_include_directories(linear_form PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(linear_form PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/linear_form
)

add_library(result STATIC
    result/result.c    
)

target_include_directories(result PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(result PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/result
)

