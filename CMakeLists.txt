cmake_minimum_required(VERSION 3.15)
project(project01)

set(CMAKE_CXX_STANDARD 14)

add_executable(project01 main.cpp src/objects/Object_interface.h src/objects/Object_interface.cpp src/UI.cpp src/UI.h src/structures/Vertex.cpp src/structures/Vertex.h src/structures/Leaf.cpp src/structures/Leaf.h src/objects/Publisher.cpp src/objects/Publisher.h src/objects/Book.cpp src/objects/Book.h helpers/CoverType.h src/objects/PopularScience.cpp src/objects/PopularScience.h src/objects/Bestseller.cpp src/objects/Bestseller.h src/objects/Magazine.cpp src/objects/Magazine.h src/objects/Daily.cpp src/objects/Daily.h src/objects/MagazineType.h src/objects/Monthly.cpp src/objects/Monthly.h src/objects/Weekly.cpp src/objects/Weekly.h helpers/WeekDay.h src/objects/Article.cpp src/objects/Article.h)
