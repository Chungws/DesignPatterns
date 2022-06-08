add_library( 
  payment 
  Order.cc
  PayByCreditCard.cc
  PayByPayPal.cc
  CreditCard.cc
)

target_include_directories(payment PUBLIC ${CMAKE_SOURCE_DIR}/include)