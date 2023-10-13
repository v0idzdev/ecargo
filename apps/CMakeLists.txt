add_executable(ecargo ecargo.c)
target_compile_features(ecargo PRIVATE c_std_99)
target_link_libraries(ecargo)

add_executable(ecargo_server ecargo_server.c)
target_compile_features(ecargo_server PRIVATE c_std_99)
target_link_libraries(ecargo_server)