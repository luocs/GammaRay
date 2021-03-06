# probe part
set(gammaray_sceneinspector_plugin_srcs
  scenemodel.cpp
  sceneinspectorinterface.cpp
  sceneinspector.cpp
  paintanalyzerextension.cpp
)

gammaray_add_plugin(gammaray_sceneinspector_plugin
  DESKTOP gammaray_sceneinspector.desktop.in
  JSON gammaray_sceneinspector.json
  SOURCES ${gammaray_sceneinspector_plugin_srcs}
)

target_link_libraries(gammaray_sceneinspector_plugin
  ${QT_QTGUI_LIBRARIES}
  gammaray_kitemmodels
  gammaray_core
)

# ui part
if(GAMMARAY_BUILD_UI)
  set(gammaray_sceneinspector_ui_plugin_srcs
    graphicsview.cpp
    graphicssceneview.cpp
    sceneinspectorinterface.cpp
    sceneinspectorclient.cpp
    sceneinspectorwidget.cpp
  )

  qt4_wrap_ui(gammaray_sceneinspector_ui_plugin_srcs
    graphicssceneview.ui
    sceneinspectorwidget.ui
  )

  gammaray_add_plugin(gammaray_sceneinspector_ui_plugin
    DESKTOP gammaray_sceneinspector_ui.desktop.in
    JSON gammaray_sceneinspector.json
    SOURCES ${gammaray_sceneinspector_ui_plugin_srcs}
  )

  target_link_libraries(gammaray_sceneinspector_ui_plugin
    ${QT_QTGUI_LIBRARIES}
    gammaray_ui
  )
endif()
