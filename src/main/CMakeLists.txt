add_executable(out main_scores.cpp)


# Link the executable with the libraries
# PRIVATE: no other libraries will be linked to out.
target_link_libraries(out 
    PRIVATE 
        GameEntryLib
        ScoresLib
)

# Set the output directory for the executable
# CMAKE_BINARY_DIR refers to the directory where make is run, not where the top-level CMakeLists.txt is located.
set_target_properties(out PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)