if(NETGEN_USE_PYTHON)
  add_test(NAME pytest COMMAND ${NETGEN_PYTHON_EXECUTABLE} -m pytest --durations=20 --ignore=mpi_only WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
  if(NETGEN_USE_MPI)
    add_test(NAME mpi_pytest COMMAND mpirun -np 5 --allow-run-as-root ${NETGEN_PYTHON_EXECUTABLE} -m pytest --durations=20 WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/mpi_only )
    set_tests_properties ( mpi_pytest PROPERTIES TIMEOUT 60 )
  endif()
  set_tests_properties ( pytest PROPERTIES TIMEOUT 1500 )
  add_custom_target(pytest ${NETGEN_PYTHON_EXECUTABLE} -m pytest --durations=20 --ignore=mpi_only WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif(NETGEN_USE_PYTHON)
