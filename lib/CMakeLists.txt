
add_library(MoveConstructorNoexcept SHARED MoveConstructorNoexcept.cpp)

target_link_libraries(
    MoveConstructorNoexcept
    "$<$<PLATFORM_ID:Darwin>:-undefined dynamic_lookup>"
)
