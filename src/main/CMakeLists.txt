project(main)

set(${PROJECT_NAME}_headers "")
set(${PROJECT_NAME}_sources main.cpp node.cpp analyzer.cpp)

add_executable (${PROJECT_NAME} ${${PROJECT_NAME}_heareds} ${${PROJECT_NAME}_sources})

#set(THREADS_PREFER_PTHREAD_FLAG ON)
#find_package(Threads REQUIRED)
#target_link_libraries(${PROJECT_NAME} Threads::Threads)

install(TARGETS ${PROJECT_NAME}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib/static)

