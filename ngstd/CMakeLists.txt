include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR})

add_library( ngstd ${NGS_LIB_TYPE}
        blockalloc.cpp evalfunc.cpp templates.cpp
        stringops.cpp statushandler.cpp
        python_ngstd.cpp
        bspline.cpp
        )

target_compile_definitions(ngstd PUBLIC ${NGSOLVE_COMPILE_DEFINITIONS})
target_compile_definitions(ngstd PRIVATE ${NGSOLVE_COMPILE_DEFINITIONS_PRIVATE})
target_compile_options(ngstd PUBLIC ${NGSOLVE_COMPILE_OPTIONS})
target_include_directories(ngstd PUBLIC ${NGSOLVE_INCLUDE_DIRS} )

add_dependencies( ngstd generate_version_file )

target_link_libraries(ngstd PUBLIC netgen_libs)
target_link_libraries(ngstd PUBLIC ${MPI_CXX_LIBRARIES} PRIVATE "$<BUILD_INTERFACE:netgen_python>")
target_link_libraries(ngstd ${LAPACK_CMAKE_LINK_INTERFACE} "$<BUILD_INTERFACE:ngs_lapack>")
install( TARGETS ngstd ${ngs_install_dir} )

install( FILES
        bessel.hpp blockalloc.hpp evalfunc.hpp
        memusage.hpp ngstd.hpp
        stringops.hpp
        statushandler.hpp ngsstream.hpp 
        mycomplex.hpp python_ngstd.hpp ngs_utils.hpp
        bspline.hpp sample_sort.hpp
        DESTINATION ${NGSOLVE_INSTALL_DIR_INCLUDE}
        COMPONENT ngsolve_devel
       )
