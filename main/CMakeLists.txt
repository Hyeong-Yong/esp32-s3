file(GLOB SRC_FILES 
  bsp/*.c
  hw/*.c
  hw/driver/*.c
)

file(GLOB_RECURSE SRC_FILES_RECURSE
  ap/*.c
  common/*.c 
)


idf_component_register(
  SRCS "main.c"
  
  SRCS ${SRC_FILES}
  SRCS ${SRC_FILES_RECURSE}
  
<<<<<<< HEAD
  INCLUDE_DIRS "."
=======
  INCLUDE_DIRS ""
>>>>>>> 3b4ca14042be31702f1cc9a505a03565deafddf0
  INCLUDE_DIRS "ap"
  INCLUDE_DIRS "bsp"
  INCLUDE_DIRS "common"
  INCLUDE_DIRS "common/core"
  INCLUDE_DIRS "common/hw/include"
  INCLUDE_DIRS "hw"
  #INCLUDE_DIRS "lib" 
  )