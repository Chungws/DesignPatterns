add_library(
    eventsubscription
    Editor.cc
    ObserverManager.cc
    EmailNotificationObserver.cc
    LogOpenObserver.cc
)

target_include_directories(eventsubscription PUBLIC ${CMAKE_SOURCE_DIR}/include)