set(SRC_FILE
    main.cpp
    sudoku.cpp)
add_executable(sudoku ${SRC_FILE})

if(ENABLE_SANITIZER)
    message("Enable sanitizer for compiler and linker")
    enable_sanitizer(sudoku)
endif()

set_target_properties( sudoku
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)