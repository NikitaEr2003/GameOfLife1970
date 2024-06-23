add_executable(GameOfLife1970
    main.cpp
    Const.h
    Cour.h
    Cour.cpp
)
set_target_properties(GameOfLife1970 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/src)