cmake_minimum_required(VERSION 3.6)
project(TestBench)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11")

# SDL2
# =======
if(WIN32)

    #
    # MSYS MINGW
    #

    INCLUDE(FindPkgConfig)

    pkg_check_modules(SDL2 REQUIRED sdl2)
    pkg_check_modules(SDL2_IMG REQUIRED SDL2_image)
    pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)
    pkg_check_modules(SDL2_MIX REQUIRED SDL2_mixer)


    link_directories (${SDL2_LIBRARY_DIRS}
            ${SDL2_IMG_LIBRARY_DIRS}
            ${SDL2_TTF_LIBRARY_DIRS}
            ${SDL2_MIX_LIBRARY_DIRS})
			
endif(WIN32)
if(UNIX)
    INCLUDE(FindPkgConfig)

    PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
    PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image >= 2.0.0)
    PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf >= 2.0.0)
    PKG_SEARCH_MODULE(SD2MIXER REQUIRED SDL2_mixer >= 2.0.0)

    set(SDL2_LIB -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lGL)

    set(SDL2_INCLUDE ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS})
endif(UNIX)

# =======

# PROJECT-FILES
# =============
set(SOURCE_FILES main.cpp Draw.cpp Draw.h)

# -PROJECT-RESOURCES
# Copies files (preserving file tree) from /res folder to debug /res folder.

file(GLOB_RECURSE RES_FILES ${PROJECT_SOURCE_DIR}/res/*)
file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/res)
foreach(F ${RES_FILES})
    get_filename_component(q ${F} DIRECTORY)
    file(RELATIVE_PATH g ${PROJECT_SOURCE_DIR}/res ${q}  )
    if(g)
        file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/res/${g})
    endif(g)
    file(COPY ${F} DESTINATION ${PROJECT_BINARY_DIR}/res/${g})
endforeach()
# =============

# Finalising
if(WIN32)
    set(FINAL_INCLUDE ${SDL2_INCLUDE_DIRS}
            ${SDL2_IMG_INCLUDE_DIRS}
            ${SDL2_TTF_INCLUDE_DIRS}
            ${SDL2_MIX_INCLUDE_DIRS} ${ENGINE_INCLUDE_DIR})

    set(FINAL_LINKER
            -lmingw32
            ${SDL2_LIBRARIES}
            ${SDL2_IMG_LIBRARIES}
            ${SDL2_TTF_LIBRARIES}
            ${SDL2_MIX_LIBRARIES}
            -lopengl32
            -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lversion -luuid -lfreetype
    )

    link_directories (${SDL2_LIBRARY_DIRS}
            ${SDL2_IMG_LIBRARY_DIRS}
            ${SDL2_TTF_LIBRARY_DIRS}
            ${SDL2_MIX_LIBRARY_DIRS})
endif(WIN32)
if(UNIX)
    SET(FINAL_INCLUDE ${SDL2_INCLUDE} )
    SET(FINAL_LINKER ${SDL2_LIB})
endif(UNIX)
# =============


include_directories(${FINAL_INCLUDE})

add_executable(TestBench_CMAKE ${SOURCE_FILES})
target_link_libraries(TestBench_CMAKE ${FINAL_LINKER})