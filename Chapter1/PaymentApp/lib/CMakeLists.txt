add_library( 
  payment 
  QuackBehavior.cc  
)

target_include_directories(content PUBLIC ${CMAKE_SOURCE_DIR}/include)