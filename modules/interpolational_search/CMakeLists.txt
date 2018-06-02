# Объявляем переменные для будущих исполняемых файлов
get_filename_component(DIR_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)
set(MODULE      "${DIR_NAME}")
set(LIBRARY     "lib_${MODULE}")
set(TESTS       "test_${MODULE}")
set(APPLICATION "app_${MODULE}")

# Включаем папку с включаемыми файлами
include_directories("./")

# Добавляем подмодули
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(application)

#############################################
##### Тестирование
#############################################

include("CTestTests.txt")
