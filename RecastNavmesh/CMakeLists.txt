file(GLOB_RECURSE SOURCES private/*.cpp)
add_library(RecastNavmesh ${SOURCES})

add_library(RecastNavigation::RecastNavmesh ALIAS RecastNavmesh)
set_target_properties(RecastNavmesh PROPERTIES DEBUG_POSTFIX -d)

set(RecastNavmesh_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/public")

if(RECASTNAVIGATION_DT_POLYREF64)
    target_compile_definitions(RecastNavmesh PUBLIC DT_POLYREF64)
endif()

if(RECASTNAVIGATION_DT_VIRTUAL_QUERYFILTER)
    target_compile_definitions(RecastNavmesh PUBLIC DT_VIRTUAL_QUERYFILTER)
endif()

if(NOT RECASTNAVIGATION_ENABLE_ASSERTS)
    target_compile_definitions(RecastNavmesh PUBLIC RC_DISABLE_ASSERTS)
endif()

if(RECASTNAVIGATION_RECAST_UNREAL_ENGINE)
    target_compile_definitions(RecastNavmesh PUBLIC RECAST_UNREAL_ENGINE=1)
else()
	target_compile_definitions(RecastNavmesh PUBLIC RECAST_UNREAL_ENGINE=0)
endif()

if(RECASTNAVIGATION_RECAST_DEMO)
    target_compile_definitions(RecastNavmesh PUBLIC RECAST_DEMO=1)
else()
	target_compile_definitions(RecastNavmesh PUBLIC RECAST_DEMO=0)
endif()

if(RECASTNAVIGATION_RECAST_TODO)
    target_compile_definitions(RecastNavmesh PUBLIC RECAST_TODO=1)
else()
	target_compile_definitions(RecastNavmesh PUBLIC RECAST_TODO=0)
endif()

target_include_directories(RecastNavmesh PUBLIC
    "$<BUILD_INTERFACE:${RecastNavmesh_INCLUDE_DIR}>"
)

set_target_properties(RecastNavmesh PROPERTIES
        SOVERSION ${SOVERSION}
        VERSION ${LIB_VERSION}
        COMPILE_PDB_OUTPUT_DIRECTORY .
        COMPILE_PDB_NAME "RecastNavmesh-d"
        )

install(TARGETS RecastNavmesh
        EXPORT recastnavigation-targets
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT library
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} ${CMAKE_INSTALL_INCLUDEDIR}/recastnavigation
        )

file(GLOB INCLUDES Include/*.h)
install(FILES ${INCLUDES} DESTINATION
    ${CMAKE_INSTALL_INCLUDEDIR}/recastnavigation)
if(MSVC)
    install(FILES "$<TARGET_FILE_DIR:RecastNavmesh>/RecastNavmesh-d.pdb" CONFIGURATIONS "Debug" DESTINATION "lib" OPTIONAL)
endif()
