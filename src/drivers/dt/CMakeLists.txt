SETUP_LIBRARY(dt)

target_link_libraries(dt PRIVATE stdbigos)

target_link_libraries(dt PRIVATE Debug)

target_include_directories(dt
  PUBLIC
    ${CMAKE_SOURCE_DIR}/include/drivers/dt
)
