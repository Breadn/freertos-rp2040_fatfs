# CMake for FatFS lib

SET(libname fatfs_lib)

# Create lib
add_library(${libname}
    sdmm.h
    sdmm.c
    diskio.h
    ff.c
    ff.h
    ffconf.h
    ffsystem.c
    ffunicode.c
)

# Link external lib
target_link_libraries(${libname}
    pico_stdlib
    hardware_spi
    hardware_clocks
)