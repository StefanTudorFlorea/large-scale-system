# config
set(SERVICE_ID serviceOne)

# crud-service
add_executable(${SERVICE_ID}
    src/main.cpp 
    src/ServiceOneAgent.hpp
    src/ServiceOneImpl.hpp
)

# dependencies
target_link_libraries(${SERVICE_ID}
    PRIVATE
        common
        Crow::Crow
        fmt::fmt-header-only 
        yaml-cpp::yaml-cpp
)

# the services is found under bin/serviceA/
set_target_properties(${SERVICE_ID} 
    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${SERVICE_ID}
)

# config
add_custom_command(
    TARGET ${SERVICE_ID} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/config.yml
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${SERVICE_ID}/config.yml)