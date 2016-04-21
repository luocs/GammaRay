# probe plugin
if(Qt5WaylandCompositor_FOUND)
  find_package(Wayland COMPONENTS Server)
  set_package_properties(Wayland PROPERTIES PURPOSE "Needed for the QtWayland compositor inspector plug-in." TYPE OPTIONAL)

  include(CMakePushCheckState)
  include(CheckSymbolExists)
  cmake_push_check_state()
  set(CMAKE_REQUIRED_INCLUDES ${Wayland_INCLUDE_DIRS})
  set(CMAKE_REQUIRED_LIBRARIES Wayland::Server)
  check_symbol_exists(wl_add_protocol_logger "wayland-server.h" HAVE_WAYLAND_PROTOCOL_LOGGER)
  check_symbol_exists(wl_resource_get_interface "wayland-server.h" HAVE_WAYLAND_RESOURCE_GET_INTERFACE)
  cmake_pop_check_state()
  configure_file(config-gammaray-wayland.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config-gammaray-wayland.h)

  set(gammaray_wlcompositorinspector_srcs
    wlcompositorinspector.cpp
    wlcompositorinterface.cpp
    resourceinfo.cpp
  )
  gammaray_add_plugin(gammaray_wlcompositorinspector
    JSON gammaray_wlcompositorinspector.json SOURCES
    ${gammaray_wlcompositorinspector_srcs}
  )
  target_link_libraries(gammaray_wlcompositorinspector
    gammaray_core gammaray_kitemmodels Qt5::WaylandCompositor Wayland::Server)

endif()

# ui part
if(GAMMARAY_BUILD_UI)

  set(gammaray_wlcompositorinspector_ui_srcs
    inspectorwidget.cpp
    wlcompositorinterface.cpp
    wlcompositorclient.cpp
    logview.cpp
  )

  qt5_wrap_ui(gammaray_wlcompositorinspector_ui_srcs
    inspectorwidget.ui
  )

  gammaray_add_plugin(gammaray_wlcompositorinspector_ui
    JSON gammaray_wlcompositorinspector.json
    SOURCES ${gammaray_wlcompositorinspector_ui_srcs}
  )


  target_link_libraries(gammaray_wlcompositorinspector_ui
    Qt5::Widgets
    gammaray_common
    gammaray_ui
  )

endif()
