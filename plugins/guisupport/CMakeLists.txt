# probe plugin
set(gammaray_guisupport_srcs
  guisupport.cpp
)
gammaray_add_plugin(gammaray_guisupport JSON gammaray_guisupport.json DESKTOP gammaray_guisupport.desktop SOURCES ${gammaray_guisupport_srcs})
target_link_libraries(gammaray_guisupport gammaray_core)
if(Qt5Core_FOUND)
  target_link_libraries(gammaray_guisupport Qt5::Gui)
else()
  target_link_libraries(gammaray_guisupport ${QT_QT_GUI_LIBRARIES})
endif()

# ui plugin
if(GAMMARAY_BUILD_UI)
  set(gammaray_guisupport_ui_srcs
    guisupportuifactory.cpp
    paintanalyzertab.cpp
  )
  gammaray_add_plugin(gammaray_guisupport_ui JSON gammaray_guisupport.json DESKTOP gammaray_guisupport_ui.desktop SOURCES ${gammaray_guisupport_ui_srcs})
  target_link_libraries(gammaray_guisupport_ui gammaray_ui)
endif()
