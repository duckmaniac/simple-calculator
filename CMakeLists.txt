cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Calculator")

# Add header files.
include_directories(include)

# Add source files.
file(GLOB SOURCES "src/*.cpp")

add_executable (Calculator WIN32 ${SOURCES} app.rc)

set(CPP_LIBRARIES_DIR "C:/Program Files/Cpp Libraries")

# Connect SFML library.
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "${CPP_LIBRARIES_DIR}/SFML-2.6.0/lib/cmake/SFML")
find_package(SFML 2.6.0 REQUIRED graphics network audio window system)

# Connect Boost library.
set(Boost_USE_STATIC_LIBS   ON)
set(BOOST_ROOT "${CPP_LIBRARIES_DIR}/Boost/boost_1_83_0")
FIND_PACKAGE( Boost 1.83 COMPONENTS program_options REQUIRED )
include_directories( ${Boost_INCLUDE_DIR} )

# Link libraries.
target_link_libraries(Calculator sfml-graphics ${Boost_LIBRARIES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Calculator PROPERTY CXX_STANDARD 20)
endif()