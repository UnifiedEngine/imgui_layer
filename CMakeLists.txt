project(imgui_layer)

set(IMGUI_LAYER_IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui")

file(GLOB IMGUI_LAYER_IMGUI_SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${IMGUI_LAYER_IMGUI_DIR}/*.cpp")

add_library(${PROJECT_NAME} STATIC ${IMGUI_LAYER_IMGUI_SRC_FILES} 
    "${IMGUI_LAYER_IMGUI_DIR}/backends/imgui_impl_opengl3.cpp"
    "${IMGUI_LAYER_IMGUI_DIR}/backends/imgui_impl_glfw.cpp"
)

target_compile_definitions(${PROJECT_NAME} PUBLIC -DIMGUI_IMPL_OPENGL_LOADER_GLAD)
target_include_directories(${PROJECT_NAME} PUBLIC ${IMGUI_LAYER_IMGUI_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC ${UNIFIED_PROJECT} glfw ${GLFW_LIBRARIES} glad ${CMAKE_DL_LIBS})