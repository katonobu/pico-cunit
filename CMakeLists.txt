add_library(pico_cunit_basic INTERFACE)
target_sources(pico_cunit_basic INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/pico-BasicTest.c
        ${CMAKE_CURRENT_LIST_DIR}/CUnit-2.1-3/CUnit/Sources/Basic/Basic.c
        ${CMAKE_CURRENT_LIST_DIR}/CUnit-2.1-3/CUnit/Sources/Framework/CUError.c
        ${CMAKE_CURRENT_LIST_DIR}/CUnit-2.1-3/CUnit/Sources/Framework/TestDB.c
        ${CMAKE_CURRENT_LIST_DIR}/CUnit-2.1-3/CUnit/Sources/Framework/MyMem.c
        ${CMAKE_CURRENT_LIST_DIR}/CUnit-2.1-3/CUnit/Sources/Framework/Util.c
        ${CMAKE_CURRENT_LIST_DIR}/CUnit-2.1-3/CUnit/Sources/Framework/TestRun.c
        )
target_include_directories(pico_cunit_basic INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/CUnit-2.1-3/CUnit/Headers
        )
if (PICO_NO_HARDWARE)
        target_link_libraries(pico_cunit_basic INTERFACE pico_stdlib pico_stdio)
else ()
        target_link_libraries(pico_cunit_basic INTERFACE pico_stdlib pico_stdio pico_bootrom)
endif ()

##################################

add_library(pico_cunit_console INTERFACE)
target_sources(pico_cunit_console INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/pico-ConsoleTest.c
        ${CMAKE_CURRENT_LIST_DIR}/CUnit-2.1-3/CUnit/Sources/Console/Console.c
        ${CMAKE_CURRENT_LIST_DIR}/CUnit-2.1-3/CUnit/Sources/Framework/CUError.c
        ${CMAKE_CURRENT_LIST_DIR}/CUnit-2.1-3/CUnit/Sources/Framework/TestDB.c
        ${CMAKE_CURRENT_LIST_DIR}/CUnit-2.1-3/CUnit/Sources/Framework/MyMem.c
        ${CMAKE_CURRENT_LIST_DIR}/CUnit-2.1-3/CUnit/Sources/Framework/Util.c
        ${CMAKE_CURRENT_LIST_DIR}/CUnit-2.1-3/CUnit/Sources/Framework/TestRun.c
        )
target_include_directories(pico_cunit_console INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/CUnit-2.1-3/CUnit/Headers
        )
if (PICO_NO_HARDWARE)
        target_link_libraries(pico_cunit_console INTERFACE pico_stdlib pico_stdio)
else ()
        target_link_libraries(pico_cunit_console INTERFACE pico_stdlib pico_stdio pico_bootrom)
endif ()

####################################################################

add_executable(pico_cunit_example_basic
        ${CMAKE_CURRENT_LIST_DIR}/CUnit-2.1-3/Examples/ExampleTests.c
        )
target_include_directories(pico_cunit_example_basic PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/CUnit-2.1-3/Examples
        )

target_link_libraries(pico_cunit_example_basic pico_cunit_basic)
pico_add_extra_outputs(pico_cunit_example_basic)
example_auto_set_url(pico_cunit_example_basic)

##################################
add_executable(pico_cunit_example_console
        ${CMAKE_CURRENT_LIST_DIR}/CUnit-2.1-3/Examples/ExampleTests.c
        )
target_include_directories(pico_cunit_example_console PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/CUnit-2.1-3/Examples
        )

target_link_libraries(pico_cunit_example_console pico_cunit_console)
pico_add_extra_outputs(pico_cunit_example_console)
example_auto_set_url(pico_cunit_example_console)

