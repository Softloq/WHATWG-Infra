set(SCRIPT_DIR "${CMAKE_CURRENT_LIST_DIR}")

if (WIN32)
    set(LIB_EXTENSION ".dll")
elseif(APPLE)
    set(LIB_EXTENSION ".dylib")
else()
    set(LIB_EXTENSION ".so")
endif()

function(copy_softloq_whatwg_infra_shared_lib TARGET_NAME)
    if (SOFTLOQ_WHATWG_INFRA_BUILD_SHARED_LIBS AND NOT SOFTLOQ_WHATWG_INFRA_HEADER_ONLY)
        add_custom_command(
            TARGET ${TARGET_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE_DIR:Softloq-WHATWG-Infra>/Softloq-WHATWG-Infra${LIB_EXTENSION}" "$<TARGET_FILE_DIR:${TARGET_NAME}>/Softloq-WHATWG-Infra${LIB_EXTENSION}"
        )
    else ()
        add_custom_command(
            TARGET ${TARGET_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -DTARGET_FILE_DIR="$<TARGET_FILE_DIR:${TARGET_NAME}>" -P "${SCRIPT_DIR}/script.cmake"
        )
    endif()
endfunction()