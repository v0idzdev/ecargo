set(ecargo_sources
  "ecargo.c"
  "ecargo_server.c"
)

foreach(ecargo_source IN LISTS ecargo_sources)
  get_filename_component(ecargo_executable ${ecargo_source} NAME_WE)
  add_executable("${ecargo_executable}" "${ecargo_source}")
  target_compile_features("${ecargo_executable}" PRIVATE c_std_99)
  target_link_libraries("${ecargo_executable}" ecargo_utils)
endforeach()