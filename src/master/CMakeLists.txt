# src/master/CMakeLists.txt

# 이 디렉토리의 소스 파일 추가
set(SOURCES initializer.c)

# 이 디렉토리의 소스 코드로 라이브러리 생성
add_library(master_lib ${SOURCES})

# 이 디렉토리의 라이브러리에 include 디렉토리 포함
target_include_directories(master_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)