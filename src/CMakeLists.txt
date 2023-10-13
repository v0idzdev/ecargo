file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${ecargo_SOURCE_DIR}/include/ecargo/*.h")
add_library(ecargo_utils
    "init.c"
    "input.c"
    "print.c"
    "validate.c"
    ${HEADER_LIST}
)
target_include_directories(ecargo_utils PUBLIC ../include)
target_compile_features(ecargo_utils PUBLIC c_std_99)

source_group(
  TREE "${ecargo_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST}
)

# add_library(ecargo_utils)
# target_sources(ecargo_utils
#   PRIVATE
#     "init.c"
#     "input.c"
#     "print.c"
#     "validate.c"
#   PUBLIC
#     ${HEADER_LIST}
# )