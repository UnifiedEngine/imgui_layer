cmake_minimum_required(VERSION 3.12)

project(imgui_layer)

set(IMGUI_LAYER_IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui")

file(GLOB IMGUI_LAYER_IMGUI_SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${IMGUI_LAYER_IMGUI_DIR}/*.cpp")

add_library(${PROJECT_NAME} STATIC ${IMGUI_LAYER_IMGUI_SRC_FILES} 
    "${IMGUI_LAYER_IMGUI_DIR}/backends/imgui_impl_opengl3.cpp"
    "${IMGUI_LAYER_IMGUI_DIR}/backends/imgui_impl_glfw.cpp"
)

target_compile_definitions(${PROJECT_NAME} PUBLIC -DIMGUI_IMPL_OPENGL_LOADER_GLAD)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${IMGUI_LAYER_IMGUI_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../../include"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../vendor/fmt/include" 
    "${CMAKE_CURRENT_SOURCE_DIR}/../../vendor/glfw/include" 
    "${CMAKE_CURRENT_SOURCE_DIR}/../../vendor/glad/include"
)