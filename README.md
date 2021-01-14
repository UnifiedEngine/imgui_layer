# imgui_layer
Simple module for implementing [imgui](https://github.com/ocornut/imgui) in [UnifiedEngine](https://github.com/UnifiedEngine/UnifiedEngine).

## Minimal Example
```cpp
#include <imgui_layer/imgui_layer.hpp>

using namespace Unified;

class ImGuiLayer : public Modules::ImGuiLayer
{
public:

    ImGuiLayer(Application *application) {
        Create(application);
    }

    virtual ~ImGuiLayer() {
        Destroy();
    }

    virtual void OnUpdate(Time) override {
        ImGui::Begin("ImGuiLayer");
        ImGui::Text("Hello World!");
        ImGui::End();
    }

};
```

## Dependencies
* [imgui](https://github.com/ocornut/imgui)