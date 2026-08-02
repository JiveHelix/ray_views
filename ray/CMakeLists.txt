add_library(ray_views)

if (${fPIC})
    set_property(TARGET ray_views PROPERTY POSITION_INDEPENDENT_CODE ON)
endif ()

FindPackages(tau wxpex ray)

# Projects that include this project must #include <ray/views/header-name>
target_include_directories(ray_views PUBLIC ${PROJECT_SOURCE_DIR})

target_link_libraries(
    ray_views
    PUBLIC
    ray::ray
    wxpex::wxpex)

target_sources(
    ray_views
    PRIVATE
    views/distortion_view.cpp
    views/homography_settings_view.cpp
    views/intrinsics_view.cpp)


install(TARGETS ray_views DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
    DIRECTORY ${PROJECT_SOURCE_DIR}/ray_views
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
