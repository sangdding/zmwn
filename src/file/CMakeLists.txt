# src/file/CMakeLists.txt

# 이 디렉토리의 소스 파일 추가
set(SOURCES io.c)

find_library(LIBZBD zbd PATHS /usr/lib)
find_library(LIBNVME nvme PATHS /usr/local/lib/x86_64-linux-gnu)


link_libraries(${LIBZBD} ${LIBNVME})

# 이 디렉토리의 소스 코드로 라이브러리 생성
add_library(file_lib ${SOURCES})

# 이 디렉토리의 라이브러리에 include 디렉토리 포함
target_include_directories(file_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)