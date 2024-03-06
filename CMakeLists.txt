cmake_minimum_required(VERSION 3.10)
project(zmwn) # 프로젝트 이름 설정

# include 디렉토리 추가
include_directories(src/include)

# 하위 디렉토리 추가
add_subdirectory(src/file)
add_subdirectory(src/master)
add_subdirectory(src/test)