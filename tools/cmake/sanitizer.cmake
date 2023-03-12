function(
    enable_sanitizer  # function' name
    project_name      # function's arugment
)

    set(SANITIZERS "")

    option(
        SANITIZER_ADDRESS            # variable name
        "Enable address sanitizer"   # help text
        FALSE)                       # default value

    if (SANITIZER_ADDRESS)
        list(
            APPEND
            SANITIZERS
            "address"
        )
    endif()

    option(
        SANITIZER_MEMORY
        "Enable memory leak sanitizer"
        FALSE)

    if (SANITIZER_MEMORY)
        list(
            APPEND
            SANITIZERS
            "leak"
        )
    endif()

    option(
        SANITIZER_UNDIFINED_BEHAVIOUR
        "Enable undefined behaviour sanitizer"
        FALSE)

    if (SANITIZER_UNDIFINED_BEHAVIOUR)
        list(
            APPEND
            SANITIZERS
            "undefined"
        )
    endif()

    list(
        JOIN
        SANITIZERS
        ","
        LIST_OF_SANITIZERS
    )

    if (LIST_OF_SANITIZERS)
        if (NOT
            "${LIST_OF_SANITIZERS}"
            STREQUAL
            ""
        )
            target_compile_options(${project_name} PRIVATE -fsanitize=${LIST_OF_SANITIZERS})
            target_link_libraries(${project_name} PRIVATE -fsanitize=${LIST_OF_SANITIZERS})
        endif()
    endif()

endfunction()


    