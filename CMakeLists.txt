cmake_minimum_required(VERSION 2.8)


project(path_planning) #PROJECT NAME

find_package( OpenCV REQUIRED ) #INCLUDING ANOTHER PACKAGES IN THE SYSTEM

include_directories( include ${OpenCV_INCLUDE_DIRS} mazes) #INCLUDING HEADERS AND ANOTHER DIRS IN THE SYSTEM


file(GLOB SOURCES "src/*.cpp") #SETTING SOURCES AS THE SRC FOLDER

add_executable(main ${SOURCES}) #add_executable

target_link_libraries(main ${OpenCV_LIBS} ) #LIKING OUR SOURCES WITH OpenCV_LIBS
