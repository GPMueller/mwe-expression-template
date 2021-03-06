######### CMake Version #####################
cmake_minimum_required(VERSION 3.9)
#############################################


######### Info ##############################
MESSAGE( STATUS ">> CMAKE_C_COMPILER:        " ${CMAKE_C_COMPILER} )
MESSAGE( STATUS ">> CMAKE_CXX_COMPILER:      " ${CMAKE_CXX_COMPILER} )
#############################################


######### Project Name ######################
project(FieldMath)
SET( EXECUTABLE_NAME run )
#############################################


### Find includes in corresponding build directories
set( CMAKE_INCLUDE_CURRENT_DIR ON )
######### Have the binary placed into the source head
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR} )
### Output paths for multi-config builds (e.g. msvc)
foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
    string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
    set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_SOURCE_DIR} )
    # set( CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${youroutputdirectory} )
    # set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${youroutputdirectory} )
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )
#############################################
set( CMAKE_DISABLE_SOURCE_CHANGES  ON )
set( CMAKE_DISABLE_IN_SOURCE_BUILD ON )
#############################################


#############################################
set(HEADER_FILES
    include/FieldMath.hpp
    include/detail/Typedefs.hpp
    include/detail/Field.hpp
    include/detail/FieldExpression.hpp
)

set(SOURCE_FILES
)
#############################################



#############################################
add_executable( ${EXECUTABLE_NAME} main.cpp ${SOURCE_FILES} )

target_link_libraries( ${EXECUTABLE_NAME} ${CUDA_LIBRARIES})

target_include_directories( ${EXECUTABLE_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories( ${EXECUTABLE_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/thirdparty)

set_property(TARGET ${EXECUTABLE_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${EXECUTABLE_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${EXECUTABLE_NAME} PROPERTY CXX_EXTENSIONS OFF)
#############################################