set(INCLUDES "." "./ui/generated" "./ui/custom" "./ui/generated/guider_customer_fonts")
file(GLOB_RECURSE SOURCES ./*.c)

idf_component_register(SRCS ${SOURCES}
                        INCLUDE_DIRS ${INCLUDES})

spiffs_create_partition_image(img ../img FLASH_IN_PROJECT) 

