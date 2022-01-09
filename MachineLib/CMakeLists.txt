project(MachineLib)

set(SOURCE_FILES
        pch.h
        Machine.h Machine.cpp
        MachineFactory.cpp MachineFactory.h
        MachineStandin.cpp MachineStandin.h
        MachineDialog.cpp MachineDialog.h
        Polygon.cpp Polygon.h include/machine-api.h MachineBase.cpp MachineBase.h CustomMachineFactory.cpp CustomMachineFactory.h MachineController.cpp MachineController.h Component.cpp Component.h Shape.cpp Shape.h OwenMachineFactory.cpp OwenMachineFactory.h Motor.cpp Motor.h RotationSource.cpp RotationSource.h RotationSink.cpp RotationSink.h Gear.cpp Gear.h Arm.cpp Arm.h Rod.cpp Rod.h TranslationSource.cpp TranslationSource.h TranslationSink.cpp TranslationSink.h Lever.cpp Lever.h RodNegotiator.h RodSink.cpp RodSink.h RodSource.cpp RodSource.h Piston.cpp Piston.h)

find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)
include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)