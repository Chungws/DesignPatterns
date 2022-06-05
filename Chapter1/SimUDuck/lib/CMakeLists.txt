add_library( 
  content 
  QuackBehavior.cc  
  Squeak.cc  
  FlyBehavior.cc  
  FlyWithWings.cc      
  MuteQuack.cc
  Duck.cc        
  FlyNoWay.cc     
  MallardDuck.cc       
  Quack.cc
  FlyRocketPowered.cc
  ModelDuck.cc
)

target_include_directories(content PUBLIC ${CMAKE_SOURCE_DIR}/include)