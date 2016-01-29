SOURCE_FOLDER=./src
SHARED_LIB_NAME=libml.so
SHARED_LIB=ml
EXAMPLE_FOLDER=./examples
MAIN_SRC_FILES=|linear_regression.cpp
dev:
	g++ ${SOURCE_FOLDER}/linear_regression.cpp -o chk -larmadillo
allmake:
	g++ -fPIC $(subst |, ${SOURCE_FOLDER}/,${MAIN_SRC_FILES}) -shared -o ${SHARED_LIB_NAME} -larmadillo
	g++ ${EXAMPLE_FOLDER}/armadillo-example.cpp -o armadillo-example -larmadillo -L./ -lml
