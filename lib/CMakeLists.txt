
add_library(MoveConstructorNoexcept SHARED MoveConstructorNoexcept.cpp)


# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs all-targets)

message(STATUS "llvm libs: ${llvm_libs}")

if (APPLE)
    target_link_libraries(
        MoveConstructorNoexcept
        "$<$<PLATFORM_ID:Darwin>:-undefined dynamic_lookup>"
    )
endif()